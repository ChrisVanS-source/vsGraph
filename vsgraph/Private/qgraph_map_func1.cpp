#include "qgraph_mapfunc.h"

Operation map_func1(Operation op, bool xp)
{
    switch (op)
    {
        case MAP_FUNC1(SINE);
        case MAP_FUNC1(COSINE);
        case MAP_FUNC1(TANGENT);
        case MAP_FUNC1(ARC_SINE);
        case MAP_FUNC1(ARC_COSINE);
        case MAP_FUNC1(ARC_TANGENT);
        case MAP_FUNC1(LOGARITHM);
        case MAP_FUNC1(LOGARITHM2);
        case MAP_FUNC1(LOGARITHM10);
        case MAP_FUNC1(EXPONENTIAL);
        case MAP_FUNC1(HYPERBOLIC_SINE);
        case MAP_FUNC1(HYPERBOLIC_COSINE);
        case MAP_FUNC1(HYPERBOLIC_TANGENT);
        case MAP_FUNC1(SQUAREROOT);
        case MAP_FUNC1(COMPLEMENTARY_ERRORFUNC);
        case MAP_FUNC1(CEILING);
        case MAP_FUNC1(FLOORING);
        case MAP_FUNC1(HEAVISIDE_STEP);
        case MAP_FUNC1(CHANGE_SIGN);
        case MAP_FUNC1(IFF_SCALAR);
        case MAP_FUNC1(ADD_SCALAR);
        case MAP_FUNC1(MULTIPLY_SCALAR);
        case MAP_FUNC1(SUBTRACT_SCALAR);
        case MAP_FUNC1(DIVIDE_SCALAR);
        case MAP_FUNC1(SCALAR_SUBTRACT);
        case MAP_FUNC1(SCALAR_DIVIDE);
        case MAP_FUNC1(POWER_SCALAR);
        case MAP_FUNC1(SCALAR_POWER);
        case MAP_FUNC1(MAXIMUM_SCALAR);
        case MAP_FUNC1(MINIMUM_SCALAR);
        case MAP_FUNC1(EQUAL);
        default: return UNKNOWN;
    }
}

#include <utility>

#define UNMAP_FUNC1(A) \
	A: \
		break; \
	case A##_PX: \
		xp = true; \
		new_op = A; \
		break; 

std::pair<Operation, bool> unmap_func1(Operation op)
{
    bool xp = false;
    Operation new_op = op;

    switch (op)
    {
        case UNMAP_FUNC1(SINE);
        case UNMAP_FUNC1(COSINE);
        case UNMAP_FUNC1(TANGENT);
        case UNMAP_FUNC1(ARC_SINE);
        case UNMAP_FUNC1(ARC_COSINE);
        case UNMAP_FUNC1(ARC_TANGENT);
        case UNMAP_FUNC1(LOGARITHM);
        case UNMAP_FUNC1(LOGARITHM2);
        case UNMAP_FUNC1(LOGARITHM10);
        case UNMAP_FUNC1(EXPONENTIAL);
        case UNMAP_FUNC1(HYPERBOLIC_SINE);
        case UNMAP_FUNC1(HYPERBOLIC_COSINE);
        case UNMAP_FUNC1(HYPERBOLIC_TANGENT);
        case UNMAP_FUNC1(SQUAREROOT);
        case UNMAP_FUNC1(COMPLEMENTARY_ERRORFUNC);
        case UNMAP_FUNC1(CEILING);
        case UNMAP_FUNC1(FLOORING);
        case UNMAP_FUNC1(HEAVISIDE_STEP);
        case UNMAP_FUNC1(CHANGE_SIGN);
        case UNMAP_FUNC1(IFF_SCALAR);
        case UNMAP_FUNC1(ADD_SCALAR);
        case UNMAP_FUNC1(MULTIPLY_SCALAR);
        case UNMAP_FUNC1(SUBTRACT_SCALAR);
        case UNMAP_FUNC1(DIVIDE_SCALAR);
        case UNMAP_FUNC1(SCALAR_SUBTRACT);
        case UNMAP_FUNC1(SCALAR_DIVIDE);
        case UNMAP_FUNC1(POWER_SCALAR);
        case UNMAP_FUNC1(SCALAR_POWER);
        case UNMAP_FUNC1(MAXIMUM_SCALAR);
        case UNMAP_FUNC1(MINIMUM_SCALAR);
        case UNMAP_FUNC1(EQUAL);
        default: return std::make_pair(UNKNOWN,false);
    }
    return std::make_pair(new_op, xp);
}
