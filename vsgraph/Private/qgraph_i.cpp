#include "qdefines.h"
#include "qgraph_i.h"
#include "intrin.h"
#include "qgraph_traits.h"
#include "qexception.h"
#include "qgraph_mapfunc.h"
using namespace vstech;

#ifdef __linux__
#define m512d_f64(x,i) x[i]
#define m512_f32(x,i) x[i]
#define m256d_f64(x,i) x[i]
#define m256_f32(x,i) x[i]
#define m128d_f64(x,i) x[i]
#define m128_f32(x,i) x[i]
#else
#define m512d_f64(x,i) x.m512d_f64[i]
#define m512_f32(x,i) x.m512_f32[i]
#define m256d_f64(x,i) x.m256d_f64[i]
#define m256_f32(x,i) x.m256_f32[i]
#define m128d_f64(x,i) x.m128d_f64[i]
#define m128_f32(x,i) x.m128_f32[i]
#endif


#ifdef INSTANTIATE_AVX512
bool operator<(const _m_wrapper<__m512d>& _lhs, const _m_wrapper<__m512d>& _rhs)
{
	const __m512d& lhs = _lhs.m_;
	const __m512d& rhs = _rhs.m_;

	for (size_t i = 0; i < 8; ++i)
		if (m512d_f64(lhs, i) < m512d_f64(rhs, i))
			return true;
		else if (m512d_f64(lhs, i) > m512d_f64(rhs, i))
			return false;
	return false;
}

bool operator<(const _m_wrapper<__m512>& _lhs, const _m_wrapper<__m512>& _rhs)
{
	const __m512& lhs = _lhs.m_;
	const __m512& rhs = _rhs.m_;

	for (size_t i = 0; i < 16; ++i)
		if (m512_f32(lhs, i) < m512_f32(rhs, i))
			return true;
		else if (m512_f32(lhs, i) > m512_f32(rhs, i))
			return false;
	return false;
}
#endif

bool operator<(const _m_wrapper<__m256d>& _lhs, const _m_wrapper<__m256d>& _rhs)
{
	const __m256d& lhs = _lhs.m_;
	const __m256d& rhs = _rhs.m_;

	for (size_t i = 0; i < 4; ++i)
		if (m256d_f64(lhs, i) < m256d_f64(rhs, i))
			return true;
		else if (m256d_f64(lhs, i) > m256d_f64(rhs, i))
			return false;
	return false;
}

bool operator<(const _m_wrapper<__m256>& _lhs, const _m_wrapper<__m256>& _rhs)
{
	const __m256& lhs = _lhs.m_;
	const __m256& rhs = _rhs.m_;

	for (size_t i = 0; i < 8; ++i)
		if (m256_f32(lhs, i) < m256_f32(rhs, i))
			return true;
		else if (m256_f32(lhs, i) > m256_f32(rhs, i))
			return false;
	return false;
}

bool operator<(const _m_wrapper<__m128d>& _lhs, const _m_wrapper <__m128d>& _rhs)
{
	const __m128d& lhs = _lhs.m_;
	const __m128d& rhs = _rhs.m_;

	for (size_t i = 0; i < 2; ++i)
		if (m128d_f64(lhs, i) < m128d_f64(rhs, i))
			return true;
		else if (m128d_f64(lhs, i) > m128d_f64(rhs, i))
			return false;
	return false;
}

bool operator<(const _m_wrapper<__m128>& _lhs, const _m_wrapper<__m128>& _rhs)
{
	const __m128& lhs = _lhs.m_;
	const __m128& rhs = _rhs.m_;

	for (size_t i = 0; i < 4; ++i)
		if (m128_f32(lhs, i) < m128_f32(rhs, i))
			return true;
		else if (m128_f32(lhs, i) > m128_f32(rhs, i))
			return false;
	return false;
}

uint64_t qgraph_i_base::now() const { return m_ops.size(); }

uint64_t qgraph_i_base::index() const { return m_ops_arg_index.size(); }

bool& qgraph_i_base::is_param(uint64_t x_i) { return m_lifecycle[QFLOATING_POINT][x_i].is_param(); }
const bool& qgraph_i_base::is_param(uint64_t x_i) const { return m_lifecycle[QFLOATING_POINT][x_i].is_param(); }

bool qgraph_i_base::was_used(uint64_t x_i) const { return m_lifecycle[QFLOATING_POINT][x_i].was_used(); }
uint64_t& qgraph_i_base::first_used(uint64_t x_i) { return m_lifecycle[QFLOATING_POINT][x_i].first_used(); }
uint64_t& qgraph_i_base::last_used(uint64_t x_i) { return m_lifecycle[QFLOATING_POINT][x_i].last_used(); }
uint64_t& qgraph_i_base::first_index(uint64_t x_i) { return m_lifecycle[QFLOATING_POINT][x_i].first_index(); }
uint64_t& qgraph_i_base::last_index(uint64_t x_i) { return m_lifecycle[QFLOATING_POINT][x_i].last_index(); }
uint64_t& qgraph_i_base::created(uint64_t x_i) { return m_lifecycle[QFLOATING_POINT][x_i].created(); }

uint64_t& qgraph_i_base::first_boolean_used(uint64_t x_i) { return m_lifecycle[QBOOLEAN][x_i].first_used(); }
uint64_t& qgraph_i_base::last_boolean_used(uint64_t x_i) { return m_lifecycle[QBOOLEAN][x_i].last_used(); }
uint64_t& qgraph_i_base::first_boolean_index(uint64_t x_i) { return m_lifecycle[QBOOLEAN][x_i].first_index(); }
uint64_t& qgraph_i_base::last_boolean_index(uint64_t x_i) { return m_lifecycle[QBOOLEAN][x_i].last_index(); }
bool qgraph_i_base::was_boolean_used(uint64_t x_i) const { return m_lifecycle[QBOOLEAN][x_i].was_used(); }

uint64_t& qgraph_i_base::first_integer_used(uint64_t x_i) { return m_lifecycle[QINTEGER][x_i].first_used(); }
uint64_t& qgraph_i_base::last_integer_used(uint64_t x_i) { return m_lifecycle[QINTEGER][x_i].last_used(); }
uint64_t& qgraph_i_base::first_integer_index(uint64_t x_i) { return m_lifecycle[QINTEGER][x_i].first_index(); }
uint64_t& qgraph_i_base::last_integer_index(uint64_t x_i) { return m_lifecycle[QINTEGER][x_i].last_index(); }
bool qgraph_i_base::was_integer_used(uint64_t x_i) const { return m_lifecycle[QINTEGER][x_i].was_used(); }

