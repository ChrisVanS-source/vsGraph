#include "qdefines.h"
#include "qgraph_generator.h"
#include "qgraph_i.h"
#include "qgraph_sweep.h"
#include "intrin.h"
#include "qexception.h"
#include "qscalar_traits.h"
using namespace vstech;

template class graph_generator<double>;
template class graph_generator<float>;
#ifdef INSTANTIATE_AVX512
template class graph_generator<__m512d>;
template class graph_generator<__m512>;
#endif
template class graph_generator<__m256d>;
template class graph_generator<__m256>;
template class graph_generator<__m128d>;
template class graph_generator<__m128>;

template class graph_generator<double*>;
template class graph_generator<float*>;
#ifdef INSTANTIATE_AVX512
template class graph_generator<__m512d*>;
template class graph_generator<__m512*>;
#endif
template class graph_generator<__m256d*>;
template class graph_generator<__m256*>;
template class graph_generator<__m128d*>;
template class graph_generator<__m128*>;

#include "qgraph_prune.h"
#include "qgraph_remap.h"

template<class T>
graph_generator<T>::graph_generator(const qgraph_i<T>& g) : 
	m_g(new qgraph_i<T>()), 
	m_address(0), 
	m_n_orig_variable(0),
	m_n_non_param(0),
	m_adtype(NONE),
	m_phase(NONE), 
	m_var_counter(g.get_var_counter()),
	m_skip_ops_init(g.get_skip_ops_init()),
	m_skip_ops_arg_init(g.get_skip_ops_arg_init()),
	m_skip_index(0),
	m_zero_index((uint64_t)-1),
	m_input_map(g.get_input_map()[0]),
	m_output_map(g.get_output_map()),
	m_input_output_map(g.get_input_output_map()),
	m_variable_map(g.get_variable_map()),
	m_scalar(g.get_scalar()),
	m_assign_map(NUMBER_OF_TYPES)
{
	// Populate graph with same scalars as original graph

	const auto& scalar = g.get_scalar();

	for (uint64_t j = 0; j < scalar.size(); ++j)
		m_g->get_scalar_index(scalar[j]);

	// Add zero: used for initialising input auxiliary variables, which are parameters by definition

	m_zero_index = m_g->get_scalar_index(graph_traits<T>::cast(0.0));

	// Populate assign map

	const auto& assign_map = g.get_assign_map()[0];

	for (auto it = assign_map.begin(); it != assign_map.end(); ++it)
		m_assign_map[QFLOATING_POINT][it->first] = m_g->get_scalar_index(scalar[it->second]);

	// Go through auxiliary inputs and add them to the assign map
	// Logic is temporary and will be changed to b egeneric for any order graph

	const auto& adtype = g.get_adtype();
	uint64_t order = adtype.size();

	if (adtype[order - 1] == FORWARD) // works for any order FORWARD^n but not if a BACKWARD was inserted
	{
		m_adtype = FORWARD;

		for (auto it = m_input_map[0].left.begin(); it != m_input_map[0].left.end(); ++it)
		{
			for (uint64_t j = 1; j < m_input_map.size(); ++j)
			{
				auto jt = m_input_map[j].left.find(it->second);
				if (jt != m_input_map[j].left.end())
					m_assign_map[QFLOATING_POINT].insert({jt->second, m_zero_index});
			}
		}
	}
	else // Only works for BACKWARD^1
	{
		m_adtype = BACKWARD;

		for (auto it = m_output_map[0].left.begin(); it != m_output_map[0].left.end(); ++it)
		{
			auto jt = m_input_map[1].left.find(it->second);

			if (jt != m_input_map[1].left.end())
				m_assign_map[QFLOATING_POINT].insert({jt->second, m_zero_index});
		}
	}

	// Setup address for auxiliary variables

	m_n_orig_variable = m_address = m_var_counter + g.get_n_nonparam();
	m_param_remap.resize(m_address, (uint64_t)-1);

	// Setup auxiliary map

	for (uint64_t i = 0; i < g.get_n_nonparam(); ++i)
		m_aux_map.push_back(i + m_var_counter);

	// Declare non-parametric inputs for the new graph
	// We not declare auxiliary as inputs as they are parameters and will be treated as such upon first use

	const auto& lc = g.get_lifecycle();

	for (auto it = m_input_map[0].left.begin(); it != m_input_map[0].left.end(); ++it)
		if (!lc[0][it->second].is_param())
			m_g->input(it->second, scalar[it->second]);

	// Perform sweep

	g.sweep_forward(*this);
	if (m_adtype == BACKWARD)
		g.sweep_backward(*this);


	// Declare outputs

	for (uint64_t i = 0; i < m_output_map.size(); ++i)
		for (auto it = m_output_map[i].left.begin(); it != m_output_map[i].left.end(); ++it)
		{
			uint64_t idx = it->second;
			if (idx >= m_var_counter)
			{
				if (order == i)
					idx = m_aux_map[idx - m_var_counter];
				else
					throw qexception("Bad state should not happen");
			}
			m_g->qgraph_i_base::output(idx);
		}

	// Post-process without remapping

	m_g->post_process(false);

	m_zero_index = m_g->get_scalar_index(graph_traits<T>::cast(0.0));

	// Prune to determine subtree that ipacts high order derivs

	boost::bimap<uint64_t, uint64_t> omderiv;

	for (auto it = m_output_map[order].left.begin(); it != m_output_map[order].left.end(); ++it)
		omderiv.insert({ m_aux_map[it->second - m_var_counter], m_param_remap[it->second] });

	graph_prune_base gp(m_g->get_ops(),
		m_g->get_ops_arg_index(),
		omderiv,
		m_g->get_lifecycle(),
		m_g->get_checkpoint_ops_index());

	// Remap m_g graph

	graph_remap gr(m_g->get_lifecycle()[0], gp.get_arg_hit()[0]);
	m_g->sweep_forward(gr);
	gr.swap(m_g->get_ops_arg_index());

	// Remap lifecycle vector so no need to call swap above

	m_n_non_param = gr.get_n_nonparam();

	const auto& pr = gr.get_param_remap();
	graph_remap::remap(m_g->get_lifecycle()[0], m_g->get_var_counter(), pr);
	graph_remap::remap(m_g->get_assign_map()[0], pr);

	// Further adjust param_remap because m_g had its own internal address so need to change to map used to change the index of the graph

	for (uint64_t i = 0; i < m_param_remap.size(); ++i) if (m_param_remap[i] != (uint64_t)-1)
		m_param_remap[i] = pr[m_param_remap[i]];

	// Remap input, output, and variable map

	graph_remap::remap(m_variable_map, true, m_param_remap);
	for (uint64_t i = 0; i < m_input_map.size(); ++i)
		graph_remap::remap(m_input_map[i], i == 0, m_param_remap);
	for (uint64_t i = 0; i < m_output_map.size(); ++i)
		graph_remap::remap(m_output_map[i], i == 0, m_param_remap);
	graph_remap::remap(m_input_output_map, true, m_param_remap);

	// Change var counter

	m_var_counter = m_g->get_var_counter();


}

template<class T>
graph_generator<T>::~graph_generator()
{
}

template<class T>
void graph_generator<T>::swap(qgraph_i<T>& g)
{
	g.get_zero_index() = m_zero_index;
	g.get_assign_map()[0].swap(m_g->get_assign_map()[0]);
	g.get_variable_map().swap(m_variable_map);
	g.get_n_nonparam() = m_n_non_param;
	g.get_var_counter() = m_var_counter;
	g.get_lifecycle()[0].swap(m_g->get_lifecycle()[0]);
	g.get_input_map()[0].swap(m_input_map);
	g.get_output_map().swap(m_output_map);
	g.get_input_output_map().swap(m_g->get_input_output_map());
	g.get_ops().swap(m_g->get_ops());
	g.get_ops_arg_index().swap(m_g->get_ops_arg_index());
	g.get_scalar().swap(m_g->get_scalar());
	g.get_scalar_map().swap(m_g->get_scalar_map());
	g.get_checkpoint_ops_index().swap(m_g->get_checkpoint_ops_index());
	g.get_checkpoint_ops_arg_index().swap(m_g->get_checkpoint_ops_arg_index());
}


class scalar_assign : public scalar_value {

	const std::map<uint64_t, uint64_t>& m_assign_map;
	uint64_t m_x;

public:

	scalar_assign(uint64_t x, std::map<uint64_t, uint64_t>& assign_map) : m_x(x), m_assign_map(assign_map) {}
	~scalar_assign() {}

	uint64_t get_index() const
	{
		auto it = m_assign_map.find(m_x);
		if (it == m_assign_map.end())
			throw qexception("Code in bad state should never get here");
		return it->second;
	}

};

class integer_assign : public integer_value {

	const std::map<uint64_t, uint64_t>& m_assign_map;
	uint64_t m_x;

public:

	integer_assign(uint64_t x, std::map<uint64_t, uint64_t>& assign_map) : m_x(x), m_assign_map(assign_map) {}
	~integer_assign() {}

	uint64_t get_index() const
	{
		auto it = m_assign_map.find(m_x);
		if (it == m_assign_map.end())
			throw qexception("Code in bad state should never get here");
		return it->second;
	}

};

class boolean_assign : public boolean_value {

	const std::map<uint64_t, uint64_t>& m_assign_map;
	uint64_t m_x;

public:

	boolean_assign(uint64_t x, std::map<uint64_t, uint64_t>& assign_map) : m_x(x), m_assign_map(assign_map) {}
	~boolean_assign() {}

