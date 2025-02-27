#include "qgraph_prune.h"
#include "qexception.h"
#include "qgraph_enum.h"
using namespace vstech;

std::vector<unsigned short> graph_prune_base::get_signature(const lifecycle& lc) const
{
	Operation op = m_ops_orig[lc.created()];

	switch (op)
	{
//${begin}
	case EQUAL_SCALAR:
		return { XXX,QFLOATING_POINT,1 };

	case FWD_FUNC1(EQUAL):
	case FWD_FUNC1(SQUAREROOT):
	case FWD_FUNC1(CHANGE_SIGN):
	case FWD_FUNC1(CEILING):
	case FWD_FUNC1(FLOORING):
	case FWD_FUNC1(HEAVISIDE_STEP):
	case FWD_FUNC1(EXPONENTIAL):
	case FWD_FUNC1(LOGARITHM):
	case FWD_FUNC1(LOGARITHM2):
	case FWD_FUNC1(LOGARITHM10):
	case FWD_FUNC1(COMPLEMENTARY_ERRORFUNC):
	case FWD_FUNC1(SINE):
	case FWD_FUNC1(COSINE):
	case FWD_FUNC1(TANGENT):
	case FWD_FUNC1(ARC_SINE):
	case FWD_FUNC1(ARC_COSINE):
	case FWD_FUNC1(ARC_TANGENT):
	case FWD_FUNC1(HYPERBOLIC_SINE):
	case FWD_FUNC1(HYPERBOLIC_COSINE):
	case FWD_FUNC1(HYPERBOLIC_TANGENT):
		return { QFLOATING_POINT,QFLOATING_POINT,1 };

	case FWD_FUNC2(ADD):
	case FWD_FUNC2(SUBTRACT):
	case FWD_FUNC2(MULTIPLY):
	case FWD_FUNC2(DIVIDE):
	case FWD_FUNC2(MAXIMUM):
	case FWD_FUNC2(MINIMUM):
	case FWD_FUNC2(POWER):
		return { QFLOATING_POINT,QFLOATING_POINT,QFLOATING_POINT,1 };

	case FWD_FUNC1(ADD_SCALAR):
	case FWD_FUNC1(SUBTRACT_SCALAR):
	case FWD_FUNC1(MULTIPLY_SCALAR):
	case FWD_FUNC1(DIVIDE_SCALAR):
	case FWD_FUNC1(MAXIMUM_SCALAR):
	case FWD_FUNC1(MINIMUM_SCALAR):
	case FWD_FUNC1(POWER_SCALAR):
		return { QFLOATING_POINT, XXX, QFLOATING_POINT, 1 };

	case FWD_FUNC1(SCALAR_SUBTRACT):
	case FWD_FUNC1(SCALAR_DIVIDE):
	case FWD_FUNC1(SCALAR_POWER):
		return { XXX, QFLOATING_POINT, QFLOATING_POINT, 1 };

	case GREATER_THAN:
	case LESS_THAN:
	case EQUAL_TO:
		return { QFLOATING_POINT,QFLOATING_POINT,QBOOLEAN,1 };

	case GREATER_THAN_SCALAR:
	case LESS_THAN_SCALAR:
	case EQUAL_TO_SCALAR:
		return { QFLOATING_POINT,XXX,QBOOLEAN,1 };

	case FWD_FUNC2(IFF):
		return { QBOOLEAN,QFLOATING_POINT,QFLOATING_POINT,QFLOATING_POINT,1 };

	case FWD_FUNC1(IFF_SCALAR):
		return { QBOOLEAN,QFLOATING_POINT,XXX,QFLOATING_POINT,1 };

	case IFF_SCALAR_SCALAR:
		return { QBOOLEAN,XXX,XXX,QFLOATING_POINT,1 };

	case INTEGER_EQUAL_INT:
		return { XXX, QINTEGER, 1 };

	case INTEGER_EQUAL:
	case INTEGER_CHANGE_SIGN:
		return { QINTEGER,QINTEGER,1 };

	case INTEGER_ADD:
	case INTEGER_SUBTRACT:
	case INTEGER_MULTIPLY:
	case INTEGER_DIVIDE:
		return { QINTEGER, QINTEGER, QINTEGER, 1 };

	case INTEGER_ADD_INT:
	case INTEGER_SUBTRACT_INT:
	case INTEGER_MULTIPLY_INT:
	case INTEGER_DIVIDE_INT:
		return { QINTEGER, XXX, QINTEGER, 1 };

	case INTEGER_INT_SUBTRACT:
	case INTEGER_INT_DIVIDE:
		return { XXX, QINTEGER, QINTEGER, 1 };

	case INTEGER_GREATER_THAN:
	case INTEGER_LESS_THAN:
	case INTEGER_EQUAL_TO:
		return { QINTEGER, QINTEGER, QBOOLEAN, 1 };

	case INTEGER_GREATER_THAN_INT:
	case INTEGER_LESS_THAN_INT:
	case INTEGER_EQUAL_TO_INT:
		return { QINTEGER, XXX, QBOOLEAN, 1 };

	case INTEGER_IFF:
		return { QBOOLEAN, QINTEGER, QINTEGER, QINTEGER, 1 };

	case INTEGER_IFF_INT:
		return { QBOOLEAN, QINTEGER, XXX, QINTEGER, 1 };

	case INTEGER_IFF_INT_INT:
		return { QBOOLEAN, XXX, XXX, QINTEGER, 1 };

	case BOOLEAN_EQUAL_BOOL:
		return { XXX, QBOOLEAN, 1 };

	case BOOLEAN_EQUAL:
	case BOOLEAN_NOT:
		return { QBOOLEAN,QBOOLEAN,1 };

	case BOOLEAN_AND:
	case BOOLEAN_OR:
	case BOOLEAN_EQUAL_TO:
		return { QBOOLEAN,QBOOLEAN,QBOOLEAN,1 };

	case BOOLEAN_AND_BOOL:
	case BOOLEAN_OR_BOOL:
	case BOOLEAN_EQUAL_TO_BOOL:
		return { QBOOLEAN,XXX,QBOOLEAN,1 };

	case BOOLEAN_IFF:
		return { QBOOLEAN, QBOOLEAN, QBOOLEAN, QBOOLEAN, 1 };

	case BOOLEAN_IFF_BOOL:
		return { QBOOLEAN, QBOOLEAN, XXX, QBOOLEAN, 1 };

	case BOOLEAN_IFF_BOOL_BOOL:
		return { QBOOLEAN, XXX, XXX, QBOOLEAN, 1 };

//${end}

	case STD_LOWER_BOUND_SCALAR:
		return { 0,1,1 }; // For now, this is fine because STD_LOWER_BOUND_SCALAR only takes 1 input (qscalar<T>) and output an integer (qinteger<T>)
#if 0
	case BRACKET:
	{
		// 1 integer input, m_algo_dim[lc.m_info]-1 qscalar<T> inputs, 1 qscalar<T> output 
		// Thus size of vector should be 1 + (m_algo_dim[lc.m_info]-1) + 1 (for output type) + 1 (for size)
		std::vector<size_t> signature;
		signature.push_back(1); // Integer
		signature.resize(m_algo_dim[lc.m_info] + 1, 0); // (m_algo_dim[lc.m_info]-1) inputs + 1 output on top of original size 1 vector
		signature.push_back(1); // 1 output
		return signature;
	}

	case FUNCTION:
	{
		std::vector<size_t> signature(m_func_dim[lc.m_info] + m_func_dim[lc.m_info + 1], 0);
		signature.push_back(m_func_dim[lc.m_info + 1]);
		return signature;
	}
#endif

	}

	throw qexception("Unknown operation");

	return std::vector<unsigned short>();
}