uint64_t qgraph_i_base::generic_add_variable(DataType dt)
{
	m_lifecycle[dt].push_back(lifecycle(now()));
	m_processed[dt].push_back(false);
	return m_var_counter[dt]++;
}

uint64_t qgraph_i_base::add_variable()
{
	return generic_add_variable(QFLOATING_POINT);
}

uint64_t qgraph_i_base::add_boolean_variable()
{
	return generic_add_variable(QBOOLEAN);
}

uint64_t qgraph_i_base::add_integer_variable()
{
	return generic_add_variable(QINTEGER);
}

qgraph_i_base::qgraph_i_base() : 
	m_wksp_size(NUMBER_OF_TYPES, 0), 
	m_wksp_index(NUMBER_OF_TYPES), 
	m_lifecycle_input(true), 
	m_zero_index(-1),
	m_var_counter(NUMBER_OF_TYPES,0), 
	m_variable_map(NUMBER_OF_TYPES),
	m_n_nonparam(0),
	m_lifecycle(NUMBER_OF_TYPES),
	m_processed(NUMBER_OF_TYPES),
	m_checkpoint_input(NUMBER_OF_TYPES),
	m_input_map(NUMBER_OF_TYPES), 
	m_output_map(1),
	m_assign_map(NUMBER_OF_TYPES)
{
	m_input_map[QFLOATING_POINT].resize(1);
	m_input_map[QINTEGER].resize(1);
	m_input_map[QBOOLEAN].resize(1);
}
qgraph_i_base::~qgraph_i_base() {}

std::pair<std::map<uint64_t, uint64_t>::iterator, bool> qgraph_i_base::generic_varmap(DataType dt, uint64_t x)
{
	auto it = m_variable_map[dt].find(x);

	if (it == m_variable_map[dt].end())
		return m_variable_map[dt].insert({x, generic_add_variable(dt)});
	else
		return std::make_pair(it, false);
}


std::pair<std::map<uint64_t, uint64_t>::iterator, bool> qgraph_i_base::varmap(uint64_t x)
{
	return generic_varmap(QFLOATING_POINT, x);
}

std::pair<std::map<uint64_t, uint64_t>::iterator, bool> qgraph_i_base::boolean_varmap(uint64_t x)
{
	return generic_varmap(QBOOLEAN, x);
}

std::pair<std::map<uint64_t, uint64_t>::iterator, bool> qgraph_i_base::integer_varmap(uint64_t x)
{
	return generic_varmap(QINTEGER, x);
}

void qgraph_i_base::generic_destroy(DataType dt, uint64_t x)
{
	auto it = m_variable_map[dt].find(x);
	if (it != m_variable_map[dt].end())
		m_variable_map[dt].erase(it);
}

void qgraph_i_base::destroy(uint64_t x)
{
	generic_destroy(QFLOATING_POINT, x);
}

// call to input(x) with x = qscalar, xv is the value of x
// x could have been created before recording started, in which case it will not show up in m_variable_map
// It could have been created after recording started, in which case it will be in m_variable_map
// x could have already been declared an input previously based on 3 possible scenarios:
// 1) Previous direct call to input
// 2) Call to x = value with x not having been used  
// 3) First use of the variable
// In the first 2 cases, we can update the m_assign_map as long as the variable has not been used
// If it has been used (case 3), we have to throw an exception

void qgraph_i_base::input(uint64_t x, const scalar_value& xv, const char* s, bool xp)
{
	auto it = varmap(x);
	auto x_i = it.first->second;
	created(x_i) = (uint64_t)-1;
	if (was_used(x_i))
		throw qexception("Attempt to declare an input that has already been used");
	is_param(x_i) = xp;
	m_assign_map[QFLOATING_POINT][x_i] = xv.get_index();
	m_input_map[QFLOATING_POINT][0].insert({ x, x_i });
	if (s != 0)
		m_variable_name_map.insert({s, x_i});
}

void qgraph_i_base::output(uint64_t x, const char* s)
{
	auto o_it = varmap(x);
	auto r_i = o_it.first->second;

	m_output_map[0].insert({ x, r_i });

	// Is x also an input ?
	// If so, we put it in the input to output map

	auto it = m_input_map[QFLOATING_POINT][0].left.find(x);

	if (it != m_input_map[QFLOATING_POINT][0].left.end())
		m_input_output_map[it->second] = r_i;

	if (s != 0)
		m_variable_name_map.insert({ s, r_i });
}

void qgraph_i_base::checkpoint()
{
	if (m_ops.size() == 0)
		return;
	m_ops.push_back(CHECKPOINT);
	m_checkpoint_ops_index.push_back(m_ops.size());
	m_checkpoint_ops_arg_index.push_back(m_ops_arg_index.size());
	for (DataType dt = QFLOATING_POINT; dt != NUMBER_OF_TYPES; dt = next_data_type(dt))
		std::fill(m_processed[dt].begin(), m_processed[dt].end(), false);
}

uint64_t qgraph_i_base::get_input_index(uint64_t x) const
{
	auto it = m_input_map[QFLOATING_POINT][0].left.find(x);
	if (it != m_input_map[QFLOATING_POINT][0].left.end())
		return it->second;
	throw qexception("Attempt to access unrecorded variable");
	return (uint64_t)-1;
}

uint64_t qgraph_i_base::get_index(uint64_t x) const
{
	auto it = m_variable_map[QFLOATING_POINT].find(x);
	if (it != m_variable_map[QFLOATING_POINT].end())
		return it->second;
	else
		return get_input_index(x);
}

uint64_t qgraph_i_base::get_index(const char* s) const
{
	auto it = m_variable_name_map.left.find(s);
	return it == m_variable_name_map.left.end() ? (uint64_t)-1 : it->second;
}

// x = xv with x = qscalar and xv a value
// If variable has not been used, we do not yet know if it will be an input or not so no need to do anything 
// If already used, we have to create a new variable and add EQUAL_SCALAR op 
// This new variable is a parameter by definition

void qgraph_i_base::equal_scalar(uint64_t x, const scalar_value& xv)
{
	auto it = varmap(x);
	auto& x_i = it.first->second;
	if (was_used(x_i))
	{
		x_i = add_variable();
		first_index(x_i) = index();
		m_ops_arg_index.push_back(x_i);
		m_ops_arg_index.push_back(xv.get_index());
		is_param(x_i) = true;
		m_ops.push_back(EQUAL_SCALAR);
		last_index(x_i) = index();
		process_output(x_i);
	}
}

void qgraph_i_base::update_use(uint64_t x, uint64_t x_i, const scalar_value& xv)
{
	if (!was_used(x_i))
	{
		m_assign_map[QFLOATING_POINT][x_i] = xv.get_index();
		m_input_map[QFLOATING_POINT][0].insert({ x, x_i });
	}
	if (first_used(x_i) = (uint64_t)-1)
		first_used(x_i) = now();

	last_used(x_i) = now();
}

