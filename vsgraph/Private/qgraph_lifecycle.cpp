#include "qgraph_lifecycle.h"

#include "qgraph_i.h"
#include "qgraph_sweep.h"
#include "qgraph_mapfunc.h"

graph_lifecycle::graph_lifecycle(const qgraph_i_base& g, ADType adtype) : 
	m_wksp_index(NUMBER_OF_TYPES),
	m_wksp_available(NUMBER_OF_TYPES),
	m_wksp_size(NUMBER_OF_TYPES,0),
	m_adtype(adtype),
	m_phase(adtype == BACKWARD ? NONE : FORWARD), 
	m_direction(NONE),
	m_var_counter(g.get_var_counter()), 
	m_clock(0), 
	m_lifecycle(g.get_lifecycle())
{
	const auto& input_map = g.get_input_map();
	const auto& output_map = g.get_output_map();
	const auto& checkpoint_input = g.get_checkpoint_input();

	uint64_t sz = g.get_checkpoint_ops_index().size();

	if (m_adtype == BACKWARD || m_adtype == FORWARD)
	{
		m_var_counter = m_lifecycle[QFLOATING_POINT].size();
		m_lifecycle[QFLOATING_POINT].resize(m_var_counter + g.get_n_nonparam());
		m_clock = g.get_ops().size();
		if (m_adtype == BACKWARD)
		{
			const auto& inp_map = input_map[QFLOATING_POINT].back();
			for (auto it = inp_map.left.begin(); it != inp_map.left.end(); ++it)
				m_lifecycle[QFLOATING_POINT][it->second].first_used() = 0;

			if (sz > 2)
			{
				m_clock = g.get_checkpoint_ops_index()[sz-2];

				for (DataType dt = QFLOATING_POINT; dt != NUMBER_OF_TYPES; dt = next_data_type(dt))
					for (uint64_t i = 0; i < m_lifecycle[dt].size(); ++i)
					{
						auto& lc = m_lifecycle[dt][i];
						lc.first_used() = lc.last_used() = (uint64_t)-1;
					}

				m_direction = FORWARD;
				g.sweep_forward(*this,sz-2,sz-1); // Redo last forward pass
			}
			g.sweep_backward(*this); // Extend lifecycle (phase = NONE)
			// Update lifecycle of checkpoint inputs
			for (DataType dt = QFLOATING_POINT; dt != NUMBER_OF_TYPES; dt = next_data_type(dt))
				for (uint64_t i = 0; i < checkpoint_input[dt].size(); ++i)
					if (checkpoint_input[dt][i] != (uint64_t)-1)
					{
						auto& lc = m_lifecycle[dt][checkpoint_input[dt][i]];
						lc.first_used() = 0;
						lc.last_used() = m_clock;
					}
		}
		else for (uint64_t i = 0; i < g.get_n_nonparam(); ++i)
			m_lifecycle[QFLOATING_POINT][i + m_var_counter] = m_lifecycle[QFLOATING_POINT][i]; // Duals have the same lifespan as original variables
		lifecycle_helper(input_map, output_map).update(m_lifecycle, m_clock);
		m_clock = 0;
	}

	// Construct inputs

	for (DataType dt = QFLOATING_POINT; dt != NUMBER_OF_TYPES; dt = next_data_type(dt))
	{
		for (uint64_t i = 0; i < input_map[dt].size(); ++i)
			for (auto it = input_map[dt][i].left.begin(); it != input_map[dt][i].left.end(); ++it)
				generic_constructor(dt, it->second);

		for (uint64_t i = 0; i < m_lifecycle[dt].size(); ++i)
		{
			const auto& lc = m_lifecycle[dt][i];
			if (lc.created() == (uint64_t)-1 && lc.first_used() != (uint64_t)-1)
				generic_constructor(dt, i);
		}
	}

	// In case of backward, need to create an adjoint for all outputs up to order initialized to zero
	// Is there a better way ? Should we skip step in backward sweep ?
	// We also need to allocate memory for the checkpoint inputs 

	if (m_adtype == BACKWARD)
	{
		for (uint64_t i = 0; i < output_map.size() - 2; ++i)
			for (auto it = output_map[i].left.begin(); it != output_map[i].left.end(); ++it)
			{
				constructor(it->second + m_var_counter);
				m_assign_map[it->second + m_var_counter] = g.get_zero_index();
			}

		for (DataType dt = QFLOATING_POINT; dt != NUMBER_OF_TYPES; dt = next_data_type(dt))
			for (uint64_t i = 0; i < checkpoint_input[dt].size(); ++i)
				if (checkpoint_input[dt][i] != (uint64_t)-1)
					generic_constructor(dt, checkpoint_input[dt][i]);

	}

	// Proceed to determine memory requirements

	if (m_adtype == BACKWARD)
	{
		m_clock = g.get_checkpoint_ops_index()[sz - 2];
		m_phase = m_direction = FORWARD;
		g.sweep_forward(*this, sz - 2, sz - 1);  // Memory requirement of forward pass (phase = FORWARD)
		g.sweep_backward(*this); // Memory requirement of backward pass (phase = BACKWARD)
		m_clock = 0;
	}
	else
		g.sweep_forward(*this);  // Memory requirement of forward pass (phase = FORWARD)

}

