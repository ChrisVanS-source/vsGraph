#pragma once

#include "qexception.h"

template<class Op>
Op& qgraph_i_base::sweep_forward(Op& visitor, uint64_t from, uint64_t to) const
{
	int64_t wksp_i = m_checkpoint_ops_arg_index[from];

	for (uint64_t i = m_checkpoint_ops_index[from]; i < m_checkpoint_ops_index[to]; ++i)
	{
		Operation op = m_ops[i];

		switch (op)
		{
//${begin}[0]
		case EQUAL_SCALAR: visitor.equal_scalar(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case EQUAL: visitor.equal(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case EQUAL_PX: visitor.equal_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case SQUAREROOT: visitor.squareroot(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case SQUAREROOT_PX: visitor.squareroot_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case CHANGE_SIGN: visitor.change_sign(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case CHANGE_SIGN_PX: visitor.change_sign_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case CEILING: visitor.ceiling(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case CEILING_PX: visitor.ceiling_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case FLOORING: visitor.flooring(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case FLOORING_PX: visitor.flooring_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case HEAVISIDE_STEP: visitor.heaviside_step(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case HEAVISIDE_STEP_PX: visitor.heaviside_step_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case EXPONENTIAL: visitor.exponential(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case EXPONENTIAL_PX: visitor.exponential_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case LOGARITHM: visitor.logarithm(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case LOGARITHM_PX: visitor.logarithm_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case LOGARITHM2: visitor.logarithm2(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case LOGARITHM2_PX: visitor.logarithm2_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case LOGARITHM10: visitor.logarithm10(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case LOGARITHM10_PX: visitor.logarithm10_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case COMPLEMENTARY_ERRORFUNC: visitor.complementary_errorfunc(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case COMPLEMENTARY_ERRORFUNC_PX: visitor.complementary_errorfunc_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case SINE: visitor.sine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case SINE_PX: visitor.sine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case COSINE: visitor.cosine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case COSINE_PX: visitor.cosine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case TANGENT: visitor.tangent(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case TANGENT_PX: visitor.tangent_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case ARC_SINE: visitor.arc_sine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case ARC_SINE_PX: visitor.arc_sine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case ARC_COSINE: visitor.arc_cosine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case ARC_COSINE_PX: visitor.arc_cosine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case ARC_TANGENT: visitor.arc_tangent(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case ARC_TANGENT_PX: visitor.arc_tangent_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case HYPERBOLIC_SINE: visitor.hyperbolic_sine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case HYPERBOLIC_SINE_PX: visitor.hyperbolic_sine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case HYPERBOLIC_COSINE: visitor.hyperbolic_cosine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case HYPERBOLIC_COSINE_PX: visitor.hyperbolic_cosine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case HYPERBOLIC_TANGENT: visitor.hyperbolic_tangent(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case HYPERBOLIC_TANGENT_PX: visitor.hyperbolic_tangent_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case ADD: visitor.add(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case ADD_PX: visitor.add_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case ADD_PY: visitor.add_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case ADD_PX_PY: visitor.add_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SUBTRACT: visitor.subtract(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SUBTRACT_PX: visitor.subtract_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SUBTRACT_PY: visitor.subtract_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SUBTRACT_PX_PY: visitor.subtract_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MULTIPLY: visitor.multiply(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MULTIPLY_PX: visitor.multiply_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MULTIPLY_PY: visitor.multiply_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MULTIPLY_PX_PY: visitor.multiply_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case DIVIDE: visitor.divide(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case DIVIDE_PX: visitor.divide_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case DIVIDE_PY: visitor.divide_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case DIVIDE_PX_PY: visitor.divide_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MAXIMUM: visitor.maximum(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MAXIMUM_PX: visitor.maximum_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MAXIMUM_PY: visitor.maximum_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MAXIMUM_PX_PY: visitor.maximum_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MINIMUM: visitor.minimum(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MINIMUM_PX: visitor.minimum_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MINIMUM_PY: visitor.minimum_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MINIMUM_PX_PY: visitor.minimum_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case POWER: visitor.power(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case POWER_PX: visitor.power_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case POWER_PY: visitor.power_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case POWER_PX_PY: visitor.power_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case ADD_SCALAR: visitor.add_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case ADD_SCALAR_PX: visitor.add_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SUBTRACT_SCALAR: visitor.subtract_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SUBTRACT_SCALAR_PX: visitor.subtract_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SCALAR_SUBTRACT: visitor.scalar_subtract(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SCALAR_SUBTRACT_PX: visitor.scalar_subtract_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MULTIPLY_SCALAR: visitor.multiply_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MULTIPLY_SCALAR_PX: visitor.multiply_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case DIVIDE_SCALAR: visitor.divide_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case DIVIDE_SCALAR_PX: visitor.divide_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SCALAR_DIVIDE: visitor.scalar_divide(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SCALAR_DIVIDE_PX: visitor.scalar_divide_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MAXIMUM_SCALAR: visitor.maximum_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MAXIMUM_SCALAR_PX: visitor.maximum_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MINIMUM_SCALAR: visitor.minimum_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case MINIMUM_SCALAR_PX: visitor.minimum_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case POWER_SCALAR: visitor.power_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case POWER_SCALAR_PX: visitor.power_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SCALAR_POWER: visitor.scalar_power(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case SCALAR_POWER_PX: visitor.scalar_power_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case GREATER_THAN: visitor.greater_than(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case LESS_THAN: visitor.less_than(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case EQUAL_TO: visitor.equal_to(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case GREATER_THAN_SCALAR: visitor.greater_than_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case LESS_THAN_SCALAR: visitor.less_than_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case EQUAL_TO_SCALAR: visitor.equal_to_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case IFF: visitor.iff(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case IFF_PX: visitor.iff_px(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case IFF_PY: visitor.iff_py(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case IFF_PX_PY: visitor.iff_px_py(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case IFF_SCALAR: visitor.iff_scalar(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case IFF_SCALAR_PX: visitor.iff_scalar_px(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case IFF_SCALAR_SCALAR: visitor.iff_scalar_scalar(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case INTEGER_EQUAL_INT: visitor.integer_equal_int(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case INTEGER_EQUAL: visitor.integer_equal(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case INTEGER_CHANGE_SIGN: visitor.integer_change_sign(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case INTEGER_ADD: visitor.integer_add(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_SUBTRACT: visitor.integer_subtract(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_MULTIPLY: visitor.integer_multiply(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_DIVIDE: visitor.integer_divide(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_ADD_INT: visitor.integer_add_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_SUBTRACT_INT: visitor.integer_subtract_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_INT_SUBTRACT: visitor.integer_int_subtract(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_MULTIPLY_INT: visitor.integer_multiply_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_DIVIDE_INT: visitor.integer_divide_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_INT_DIVIDE: visitor.integer_int_divide(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_GREATER_THAN: visitor.integer_greater_than(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_LESS_THAN: visitor.integer_less_than(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_EQUAL_TO: visitor.integer_equal_to(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_GREATER_THAN_INT: visitor.integer_greater_than_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_LESS_THAN_INT: visitor.integer_less_than_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_EQUAL_TO_INT: visitor.integer_equal_to_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case INTEGER_IFF: visitor.integer_iff(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case INTEGER_IFF_INT: visitor.integer_iff_int(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case INTEGER_IFF_INT_INT: visitor.integer_iff_int_int(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case BOOLEAN_EQUAL_BOOL: visitor.boolean_equal_bool(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case BOOLEAN_EQUAL: visitor.boolean_equal(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case BOOLEAN_NOT: visitor.boolean_not(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); wksp_i += 2; break;
		case BOOLEAN_AND: visitor.boolean_and(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case BOOLEAN_OR: visitor.boolean_or(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case BOOLEAN_EQUAL_TO: visitor.boolean_equal_to(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case BOOLEAN_AND_BOOL: visitor.boolean_and_bool(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case BOOLEAN_OR_BOOL: visitor.boolean_or_bool(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case BOOLEAN_EQUAL_TO_BOOL: visitor.boolean_equal_to_bool(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); wksp_i += 3; break;
		case BOOLEAN_IFF: visitor.boolean_iff(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case BOOLEAN_IFF_BOOL: visitor.boolean_iff_bool(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
		case BOOLEAN_IFF_BOOL_BOOL: visitor.boolean_iff_bool_bool(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); wksp_i += 4; break;
//${end} 
		case CHECKPOINT: visitor.checkpoint(i, op); break;
		default: throw vstech::qexception("Bad state");
		}
	}

	return visitor;
}

template<class Op>
Op& qgraph_i_base::sweep_forward(Op& visitor) const
{
	visitor.before_forward();

	for (uint64_t k = 0; k < m_checkpoint_ops_index.size() - 1; ++k)
		sweep_forward(visitor, k, k + 1);

	visitor.after_forward();

	return visitor;
}

template<class Op>
Op& qgraph_i_base::sweep_backward(Op& visitor, uint64_t from, uint64_t to) const
{
	int64_t wksp_i = m_checkpoint_ops_arg_index[to];

	for (uint64_t j = m_checkpoint_ops_index[from]; j < m_checkpoint_ops_index[to]; ++j)
	{
		uint64_t i = m_checkpoint_ops_index[from] + m_checkpoint_ops_index[to] - j - 1;

		Operation op = m_ops[i];

		switch (op)
		{
//${begin}[1]
		case EQUAL_SCALAR: wksp_i -= 2; visitor.equal_scalar(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case EQUAL: wksp_i -= 2; visitor.equal(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case EQUAL_PX: wksp_i -= 2; visitor.equal_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case SQUAREROOT: wksp_i -= 2; visitor.squareroot(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case SQUAREROOT_PX: wksp_i -= 2; visitor.squareroot_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case CHANGE_SIGN: wksp_i -= 2; visitor.change_sign(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case CHANGE_SIGN_PX: wksp_i -= 2; visitor.change_sign_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case CEILING: wksp_i -= 2; visitor.ceiling(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case CEILING_PX: wksp_i -= 2; visitor.ceiling_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case FLOORING: wksp_i -= 2; visitor.flooring(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case FLOORING_PX: wksp_i -= 2; visitor.flooring_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case HEAVISIDE_STEP: wksp_i -= 2; visitor.heaviside_step(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case HEAVISIDE_STEP_PX: wksp_i -= 2; visitor.heaviside_step_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case EXPONENTIAL: wksp_i -= 2; visitor.exponential(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case EXPONENTIAL_PX: wksp_i -= 2; visitor.exponential_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case LOGARITHM: wksp_i -= 2; visitor.logarithm(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case LOGARITHM_PX: wksp_i -= 2; visitor.logarithm_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case LOGARITHM2: wksp_i -= 2; visitor.logarithm2(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case LOGARITHM2_PX: wksp_i -= 2; visitor.logarithm2_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case LOGARITHM10: wksp_i -= 2; visitor.logarithm10(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case LOGARITHM10_PX: wksp_i -= 2; visitor.logarithm10_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case COMPLEMENTARY_ERRORFUNC: wksp_i -= 2; visitor.complementary_errorfunc(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case COMPLEMENTARY_ERRORFUNC_PX: wksp_i -= 2; visitor.complementary_errorfunc_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case SINE: wksp_i -= 2; visitor.sine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case SINE_PX: wksp_i -= 2; visitor.sine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case COSINE: wksp_i -= 2; visitor.cosine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case COSINE_PX: wksp_i -= 2; visitor.cosine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case TANGENT: wksp_i -= 2; visitor.tangent(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case TANGENT_PX: wksp_i -= 2; visitor.tangent_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case ARC_SINE: wksp_i -= 2; visitor.arc_sine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case ARC_SINE_PX: wksp_i -= 2; visitor.arc_sine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case ARC_COSINE: wksp_i -= 2; visitor.arc_cosine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case ARC_COSINE_PX: wksp_i -= 2; visitor.arc_cosine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case ARC_TANGENT: wksp_i -= 2; visitor.arc_tangent(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case ARC_TANGENT_PX: wksp_i -= 2; visitor.arc_tangent_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case HYPERBOLIC_SINE: wksp_i -= 2; visitor.hyperbolic_sine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case HYPERBOLIC_SINE_PX: wksp_i -= 2; visitor.hyperbolic_sine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case HYPERBOLIC_COSINE: wksp_i -= 2; visitor.hyperbolic_cosine(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case HYPERBOLIC_COSINE_PX: wksp_i -= 2; visitor.hyperbolic_cosine_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case HYPERBOLIC_TANGENT: wksp_i -= 2; visitor.hyperbolic_tangent(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case HYPERBOLIC_TANGENT_PX: wksp_i -= 2; visitor.hyperbolic_tangent_px(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case ADD: wksp_i -= 3; visitor.add(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case ADD_PX: wksp_i -= 3; visitor.add_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case ADD_PY: wksp_i -= 3; visitor.add_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case ADD_PX_PY: wksp_i -= 3; visitor.add_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SUBTRACT: wksp_i -= 3; visitor.subtract(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SUBTRACT_PX: wksp_i -= 3; visitor.subtract_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SUBTRACT_PY: wksp_i -= 3; visitor.subtract_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SUBTRACT_PX_PY: wksp_i -= 3; visitor.subtract_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MULTIPLY: wksp_i -= 3; visitor.multiply(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MULTIPLY_PX: wksp_i -= 3; visitor.multiply_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MULTIPLY_PY: wksp_i -= 3; visitor.multiply_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MULTIPLY_PX_PY: wksp_i -= 3; visitor.multiply_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case DIVIDE: wksp_i -= 3; visitor.divide(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case DIVIDE_PX: wksp_i -= 3; visitor.divide_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case DIVIDE_PY: wksp_i -= 3; visitor.divide_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case DIVIDE_PX_PY: wksp_i -= 3; visitor.divide_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MAXIMUM: wksp_i -= 3; visitor.maximum(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MAXIMUM_PX: wksp_i -= 3; visitor.maximum_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MAXIMUM_PY: wksp_i -= 3; visitor.maximum_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MAXIMUM_PX_PY: wksp_i -= 3; visitor.maximum_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MINIMUM: wksp_i -= 3; visitor.minimum(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MINIMUM_PX: wksp_i -= 3; visitor.minimum_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MINIMUM_PY: wksp_i -= 3; visitor.minimum_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MINIMUM_PX_PY: wksp_i -= 3; visitor.minimum_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case POWER: wksp_i -= 3; visitor.power(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case POWER_PX: wksp_i -= 3; visitor.power_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case POWER_PY: wksp_i -= 3; visitor.power_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case POWER_PX_PY: wksp_i -= 3; visitor.power_px_py(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case ADD_SCALAR: wksp_i -= 3; visitor.add_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case ADD_SCALAR_PX: wksp_i -= 3; visitor.add_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SUBTRACT_SCALAR: wksp_i -= 3; visitor.subtract_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SUBTRACT_SCALAR_PX: wksp_i -= 3; visitor.subtract_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SCALAR_SUBTRACT: wksp_i -= 3; visitor.scalar_subtract(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SCALAR_SUBTRACT_PX: wksp_i -= 3; visitor.scalar_subtract_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MULTIPLY_SCALAR: wksp_i -= 3; visitor.multiply_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MULTIPLY_SCALAR_PX: wksp_i -= 3; visitor.multiply_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case DIVIDE_SCALAR: wksp_i -= 3; visitor.divide_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case DIVIDE_SCALAR_PX: wksp_i -= 3; visitor.divide_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SCALAR_DIVIDE: wksp_i -= 3; visitor.scalar_divide(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SCALAR_DIVIDE_PX: wksp_i -= 3; visitor.scalar_divide_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MAXIMUM_SCALAR: wksp_i -= 3; visitor.maximum_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MAXIMUM_SCALAR_PX: wksp_i -= 3; visitor.maximum_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MINIMUM_SCALAR: wksp_i -= 3; visitor.minimum_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case MINIMUM_SCALAR_PX: wksp_i -= 3; visitor.minimum_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case POWER_SCALAR: wksp_i -= 3; visitor.power_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case POWER_SCALAR_PX: wksp_i -= 3; visitor.power_scalar_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SCALAR_POWER: wksp_i -= 3; visitor.scalar_power(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case SCALAR_POWER_PX: wksp_i -= 3; visitor.scalar_power_px(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case GREATER_THAN: wksp_i -= 3; visitor.greater_than(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case LESS_THAN: wksp_i -= 3; visitor.less_than(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case EQUAL_TO: wksp_i -= 3; visitor.equal_to(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case GREATER_THAN_SCALAR: wksp_i -= 3; visitor.greater_than_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case LESS_THAN_SCALAR: wksp_i -= 3; visitor.less_than_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case EQUAL_TO_SCALAR: wksp_i -= 3; visitor.equal_to_scalar(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case IFF: wksp_i -= 4; visitor.iff(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case IFF_PX: wksp_i -= 4; visitor.iff_px(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case IFF_PY: wksp_i -= 4; visitor.iff_py(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case IFF_PX_PY: wksp_i -= 4; visitor.iff_px_py(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case IFF_SCALAR: wksp_i -= 4; visitor.iff_scalar(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case IFF_SCALAR_PX: wksp_i -= 4; visitor.iff_scalar_px(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case IFF_SCALAR_SCALAR: wksp_i -= 4; visitor.iff_scalar_scalar(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case INTEGER_EQUAL_INT: wksp_i -= 2; visitor.integer_equal_int(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case INTEGER_EQUAL: wksp_i -= 2; visitor.integer_equal(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case INTEGER_CHANGE_SIGN: wksp_i -= 2; visitor.integer_change_sign(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case INTEGER_ADD: wksp_i -= 3; visitor.integer_add(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_SUBTRACT: wksp_i -= 3; visitor.integer_subtract(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_MULTIPLY: wksp_i -= 3; visitor.integer_multiply(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_DIVIDE: wksp_i -= 3; visitor.integer_divide(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_ADD_INT: wksp_i -= 3; visitor.integer_add_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_SUBTRACT_INT: wksp_i -= 3; visitor.integer_subtract_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_INT_SUBTRACT: wksp_i -= 3; visitor.integer_int_subtract(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_MULTIPLY_INT: wksp_i -= 3; visitor.integer_multiply_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_DIVIDE_INT: wksp_i -= 3; visitor.integer_divide_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_INT_DIVIDE: wksp_i -= 3; visitor.integer_int_divide(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_GREATER_THAN: wksp_i -= 3; visitor.integer_greater_than(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_LESS_THAN: wksp_i -= 3; visitor.integer_less_than(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_EQUAL_TO: wksp_i -= 3; visitor.integer_equal_to(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_GREATER_THAN_INT: wksp_i -= 3; visitor.integer_greater_than_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_LESS_THAN_INT: wksp_i -= 3; visitor.integer_less_than_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_EQUAL_TO_INT: wksp_i -= 3; visitor.integer_equal_to_int(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case INTEGER_IFF: wksp_i -= 4; visitor.integer_iff(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case INTEGER_IFF_INT: wksp_i -= 4; visitor.integer_iff_int(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case INTEGER_IFF_INT_INT: wksp_i -= 4; visitor.integer_iff_int_int(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case BOOLEAN_EQUAL_BOOL: wksp_i -= 2; visitor.boolean_equal_bool(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case BOOLEAN_EQUAL: wksp_i -= 2; visitor.boolean_equal(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case BOOLEAN_NOT: wksp_i -= 2; visitor.boolean_not(i, m_ops_arg_index[wksp_i + 1], op, m_ops_arg_index[wksp_i]); break;
		case BOOLEAN_AND: wksp_i -= 3; visitor.boolean_and(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case BOOLEAN_OR: wksp_i -= 3; visitor.boolean_or(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case BOOLEAN_EQUAL_TO: wksp_i -= 3; visitor.boolean_equal_to(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case BOOLEAN_AND_BOOL: wksp_i -= 3; visitor.boolean_and_bool(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case BOOLEAN_OR_BOOL: wksp_i -= 3; visitor.boolean_or_bool(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case BOOLEAN_EQUAL_TO_BOOL: wksp_i -= 3; visitor.boolean_equal_to_bool(i, m_ops_arg_index[wksp_i + 2], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1]); break;
		case BOOLEAN_IFF: wksp_i -= 4; visitor.boolean_iff(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case BOOLEAN_IFF_BOOL: wksp_i -= 4; visitor.boolean_iff_bool(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
		case BOOLEAN_IFF_BOOL_BOOL: wksp_i -= 4; visitor.boolean_iff_bool_bool(i, m_ops_arg_index[wksp_i + 3], op, m_ops_arg_index[wksp_i], m_ops_arg_index[wksp_i + 1], m_ops_arg_index[wksp_i + 2]); break;
//${end} 
		case CHECKPOINT: visitor.checkpoint(i, op); break;
		default: throw vstech::qexception("Bad state");
		}
	}

	return visitor;
}

template<class Op>
Op& qgraph_i_base::sweep_backward(Op& visitor) const
{
	return sweep_backward(visitor, visitor);
}

template<class Op, class fwdOp>
Op& qgraph_i_base::sweep_backward(Op& visitor, fwdOp& fwd_visitor) const
{
	visitor.before_backward();

	for (uint64_t k = m_checkpoint_ops_index.size(); k > 1; --k)
	{
		if (k != m_checkpoint_ops_index.size())
		{
			visitor.before_forward();
			sweep_forward(fwd_visitor, k - 2, k - 1);
			visitor.before_backward();
		}

		sweep_backward(visitor, k - 2, k - 1);
	}

	visitor.after_backward();

	return visitor;
}