void qgraph_i_base::update_use(uint64_t c, uint64_t c_i, const boolean_value& cv)
{
	if (!was_boolean_used(c_i))
	{
		m_assign_map[QBOOLEAN][c_i] = cv.get_index();
		m_input_map[QBOOLEAN][0].insert({c, c_i});
	}
	if (first_boolean_used(c_i) = (uint64_t)-1)
		first_boolean_used(c_i) = now();

	last_boolean_used(c_i) = now();
}

void qgraph_i_base::update_use(uint64_t x, uint64_t x_i, const integer_value& xv)
{
	if (!was_integer_used(x_i))
	{
		m_assign_map[QINTEGER][x_i] = xv.get_index();
		m_input_map[QINTEGER][0].insert({x, x_i});
	}
	if (first_integer_used(x_i) = (uint64_t)-1)
		first_integer_used(x_i) = now();

	last_integer_used(x_i) = now();
}

void qgraph_i_base::generic_process_input(DataType dt, uint64_t x)
{
	if (!m_processed[dt][x])
		m_checkpoint_input[dt].push_back(x);
	m_processed[dt][x] = true;
}

void qgraph_i_base::generic_process_output(DataType dt, uint64_t r)
{
	m_processed[dt][r] = true;
}

void qgraph_i_base::process_input(uint64_t x)
{
	generic_process_input(QFLOATING_POINT, x);
}

void qgraph_i_base::process_output(uint64_t r)
{
	generic_process_output(QFLOATING_POINT, r);
}

void qgraph_i_base::process_integer_input(uint64_t x)
{
	generic_process_input(QINTEGER, x);
}

void qgraph_i_base::process_integer_output(uint64_t r)
{
	generic_process_output(QINTEGER, r);
}

void qgraph_i_base::process_boolean_input(uint64_t x)
{
	generic_process_input(QBOOLEAN, x);
}

void qgraph_i_base::process_boolean_output(uint64_t r)
{
	generic_process_output(QBOOLEAN, r);
}

// This is called for the following cases for op = EQUAL
//		This is called in 2 cases, copy constructor and operator=(const qscalar<T>&)

void qgraph_i_base::process_equal(uint64_t r, Operation op, uint64_t x, const scalar_value& xv)
{
	auto x_i = varmap(x).first->second;
	auto rit = varmap(r);
	auto& r_i = rit.first->second;
	r_i = x_i;
	update_use(x, x_i, xv);
}

// This is called for op = functions of 1 variable (sin, cos, exp, ...)
//		In this case, the variable r is always new

void qgraph_i_base::process_func1(uint64_t r, Operation op, uint64_t x, const scalar_value& xv)
{
	auto x_i = varmap(x).first->second;
	auto rit = varmap(r);
	auto& r_i = rit.first->second;

	update_use(x, x_i, xv);

	// Check if r is a newly discovered variable
	// This is the case if a copy constructor is invoked or if an equal operator is called on a variable that was constructed before recording started
	// If not new, we must add a new variable.
	// Note that functions alwyas create a new variable so rit.second is always true. EQUAL is a special case

	if (!rit.second)
		r_i = add_variable();

	first_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(map_func1(op, is_param(r_i) = is_param(x_i)));
	last_index(r_i) = index();
	process_input(x_i);
	process_output(r_i);
}

// This is called for r = x op y where op can be +, *, -, /, pow, max, min, ...

void qgraph_i_base::process_func2(uint64_t r, Operation op, uint64_t x, const scalar_value& xv, uint64_t y, const scalar_value& yv)
{
	auto x_i = varmap(x).first->second;
	update_use(x, x_i, xv);

	auto y_i = varmap(y).first->second;
	if (x != y)
		update_use(y, y_i, yv);

	auto it = varmap(r);
	auto& r_i = it.first->second;

	if (r == x || r == y) // This happens when we do e.g. r*=y or r = x*r (e.g. qgraph_generator.cpp), in which case we have to create a new variable for r
		r_i = add_variable();

	first_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
	last_index(r_i) = index();
	bool x_p = is_param(x_i);
	bool y_p = is_param(y_i);
	is_param(r_i) = x_p && y_p;
	m_ops.push_back(map_func2(op, x_p, y_p));
	process_input(x_i);
	process_input(y_i);
	process_output(r_i);
}

// This is called for r = x op y where op can be +, *, -, /, pow, max, min, ...
// x is qscalar and y is a number

void qgraph_i_base::process_func2_sy(uint64_t r, Operation op, uint64_t x, const scalar_value& xv, const scalar_value& yv)
{
	auto x_i = varmap(x).first->second;
	update_use(x, x_i, xv);

	auto it = varmap(r);
	auto& r_i = it.first->second;

	if (r == x) // This happens when we do e.g. r*=y, in which case we have to create a new variable for r
		r_i = add_variable();

	first_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(map_func1(op, is_param(r_i) = is_param(x_i)));
	last_index(r_i) = index();
	process_input(x_i);
	process_output(r_i);
}

// This is called for r = x op y where op can be +, *, -, /, pow, max, min, ...
// x is number and y is a qscalar

void qgraph_i_base::process_func2_sx(uint64_t r, Operation op, const scalar_value& xv, uint64_t y, const scalar_value& yv)
{
	auto y_i = varmap(y).first->second;
	update_use(y, y_i, yv);

	auto it = varmap(r);
	auto& r_i = it.first->second;

	// Note that r == y never happens

	first_index(r_i) = index();
	m_ops_arg_index.push_back(xv.get_index());
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(map_func1(op, is_param(r_i) = is_param(y_i)));
	last_index(r_i) = index();
	process_input(y_i);
	process_output(r_i);
}

void qgraph_i_base::process_func2_logical(uint64_t r, Operation op, uint64_t x, const scalar_value& xv, uint64_t y, const scalar_value& yv)
{
	auto x_i = varmap(x).first->second;
	update_use(x, x_i, xv);

	auto y_i = varmap(y).first->second;
	if (x != y)
		update_use(y, y_i, yv);

	auto it = boolean_varmap(r);
	auto r_i = it.first->second;

	first_boolean_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
	last_boolean_index(r_i) = index();
	m_ops.push_back(op);
	process_input(x_i);
	process_input(y_i);
	process_boolean_output(r_i);
}

void qgraph_i_base::process_func2_logical_sy(uint64_t r, Operation op, uint64_t x, const scalar_value& xv, const scalar_value& yv)
{
	auto x_i = varmap(x).first->second;
	update_use(x, x_i, xv);

	auto it = boolean_varmap(r);
	auto r_i = it.first->second;

	first_boolean_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_boolean_index(r_i) = index();
	process_input(x_i);
	process_boolean_output(r_i);
}

