#include "qscalar_defines.h"
#include "qscalar.h"
#include "qscalar_traits.h"
using namespace vstech;

EXPLICIT_INSTANTATION_FUNC1_ALL(std::sin)

template<class T>
qscalar<T> std::sin(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::sine(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->sine(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::cos)

template<class T>
qscalar<T> std::cos(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::cosine(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->cosine(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::tan)

template<class T>
qscalar<T> std::tan(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::tangent(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->tangent(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::asin)

template<class T>
qscalar<T> std::asin(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::arc_sine(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->arc_sine(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::acos)

template<class T>
qscalar<T> std::acos(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::arc_cosine(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->arc_cosine(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::atan)

template<class T>
qscalar<T> std::atan(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::arc_tangent(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->arc_tangent(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::log)

template<class T>
qscalar<T> std::log(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::logarithm(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->logarithm(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::log2)

template<class T>
qscalar<T> std::log2(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::logarithm2(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->logarithm2(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::log10)

template<class T>
qscalar<T> std::log10(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::logarithm10(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->logarithm10(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::exp)

template<class T>
qscalar<T> std::exp(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::exponential(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->exponential(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::sinh)

template<class T>
qscalar<T> std::sinh(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::hyperbolic_sine(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->hyperbolic_sine(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::cosh)

template<class T>
qscalar<T> std::cosh(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::hyperbolic_cosine(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->hyperbolic_cosine(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::tanh)

template<class T>
qscalar<T> std::tanh(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::hyperbolic_tangent(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->hyperbolic_tangent(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::sqrt)

template<class T>
qscalar<T> std::sqrt(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::squareroot(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->squareroot(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::erfc)

template<class T>
qscalar<T> std::erfc(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::complementary_errorfunction(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->complementary_errorfunction(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::ceil)

template<class T>
qscalar<T> std::ceil(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::ceiling(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->ceiling(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(std::floor)

template<class T>
qscalar<T> std::floor(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::flooring(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->flooring(r, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC1_ALL(vstech::heaviside)

template<class T>
qscalar<T> vstech::heaviside(const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::heaviside_step(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->heaviside_step(r, rhs);

	return r;
}

#include "qimmhss.h"

double hss(const double& x)
{
	return x == 0.0 ? 0.5 : (x >= 0.0 ? 1.0 : 0.0);
}

float hss(const float& x)
{
	return x == 0.0f ? 0.5f : (x >= 0.0f ? 1.0f : 0.0f);
}

__m512d _mm512_hss_pd(__m512d x)
{
	return _mm512_set_pd(hss(bracket(x, 7)), hss(bracket(x, 6)), hss(bracket(x, 5)), hss(bracket(x, 4)), hss(bracket(x, 3)), hss(bracket(x, 2)), hss(bracket(x, 1)), hss(bracket(x, 0)));
}

__m256d _mm256_hss_pd(__m256d x)
{
	return _mm256_set_pd(hss(bracket(x, 3)), hss(bracket(x, 2)), hss(bracket(x, 1)), hss(bracket(x, 0)));
}

__m128d _mm_hss_pd(__m128d x)
{
	return _mm_set_pd(hss(bracket(x, 1)), hss(bracket(x, 0)));
}

__m512 _mm512_hss_ps(__m512 x)
{
	return _mm512_set_ps(hss(bracket(x, 15)), hss(bracket(x, 14)), hss(bracket(x, 13)), hss(bracket(x, 12)), hss(bracket(x, 11)), hss(bracket(x, 10)), hss(bracket(x, 9)), hss(bracket(x, 8)), hss(bracket(x, 7)), hss(bracket(x, 6)), hss(bracket(x, 5)), hss(bracket(x, 4)), hss(bracket(x, 3)), hss(bracket(x, 2)), hss(bracket(x, 1)), hss(bracket(x, 0)));
}

__m256 _mm256_hss_ps(__m256 x)
{
	return _mm256_set_ps(hss(bracket(x, 7)), hss(bracket(x, 6)), hss(bracket(x, 5)), hss(bracket(x, 4)), hss(bracket(x, 3)), hss(bracket(x, 2)), hss(bracket(x, 1)), hss(bracket(x, 0)));
}

__m128 _mm_hss_ps(__m128 x)
{
	return _mm_set_ps(hss(bracket(x, 3)), hss(bracket(x, 2)), hss(bracket(x, 1)), hss(bracket(x, 0)));
}