graph_lifecycle::~graph_lifecycle()
{
}

void graph_lifecycle::checkpoint(uint64_t clock, Operation op)
{
	++m_clock;
}

void graph_lifecycle::swap(std::vector<uint64_t>& wksp_size, std::vector<std::vector<uint64_t>>& wksp_index)
{
	wksp_size = m_wksp_size;
	wksp_index.swap(m_wksp_index);
}

void graph_lifecycle::swap(std::vector<uint64_t>& wksp_size, std::vector<std::vector<uint64_t>>& wksp_index, std::map<uint64_t, uint64_t>& assign_map, std::vector<std::vector<lifecycle>>& lc, std::vector<uint64_t>& skip_ops_init, std::vector<uint64_t>& skip_ops_arg_init)
{
	swap(wksp_size, wksp_index);
	lc.swap(m_lifecycle);
	skip_ops_init.swap(m_skip_ops_init);
	skip_ops_arg_init.swap(m_skip_ops_arg_init);
	for (auto it = m_assign_map.begin(); it != m_assign_map.end(); ++it)
		assign_map[it->first] = it->second;
}

void graph_lifecycle::before_forward() 
{
	if (m_phase != NONE)
		m_phase = FORWARD;

	m_direction = FORWARD;
}

void graph_lifecycle::before_backward() 
{ 
	if (m_phase != NONE)
		m_phase = BACKWARD;

	m_direction = BACKWARD;
}

void graph_lifecycle::after_backward()
{
	if (m_phase == NONE)
	{
		m_skip_ops_init.push_back((uint64_t)-1);
		m_skip_ops_arg_init.push_back((uint64_t)-1);
	}
}

void graph_lifecycle::generic_constructor(DataType dt, uint64_t x)
{
	if (x < m_wksp_index[dt].size() && m_wksp_index[dt][x] != (uint64_t)-1)
		return;

	size_t wksp_i = (uint64_t)-1;

	size_t sz = m_wksp_available[dt].size();

	if (sz > 0) {

		// Memory available

		wksp_i = m_wksp_available[dt][sz - 1];
		m_wksp_available[dt].pop_back();

		// wksp_i = m_wksp_available[dt];
		// m_wksp_available[dt].erase(m_wksp_available[dt].begin());

	}
	else {

		// Memory not available, create it

		wksp_i = m_wksp_size[dt]++;

	}

	if (m_wksp_index[dt].size() <= x)
		m_wksp_index[dt].resize(x + 1, (uint64_t)-1);

	m_wksp_index[dt][x] = wksp_i;
}


void graph_lifecycle::constructor(uint64_t x)
{
	generic_constructor(QFLOATING_POINT, x);
}

void graph_lifecycle::generic_destructor(DataType vt, uint64_t x)
{
	m_wksp_available[vt].push_back(m_wksp_index[vt][x]);
}

void graph_lifecycle::destructor(uint64_t x)
{
	generic_destructor(QFLOATING_POINT, x);
}