void qgraph_i_base::process_iff(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const scalar_value& xv, uint64_t y, const scalar_value& yv)
{
	auto x_i = varmap(x).first->second;
	update_use(x, x_i, xv);

	auto y_i = varmap(y).first->second;
	if (x != y)
		update_use(y, y_i, yv);

	auto c_i = boolean_varmap(c).first->second;
	update_use(c, c_i, cv);

	auto r_i = varmap(r).first->second;

	first_index(r_i) = index();
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
	last_index(r_i) = index();
	bool x_p = is_param(x_i);
	bool y_p = is_param(y_i);
	is_param(r_i) = x_p && y_p;
	m_ops.push_back(map_func2(op, x_p, y_p));
	process_boolean_input(c_i);
	process_input(x_i);
	process_input(y_i);
	process_output(r_i);
}

void qgraph_i_base::process_iff_sy(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const scalar_value& xv, const scalar_value& yv)
{
	auto x_i = varmap(x).first->second;
	update_use(x, x_i, xv);

	auto c_i = boolean_varmap(c).first->second;
	update_use(c, c_i, cv);

	auto r_i = varmap(r).first->second;

	first_index(r_i) = index();
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(map_func1(op, is_param(r_i) = is_param(x_i)));
	last_index(r_i) = index();
	process_boolean_input(c_i);
	process_input(x_i);
	process_output(r_i);
}

void qgraph_i_base::process_iff_sx_sy(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, const scalar_value& xv, const scalar_value& yv)
{
	auto c_i = boolean_varmap(c).first->second;
	update_use(c, c_i, cv);

	auto r_i = varmap(r).first->second;

	first_index(r_i) = index();
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(xv.get_index());
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_index(r_i) = index();
	process_boolean_input(c_i);
	process_output(r_i);
}

void qgraph_i_base::destroy_boolean(uint64_t x)
{
	generic_destroy(QBOOLEAN, x);
}

void qgraph_i_base::equal_bool(uint64_t x, const boolean_value& xv)
{
	auto it = boolean_varmap(x);
	auto& x_i = it.first->second;
	if (was_boolean_used(x_i))
	{
		x_i = add_boolean_variable();
		first_boolean_index(x_i) = index();
		m_ops_arg_index.push_back(x_i);
		m_ops_arg_index.push_back(xv.get_index());
		m_ops.push_back(BOOLEAN_EQUAL_BOOL);
		last_boolean_index(x_i) = index();
		process_boolean_output(x_i);
	}
}

void qgraph_i_base::process_boolean1(uint64_t r, Operation op, uint64_t x, const boolean_value& xv)
{
	auto x_i = boolean_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto r_i = boolean_varmap(r).first->second;

	first_boolean_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_boolean_index(r_i) = index();
	process_boolean_input(x_i);
	process_boolean_output(r_i);
}

void qgraph_i_base::process_boolean1_bx(uint64_t r, Operation op, const boolean_value& xv)
{
	equal_bool(r, xv);
}


void qgraph_i_base::process_boolean2(uint64_t r, Operation op, uint64_t x, const boolean_value& xv, uint64_t y, const boolean_value& yv)
{
	auto x_i = boolean_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto y_i = boolean_varmap(y).first->second;
	update_use(y, y_i, yv);

	auto r_i = boolean_varmap(r).first->second;

	first_boolean_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_boolean_index(r_i) = index();
	process_boolean_input(x_i);
	process_boolean_input(y_i);
	process_boolean_output(r_i);
}

void qgraph_i_base::process_boolean2_by(uint64_t r, Operation op, uint64_t x, const boolean_value& xv, const boolean_value& yv)
{
	auto x_i = boolean_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto r_i = boolean_varmap(r).first->second;

	first_boolean_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_boolean_index(r_i) = index();
	process_boolean_input(x_i);
	process_boolean_output(r_i);
}

void qgraph_i_base::process_boolean_iff(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const boolean_value& xv, uint64_t y, const boolean_value& yv)
{
	auto x_i = boolean_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto y_i = boolean_varmap(x).first->second;
	update_use(y, y_i, yv);

	auto c_i = boolean_varmap(c).first->second;
	update_use(c, c_i, cv);

	auto r_i = boolean_varmap(r).first->second;

	first_boolean_index(r_i) = index();
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_boolean_index(r_i) = index();
	process_boolean_input(c_i);
	process_boolean_input(x_i);
	process_boolean_input(y_i);
	process_boolean_output(r_i);
}

void qgraph_i_base::process_boolean_iff_by(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const boolean_value& xv, const boolean_value& yv)
{
	auto x_i = boolean_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto c_i = boolean_varmap(c).first->second;
	update_use(c, c_i, cv);

	auto r_i = boolean_varmap(r).first->second;

	first_boolean_index(r_i) = index();
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_boolean_index(r_i) = index();
	process_boolean_input(c_i);
	process_boolean_input(x_i);
	process_boolean_output(r_i);
}

void qgraph_i_base::process_boolean_iff_bx_by(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, const boolean_value& xv, const boolean_value& yv)
{
	auto c_i = boolean_varmap(c).first->second;
	update_use(c, c_i, cv);

	auto r_i = boolean_varmap(r).first->second;

	first_boolean_index(r_i) = index();
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(xv.get_index());
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_boolean_index(r_i) = index();
	process_boolean_input(c_i);
	process_boolean_output(r_i);
}

void qgraph_i_base::destroy_integer(uint64_t x)
{
	generic_destroy(QINTEGER, x);
}

void qgraph_i_base::equal_int(uint64_t x, const integer_value& xv)
{
	auto it = integer_varmap(x);
	auto& x_i = it.first->second;
	if (was_integer_used(x_i))
	{
		x_i = add_integer_variable();
		first_integer_index(x_i) = index();
		m_ops_arg_index.push_back(x_i);
		m_ops_arg_index.push_back(xv.get_index());
		m_ops.push_back(INTEGER_EQUAL_INT);
		last_integer_index(x_i) = index();
		process_integer_output(x_i);
	}
}

void qgraph_i_base::process_integer1(uint64_t r, Operation op, uint64_t x, const integer_value& xv)
{
	auto x_i = integer_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto r_i = integer_varmap(r).first->second;

	first_integer_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_integer_index(r_i) = index();
	process_integer_input(x_i);
	process_integer_output(r_i);
}

void qgraph_i_base::process_integer1_ix(uint64_t r, Operation op, const integer_value& xv)
{
	equal_int(r, xv);
}