	uint64_t get_index() const
	{
		auto it = m_assign_map.find(m_x);
		if (it == m_assign_map.end())
			throw qexception("Code in bad state should never get here");
		return it->second;
	}

};


class scalar_id : public scalar_value {

	int64_t m_x;

public:

	scalar_id(const uint64_t& x) : m_x(x) {}
	uint64_t get_index() const
	{
		return m_x;
	}

};

class integer_id : public integer_value {

	int64_t m_x;

public:

	integer_id(const uint64_t& x) : m_x(x) {}
	uint64_t get_index() const
	{
		return m_x;
	}

};

class boolean_id : public boolean_value {

	int64_t m_x;

public:

	boolean_id(const uint64_t& x) : m_x(x) {}
	uint64_t get_index() const
	{
		return m_x;
	}

};



template<class T>
void graph_generator<T>::before_forward()
{
	m_phase = FORWARD;
}

template<class T>
void graph_generator<T>::before_backward()
{
	m_phase = BACKWARD;
}

template<class T>
void graph_generator<T>::check_integrity(uint64_t new_i, const uint64_t& i)
{
	if (i >= m_n_orig_variable)
		return;

	if (i >= m_param_remap.size())
		m_param_remap.resize(i + 1, (uint64_t)-1);

	if (m_param_remap[i] == (uint64_t)-1)
		m_param_remap[i] = new_i;
	if (new_i != m_param_remap[i])
		throw qexception("Bad graph state : intrgrity check failed");
}

template<class T>
const uint64_t& graph_generator<T>::auxiliary(uint64_t x) const
{ 
	return m_aux_map[x];
}

template<class T>
void graph_generator<T>::set_auxiliary(uint64_t x, const uint64_t& wx)
{
	m_aux_map[x] = wx;
	m_param_remap[x + m_var_counter] = m_g->varmap(wx).first->second;
}

template<class T>
int64_t graph_generator<T>::get_double_index(const double& x)
{
	return m_g->get_scalar_index(graph_traits<T>::cast(x));
}


template<class T>
int64_t graph_generator<T>::get_scalar_index(const typename graph_traits<T>::scalar_type& x)
{
	return m_g->get_scalar_index(x);
}

template<class T>
void graph_generator<T>::equal_scalar(uint64_t orig_clock, const uint64_t& r_i, const uint64_t& s_i)
{
	m_g->qgraph_i_base::equal_scalar(r_i, scalar_id(s_i));
}


template<class T>
void graph_generator<T>::process_func1(uint64_t& clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, bool check_output)
{
	m_g->qgraph_i_base::process_func1(r_i, op, x_i, scalar_assign(x_i, m_assign_map[QFLOATING_POINT]));

	if (x_i == r_i)
		throw qexception("Bad state");

	const auto& i = m_g->get_ops_arg_index();
	check_integrity(i[i.size() - 2], x_i);
	if (check_output)
		check_integrity(i[i.size() - 1], r_i);

	++clock;
}

template<class T>
void graph_generator<T>::process_func2(uint64_t& clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, bool check_output)
{
	m_g->qgraph_i_base::process_func2(r_i, op, x_i, scalar_assign(x_i, m_assign_map[QFLOATING_POINT]), y_i, scalar_assign(y_i, m_assign_map[QFLOATING_POINT]));

	if (x_i == r_i || y_i == r_i)
		throw qexception("Bad state");

	const auto& i = m_g->get_ops_arg_index();
	check_integrity(i[i.size() - 3], x_i);
	check_integrity(i[i.size() - 2], y_i);
	if (check_output)
		check_integrity(i[i.size() - 1], r_i);

	++clock;
}

template<class T>
void graph_generator<T>::process_func2_sy(uint64_t& clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i, bool check_output)
{
	m_g->qgraph_i_base::process_func2_sy(r_i, op, x_i, scalar_assign(x_i, m_assign_map[QFLOATING_POINT]), scalar_id(s_i));

	if (x_i == r_i)
		throw qexception("Bad state");

	const auto& i = m_g->get_ops_arg_index();
	check_integrity(i[i.size() - 3], x_i);
	if (check_output)
		check_integrity(i[i.size() - 1], r_i);

	++clock;
}

template<class T>
void graph_generator<T>::process_integer1(uint64_t& clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	m_g->qgraph_i_base::process_integer1(r_i, op, x_i, integer_assign(x_i, m_assign_map[QINTEGER]));
}

template<class T>
void graph_generator<T>::process_integer2(uint64_t& clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_integer2(r_i, op, x_i, integer_assign(x_i, m_assign_map[QINTEGER]), y_i, integer_assign(y_i, m_assign_map[QINTEGER]));
}

template<class T>
void graph_generator<T>::process_integer2_ix(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_integer2_ix(r_i, op, integer_id(x_i), y_i, integer_assign(y_i, m_assign_map[QINTEGER]));
}

template<class T>
void graph_generator<T>::process_integer2_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_integer2_iy(r_i, op, x_i, integer_assign(x_i, m_assign_map[QINTEGER]), integer_id(y_i));
}

template<class T>
void graph_generator<T>::process_integer2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_integer2_logical(r_i, op, x_i, integer_assign(x_i, m_assign_map[QINTEGER]), y_i, integer_assign(y_i, m_assign_map[QINTEGER]));
}

template<class T>
void graph_generator<T>::process_integer2_logical_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_integer2_logical_iy(r_i, op, x_i, integer_assign(x_i, m_assign_map[QINTEGER]), integer_id(y_i));
}

template<class T>
void graph_generator<T>::process_integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_integer_iff(r_i, op, c_i, boolean_assign(c_i, m_assign_map[QBOOLEAN]), x_i, integer_assign(x_i, m_assign_map[QINTEGER]), y_i, integer_assign(y_i, m_assign_map[QINTEGER]));
}

template<class T>
void graph_generator<T>::process_integer_iff_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_integer_iff_iy(r_i, op, c_i, boolean_assign(c_i, m_assign_map[QBOOLEAN]), x_i, integer_assign(x_i, m_assign_map[QINTEGER]), integer_id(y_i));
}

template<class T>
void graph_generator<T>::process_integer_iff_ix_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_integer_iff_ix_iy(r_i, op, c_i, boolean_assign(c_i, m_assign_map[QBOOLEAN]), integer_id(x_i), integer_id(y_i));
}

template<class T>
void graph_generator<T>::process_boolean1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	m_g->qgraph_i_base::process_boolean1(r_i, op, x_i, boolean_assign(x_i, m_assign_map[QBOOLEAN]));
}

template<class T>
void graph_generator<T>::process_boolean1_bx(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	m_g->qgraph_i_base::process_boolean1_bx(r_i, op, boolean_id(x_i));
}

template<class T>
void graph_generator<T>::process_boolean2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_boolean2(r_i, op, x_i, boolean_assign(x_i, m_assign_map[QBOOLEAN]), y_i, boolean_assign(y_i, m_assign_map[QBOOLEAN]));
}

template<class T>
void graph_generator<T>::process_boolean2_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_boolean2_by(r_i, op, x_i, boolean_assign(x_i, m_assign_map[QBOOLEAN]), boolean_id(y_i));
}

template<class T>
void graph_generator<T>::process_boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_boolean_iff(r_i, op, c_i, boolean_assign(c_i, m_assign_map[QBOOLEAN]), x_i, boolean_assign(x_i, m_assign_map[QBOOLEAN]), y_i, boolean_assign(y_i, m_assign_map[QBOOLEAN]));
}

template<class T>
void graph_generator<T>::process_boolean_iff_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_boolean_iff_by(r_i, op, c_i, boolean_assign(c_i, m_assign_map[QBOOLEAN]), x_i, boolean_assign(x_i, m_assign_map[QBOOLEAN]), boolean_id(y_i));
}

template<class T>
void graph_generator<T>::process_boolean_iff_bx_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	m_g->qgraph_i_base::process_boolean_iff_bx_by(r_i, op, c_i, boolean_assign(c_i, m_assign_map[QBOOLEAN]), boolean_id(x_i), boolean_id(y_i));
}

template<class T>
bool graph_generator<T>::adjoint_used(const uint64_t& x_i, uint64_t clock)
{
	if (clock == m_skip_ops_init[m_skip_index] && x_i == m_skip_ops_arg_init[m_skip_index])
	{
		++m_skip_index;
		return true;
	}
	else
		return false;
}

template<class T>
uint64_t graph_generator<T>::add_variable()
{
	return m_address++;
}

template<class T>
void graph_generator<T>::update_adjoint_sy(uint64_t orig_clock, const uint64_t& x_i, Operation op, const uint64_t& r_i, const int64_t& s_i, Operation wrop)
{
	uint64_t clock = m_g->now();

	if ((op != ADD && op != SUBTRACT) || (wrop != MULTIPLY_SCALAR && wrop != DIVIDE_SCALAR))
		throw qexception("Invalid operation passed to update_adjoint function - this should never happen");

	bool adj_used = adjoint_used(x_i, orig_clock);

	uint64_t var = r_i;

	if (adj_used)
	{
		process_func2_sy(clock, var = add_variable(), wrop, r_i, s_i);
		uint64_t wx = add_variable();
		process_func2(clock, wx, op, auxiliary(x_i), var);
		set_auxiliary(x_i, wx);
	}
	else
	{
		if (op == SUBTRACT)
			process_func1(clock, var = add_variable(), CHANGE_SIGN, r_i);
		process_func2_sy(clock, auxiliary(x_i), wrop, var, s_i);
	}
}

