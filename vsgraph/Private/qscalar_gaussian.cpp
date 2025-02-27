#include "qscalar_defines.h"
#include "qscalar.h"
#include "qscalar_traits.h"
using namespace vstech;

// Functions defined in terms of other functions

EXPLICIT_INSTANTATION_FUNC1_ALL(std::normal_cdf)

#define _USE_MATH_DEFINES
#include "math.h"

template<class T> qscalar<T> std::normal_cdf(const qscalar<T>& x)
{
	return std::erfc(-x * typename scalar_traits<T>::type(M_SQRT1_2)) * 0.5;
}