void graph_lifecycle::generic_destroy_on_last_use(DataType vt, const uint64_t& x_i)
{
	const auto& lc_x = m_lifecycle[vt][x_i];

	if (lc_x.last_used() == m_clock)
		generic_destructor(vt, x_i);
}

void graph_lifecycle::destroy_on_last_use(const uint64_t& x_i)
{
	generic_destroy_on_last_use(QFLOATING_POINT, x_i);
}

void graph_lifecycle::process_func2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		generic_constructor(QBOOLEAN, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_func2_logical_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		generic_constructor(QBOOLEAN, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	bool xp = is_func2_x_param(op);
	bool yp = is_func2_y_param(op);
	bool rp = xp && yp;

	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		// wx += if(c,1,0)*wr
		// wy += if(c,0,1)*wr
		// -> x and y are unused, c is used

		if (rp) // Backward is no-op for iff_px_py
			return;
		generic_update_lifecycle(QBOOLEAN, input(c_i), clock);
		update_lifecycle(unused_input(x_i), clock);
		if (x_i != y_i)
			update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(output(r_i), clock);

	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		if (rp) // Backward is no-op for iff_px_py
			return;

		generic_destroy_on_last_use(QBOOLEAN,c_i);

		if (!xp)
			constructor(auxiliary(x_i));
		if (x_i != y_i && !yp)
			constructor(auxiliary(y_i));

		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		generic_destroy_on_last_use(QBOOLEAN, c_i);
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
		if (x_i != y_i && !yp)
			destroy_on_last_use(auxiliary(y_i));
		if (!xp)	
			destroy_on_last_use(auxiliary(x_i));
		if (!rp)
			constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		generic_destroy_on_last_use(QBOOLEAN, c_i);
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_iff_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	bool xp = is_func2_x_param(op);

	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		// wx += if(c,1,0)*wr
		// -> x is unused, c is used

		if (xp) // Backward is no-op for iff_scalar_px
			return;
		generic_update_lifecycle(QBOOLEAN, input(c_i), clock);
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(output(r_i), clock);

	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		if (xp) // Backward is no-op for iff_scalar_px
			return;

		// wx += if(c,1,0)*wr

		generic_destroy_on_last_use(QBOOLEAN, c_i);
		destroy_on_last_use(x_i); // This is unnecessary since x is not used so would have been destroyed earlier if no longer used but it is safe
		constructor(auxiliary(x_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD && !xp) // Forward phase for forward only
	{
		// r = if(c,x,y)
		// dr = if(c,dx,0)

		generic_destroy_on_last_use(QBOOLEAN, c_i);
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type or x is paramater for ForwardType
	{
		// r = if(c,x,y)

		generic_destroy_on_last_use(QBOOLEAN, c_i);
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_iff_sx_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QBOOLEAN, c_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_integer1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QINTEGER, x_i);
		generic_constructor(QINTEGER, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_integer2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QINTEGER, x_i);
		if (x_i != y_i)
			generic_destroy_on_last_use(QINTEGER, y_i);
		generic_constructor(QINTEGER, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_integer2_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& i_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QINTEGER, x_i);
		generic_constructor(QINTEGER, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_integer2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QINTEGER, x_i);
		if (x_i != y_i)
			generic_destroy_on_last_use(QINTEGER, y_i);
		generic_constructor(QBOOLEAN, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_integer2_logical_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QINTEGER, x_i);
		generic_constructor(QBOOLEAN, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QBOOLEAN, c_i);
		generic_destroy_on_last_use(QINTEGER, x_i);
		if (x_i != y_i)
			generic_destroy_on_last_use(QINTEGER, y_i);
		generic_constructor(QINTEGER, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_integer_iff_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QBOOLEAN, c_i);
		generic_destroy_on_last_use(QINTEGER, x_i);
		generic_constructor(QINTEGER, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_integer_iff_ix_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QBOOLEAN, c_i);
		generic_constructor(QINTEGER, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_boolean1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QBOOLEAN, x_i);
		generic_constructor(QBOOLEAN, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_boolean2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QBOOLEAN, x_i);
		if (x_i != y_i)
			generic_destroy_on_last_use(QBOOLEAN, y_i);
		generic_constructor(QBOOLEAN, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_boolean2_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& i_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QBOOLEAN, x_i);
		generic_constructor(QBOOLEAN, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QBOOLEAN, c_i);
		generic_destroy_on_last_use(QBOOLEAN, x_i);
		if (x_i != y_i)
			generic_destroy_on_last_use(QBOOLEAN, y_i);
		generic_constructor(QBOOLEAN, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_boolean_iff_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QBOOLEAN, c_i);
		generic_destroy_on_last_use(QBOOLEAN, x_i);
		generic_constructor(QBOOLEAN, r_i);
	}
	++m_clock;
}

void graph_lifecycle::process_boolean_iff_bx_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		generic_destroy_on_last_use(QBOOLEAN, c_i);
		generic_constructor(QBOOLEAN, r_i);
	}
	++m_clock;
}