template<class T>
void graph_generator<T>::update_adjoint(uint64_t orig_clock, const uint64_t& x_i, Operation op, const uint64_t& r_i, const uint64_t& m_i, Operation wrop)
{
	uint64_t clock = m_g->now();

	if ((op != ADD && op != SUBTRACT) || (wrop != MULTIPLY && wrop != DIVIDE))
		throw qexception("Invalid operation passed to update_adjoint function - this should never happen");

	// Adjoint has not been used:
	//	m_i  = -1 and op = ADD -> aux(x) = r_i -> process_func1(aux(x),EQUAL,r_i)
	//	m_i  = -1 and op = SUBTRACT -> aux(x) = -r_i -> process_func1(aux(x),CHANGE_SIGN,r_i)
	//	m_i != -1 and op = ADD and wrop = MULTIPLY -> aux(x) = r_i*m_i -> process_func2(aux(x), wrop, r_i, m_i)
	//	m_i != -1 and op = ADD and wrop = DIVIDE -> aux(x) = r_i/m_i -> process_func2(aux(x), wrop, r_i, m_i)
	//	m_i != -1 and op = SUBTRACT and wrop = MULTIPLY -> aux(x) = -r_i*m_i -> new_var process_func1(new_var, CHANGE_SIGN, r_i) -> process_func2(aux(x), wrop, new_var, m_i)
	//	m_i != -1 and op = SUBTRACT and wrop = DIVIDE -> aux(x) = -r_i/m_i -> new_var process_func1(new_var, CHANGE_SIGN, r_i) -> process_func2(aux(x), wrop, new_var, m_i)
	//  Therefore the logic when adjoint has not been used
	//	   if (m_i == -1)
	//			process_func1(aux(x),map(op),r_i)
	//     if (m_i != -1) 
	//			var = r_i 
	//			if (op == SUBTRACT) -> process_func1(var, CHANGE_SIGN, r_i) 
	//			process_func2(aux(x),op,var,m_i)
	//   
	// Adjoint has been used:
	//	m_i  = -1 and op = ADD -> aux(x) += r_i -> new_aux -> process_func2(new_aux(x),op,aux(x),r_i)
	//	m_i  = -1 and op = SUBTRACT -> aux(x) -= r_i -> new_aux -> process_func2(new_aux(x),op,aux(x),r_i)
	//	m_i != -1 and op = ADD and wrop = MULTIPLY -> aux(x) += r_i*m_i -> new_var -> process_func2(new_var, wrop, r_i, m_i) -> new_aux -> process_func2(new_aux(x), op, aux(x), new_var)
	//	m_i != -1 and op = ADD and wrop = DIVIDE -> aux(x) += r_i/m_i -> new_var -> process_func2(new_var, wrop, r_i, m_i) -> new_aux -> process_func2(new_aux(x), op, aux(x), new_var)
	//	m_i != -1 and op = SUBTRACT and wrop = MULTIPLY -> aux(x) -= r_i*m_i -> new_var -> process_func2(new_var, wrop, r_i, m_i) -> new_aux -> process_func2(new_aux(x), op, aux(x), new_var)
	//	m_i != -1 and op = SUBTRACT and wrop = DIVIDE -> aux(x) += r_i/m_i -> new_var -> process_func2(new_var, wrop, r_i, m_i) -> new_aux -> process_func2(new_aux(x), op, aux(x), new_var)
	//  Therefore the logic when adjoint has been used is:
	//     if (m_i == -1)
	//			process_func2(new_aux(x),op,aux(x),r_i)
	//     if (m_i != -1) 
	//			var = r_i 
	//			process_func2(var, wrop, r_i, m_i) 
	//			process_func2(new_aux(x),op,aux(x),var)
	//  which can be collapsed as follows:
	//		var = r_i
	//		if (m_i != -1)
	//			var = add_variable(); process_func2(var, wrop, r_i, m_i) 
	//		process_func2(new_aux(x), op, aux(x), var)
	// If m_i is a scalar, we have the same logic except DIVIDE is replaced by DIVIDE_SCALAR and MULTIPLY by MULTIPLY_SCALAR
	// and process_func2_sy is called instead of process_func2

	bool adj_used = adjoint_used(x_i, orig_clock);

	uint64_t var = r_i;

	if (adj_used)
	{
		if (m_i != (uint64_t)-1)
			process_func2(clock, var = add_variable(), wrop, r_i, m_i);
		uint64_t wx = add_variable();
		process_func2(clock, wx, op, auxiliary(x_i), var);
		set_auxiliary(x_i, wx);
	}
	else
	{
		if (m_i == (uint64_t)-1)
			process_func1(clock, auxiliary(x_i), op == ADD ? EQUAL : CHANGE_SIGN, r_i);
		else
		{
			if (op == SUBTRACT)
				process_func1(clock, var = add_variable(), CHANGE_SIGN, r_i);
			process_func2(clock, auxiliary(x_i), wrop, var, m_i);
		}
	}
}


//${begin}
template<class T>
void graph_generator<T>::equal_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1_sx(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::equal(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i)); // wx=wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, EQUAL, x_i); // r=x
		process_func1(clock, auxiliary(r_i), EQUAL, auxiliary(x_i)); // dr=dx
	}
	else
	{
		process_func1(clock, r_i, EQUAL, x_i); // r=x
	}
}

template<class T>
void graph_generator<T>::equal_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::squareroot(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, MULTIPLY_SCALAR, auxiliary(r_i), get_double_index(0.5)); // x0=wr*0.5
		update_adjoint(orig_clock, x_i, ADD, x0, r_i, DIVIDE); // wx=wr*0.5/r

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, SQUAREROOT, x_i); // r=std::sqrt(x)
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, MULTIPLY_SCALAR, auxiliary(x_i), get_double_index(0.5)); // x0=dx*0.5
		process_func2(clock, auxiliary(r_i), DIVIDE, x0, r_i); // dr=dx*0.5/r
	}
	else
	{
		process_func1(clock, r_i, SQUAREROOT, x_i); // r=std::sqrt(x)
	}
}

template<class T>
void graph_generator<T>::squareroot_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::change_sign(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, SUBTRACT, auxiliary(r_i)); // wx=-wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, CHANGE_SIGN, x_i); // r=-x
		process_func1(clock, auxiliary(r_i), CHANGE_SIGN, auxiliary(x_i)); // dr=-dx
	}
	else
	{
		process_func1(clock, r_i, CHANGE_SIGN, x_i); // r=-x
	}
}

template<class T>
void graph_generator<T>::change_sign_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::ceiling(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, CEILING, x_i); // r=std::ceil(x)
		equal_scalar(clock, auxiliary(r_i), get_double_index(0.0)); // dr=0
	}
	else if (m_phase != BACKWARD)
	{
		process_func1(clock, r_i, CEILING, x_i); // r=std::ceil(x)
	}
}

template<class T>
void graph_generator<T>::ceiling_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::flooring(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, FLOORING, x_i); // r=std::floor(x)
		equal_scalar(clock, auxiliary(r_i), get_double_index(0.0)); // dr=0
	}
	else if (m_phase != BACKWARD)
	{
		process_func1(clock, r_i, FLOORING, x_i); // r=std::floor(x)
	}
}

template<class T>
void graph_generator<T>::flooring_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::heaviside_step(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, HEAVISIDE_STEP, x_i); // r=hss(x)
		equal_scalar(clock, auxiliary(r_i), get_double_index(0.0)); // dr=0
	}
	else if (m_phase != BACKWARD)
	{
		process_func1(clock, r_i, HEAVISIDE_STEP, x_i); // r=hss(x)
	}
}

template<class T>
void graph_generator<T>::heaviside_step_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::exponential(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), r_i); // wx=wr*r

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, EXPONENTIAL, x_i); // r=std::exp(x)
		process_func2(clock, auxiliary(r_i), MULTIPLY, r_i, auxiliary(x_i)); // dr=r*dx
	}
	else
	{
		process_func1(clock, r_i, EXPONENTIAL, x_i); // r=std::exp(x)
	}
}

template<class T>
void graph_generator<T>::exponential_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::logarithm(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x_i, DIVIDE); // wx=wr/x

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, LOGARITHM, x_i); // r=std::log(x)
		process_func2(clock, auxiliary(r_i), DIVIDE, auxiliary(x_i), x_i); // dr=dx/x
	}
	else
	{
		process_func1(clock, r_i, LOGARITHM, x_i); // r=std::log(x)
	}
}

template<class T>
void graph_generator<T>::logarithm_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::logarithm2(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, MULTIPLY_SCALAR, x_i, get_double_index(0.69314718055994529)); // x0=x*0.69314718055994529
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x0, DIVIDE); // wx=wr/(x*0.69314718055994529)

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, LOGARITHM2, x_i); // r=std::log2(x)
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, MULTIPLY_SCALAR, x_i, get_double_index(0.69314718055994529)); // x0=x*0.69314718055994529
		process_func2(clock, auxiliary(r_i), DIVIDE, auxiliary(x_i), x0); // dr=dx/(x*0.69314718055994529)
	}
	else
	{
		process_func1(clock, r_i, LOGARITHM2, x_i); // r=std::log2(x)
	}
}

template<class T>
void graph_generator<T>::logarithm2_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::logarithm10(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, MULTIPLY_SCALAR, x_i, get_double_index(2.3025850929940459)); // x0=x*2.3025850929940459
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x0, DIVIDE); // wx=wr/(x*2.3025850929940459)

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, LOGARITHM10, x_i); // r=std::log10(x)
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, MULTIPLY_SCALAR, x_i, get_double_index(2.3025850929940459)); // x0=x*2.3025850929940459
		process_func2(clock, auxiliary(r_i), DIVIDE, auxiliary(x_i), x0); // dr=dx/(x*2.3025850929940459)
	}
	else
	{
		process_func1(clock, r_i, LOGARITHM10, x_i); // r=std::log10(x)
	}
}

