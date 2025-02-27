#pragma once

class qgraph_i_base;

#include "qgraph_proto.h"
#include "qgraph_visitor.h"
#include "qgraph_enum.h"

class graph_lifecycle : public graph_visitor
{
	void generic_constructor(DataType vt, uint64_t x_i);
	void generic_destructor(DataType vt, uint64_t x_i);

	void constructor(uint64_t x_i);
	void destructor(uint64_t x_i);

	std::vector<uint64_t> m_wksp_size;
	std::vector<std::vector<uint64_t>> m_wksp_index;
	std::vector<std::vector<uint64_t>> m_wksp_available;
	ADType m_adtype;
	std::vector<std::vector<lifecycle>> m_lifecycle;

	std::vector<uint64_t> m_skip_ops_init;
	std::vector<uint64_t> m_skip_ops_arg_init;

	ADType m_phase;
	ADType m_direction;

	uint64_t m_var_counter;

	std::map<uint64_t, int64_t> m_assign_map; // Additional assign map elements 

	void generic_destroy_on_last_use(DataType vt, const uint64_t& x_i);

	void destroy_on_last_use(const uint64_t& x_i);

	uint64_t auxiliary(const uint64_t& x_i) const;

	uint64_t m_clock;

	class graph_node
	{
		const uint64_t& m_x;
		bool m_is_input;
		bool m_is_used;

	public:

		graph_node(const uint64_t& x, bool is_input, bool is_used) : m_x(x), m_is_input(is_input), m_is_used(is_used) {}
		~graph_node() {}

		const uint64_t& get_x() const { return m_x; }
		bool is_input() const { return m_is_input; }
		bool is_used() const { return m_is_used; }
	};

	void generic_update_lifecycle(DataType dt, const graph_node& x_i, uint64_t clock);

	void update_lifecycle(const graph_node& x_i, uint64_t clock);

	static graph_node unused_input(const uint64_t& x);
	static graph_node input(const uint64_t& x); // Default case - used input
	static graph_node output(const uint64_t& x); // Default case - unused output
	static graph_node used_output(const uint64_t& x);

public:

	graph_lifecycle(const qgraph_i_base& g, ADType adtype);
	~graph_lifecycle();

	void before_forward();
	void before_backward();
	void after_backward();

	void process_func2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_func2_logical_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_iff_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_iff_sx_sy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void process_integer2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer2_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& i_i);
	void process_integer2_logical(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer2_logical_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer_iff_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_integer_iff_ix_iy(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean1(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void process_boolean2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean2_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& i_i);
	void process_boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean_iff_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);
	void process_boolean_iff_bx_by(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i);

//${begin}
	void equal_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void equal_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void squareroot(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void squareroot_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void change_sign_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void ceiling(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void ceiling_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void flooring(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void flooring_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void heaviside_step(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void heaviside_step_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void exponential(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void exponential_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm2_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm10(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void logarithm10_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void complementary_errorfunc(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void complementary_errorfunc_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void arc_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void hyperbolic_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i);
	void add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void add_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void add_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void add_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void subtract_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void subtract_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void multiply_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void multiply_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void multiply_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void divide_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void divide_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void maximum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void maximum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void maximum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void maximum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void minimum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void minimum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void minimum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void minimum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void power_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void power_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i);
	void add_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void add_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void subtract_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void subtract_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void scalar_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void scalar_subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void multiply_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void multiply_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void divide_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void divide_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void scalar_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void scalar_divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void maximum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void maximum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void minimum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void minimum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void power_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void power_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& s_i);
	void scalar_power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
	void scalar_power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& y_i, const uint64_t& s_i);
//${end}

	void checkpoint(uint64_t clock, Operation op);

	void swap(std::vector<uint64_t>& wksp_size, std::vector<std::vector<uint64_t>>& wksp_index);
	void swap(std::vector<uint64_t>& wksp_size, std::vector<std::vector<uint64_t>>& wksp_index, std::map<uint64_t, uint64_t>& assign_map, std::vector<std::vector<lifecycle>>& lc, std::vector<uint64_t>& skip_ops_init, std::vector<uint64_t>& skip_ops_arg_init);

};