uint64_t graph_lifecycle::auxiliary(const uint64_t& x_i) const
{
	return x_i + m_var_counter;
}

graph_lifecycle::graph_node graph_lifecycle::unused_input(const uint64_t& x) 
{ 
	return graph_lifecycle::graph_node(x, true, false);
}

graph_lifecycle::graph_node graph_lifecycle::input(const uint64_t& x) 
{ 
	return graph_lifecycle::graph_node(x, true, true);
}

graph_lifecycle::graph_node graph_lifecycle::output(const uint64_t& x) 
{ 
	return graph_lifecycle::graph_node(x, false, false); 
}

graph_lifecycle::graph_node graph_lifecycle::used_output(const uint64_t& x) 
{ 	
	return graph_lifecycle::graph_node(x, false, true);
}

void graph_lifecycle::generic_update_lifecycle(DataType dt, const graph_node& x, uint64_t clock)
{
	const uint64_t& x_i = x.get_x();
	auto& lc_x = m_lifecycle[dt][x_i];
	if (!lc_x.is_param() && m_direction == BACKWARD)
	{
		auto& lc_adjointx = m_lifecycle[dt][x_i + m_var_counter];
		// If x was last used here, we have to create the adjoint here
		if (lc_adjointx.first_used() == (uint64_t)-1)
			lc_adjointx.created() = lc_adjointx.first_used() = m_clock;
		else if (x.is_input()) // skip initialisation of adjoint of x_i if not the first use
		{
			m_skip_ops_init.push_back(clock);
			m_skip_ops_arg_init.push_back(x_i);
		}
		lc_adjointx.last_used() = m_clock;
	}
	if ((m_direction == BACKWARD && x.is_used()) || (m_direction == FORWARD && x.is_input()))
	{
		if (lc_x.first_used() == (uint64_t)-1)
			lc_x.first_used() = m_clock;
		lc_x.last_used() = m_clock;
	}
}

void graph_lifecycle::update_lifecycle(const graph_node& x, uint64_t clock)
{
	generic_update_lifecycle(QFLOATING_POINT, x, clock);
}

//${begin}
void graph_lifecycle::equal_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
}