template<class T>
void graph_generator<T>::logarithm10_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::complementary_errorfunc(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func1(clock, x0, CHANGE_SIGN, x_i); // x0=-x
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, x0, x_i); // x1=-x*x
		uint64_t x2 = add_variable(); process_func1(clock, x2, EXPONENTIAL, x1); // x2=std::exp(-x*x)
		uint64_t x3 = add_variable(); process_func2(clock, x3, MULTIPLY, auxiliary(r_i), x2); // x3=wr*std::exp(-x*x)
		uint64_t x4 = add_variable(); process_func2_sy(clock, x4, MULTIPLY_SCALAR, x3, get_double_index(1.1283791670955126)); // x4=wr*std::exp(-x*x)*1.1283791670955126
		update_adjoint(orig_clock, x_i, SUBTRACT, x4); // wx=-wr*std::exp(-x*x)*1.1283791670955126

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, COMPLEMENTARY_ERRORFUNC, x_i); // r=std::erfc(x)
		uint64_t x0 = add_variable(); process_func1(clock, x0, CHANGE_SIGN, x_i); // x0=-x
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, x0, x_i); // x1=-x*x
		uint64_t x2 = add_variable(); process_func1(clock, x2, EXPONENTIAL, x1); // x2=std::exp(-x*x)
		uint64_t x3 = add_variable(); process_func2_sy(clock, x3, MULTIPLY_SCALAR, x2, get_double_index(1.1283791670955126)); // x3=std::exp(-x*x)*1.1283791670955126
		uint64_t x4 = add_variable(); process_func2(clock, x4, MULTIPLY, x3, auxiliary(x_i)); // x4=std::exp(-x*x)*1.1283791670955126*dx
		process_func1(clock, auxiliary(r_i), CHANGE_SIGN, x4); // dr=-std::exp(-x*x)*1.1283791670955126*dx
	}
	else
	{
		process_func1(clock, r_i, COMPLEMENTARY_ERRORFUNC, x_i); // r=std::erfc(x)
	}
}

template<class T>
void graph_generator<T>::complementary_errorfunc_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::sine(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func1(clock, x0, COSINE, x_i); // x0=std::cos(x)
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x0); // wx=wr*std::cos(x)

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, SINE, x_i); // r=std::sin(x)
		uint64_t x0 = add_variable(); process_func1(clock, x0, COSINE, x_i); // x0=std::cos(x)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x0, auxiliary(x_i)); // dr=std::cos(x)*dx
	}
	else
	{
		process_func1(clock, r_i, SINE, x_i); // r=std::sin(x)
	}
}

template<class T>
void graph_generator<T>::sine_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::cosine(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func1(clock, x0, SINE, x_i); // x0=std::sin(x)
		uint64_t x1 = add_variable(); process_func1(clock, x1, CHANGE_SIGN, auxiliary(r_i)); // x1=-wr
		update_adjoint(orig_clock, x_i, ADD, x1, x0); // wx=-wr*std::sin(x)

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, COSINE, x_i); // r=std::cos(x)
		uint64_t x0 = add_variable(); process_func1(clock, x0, SINE, x_i); // x0=std::sin(x)
		uint64_t x1 = add_variable(); process_func1(clock, x1, CHANGE_SIGN, x0); // x1=-std::sin(x)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(x_i)); // dr=-std::sin(x)*dx
	}
	else
	{
		process_func1(clock, r_i, COSINE, x_i); // r=std::cos(x)
	}
}

template<class T>
void graph_generator<T>::cosine_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::tangent(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func1(clock, x0, COSINE, x_i); // x0=std::cos(x)
		uint64_t x1 = add_variable(); process_func1(clock, x1, COSINE, x_i); // x1=std::cos(x)
		uint64_t x2 = add_variable(); process_func2(clock, x2, MULTIPLY, x1, x0); // x2=std::cos(x)*std::cos(x)
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x2, DIVIDE); // wx=wr/(std::cos(x)*std::cos(x))

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, TANGENT, x_i); // r=std::tan(x)
		uint64_t x0 = add_variable(); process_func1(clock, x0, COSINE, x_i); // x0=std::cos(x)
		uint64_t x1 = add_variable(); process_func1(clock, x1, COSINE, x_i); // x1=std::cos(x)
		uint64_t x2 = add_variable(); process_func2(clock, x2, MULTIPLY, x1, x0); // x2=std::cos(x)*std::cos(x)
		process_func2(clock, auxiliary(r_i), DIVIDE, auxiliary(x_i), x2); // dr=dx/(std::cos(x)*std::cos(x))
	}
	else
	{
		process_func1(clock, r_i, TANGENT, x_i); // r=std::tan(x)
	}
}

template<class T>
void graph_generator<T>::tangent_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::arc_sine(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2(clock, x0, MULTIPLY, x_i, x_i); // x0=x*x
		uint64_t x1 = add_variable(); process_func2_sy(clock, x1, SCALAR_SUBTRACT, x0, get_double_index(1.0)); // x1=1.0-x*x
		uint64_t x2 = add_variable(); process_func1(clock, x2, SQUAREROOT, x1); // x2=std::sqrt(1.0-x*x)
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x2, DIVIDE); // wx=wr/std::sqrt(1.0-x*x)

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, ARC_SINE, x_i); // r=std::asin(x)
		uint64_t x0 = add_variable(); process_func2(clock, x0, MULTIPLY, x_i, x_i); // x0=x*x
		uint64_t x1 = add_variable(); process_func2_sy(clock, x1, SCALAR_SUBTRACT, x0, get_double_index(1.0)); // x1=1.0-x*x
		uint64_t x2 = add_variable(); process_func1(clock, x2, SQUAREROOT, x1); // x2=std::sqrt(1.0-x*x)
		process_func2(clock, auxiliary(r_i), DIVIDE, auxiliary(x_i), x2); // dr=dx/std::sqrt(1.0-x*x)
	}
	else
	{
		process_func1(clock, r_i, ARC_SINE, x_i); // r=std::asin(x)
	}
}

template<class T>
void graph_generator<T>::arc_sine_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::arc_cosine(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2(clock, x0, MULTIPLY, x_i, x_i); // x0=x*x
		uint64_t x1 = add_variable(); process_func2_sy(clock, x1, SCALAR_SUBTRACT, x0, get_double_index(1.0)); // x1=1.0-x*x
		uint64_t x2 = add_variable(); process_func1(clock, x2, SQUAREROOT, x1); // x2=std::sqrt(1.0-x*x)
		uint64_t x3 = add_variable(); process_func1(clock, x3, CHANGE_SIGN, auxiliary(r_i)); // x3=-wr
		update_adjoint(orig_clock, x_i, ADD, x3, x2, DIVIDE); // wx=-wr/std::sqrt(1.0-x*x)

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, ARC_COSINE, x_i); // r=std::acos(x)
		uint64_t x0 = add_variable(); process_func2(clock, x0, MULTIPLY, x_i, x_i); // x0=x*x
		uint64_t x1 = add_variable(); process_func2_sy(clock, x1, SCALAR_SUBTRACT, x0, get_double_index(1.0)); // x1=1.0-x*x
		uint64_t x2 = add_variable(); process_func1(clock, x2, SQUAREROOT, x1); // x2=std::sqrt(1.0-x*x)
		uint64_t x3 = add_variable(); process_func1(clock, x3, CHANGE_SIGN, auxiliary(x_i)); // x3=-dx
		process_func2(clock, auxiliary(r_i), DIVIDE, x3, x2); // dr=-dx/std::sqrt(1.0-x*x)
	}
	else
	{
		process_func1(clock, r_i, ARC_COSINE, x_i); // r=std::acos(x)
	}
}

template<class T>
void graph_generator<T>::arc_cosine_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::arc_tangent(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2(clock, x0, MULTIPLY, x_i, x_i); // x0=x*x
		uint64_t x1 = add_variable(); process_func2_sy(clock, x1, ADD_SCALAR, x0, get_double_index(1.0)); // x1=x*x+1.0
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x1, DIVIDE); // wx=wr/(x*x+1.0)

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, ARC_TANGENT, x_i); // r=std::atan(x)
		uint64_t x0 = add_variable(); process_func2(clock, x0, MULTIPLY, x_i, x_i); // x0=x*x
		uint64_t x1 = add_variable(); process_func2_sy(clock, x1, ADD_SCALAR, x0, get_double_index(1.0)); // x1=x*x+1.0
		process_func2(clock, auxiliary(r_i), DIVIDE, auxiliary(x_i), x1); // dr=dx/(x*x+1.0)
	}
	else
	{
		process_func1(clock, r_i, ARC_TANGENT, x_i); // r=std::atan(x)
	}
}

template<class T>
void graph_generator<T>::arc_tangent_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::hyperbolic_sine(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func1(clock, x0, HYPERBOLIC_COSINE, x_i); // x0=std::cosh(x)
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x0); // wx=wr*std::cosh(x)

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, HYPERBOLIC_SINE, x_i); // r=std::sinh(x)
		uint64_t x0 = add_variable(); process_func1(clock, x0, HYPERBOLIC_COSINE, x_i); // x0=std::cosh(x)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x0, auxiliary(x_i)); // dr=std::cosh(x)*dx
	}
	else
	{
		process_func1(clock, r_i, HYPERBOLIC_SINE, x_i); // r=std::sinh(x)
	}
}