void qgraph_i_base::process_integer2(uint64_t r, Operation op, uint64_t x, const integer_value& xv, uint64_t y, const integer_value& yv)
{
	auto x_i = integer_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto y_i = integer_varmap(y).first->second;
	update_use(y, y_i, yv);

	auto r_i = integer_varmap(r).first->second;

	first_integer_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_integer_index(r_i) = index();
	process_integer_input(x_i);
	process_integer_input(y_i);
	process_integer_output(r_i);
}

void qgraph_i_base::process_integer2_iy(uint64_t r, Operation op, uint64_t x, const integer_value& xv, const integer_value& yv)
{
	auto x_i = integer_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto r_i = integer_varmap(r).first->second;

	first_integer_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_integer_index(r_i) = index();
	process_integer_input(x_i);
	process_integer_output(r_i);
}

void qgraph_i_base::process_integer2_ix(uint64_t r, Operation op, const integer_value& xv, uint64_t y, const integer_value& yv)
{
	auto y_i = integer_varmap(y).first->second;
	update_use(y, y_i, yv);

	auto r_i = integer_varmap(r).first->second;

	first_integer_index(r_i) = index();
	m_ops_arg_index.push_back(xv.get_index());
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_integer_index(r_i) = index();
	process_integer_input(y_i);
	process_integer_output(r_i);
}

void qgraph_i_base::process_integer2_logical(uint64_t r, Operation op, uint64_t x, const integer_value& xv, uint64_t y, const integer_value& yv)
{
	auto x_i = integer_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto y_i = integer_varmap(y).first->second;
	update_use(y, y_i, yv);

	auto r_i = boolean_varmap(r).first->second;

	first_boolean_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_boolean_index(r_i) = index();
	process_integer_input(x_i);
	process_integer_input(y_i);
	process_boolean_output(r_i);
}

void qgraph_i_base::process_integer2_logical_iy(uint64_t r, Operation op, uint64_t x, const integer_value& xv, const integer_value& yv)
{
	auto x_i = integer_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto r_i = boolean_varmap(r).first->second;

	first_boolean_index(r_i) = index();
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	m_ops.push_back(op);
	last_boolean_index(r_i) = index();
	process_integer_input(x_i);
	process_boolean_output(r_i);
}

void qgraph_i_base::process_integer_iff(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const integer_value& xv, uint64_t y, const integer_value& yv)
{
	auto x_i = integer_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto y_i = integer_varmap(y).first->second;
	if (x != y)
		update_use(y, y_i, yv);

	auto c_i = boolean_varmap(c).first->second;
	update_use(c, c_i, cv);

	auto r_i = integer_varmap(r).first->second;

	first_integer_index(r_i) = index();
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(y_i);
	m_ops_arg_index.push_back(r_i);
	last_integer_index(r_i) = index();
	m_ops.push_back(op);
	process_boolean_input(c_i);
	process_integer_input(x_i);
	process_integer_input(y_i);
	process_integer_output(r_i);
}

void qgraph_i_base::process_integer_iff_iy(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, uint64_t x, const integer_value& xv, const integer_value& yv)
{
	auto x_i = integer_varmap(x).first->second;
	update_use(x, x_i, xv);

	auto c_i = boolean_varmap(c).first->second;
	update_use(c, c_i, cv);

	auto r_i = integer_varmap(r).first->second;

	first_integer_index(r_i) = index();
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(x_i);
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	last_integer_index(r_i) = index();
	m_ops.push_back(op);
	process_boolean_input(c_i);
	process_integer_input(x_i);
	process_integer_output(r_i);
}

void qgraph_i_base::process_integer_iff_ix_iy(uint64_t r, Operation op, uint64_t c, const boolean_value& cv, const integer_value& xv, const integer_value& yv)
{
	auto c_i = boolean_varmap(c).first->second;
	update_use(c, c_i, cv);

	auto r_i = integer_varmap(r).first->second;

	first_integer_index(r_i) = index();
	m_ops_arg_index.push_back(c_i);
	m_ops_arg_index.push_back(xv.get_index());
	m_ops_arg_index.push_back(yv.get_index());
	m_ops_arg_index.push_back(r_i);
	last_integer_index(r_i) = index();
	m_ops.push_back(op);
	process_boolean_input(c_i);
	process_integer_output(r_i);
}

template class qgraph_i<double>;
template class qgraph_i<float>;
#ifdef INSTANTIATE_AVX512
template class qgraph_i<__m512d>;
template class qgraph_i<__m512>;
#endif
template class qgraph_i<__m256d>;
template class qgraph_i<__m256>;
template class qgraph_i<__m128d>;
template class qgraph_i<__m128>;

template class qgraph_i<double*>;
template class qgraph_i<float*>;
#ifdef INSTANTIATE_AVX512
template class qgraph_i<__m512d*>;
template class qgraph_i<__m512*>;
#endif
template class qgraph_i<__m256d*>;
template class qgraph_i<__m256*>;
template class qgraph_i<__m128d*>;
template class qgraph_i<__m128*>;


template<class T>
qgraph_i<T>::qgraph_i()
{}

template<class T>
qgraph_i<T>::~qgraph_i()
{}

#include <map>
#include <vector>
#include "qgraph_enum.h"

class op_proto
{
public:

	op_proto() {}
	~op_proto() {}

	std::vector<unsigned short> get_signature(const lifecycle& lc) const;
};

template<class T>
scalar<T> qgraph_i<T>::wrap(const typename graph_traits<T>::scalar_type& xv)
{
	return scalar<T>(xv, m_scalar_map);
}

template<class T>
_boolean<T> qgraph_i<T>::wrap(const typename graph_traits<T>::boolean_type& cv)
{
	return _boolean<T>(cv, m_boolean_map);
}

template<class T>
integer<T> qgraph_i<T>::wrap(const typename graph_traits<T>::integer_type& xv)
{
	return integer<T>(xv, m_integer_map);
}


template<class T>
uint64_t qgraph_i<T>::get_scalar_index(const typename graph_traits<T>::scalar_type& xv)
{
	return scalar<T>(xv, m_scalar_map).get_index();
}

template<class T>
uint64_t qgraph_i<T>::get_integer_index(const typename graph_traits<T>::integer_type& xv)
{
	return integer<T>(xv, m_integer_map).get_index();
}

template<class T>
uint64_t qgraph_i<T>::get_boolean_index(const typename graph_traits<T>::boolean_type& xv)
{
	return _boolean<T>(xv, m_boolean_map).get_index();
}

template<class T>
void qgraph_i<T>::destroy(uint64_t x) { qgraph_i_base::destroy(x); }

template<class T>
void qgraph_i<T>::input(uint64_t x, const typename graph_traits<T>::scalar_type& xv, const char* s) { qgraph_i_base::input(x, wrap(xv), s, false); }