void graph_lifecycle::equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::equal_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::squareroot(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(used_output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(r_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::squareroot_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::change_sign_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::ceiling(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(auxiliary(x_i));
		destroy_on_last_use(x_i);
		constructor(r_i);
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::ceiling_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::flooring(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(auxiliary(x_i));
		destroy_on_last_use(x_i);
		constructor(r_i);
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::flooring_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::heaviside_step(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(auxiliary(x_i));
		destroy_on_last_use(x_i);
		constructor(r_i);
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::heaviside_step_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::exponential(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(used_output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(r_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::exponential_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::logarithm(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		destroy_on_last_use(x_i);
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::logarithm_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::logarithm2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::logarithm2_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::logarithm10(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::logarithm10_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::complementary_errorfunc(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::complementary_errorfunc_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::arc_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::arc_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::arc_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::arc_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::arc_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::arc_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::hyperbolic_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::hyperbolic_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::hyperbolic_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::hyperbolic_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::hyperbolic_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(used_output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(r_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::hyperbolic_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		if (x_i != y_i)
			update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		if (x_i != y_i)
			constructor(auxiliary(y_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		if (x_i != y_i)
			destroy_on_last_use(auxiliary(y_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::add_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(y_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(y_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::add_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::add_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		if (x_i != y_i)
			update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		if (x_i != y_i)
			constructor(auxiliary(y_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		if (x_i != y_i)
			destroy_on_last_use(auxiliary(y_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(y_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(y_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::subtract_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::subtract_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		if (x_i != y_i)
			update_lifecycle(input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		if (x_i != y_i)
			constructor(auxiliary(y_i));
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(auxiliary(y_i));
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::multiply_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(y_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(y_i);
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(y_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::multiply_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::multiply_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		if (x_i != y_i)
			update_lifecycle(input(y_i), clock);
		update_lifecycle(used_output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		if (x_i != y_i)
			constructor(auxiliary(y_i));
		destroy_on_last_use(r_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		if (x_i != y_i)
			destroy_on_last_use(auxiliary(y_i));
		destroy_on_last_use(auxiliary(x_i));
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(input(y_i), clock);
		update_lifecycle(used_output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(y_i));
		destroy_on_last_use(r_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(y_i));
		destroy_on_last_use(y_i);
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::divide_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		destroy_on_last_use(y_i);
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::divide_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::maximum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		if (x_i != y_i)
			update_lifecycle(input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		if (x_i != y_i)
			constructor(auxiliary(y_i));
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		if (x_i != y_i)
			destroy_on_last_use(auxiliary(y_i));
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::maximum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(y_i));
		destroy_on_last_use(y_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(y_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::maximum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::maximum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::minimum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		if (x_i != y_i)
			update_lifecycle(input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		if (x_i != y_i)
			constructor(auxiliary(y_i));
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		if (x_i != y_i)
			destroy_on_last_use(auxiliary(y_i));
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::minimum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(y_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(y_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::minimum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(y_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::minimum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		if (x_i != y_i)
			update_lifecycle(input(y_i), clock);
		update_lifecycle(used_output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		if (x_i != y_i)
			constructor(auxiliary(y_i));
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(r_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		if (x_i != y_i)
			destroy_on_last_use(auxiliary(y_i));
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(used_output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(y_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(r_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(y_i);
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(y_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::power_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::power_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		if (x_i != y_i)
			destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::add_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::add_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::subtract_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::subtract_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::scalar_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(y_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(y_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(y_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::scalar_subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::multiply_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::multiply_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::divide_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::divide_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::scalar_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(y_i), clock);
		update_lifecycle(used_output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(y_i));
		destroy_on_last_use(r_i);
		destroy_on_last_use(y_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(auxiliary(y_i));
		destroy_on_last_use(y_i);
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::scalar_divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::maximum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::maximum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::minimum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::minimum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::power_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(input(x_i), clock);
		update_lifecycle(output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(x_i));
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		constructor(r_i);
		destroy_on_last_use(x_i);
		destroy_on_last_use(auxiliary(x_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::power_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(x_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::scalar_power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_phase == NONE) // Only for backward to update lifecycle in backward pass
	{
		update_lifecycle(unused_input(y_i), clock);
		update_lifecycle(used_output(r_i), clock);
	}
	else if (m_adtype == BACKWARD && m_phase == BACKWARD) // Backward phase for Backward AD
	{
		constructor(auxiliary(y_i));
		destroy_on_last_use(r_i);
		destroy_on_last_use(auxiliary(r_i));
	}
	else if (m_adtype == FORWARD) // Forward phase for forward only
	{
		destroy_on_last_use(y_i);
		constructor(r_i);
		destroy_on_last_use(auxiliary(y_i));
		constructor(auxiliary(r_i));
	}
	else // Forward phase for NONE and Backward type
	{
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

void graph_lifecycle::scalar_power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i)
{
	if (m_adtype == FORWARD || m_phase == FORWARD) // No-op for BACKWARD
	{
		destroy_on_last_use(y_i);
		constructor(r_i);
	}
	++m_clock;
}

//${end}