template<class T>
void graph_generator<T>::hyperbolic_sine_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::hyperbolic_cosine(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func1(clock, x0, HYPERBOLIC_SINE, x_i); // x0=std::sinh(x)
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x0); // wx=wr*std::sinh(x)

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, HYPERBOLIC_COSINE, x_i); // r=std::cosh(x)
		uint64_t x0 = add_variable(); process_func1(clock, x0, HYPERBOLIC_SINE, x_i); // x0=std::sinh(x)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x0, auxiliary(x_i)); // dr=std::sinh(x)*dx
	}
	else
	{
		process_func1(clock, r_i, HYPERBOLIC_COSINE, x_i); // r=std::cosh(x)
	}
}

template<class T>
void graph_generator<T>::hyperbolic_cosine_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::hyperbolic_tangent(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2(clock, x0, MULTIPLY, r_i, r_i); // x0=r*r
		uint64_t x1 = add_variable(); process_func2_sy(clock, x1, SCALAR_SUBTRACT, x0, get_double_index(1.0)); // x1=1.0-r*r
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x1); // wx=wr*(1.0-r*r)

	}
	else if (m_adtype == FORWARD)
	{
		process_func1(clock, r_i, HYPERBOLIC_TANGENT, x_i); // r=std::tanh(x)
		uint64_t x0 = add_variable(); process_func2(clock, x0, MULTIPLY, r_i, r_i); // x0=r*r
		uint64_t x1 = add_variable(); process_func2_sy(clock, x1, SCALAR_SUBTRACT, x0, get_double_index(1.0)); // x1=1.0-r*r
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(x_i)); // dr=(1.0-r*r)*dx
	}
	else
	{
		process_func1(clock, r_i, HYPERBOLIC_TANGENT, x_i); // r=std::tanh(x)
	}
}

template<class T>
void graph_generator<T>::hyperbolic_tangent_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func1(clock, r_i, op, x_i);
}

template<class T>
void graph_generator<T>::add(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i)); // wx=wr
		update_adjoint(orig_clock, y_i, ADD, auxiliary(r_i)); // wy=wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, ADD, x_i, y_i); // r=x+y
		process_func2(clock, auxiliary(r_i), ADD, auxiliary(x_i), auxiliary(y_i)); // dr=dx+dy
	}
	else
	{
		process_func2(clock, r_i, ADD, x_i, y_i); // r=x+y
	}
}

template<class T>
void graph_generator<T>::add_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, y_i, ADD, auxiliary(r_i)); // wy=wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, ADD, x_i, y_i); // r=x+y
		process_func1(clock, auxiliary(r_i), EQUAL, auxiliary(y_i)); // dr=dy
	}
	else
	{
		process_func2(clock, r_i, ADD, x_i, y_i); // r=x+y
	}
}

template<class T>
void graph_generator<T>::add_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i)); // wx=wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, ADD, x_i, y_i); // r=x+y
		process_func1(clock, auxiliary(r_i), EQUAL, auxiliary(x_i)); // dr=dx
	}
	else
	{
		process_func2(clock, r_i, ADD, x_i, y_i); // r=x+y
	}
}

template<class T>
void graph_generator<T>::add_px_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2(clock, r_i, op, x_i, y_i);
}

template<class T>
void graph_generator<T>::subtract(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i)); // wx=wr
		update_adjoint(orig_clock, y_i, SUBTRACT, auxiliary(r_i)); // wy=-wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, SUBTRACT, x_i, y_i); // r=x-y
		process_func2(clock, auxiliary(r_i), SUBTRACT, auxiliary(x_i), auxiliary(y_i)); // dr=dx-dy
	}
	else
	{
		process_func2(clock, r_i, SUBTRACT, x_i, y_i); // r=x-y
	}
}

template<class T>
void graph_generator<T>::subtract_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, y_i, SUBTRACT, auxiliary(r_i)); // wy=-wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, SUBTRACT, x_i, y_i); // r=x-y
		process_func1(clock, auxiliary(r_i), CHANGE_SIGN, auxiliary(y_i)); // dr=-dy
	}
	else
	{
		process_func2(clock, r_i, SUBTRACT, x_i, y_i); // r=x-y
	}
}

template<class T>
void graph_generator<T>::subtract_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i)); // wx=wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, SUBTRACT, x_i, y_i); // r=x-y
		process_func1(clock, auxiliary(r_i), EQUAL, auxiliary(x_i)); // dr=dx
	}
	else
	{
		process_func2(clock, r_i, SUBTRACT, x_i, y_i); // r=x-y
	}
}

template<class T>
void graph_generator<T>::subtract_px_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2(clock, r_i, op, x_i, y_i);
}

template<class T>
void graph_generator<T>::multiply(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, y_i, auxiliary(r_i)); // wx=y*wr
		update_adjoint(orig_clock, y_i, ADD, x_i, auxiliary(r_i)); // wy=x*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, MULTIPLY, x_i, y_i); // r=x*y
		uint64_t x0 = add_variable(); process_func2(clock, x0, MULTIPLY, x_i, auxiliary(y_i)); // x0=x*dy
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, y_i, auxiliary(x_i)); // x1=y*dx
		process_func2(clock, auxiliary(r_i), ADD, x1, x0); // dr=y*dx+x*dy
	}
	else
	{
		process_func2(clock, r_i, MULTIPLY, x_i, y_i); // r=x*y
	}
}

template<class T>
void graph_generator<T>::multiply_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, y_i, ADD, x_i, auxiliary(r_i)); // wy=x*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, MULTIPLY, x_i, y_i); // r=x*y
		process_func2(clock, auxiliary(r_i), MULTIPLY, x_i, auxiliary(y_i)); // dr=x*dy
	}
	else
	{
		process_func2(clock, r_i, MULTIPLY, x_i, y_i); // r=x*y
	}
}

template<class T>
void graph_generator<T>::multiply_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, y_i, auxiliary(r_i)); // wx=y*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, MULTIPLY, x_i, y_i); // r=x*y
		process_func2(clock, auxiliary(r_i), MULTIPLY, y_i, auxiliary(x_i)); // dr=y*dx
	}
	else
	{
		process_func2(clock, r_i, MULTIPLY, x_i, y_i); // r=x*y
	}
}

template<class T>
void graph_generator<T>::multiply_px_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2(clock, r_i, op, x_i, y_i);
}

template<class T>
void graph_generator<T>::divide(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), y_i, DIVIDE); // wx=wr/y
		uint64_t x0 = add_variable(); process_func1(clock, x0, CHANGE_SIGN, r_i); // x0=-r
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, x0, auxiliary(r_i)); // x1=-r*wr
		update_adjoint(orig_clock, y_i, ADD, x1, y_i, DIVIDE); // wy=-r*wr/y

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, DIVIDE, x_i, y_i); // r=x/y
		uint64_t x0 = add_variable(); process_func2(clock, x0, MULTIPLY, r_i, auxiliary(y_i)); // x0=r*dy
		uint64_t x1 = add_variable(); process_func2(clock, x1, SUBTRACT, auxiliary(x_i), x0); // x1=dx-r*dy
		process_func2(clock, auxiliary(r_i), DIVIDE, x1, y_i); // dr=(dx-r*dy)/y
	}
	else
	{
		process_func2(clock, r_i, DIVIDE, x_i, y_i); // r=x/y
	}
}

template<class T>
void graph_generator<T>::divide_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func1(clock, x0, CHANGE_SIGN, r_i); // x0=-r
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, x0, auxiliary(r_i)); // x1=-r*wr
		update_adjoint(orig_clock, y_i, ADD, x1, y_i, DIVIDE); // wy=-r*wr/y

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, DIVIDE, x_i, y_i); // r=x/y
		uint64_t x0 = add_variable(); process_func1(clock, x0, CHANGE_SIGN, r_i); // x0=-r
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, x0, auxiliary(y_i)); // x1=-r*dy
		process_func2(clock, auxiliary(r_i), DIVIDE, x1, y_i); // dr=-r*dy/y
	}
	else
	{
		process_func2(clock, r_i, DIVIDE, x_i, y_i); // r=x/y
	}
}

template<class T>
void graph_generator<T>::divide_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), y_i, DIVIDE); // wx=wr/y

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, DIVIDE, x_i, y_i); // r=x/y
		process_func2(clock, auxiliary(r_i), DIVIDE, auxiliary(x_i), y_i); // dr=dx/y
	}
	else
	{
		process_func2(clock, r_i, DIVIDE, x_i, y_i); // r=x/y
	}
}

template<class T>
void graph_generator<T>::divide_px_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2(clock, r_i, op, x_i, y_i);
}

template<class T>
void graph_generator<T>::maximum(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, x_i, y_i); // x0=x-y
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(x-y)
		update_adjoint(orig_clock, x_i, ADD, x1, auxiliary(r_i)); // wx=hss(x-y)*wr
		uint64_t x2 = add_variable(); process_func2(clock, x2, SUBTRACT, y_i, x_i); // x2=y-x
		uint64_t x3 = add_variable(); process_func1(clock, x3, HEAVISIDE_STEP, x2); // x3=hss(y-x)
		update_adjoint(orig_clock, y_i, ADD, x3, auxiliary(r_i)); // wy=hss(y-x)*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, MAXIMUM, x_i, y_i); // r=std::max(x,y)
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, y_i, x_i); // x0=y-x
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(y-x)
		uint64_t x2 = add_variable(); process_func2(clock, x2, MULTIPLY, x1, auxiliary(y_i)); // x2=hss(y-x)*dy
		uint64_t x3 = add_variable(); process_func2(clock, x3, SUBTRACT, x_i, y_i); // x3=x-y
		uint64_t x4 = add_variable(); process_func1(clock, x4, HEAVISIDE_STEP, x3); // x4=hss(x-y)
		uint64_t x5 = add_variable(); process_func2(clock, x5, MULTIPLY, x4, auxiliary(x_i)); // x5=hss(x-y)*dx
		process_func2(clock, auxiliary(r_i), ADD, x5, x2); // dr=hss(x-y)*dx+hss(y-x)*dy
	}
	else
	{
		process_func2(clock, r_i, MAXIMUM, x_i, y_i); // r=std::max(x,y)
	}
}