template<class T>
void qgraph_i<T>::param(uint64_t x, const typename graph_traits<T>::scalar_type& xv, const char* s) { qgraph_i_base::input(x, wrap(xv), s, true); }

template<class T>
void qgraph_i<T>::output(uint64_t x, const char* s) { qgraph_i_base::output(x, s); }

template<class T>
void qgraph_i<T>::equal_scalar(uint64_t x, const typename graph_traits<T>::scalar_type& xv) { qgraph_i_base::equal_scalar(x, wrap(xv)); }

template<class T>
void qgraph_i<T>::process_equal(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv) { qgraph_i_base::process_equal(r, op, x, wrap(xv)); }

template<class T>
void qgraph_i<T>::process_func1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv) { qgraph_i_base::process_func1(r, op, x, wrap(xv)); }

template<class T>
void qgraph_i<T>::process_func2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv) { qgraph_i_base::process_func2(r, op, x, wrap(xv), y, wrap(yv)); }

template<class T>
void qgraph_i<T>::process_func2_sy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv) { qgraph_i_base::process_func2_sy(r, op, x, wrap(xv), wrap(yv)); }

template<class T>
void qgraph_i<T>::process_func2_sx(uint64_t r, Operation op, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv) { qgraph_i_base::process_func2_sx(r, op, wrap(xv), y, wrap(yv)); }

template<class T>
void qgraph_i<T>::process_func2_logical(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv) { qgraph_i_base::process_func2_logical(r, op, x, wrap(xv), y, wrap(yv)); }

template<class T>
void qgraph_i<T>::process_func2_logical_sy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv) {  qgraph_i_base::process_func2_logical_sy(r, op, x, wrap(xv), wrap(yv)); }

template<class T>
void qgraph_i<T>::process_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::scalar_type& xv, uint64_t y, const typename graph_traits<T>::scalar_type& yv) { qgraph_i_base::process_iff(r, op, c, wrap(cv), x, wrap(xv), y, wrap(yv)); }

template<class T>
void qgraph_i<T>::process_iff_sy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv) { qgraph_i_base::process_iff_sy(r, op, c, wrap(cv), x, wrap(xv), wrap(yv)); }

template<class T>
void qgraph_i<T>::process_iff_sx_sy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::scalar_type& xv, const typename graph_traits<T>::scalar_type& yv) { qgraph_i_base::process_iff_sx_sy(r, op, c, wrap(cv), wrap(xv), wrap(yv)); }

template<class T>
void qgraph_i<T>::destroy_boolean(uint64_t x) { qgraph_i_base::destroy_boolean(x); }

template<class T>
void qgraph_i<T>::equal_bool(uint64_t x, const typename graph_traits<T>::boolean_type& xv) { qgraph_i_base::equal_bool(x, wrap(xv)); }

template<class T>
void qgraph_i<T>::process_boolean1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv) { qgraph_i_base::process_boolean1(r, op, x, wrap(xv)); }

template<class T>
void qgraph_i<T>::process_boolean1_bx(uint64_t r, Operation op, const typename graph_traits<T>::boolean_type& xv) { qgraph_i_base::process_boolean1_bx(r, op, wrap(xv)); }

template<class T>
void qgraph_i<T>::process_boolean2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv, uint64_t y, const typename graph_traits<T>::boolean_type& yv) { qgraph_i_base::process_boolean2(r, op, x, wrap(xv), y, wrap(yv)); }

template<class T>
void qgraph_i<T>::process_boolean2_by(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv) { qgraph_i_base::process_boolean2_by(r, op, x, wrap(xv), wrap(yv)); }

template<class T>
void qgraph_i<T>::process_boolean_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::boolean_type& xv, uint64_t y, const typename graph_traits<T>::boolean_type& yv) { qgraph_i_base::process_boolean_iff(r, op, c, wrap(cv), x, wrap(xv), y, wrap(yv)); }

template<class T>
void qgraph_i<T>::process_boolean_iff_by(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv) { qgraph_i_base::process_boolean_iff_by(r, op, c, wrap(cv), x, wrap(xv), wrap(yv)); }

template<class T>
void qgraph_i<T>::process_boolean_iff_bx_by(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::boolean_type& xv, const typename graph_traits<T>::boolean_type& yv) { qgraph_i_base::process_boolean_iff_bx_by(r, op, c, wrap(cv), wrap(xv), wrap(yv)); }

template<class T>
void qgraph_i<T>::destroy_integer(uint64_t x) { qgraph_i_base::destroy_integer(x); }

template<class T>
void qgraph_i<T>::equal_int(uint64_t x, const typename graph_traits<T>::integer_type& xv) { qgraph_i_base::equal_int(x, wrap(xv)); }

template<class T>
void qgraph_i<T>::process_integer1(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv) { qgraph_i_base::process_integer1(r, op, x, wrap(xv)); }

template<class T>
void qgraph_i<T>::process_integer1_ix(uint64_t r, Operation op, const typename graph_traits<T>::integer_type& xv) { qgraph_i_base::process_integer1_ix(r, op, wrap(xv)); }

template<class T>
void qgraph_i<T>::process_integer2(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv) { qgraph_i_base::process_integer2(r, op, x, wrap(xv), y, wrap(yv)); }

template<class T>
void qgraph_i<T>::process_integer2_iy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv) { qgraph_i_base::process_integer2_iy(r, op, x, wrap(xv), wrap(yv)); }

template<class T>
void qgraph_i<T>::process_integer2_ix(uint64_t r, Operation op, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv) { qgraph_i_base::process_integer2_ix(r, op, wrap(xv), y, wrap(yv)); }

template<class T>
void qgraph_i<T>::process_integer2_logical(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv) { qgraph_i_base::process_integer2_logical(r, op, x, wrap(xv), y, wrap(yv)); }

template<class T>
void qgraph_i<T>::process_integer2_logical_iy(uint64_t r, Operation op, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv) { qgraph_i_base::process_integer2_logical_iy(r, op, x, wrap(xv), wrap(yv)); }

template<class T>
void qgraph_i<T>::process_integer_iff(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::integer_type& xv, uint64_t y, const typename graph_traits<T>::integer_type& yv) { qgraph_i_base::process_integer_iff(r, op, c, wrap(cv), x, wrap(xv), y, wrap(yv)); }

template<class T>
void qgraph_i<T>::process_integer_iff_iy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, uint64_t x, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv) { qgraph_i_base::process_integer_iff_iy(r, op, c, wrap(cv), x, wrap(xv), wrap(yv)); }

