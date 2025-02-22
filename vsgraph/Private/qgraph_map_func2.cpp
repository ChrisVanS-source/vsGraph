#include "qgraph_mapfunc.h"

Operation map_func2(Operation op, bool xp, bool yp)
{
	switch (op)
	{
		case MAP_FUNC2(ADD);
		case MAP_FUNC2(MULTIPLY);
		case MAP_FUNC2(DIVIDE);
		case MAP_FUNC2(SUBTRACT);
		case MAP_FUNC2(MAXIMUM);
		case MAP_FUNC2(MINIMUM);
		case MAP_FUNC2(POWER);
		case MAP_FUNC2(IFF);
		default: return UNKNOWN;
	}
}

#define UNMAP_FUNC2_X(A) \
	A: \
	case A##_PX: \
	case A##_PY: \
	case A##_PX_PY: \
		return op == A##_PX || op == A##_PX_PY;

#define UNMAP_FUNC2_Y(A) \
	A: \
	case A##_PX: \
	case A##_PY: \
	case A##_PX_PY: \
		return op == A##_PY || op == A##_PX_PY;

bool is_func2_x_param(Operation op)
{
	switch (op)
	{
		case UNMAP_FUNC2_X(ADD);
		case UNMAP_FUNC2_X(MULTIPLY);
		case UNMAP_FUNC2_X(DIVIDE);
		case UNMAP_FUNC2_X(SUBTRACT);
		case UNMAP_FUNC2_X(MAXIMUM);
		case UNMAP_FUNC2_X(MINIMUM);
		case UNMAP_FUNC2_X(POWER);
		case UNMAP_FUNC2_X(IFF);
		default: return false;
	}
}

bool is_func2_y_param(Operation op)
{
	switch (op)
	{
		case UNMAP_FUNC2_Y(ADD);
		case UNMAP_FUNC2_Y(MULTIPLY);
		case UNMAP_FUNC2_Y(DIVIDE);
		case UNMAP_FUNC2_Y(SUBTRACT);
		case UNMAP_FUNC2_Y(MAXIMUM);
		case UNMAP_FUNC2_Y(MINIMUM);
		case UNMAP_FUNC2_Y(POWER);
		case UNMAP_FUNC2_Y(IFF);
		default: return false;
	}
}

#include <tuple>

#define UNMAP_FUNC2(A) \
	A: \
		break; \
	case A##_PX: \
		xp = true; \
		new_op = A; \
		break; \
	case A##_PY: \
		yp = true; \
		new_op = A; \
		break; \
	case A##_PX_PY: \
		xp = yp = true; \
		new_op = A; \
		break;


std::tuple<Operation, bool, bool> unmap_func2(Operation op)
{
	bool xp = false;
	bool yp = false;
	Operation new_op = op;

	switch (op)
	{
	case UNMAP_FUNC2(ADD);
	case UNMAP_FUNC2(MULTIPLY);
	case UNMAP_FUNC2(DIVIDE);
	case UNMAP_FUNC2(SUBTRACT);
	case UNMAP_FUNC2(MAXIMUM);
	case UNMAP_FUNC2(MINIMUM);
	case UNMAP_FUNC2(POWER);
	case UNMAP_FUNC2(IFF);
	default: return std::make_tuple(UNKNOWN,false,false);
	}

	return std::make_tuple(new_op, xp, yp);
}

std::pair<Operation, bool> unmap_func2_scalar(Operation op)
{
	return unmap_func1(op);
}