template<class T>
void graph_generator<T>::maximum_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, y_i, x_i); // x0=y-x
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(y-x)
		update_adjoint(orig_clock, y_i, ADD, x1, auxiliary(r_i)); // wy=hss(y-x)*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, MAXIMUM, x_i, y_i); // r=std::max(x,y)
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, y_i, x_i); // x0=y-x
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(y-x)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(y_i)); // dr=hss(y-x)*dy
	}
	else
	{
		process_func2(clock, r_i, MAXIMUM, x_i, y_i); // r=std::max(x,y)
	}
}

template<class T>
void graph_generator<T>::maximum_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, x_i, y_i); // x0=x-y
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(x-y)
		update_adjoint(orig_clock, x_i, ADD, x1, auxiliary(r_i)); // wx=hss(x-y)*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, MAXIMUM, x_i, y_i); // r=std::max(x,y)
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, x_i, y_i); // x0=x-y
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(x-y)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(x_i)); // dr=hss(x-y)*dx
	}
	else
	{
		process_func2(clock, r_i, MAXIMUM, x_i, y_i); // r=std::max(x,y)
	}
}

template<class T>
void graph_generator<T>::maximum_px_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2(clock, r_i, op, x_i, y_i);
}

template<class T>
void graph_generator<T>::minimum(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, y_i, x_i); // x0=y-x
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(y-x)
		update_adjoint(orig_clock, x_i, ADD, x1, auxiliary(r_i)); // wx=hss(y-x)*wr
		uint64_t x2 = add_variable(); process_func2(clock, x2, SUBTRACT, x_i, y_i); // x2=x-y
		uint64_t x3 = add_variable(); process_func1(clock, x3, HEAVISIDE_STEP, x2); // x3=hss(x-y)
		update_adjoint(orig_clock, y_i, ADD, x3, auxiliary(r_i)); // wy=hss(x-y)*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, MINIMUM, x_i, y_i); // r=std::min(x,y)
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, x_i, y_i); // x0=x-y
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(x-y)
		uint64_t x2 = add_variable(); process_func2(clock, x2, MULTIPLY, x1, auxiliary(y_i)); // x2=hss(x-y)*dy
		uint64_t x3 = add_variable(); process_func2(clock, x3, SUBTRACT, y_i, x_i); // x3=y-x
		uint64_t x4 = add_variable(); process_func1(clock, x4, HEAVISIDE_STEP, x3); // x4=hss(y-x)
		uint64_t x5 = add_variable(); process_func2(clock, x5, MULTIPLY, x4, auxiliary(x_i)); // x5=hss(y-x)*dx
		process_func2(clock, auxiliary(r_i), ADD, x5, x2); // dr=hss(y-x)*dx+hss(x-y)*dy
	}
	else
	{
		process_func2(clock, r_i, MINIMUM, x_i, y_i); // r=std::min(x,y)
	}
}

template<class T>
void graph_generator<T>::minimum_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, x_i, y_i); // x0=x-y
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(x-y)
		update_adjoint(orig_clock, y_i, ADD, x1, auxiliary(r_i)); // wy=hss(x-y)*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, MINIMUM, x_i, y_i); // r=std::min(x,y)
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, x_i, y_i); // x0=x-y
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(x-y)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(y_i)); // dr=hss(x-y)*dy
	}
	else
	{
		process_func2(clock, r_i, MINIMUM, x_i, y_i); // r=std::min(x,y)
	}
}

template<class T>
void graph_generator<T>::minimum_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, y_i, x_i); // x0=y-x
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(y-x)
		update_adjoint(orig_clock, x_i, ADD, x1, auxiliary(r_i)); // wx=hss(y-x)*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, MINIMUM, x_i, y_i); // r=std::min(x,y)
		uint64_t x0 = add_variable(); process_func2(clock, x0, SUBTRACT, y_i, x_i); // x0=y-x
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(y-x)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(x_i)); // dr=hss(y-x)*dx
	}
	else
	{
		process_func2(clock, r_i, MINIMUM, x_i, y_i); // r=std::min(x,y)
	}
}

template<class T>
void graph_generator<T>::minimum_px_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2(clock, r_i, op, x_i, y_i);
}

template<class T>
void graph_generator<T>::power(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, SUBTRACT_SCALAR, y_i, get_double_index(1.0)); // x0=y-1.0
		uint64_t x1 = add_variable(); process_func2(clock, x1, POWER, x_i, x0); // x1=std::pow(x,y-1.0)
		uint64_t x2 = add_variable(); process_func2(clock, x2, MULTIPLY, auxiliary(r_i), x1); // x2=wr*std::pow(x,y-1.0)
		update_adjoint(orig_clock, x_i, ADD, x2, y_i); // wx=wr*std::pow(x,y-1.0)*y
		uint64_t x3 = add_variable(); process_func1(clock, x3, LOGARITHM, x_i); // x3=std::log(x)
		uint64_t x4 = add_variable(); process_func2(clock, x4, MULTIPLY, auxiliary(r_i), x3); // x4=wr*std::log(x)
		update_adjoint(orig_clock, y_i, ADD, x4, r_i); // wy=wr*std::log(x)*r

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, POWER, x_i, y_i); // r=std::pow(x,y)
		uint64_t x0 = add_variable(); process_func1(clock, x0, LOGARITHM, x_i); // x0=std::log(x)
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, x0, r_i); // x1=std::log(x)*r
		uint64_t x2 = add_variable(); process_func2(clock, x2, MULTIPLY, x1, auxiliary(y_i)); // x2=std::log(x)*r*dy
		uint64_t x3 = add_variable(); process_func2_sy(clock, x3, SUBTRACT_SCALAR, y_i, get_double_index(1.0)); // x3=y-1.0
		uint64_t x4 = add_variable(); process_func2(clock, x4, POWER, x_i, x3); // x4=std::pow(x,y-1.0)
		uint64_t x5 = add_variable(); process_func2(clock, x5, MULTIPLY, x4, y_i); // x5=std::pow(x,y-1.0)*y
		uint64_t x6 = add_variable(); process_func2(clock, x6, MULTIPLY, x5, auxiliary(x_i)); // x6=std::pow(x,y-1.0)*y*dx
		process_func2(clock, auxiliary(r_i), ADD, x6, x2); // dr=std::pow(x,y-1.0)*y*dx+std::log(x)*r*dy
	}
	else
	{
		process_func2(clock, r_i, POWER, x_i, y_i); // r=std::pow(x,y)
	}
}

template<class T>
void graph_generator<T>::power_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func1(clock, x0, LOGARITHM, x_i); // x0=std::log(x)
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, auxiliary(r_i), x0); // x1=wr*std::log(x)
		update_adjoint(orig_clock, y_i, ADD, x1, r_i); // wy=wr*std::log(x)*r

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, POWER, x_i, y_i); // r=std::pow(x,y)
		uint64_t x0 = add_variable(); process_func1(clock, x0, LOGARITHM, x_i); // x0=std::log(x)
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, x0, r_i); // x1=std::log(x)*r
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(y_i)); // dr=std::log(x)*r*dy
	}
	else
	{
		process_func2(clock, r_i, POWER, x_i, y_i); // r=std::pow(x,y)
	}
}

template<class T>
void graph_generator<T>::power_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, SUBTRACT_SCALAR, y_i, get_double_index(1.0)); // x0=y-1.0
		uint64_t x1 = add_variable(); process_func2(clock, x1, POWER, x_i, x0); // x1=std::pow(x,y-1.0)
		uint64_t x2 = add_variable(); process_func2(clock, x2, MULTIPLY, auxiliary(r_i), x1); // x2=wr*std::pow(x,y-1.0)
		update_adjoint(orig_clock, x_i, ADD, x2, y_i); // wx=wr*std::pow(x,y-1.0)*y

	}
	else if (m_adtype == FORWARD)
	{
		process_func2(clock, r_i, POWER, x_i, y_i); // r=std::pow(x,y)
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, SUBTRACT_SCALAR, y_i, get_double_index(1.0)); // x0=y-1.0
		uint64_t x1 = add_variable(); process_func2(clock, x1, POWER, x_i, x0); // x1=std::pow(x,y-1.0)
		uint64_t x2 = add_variable(); process_func2(clock, x2, MULTIPLY, x1, y_i); // x2=std::pow(x,y-1.0)*y
		process_func2(clock, auxiliary(r_i), MULTIPLY, x2, auxiliary(x_i)); // dr=std::pow(x,y-1.0)*y*dx
	}
	else
	{
		process_func2(clock, r_i, POWER, x_i, y_i); // r=std::pow(x,y)
	}
}

template<class T>
void graph_generator<T>::power_px_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2(clock, r_i, op, x_i, y_i);
}

template<class T>
void graph_generator<T>::add_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i)); // wx=wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2_sy(clock, r_i, ADD_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=x+y
		process_func1(clock, auxiliary(r_i), EQUAL, auxiliary(x_i)); // dr=dx
	}
	else
	{
		process_func2_sy(clock, r_i, ADD_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=x+y
	}
}