template<class T>
void qgraph_i<T>::process_integer_iff_ix_iy(uint64_t r, Operation op, uint64_t c, const typename graph_traits<T>::boolean_type& cv, const typename graph_traits<T>::integer_type& xv, const typename graph_traits<T>::integer_type& yv) { qgraph_i_base::process_integer_iff_ix_iy(r, op, c, wrap(cv), wrap(xv), wrap(yv)); }

#include "qgraph_prune.h"
#include "qgraph_remap.h"
#include "qgraph_lifecycle.h"

void qgraph_i_base::set_input_output_lifecycle()
{
	lifecycle_helper(m_input_map, m_output_map, m_lifecycle_input).update(m_lifecycle, now());
}

void qgraph_i_base::set_lifecycle_input(bool f)
{
	m_lifecycle_input = f;
}

template<class T>
void qgraph_i<T>::fill_scalar()
{
	m_scalar.resize(m_scalar_map.size());
	for (auto it = m_scalar_map.begin(); it != m_scalar_map.end(); ++it)
		m_scalar[it->second] = it->first;

	m_integer.resize(m_integer_map.size());
	for (auto it = m_integer_map.begin(); it != m_integer_map.end(); ++it)
		m_integer[it->second] = it->first;

	m_boolean.resize(m_boolean_map.size());
	for (auto it = m_boolean_map.begin(); it != m_boolean_map.end(); ++it)
		m_boolean[it->second] = it->first;
}

template<class T>
void qgraph_i<T>::post_process(bool remap)
{
	fill_scalar();

	// Add checkpointing indices if needed
	m_checkpoint_ops_index.insert(m_checkpoint_ops_index.begin(), 0);
	m_checkpoint_ops_arg_index.insert(m_checkpoint_ops_arg_index.begin(), 0);

	if (m_ops[m_ops.size() - 1] != CHECKPOINT)
	{
		m_checkpoint_ops_index.push_back(m_ops.size());
		m_checkpoint_ops_arg_index.push_back(m_ops_arg_index.size());
	}

	// Prune
	graph_prune<T>(*this).swap(*this);

	// Modify lifecycle of inputs and outputs
	set_input_output_lifecycle();

	if (!remap)
		return;

	// Remap indices
	graph_remap gr(m_lifecycle[QFLOATING_POINT]);
	sweep_forward(gr).swap(m_ops_arg_index, m_var_counter[QFLOATING_POINT], m_n_nonparam, m_lifecycle[QFLOATING_POINT], m_assign_map[QFLOATING_POINT], m_input_map[QFLOATING_POINT][0], m_output_map[0], m_input_output_map, m_variable_map[QFLOATING_POINT], m_variable_name_map, m_checkpoint_input[QFLOATING_POINT]);

	graph_lifecycle(*this, NONE).swap(m_wksp_size, m_wksp_index);
}


#include "qgraph_sweep.h"

template qgraph_i<double>* make_graph<double>();
template qgraph_i<float>* make_graph<float>();
#ifdef INSTANTIATE_AVX512
template qgraph_i<__m512d>* make_graph<__m512d>();
template qgraph_i<__m512>* make_graph<__m512>();
#endif
template qgraph_i<__m256d>* make_graph<__m256d>();
template qgraph_i<__m256>* make_graph<__m256>();
template qgraph_i<__m128d>* make_graph<__m128d>();
template qgraph_i<__m128>* make_graph<__m128>();
template qgraph_i<double*>* make_graph<double*>();
template qgraph_i<float*>* make_graph<float*>();
#ifdef INSTANTIATE_AVX512
template qgraph_i<__m512d*>* make_graph<__m512d*>();
template qgraph_i<__m512*>* make_graph<__m512*>();
#endif
template qgraph_i<__m256d*>* make_graph<__m256d*>();
template qgraph_i<__m256*>* make_graph<__m256*>();
template qgraph_i<__m128d*>* make_graph<__m128d*>();
template qgraph_i<__m128*>* make_graph<__m128*>();

template<class T>
qgraph_i<T>* make_graph()
{
	return new qgraph_i<T>();
}

#include "qgraph_function.h"
#include "qgraph_forward.h"
#include "qgraph_generator.h"
#include "qgraph_backward.h"
#include "qworkspace_i.h"

// Dummy out non-pointer use cases

void run_function_nvidia(int, char, char) {}
void run_function_amd(int, char, char) {}
void run_forward_nvidia(int, char, char) {}
void run_forward_amd(int, char, char) {}
void run_backward_nvidia(int, char, char, ADType) {}
void run_backward_amd(int, char, char, ADType) {}

#include "qnvidia_function.cuh"
#include "qamd_function.h"

#include "qnvidia_forward.cuh"
#include "qamd_forward.h"

#include "qnvidia_backward.cuh"
#include "qamd_backward.h"

template<class T>
void qgraph_i<T>::run(qworkspace_i<T>& ws, ADType direction) const
{
	// This logic is temporary - to be replaced with something general

	if (m_adtype.size() == 0) 
	{
		if (direction == BACKWARD)
			throw qexception("Backward mode not available for simple function");

		switch (ws.vendor())
		{
		case NVIDIA:
			{
				auto it = m_nvidia_memory.find(ws.device_number());
			 	run_function_nvidia(ws.device_number(),it->second, ws.get_gpu_memory());
			}
			break;
		case AMD:
			{
#ifndef __linux__
				auto it = m_amd_memory.find(ws.device_number());
				run_function_amd(ws.device_number(), it->second, ws.get_gpu_memory());
#endif
			}
			break;
		case CPU:
			{
				graph_function<T> gf(ws);
				sweep_forward(gf);
			}
			break;
		}
	}
	else {

		ADType adtype = m_adtype[m_adtype.size() - 1];

		if (adtype == BACKWARD)
		{
			switch (ws.vendor())
			{
			case NVIDIA:
				{
					auto it = m_nvidia_memory.find(ws.device_number());
					run_backward_nvidia(ws.device_number(), it->second, ws.get_gpu_memory(), direction);
				}
				break;
			case AMD:
				{
#ifndef __linux__
					auto it = m_amd_memory.find(ws.device_number());
					run_backward_amd(ws.device_number(), it->second, ws.get_gpu_memory(), direction);
#endif
				}
				break;
			case CPU:
				graph_backward<T>(*this, ws, direction);
				break;
			}
		}
		else
		{
			if (direction == BACKWARD)
				throw qexception("Backward mode not available for forward AD");
			switch (ws.vendor())
			{
			case NVIDIA:
				{
					auto it = m_nvidia_memory.find(ws.device_number());
					run_forward_nvidia(ws.device_number(), it->second, ws.get_gpu_memory());
				}
				break;
			case AMD:
				{
#ifndef __linux__
					auto it = m_amd_memory.find(ws.device_number());
					run_forward_amd(ws.device_number(), it->second, ws.get_gpu_memory());
#endif
				}
				break;
			case CPU:
				{
					graph_forward<T> gf(ws);
					sweep_forward(gf);
				}
				break;
			}
		}
	}
}