template<class T>
void graph_generator<T>::add_scalar_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_sy(clock, r_i, op, x_i, s_i);
}

template<class T>
void graph_generator<T>::subtract_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i)); // wx=wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2_sy(clock, r_i, SUBTRACT_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=x-y
		process_func1(clock, auxiliary(r_i), EQUAL, auxiliary(x_i)); // dr=dx
	}
	else
	{
		process_func2_sy(clock, r_i, SUBTRACT_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=x-y
	}
}

template<class T>
void graph_generator<T>::subtract_scalar_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_sy(clock, r_i, op, x_i, s_i);
}

template<class T>
void graph_generator<T>::scalar_subtract(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint(orig_clock, y_i, SUBTRACT, auxiliary(r_i)); // wy=-wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2_sx(clock, r_i, SCALAR_SUBTRACT, get_scalar_index(m_scalar[s_i]), y_i); // r=x-y
		process_func1(clock, auxiliary(r_i), CHANGE_SIGN, auxiliary(y_i)); // dr=-dy
	}
	else
	{
		process_func2_sx(clock, r_i, SCALAR_SUBTRACT, get_scalar_index(m_scalar[s_i]), y_i); // r=x-y
	}
}

template<class T>
void graph_generator<T>::scalar_subtract_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_sy(clock, r_i, op, y_i, s_i);
}

template<class T>
void graph_generator<T>::multiply_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint_sy(orig_clock, x_i, ADD, auxiliary(r_i), get_scalar_index(m_scalar[s_i]), MULTIPLY_SCALAR); // wx=y*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2_sy(clock, r_i, MULTIPLY_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=x*y
		process_func2_sy(clock, auxiliary(r_i), MULTIPLY_SCALAR, auxiliary(x_i), get_scalar_index(m_scalar[s_i])); // dr=y*dx
	}
	else
	{
		process_func2_sy(clock, r_i, MULTIPLY_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=x*y
	}
}

template<class T>
void graph_generator<T>::multiply_scalar_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_sy(clock, r_i, op, x_i, s_i);
}

template<class T>
void graph_generator<T>::divide_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		update_adjoint_sy(orig_clock, x_i, ADD, auxiliary(r_i), get_scalar_index(m_scalar[s_i]), DIVIDE_SCALAR); // wx=wr/y

	}
	else if (m_adtype == FORWARD)
	{
		process_func2_sy(clock, r_i, DIVIDE_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=x/y
		process_func2_sy(clock, auxiliary(r_i), DIVIDE_SCALAR, auxiliary(x_i), get_scalar_index(m_scalar[s_i])); // dr=dx/y
	}
	else
	{
		process_func2_sy(clock, r_i, DIVIDE_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=x/y
	}
}

template<class T>
void graph_generator<T>::divide_scalar_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_sy(clock, r_i, op, x_i, s_i);
}

template<class T>
void graph_generator<T>::scalar_divide(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func1(clock, x0, CHANGE_SIGN, r_i); // x0=-r
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, x0, auxiliary(r_i)); // x1=-r*wr
		update_adjoint(orig_clock, y_i, ADD, x1, y_i, DIVIDE); // wy=-r*wr/y

	}
	else if (m_adtype == FORWARD)
	{
		process_func2_sx(clock, r_i, SCALAR_DIVIDE, get_scalar_index(m_scalar[s_i]), y_i); // r=x/y
		uint64_t x0 = add_variable(); process_func1(clock, x0, CHANGE_SIGN, r_i); // x0=-r
		uint64_t x1 = add_variable(); process_func2(clock, x1, MULTIPLY, x0, auxiliary(y_i)); // x1=-r*dy
		process_func2(clock, auxiliary(r_i), DIVIDE, x1, y_i); // dr=-r*dy/y
	}
	else
	{
		process_func2_sx(clock, r_i, SCALAR_DIVIDE, get_scalar_index(m_scalar[s_i]), y_i); // r=x/y
	}
}

template<class T>
void graph_generator<T>::scalar_divide_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_sy(clock, r_i, op, y_i, s_i);
}

template<class T>
void graph_generator<T>::maximum_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, SUBTRACT_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // x0=x-y
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(x-y)
		update_adjoint(orig_clock, x_i, ADD, x1, auxiliary(r_i)); // wx=hss(x-y)*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2_sy(clock, r_i, MAXIMUM_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=std::max(x,y)
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, SUBTRACT_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // x0=x-y
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(x-y)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(x_i)); // dr=hss(x-y)*dx
	}
	else
	{
		process_func2_sy(clock, r_i, MAXIMUM_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=std::max(x,y)
	}
}

template<class T>
void graph_generator<T>::maximum_scalar_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_sy(clock, r_i, op, x_i, s_i);
}

template<class T>
void graph_generator<T>::minimum_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2_sx(clock, x0, SCALAR_SUBTRACT, get_scalar_index(m_scalar[s_i]), x_i); // x0=y-x
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(y-x)
		update_adjoint(orig_clock, x_i, ADD, x1, auxiliary(r_i)); // wx=hss(y-x)*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2_sy(clock, r_i, MINIMUM_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=std::min(x,y)
		uint64_t x0 = add_variable(); process_func2_sx(clock, x0, SCALAR_SUBTRACT, get_scalar_index(m_scalar[s_i]), x_i); // x0=y-x
		uint64_t x1 = add_variable(); process_func1(clock, x1, HEAVISIDE_STEP, x0); // x1=hss(y-x)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(x_i)); // dr=hss(y-x)*dx
	}
	else
	{
		process_func2_sy(clock, r_i, MINIMUM_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=std::min(x,y)
	}
}

template<class T>
void graph_generator<T>::minimum_scalar_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_sy(clock, r_i, op, x_i, s_i);
}

template<class T>
void graph_generator<T>::power_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, POWER_SCALAR, x_i, get_scalar_index(scalar_traits<typename graph_traits<T>::scalar_type>::subtract(m_scalar[s_i], graph_traits<T>::cast(1.0)))); // x0=std::pow(x,y-1.0)
		uint64_t x1 = add_variable(); process_func2_sy(clock, x1, MULTIPLY_SCALAR, x0, get_scalar_index(m_scalar[s_i])); // x1=std::pow(x,y-1.0)*y
		update_adjoint(orig_clock, x_i, ADD, x1, auxiliary(r_i)); // wx=std::pow(x,y-1.0)*y*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2_sy(clock, r_i, POWER_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=std::pow(x,y)
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, POWER_SCALAR, x_i, get_scalar_index(scalar_traits<typename graph_traits<T>::scalar_type>::subtract(m_scalar[s_i], graph_traits<T>::cast(1.0)))); // x0=std::pow(x,y-1.0)
		uint64_t x1 = add_variable(); process_func2_sy(clock, x1, MULTIPLY_SCALAR, x0, get_scalar_index(m_scalar[s_i])); // x1=std::pow(x,y-1.0)*y
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(x_i)); // dr=std::pow(x,y-1.0)*y*dx
	}
	else
	{
		process_func2_sy(clock, r_i, POWER_SCALAR, x_i, get_scalar_index(m_scalar[s_i])); // r=std::pow(x,y)
	}
}

template<class T>
void graph_generator<T>::power_scalar_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_sy(clock, r_i, op, x_i, s_i);
}

template<class T>
void graph_generator<T>::scalar_power(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, MULTIPLY_SCALAR, r_i, get_scalar_index(scalar_traits<typename graph_traits<T>::scalar_type>::logarithm(m_scalar[s_i]))); // x0=std::log(x)*r
		update_adjoint(orig_clock, y_i, ADD, x0, auxiliary(r_i)); // wy=std::log(x)*r*wr

	}
	else if (m_adtype == FORWARD)
	{
		process_func2_sx(clock, r_i, SCALAR_POWER, get_scalar_index(m_scalar[s_i]), y_i); // r=std::pow(x,y)
		uint64_t x0 = add_variable(); process_func2_sy(clock, x0, MULTIPLY_SCALAR, r_i, get_scalar_index(scalar_traits<typename graph_traits<T>::scalar_type>::logarithm(m_scalar[s_i]))); // x0=std::log(x)*r
		process_func2(clock, auxiliary(r_i), MULTIPLY, x0, auxiliary(y_i)); // dr=std::log(x)*r*dy
	}
	else
	{
		process_func2_sx(clock, r_i, SCALAR_POWER, get_scalar_index(m_scalar[s_i]), y_i); // r=std::pow(x,y)
	}
}

template<class T>
void graph_generator<T>::scalar_power_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_sy(clock, r_i, op, y_i, s_i);
}

template<class T>
void graph_generator<T>::greater_than(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_logical(clock, r_i, GREATER_THAN, x_i, y_i);
}

template<class T>
void graph_generator<T>::less_than(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_logical(clock, r_i, LESS_THAN, x_i, y_i);
}

template<class T>
void graph_generator<T>::equal_to(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_logical(clock, r_i, EQUAL_TO, x_i, y_i);
}

template<class T>
void graph_generator<T>::greater_than_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_logical_sy(clock, r_i, GREATER_THAN_SCALAR, x_i, y_i);
}

template<class T>
void graph_generator<T>::less_than_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_logical_sy(clock, r_i, LESS_THAN_SCALAR, x_i, y_i);
}

template<class T>
void graph_generator<T>::equal_to_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_func2_logical_sy(clock, r_i, EQUAL_TO_SCALAR, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_equal_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer1_ix(clock, r_i, INTEGER_EQUAL_INT, x_i);
}

template<class T>
void graph_generator<T>::integer_equal(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer1(clock, r_i, INTEGER_EQUAL, x_i);
}

template<class T>
void graph_generator<T>::integer_change_sign(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer1(clock, r_i, INTEGER_CHANGE_SIGN, x_i);
}

template<class T>
void graph_generator<T>::integer_add(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2(clock, r_i, INTEGER_ADD, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_subtract(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2(clock, r_i, INTEGER_SUBTRACT, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_multiply(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2(clock, r_i, INTEGER_MULTIPLY, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_divide(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2(clock, r_i, INTEGER_DIVIDE, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_add_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_iy(clock, r_i, INTEGER_ADD_INT, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_subtract_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_iy(clock, r_i, INTEGER_SUBTRACT_INT, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_int_subtract(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_ix(clock, r_i, INTEGER_INT_SUBTRACT, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_multiply_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_iy(clock, r_i, INTEGER_MULTIPLY_INT, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_divide_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_iy(clock, r_i, INTEGER_DIVIDE_INT, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_int_divide(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_ix(clock, r_i, INTEGER_INT_DIVIDE, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_greater_than(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_logical(clock, r_i, INTEGER_GREATER_THAN, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_less_than(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_logical(clock, r_i, INTEGER_LESS_THAN, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_equal_to(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_logical(clock, r_i, INTEGER_EQUAL_TO, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_greater_than_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_logical_iy(clock, r_i, INTEGER_GREATER_THAN_INT, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_less_than_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_logical_iy(clock, r_i, INTEGER_LESS_THAN_INT, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_equal_to_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer2_logical_iy(clock, r_i, INTEGER_EQUAL_TO_INT, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_iff(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer_iff(clock, r_i, INTEGER_IFF, c_i, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_iff_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer_iff(clock, r_i, INTEGER_IFF_INT, c_i, x_i, y_i);
}

template<class T>
void graph_generator<T>::integer_iff_int_int(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_integer_iff(clock, r_i, INTEGER_IFF_INT_INT, c_i, x_i, y_i);
}

template<class T>
void graph_generator<T>::boolean_equal_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean1_bx(clock, r_i, BOOLEAN_EQUAL_BOOL, x_i);
}

template<class T>
void graph_generator<T>::boolean_equal(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean1(clock, r_i, BOOLEAN_EQUAL, x_i);
}

template<class T>
void graph_generator<T>::boolean_not(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean1(clock, r_i, BOOLEAN_NOT, x_i);
}

template<class T>
void graph_generator<T>::boolean_and(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean2(clock, r_i, BOOLEAN_AND, x_i, y_i);
}

template<class T>
void graph_generator<T>::boolean_or(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean2(clock, r_i, BOOLEAN_OR, x_i, y_i);
}

template<class T>
void graph_generator<T>::boolean_equal_to(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean2(clock, r_i, BOOLEAN_EQUAL_TO, x_i, y_i);
}

template<class T>
void graph_generator<T>::boolean_and_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean2_by(clock, r_i, BOOLEAN_AND_BOOL, x_i, y_i);
}

template<class T>
void graph_generator<T>::boolean_or_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean2_by(clock, r_i, BOOLEAN_OR_BOOL, x_i, y_i);
}

template<class T>
void graph_generator<T>::boolean_equal_to_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean2_by(clock, r_i, BOOLEAN_EQUAL_TO_BOOL, x_i, y_i);
}

template<class T>
void graph_generator<T>::boolean_iff(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean_iff(clock, r_i, BOOLEAN_IFF, c_i, x_i, y_i);
}

template<class T>
void graph_generator<T>::boolean_iff_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean_iff_by(clock, r_i, BOOLEAN_IFF_BOOL, c_i, x_i, y_i);
}

template<class T>
void graph_generator<T>::boolean_iff_bool_bool(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_boolean_iff_bx_by(clock, r_i, BOOLEAN_IFF_BOOL_BOOL, c_i, x_i, y_i);
}

//${end}

template<class T>
void graph_generator<T>::iff(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_iff_sx_sy(clock, x0, IFF_SCALAR_SCALAR, c_i, get_double_index(1.0), get_double_index(0.0)); // x0=qif(b,1,0)
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x0); // wx=wr*x0
		uint64_t x1 = add_variable(); process_func2_sx(clock, x1, SCALAR_SUBTRACT, get_double_index(1.0), x0); // x1=1.0-qif(b,1,0)
		update_adjoint(orig_clock, y_i, ADD, auxiliary(r_i), x1); // wy=wr*x1
	}
	else if (m_adtype == FORWARD)
	{
		process_iff(clock, r_i, IFF, c_i, x_i, y_i); // r=iff(c,x,y)
		uint64_t x0 = add_variable(); process_iff_sx_sy(clock, x0, IFF_SCALAR_SCALAR, c_i, get_double_index(1.0), get_double_index(0.0)); // x0=qif(b,1,0)
		uint64_t x1 = add_variable(); process_func2_sx(clock, x1, SCALAR_SUBTRACT, get_double_index(1.0), x0); // x1=1.0-qif(b,1,0)
		uint64_t x2 = add_variable(); process_func2(clock, x2, MULTIPLY, x0, auxiliary(x_i)); // x2=qif(b,1,0)*dx
		uint64_t x3 = add_variable(); process_func2(clock, x3, MULTIPLY, x1, auxiliary(y_i)); // x3=(1.0-qif(b,1,0))*dy
		process_func2(clock, auxiliary(r_i), ADD, x2, x3); // dr=qif(b,1,0)*dx+(1.0-qif(b,1,0))*dy

	}
	else
	{
		process_iff(clock, r_i, IFF, c_i, x_i, y_i); // r=iff(c,x,y)
	}
}

template<class T>
void graph_generator<T>::iff_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_iff_sx_sy(clock, x0, IFF_SCALAR_SCALAR, c_i, get_double_index(1.0), get_double_index(0.0)); // x0=qif(b,1,0)
		uint64_t x1 = add_variable(); process_func2_sx(clock, x1, SCALAR_SUBTRACT, get_double_index(1.0), x0); // x1=1.0-qif(b,1,0)
		update_adjoint(orig_clock, y_i, ADD, auxiliary(r_i), x1); // wy=wr*x1
	}
	else if (m_adtype == FORWARD)
	{
		process_iff(clock, r_i, IFF_PX, c_i, x_i, y_i); // r=iff(c,x,y)
		uint64_t x0 = add_variable(); process_iff_sx_sy(clock, x0, IFF_SCALAR_SCALAR, c_i, get_double_index(1.0), get_double_index(0.0)); // x0=qif(b,1,0)
		uint64_t x1 = add_variable(); process_func2_sx(clock, x1, SCALAR_SUBTRACT, get_double_index(1.0), x0); // x1=1.0-qif(b,1,0)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x1, auxiliary(y_i)); // dr=(1.0-qif(b,1,0))*dy
	}
	else
	{
		process_iff(clock, r_i, IFF_PX, c_i, x_i, y_i); // r=iff(c,x,y)
	}
}

template<class T>
void graph_generator<T>::iff_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_iff_sx_sy(clock, x0, IFF_SCALAR_SCALAR, c_i, get_double_index(1.0), get_double_index(0.0)); // x0=qif(b,1,0)
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x0); // wx=wr*x0
	}
	else if (m_adtype == FORWARD)
	{
		process_iff(clock, r_i, IFF_PY, c_i, x_i, y_i); // r=iff(c,x,y)
		uint64_t x0 = add_variable(); process_iff_sx_sy(clock, x0, IFF_SCALAR_SCALAR, c_i, get_double_index(1.0), get_double_index(0.0)); // x0=qif(b,1,0)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x0, auxiliary(x_i)); // x2=qif(b,1,0)*dx
	}
	else
	{
		process_iff(clock, r_i, IFF_PY, c_i, x_i, y_i); // r=iff(c,x,y)
	}
}

template<class T>
void graph_generator<T>::iff_px_py(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_iff(clock, r_i, IFF_PX_PY, c_i, x_i, y_i);
}

template<class T>
void graph_generator<T>::iff_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == BACKWARD)
	{
		uint64_t x0 = add_variable(); process_iff_sx_sy(clock, x0, IFF_SCALAR_SCALAR, c_i, get_double_index(1.0), get_double_index(0.0)); // x0=qif(b,1,0)
		update_adjoint(orig_clock, x_i, ADD, auxiliary(r_i), x0); // wx=wr*x0
	}
	else if (m_adtype == FORWARD)
	{
		process_iff(clock, r_i, IFF_SCALAR, c_i, x_i, y_i); // r=iff(c,x,y)
		uint64_t x0 = add_variable(); process_iff_sx_sy(clock, x0, IFF_SCALAR_SCALAR, c_i, get_double_index(1.0), get_double_index(0.0)); // x0=qif(b,1,0)
		process_func2(clock, auxiliary(r_i), MULTIPLY, x0, auxiliary(x_i)); // dr=qif(b,1,0)*dx
	}
	else
	{
		process_iff(clock, r_i, IFF_SCALAR, c_i, x_i, y_i); // r=iff(c,x,y)
	}
}

template<class T>
void graph_generator<T>::iff_scalar_px(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_iff_sy(clock, r_i, IFF_SCALAR_PX, c_i, x_i, y_i);
}

template<class T>
void graph_generator<T>::iff_scalar_scalar(uint64_t orig_clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	uint64_t clock = m_g->now();

	if (m_phase == FORWARD) // Noop in backward phase
		process_iff_sx_sy(clock, r_i, IFF_SCALAR_SCALAR, c_i, x_i, y_i);
}