template<class T>
void qgraph_i<T>::forward(qworkspace_i<T>& ws, uint64_t from, uint64_t to) const
{
	run(ws, FORWARD);
}

template<class T>
void qgraph_i<T>::backward(qworkspace_i<T>& ws, uint64_t from, uint64_t to) const
{
	run(ws, BACKWARD);
}

template<class T>
void qgraph_i<T>::make_forwardAD() // we can put this in the base class as protected member
{
	m_nvidia_memory.clear();
	m_amd_memory.clear();

	uint64_t order = m_adtype.size();

	if (order > 0)
		graph_generator<T>(*this).swap(*this);

	boost::bimap<uint64_t, uint64_t> im;
	for (auto it = m_input_map[QFLOATING_POINT][0].left.begin(); it != m_input_map[QFLOATING_POINT][0].left.end(); ++it)
		if (!get_lifecycle()[QFLOATING_POINT][it->second].is_param())
			im.insert({ it->second , it->second + m_var_counter[0]});
	m_input_map[QFLOATING_POINT].push_back(im);

	boost::bimap<uint64_t, uint64_t> om;
	for (auto it = m_output_map[order].left.begin(); it != m_output_map[order].left.end(); ++it)
		if (!get_lifecycle()[QFLOATING_POINT][it->second].is_param())
			om.insert({ it->second , it->second + m_var_counter[0]});
	m_output_map.push_back(om);

	m_adtype.push_back(FORWARD);

	graph_lifecycle(*this, FORWARD).swap(m_wksp_size, m_wksp_index);

}

template<class T>
std::shared_ptr<qgraph_i<T>> qgraph_i<T>::forwardAD() const
{
	std::shared_ptr<qgraph_i<T>> i(new qgraph_i<T>(*this));
	i->make_forwardAD();
	return i;
}

template<class T>
void qgraph_i<T>::make_backwardAD() // we can put this in the base class as protected member
{
	m_nvidia_memory.clear();
	m_amd_memory.clear();

	uint64_t order = m_adtype.size();

	if (order > 0)
		graph_generator<T>(*this).swap(*this);

	m_adtype.push_back(BACKWARD);

	boost::bimap<uint64_t, uint64_t> input_map;
	for (auto it = m_output_map[order].left.begin(); it != m_output_map[order].left.end(); ++it)
		if (!m_lifecycle[QFLOATING_POINT][it->second].is_param())
			input_map.insert({ it->second , it->second + m_var_counter[0]});
	m_input_map[QFLOATING_POINT].push_back(input_map);

	boost::bimap<uint64_t, uint64_t> output_map;
	for (auto it = m_input_map[QFLOATING_POINT][0].left.begin(); it != m_input_map[QFLOATING_POINT][0].left.end(); ++it)
		if (!m_lifecycle[QFLOATING_POINT][it->second].is_param())
			output_map.insert({ it->second , it->second + m_var_counter[0]});
	m_output_map.push_back(output_map);

	// Lifecycle

	graph_lifecycle(*this, BACKWARD).swap(m_wksp_size, m_wksp_index, m_assign_map[QFLOATING_POINT], m_lifecycle, m_skip_ops_init, m_skip_ops_arg_init);

}

template<class T>
std::shared_ptr<qgraph_i<T>> qgraph_i<T>::backwardAD() const
{
	std::shared_ptr<qgraph_i<T>> i(new qgraph_i<T>(*this));
	i->make_backwardAD();
	return i;
}

#include <mutex>


std::mutex amd_mutex;
std::mutex nvidia_mutex;

// Dummy out non-pointer implementation

template<class T>
void allocate_amd(int,
	char,
	uint64_t var_counter,
	const std::vector<Operation>& ops,
	const std::vector<uint64_t>& ops_arg_index,
	const std::vector<std::vector<uint64_t>>& wksp_index,
	const std::vector<T>& scalar,
	const std::vector<typename graph_traits<T>::integer_type>& integer,
	const std::vector<typename graph_traits<T>::boolean_type>& boolean,
	const std::vector<uint64_t>& skip_ops_init,
	const std::vector<uint64_t>& skip_ops_arg_init,
	const std::vector<uint64_t>& checkpoint_ops_index,
	const std::vector<uint64_t>& checkpoint_ops_arg_index) {}

template<class T>
void allocate_nvidia(int,
	char,
	uint64_t var_counter,
	const std::vector<Operation>& ops,
	const std::vector<uint64_t>& ops_arg_index,
	const std::vector<std::vector<uint64_t>>& wksp_index,
	const std::vector<T>& scalar,
	const std::vector<typename graph_traits<T>::integer_type>& integer,
	const std::vector<typename graph_traits<T>::boolean_type>& boolean,
	const std::vector<uint64_t>& skip_ops_init,
	const std::vector<uint64_t>& skip_ops_arg_init,
	const std::vector<uint64_t>& checkpoint_ops_index,
	const std::vector<uint64_t>& checkpoint_ops_arg_index) {}

#include "qnvidia_utils.cuh"
#include "qamd_utils.h"

template<class T>
void qgraph_i<T>::allocate(qworkspace_i<T>& ws, uint64_t n)
{
	// Allocate graph memory
	
	switch (ws.vendor())
	{
	case AMD:
		{
#ifndef __linux__
			std::lock_guard<std::mutex> guard(amd_mutex);
			if (m_amd_memory.find(ws.device_number()) == m_amd_memory.end())
				allocate_amd(ws.device_number(), m_amd_memory[ws.device_number()], m_var_counter[QFLOATING_POINT], m_ops, m_ops_arg_index, m_wksp_index, m_scalar, m_integer, m_boolean, m_skip_ops_init, m_skip_ops_arg_init, m_checkpoint_ops_index, m_checkpoint_ops_arg_index);
#endif
		}
		break;
	case NVIDIA:
		{
			std::lock_guard<std::mutex> guard(nvidia_mutex);
			if (m_nvidia_memory.find(ws.device_number()) == m_nvidia_memory.end())
				allocate_nvidia(ws.device_number(), m_nvidia_memory[ws.device_number()], m_var_counter[QFLOATING_POINT], m_ops, m_ops_arg_index, m_wksp_index, m_scalar, m_integer, m_boolean, m_skip_ops_init, m_skip_ops_arg_init, m_checkpoint_ops_index, m_checkpoint_ops_arg_index);
		}
		break;
	}

	// Allocate workspace memory
	ws.allocate(n);
}
