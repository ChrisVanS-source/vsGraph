#pragma once

#include "intrin.h"
#include <algorithm>
#include <cmath>
#include "qimmhss.h"

//${begin}
template<class T>
struct scalar_traits
{
	typedef T type;
	static unsigned short alignment() { return 1; }

	static T change_sign(const T& x) { return -x; }
	static T add(const T& x, const T& y) { return x + y; }
	static T subtract(const T& x, const T& y) { return x - y; }
	static T multiply(const T& x, const T& y) { return x * y; }
	static T divide(const T& x, const T& y) { return x / y; }
	static T sine(const T& x) { return sin(x); }
	static T cosine(const T& x) { return cos(x); }
	static T tangent(const T& x) { return tan(x); }
	static T arc_sine(const T& x) { return asin(x); }
	static T arc_cosine(const T& x) { return acos(x); }
	static T arc_tangent(const T& x) { return atan(x); }
	static T logarithm(const T& x) { return log(x); }
	static T logarithm2(const T& x) { return log2(x); }
	static T logarithm10(const T& x) { return log10(x); }
	static T exponential(const T& x) { return exp(x); }
	static T hyperbolic_sine(const T& x) { return sinh(x); }
	static T hyperbolic_cosine(const T& x) { return cosh(x); }
	static T hyperbolic_tangent(const T& x) { return tanh(x); }
	static T squareroot(const T& x) { return sqrt(x); }
	static T complementary_errorfunction(const T& x) { return erfc(x); }
	static T ceiling(const T& x) { return ceil(x); }
	static T flooring(const T& x) { return floor(x); }
	static T heaviside_step(const T& x) { return x == (T)0.0 ? (T)0.5 : (x > (T)0.0 ? (T)1.0 : (T)0.0); }
	static T power(const T& x, const T& y) { return std::pow(x, y); }
	static T maximum(const T& x, const T& y) { return std::max(x, y); }
	static T minimum(const T& x, const T& y) { return std::min(x, y); }
};

template<>
struct scalar_traits<__m512d>
{
	typedef double type;
	static unsigned short alignment() { return 8; }

	static __m512d change_sign(const __m512d& x) { return _mm512_sub_pd(_mm512_set1_pd(0), x); }
	static __m512d add(const __m512d& x, const __m512d& y) { return _mm512_add_pd(x, y); }
	static __m512d subtract(const __m512d& x, const __m512d& y) { return _mm512_sub_pd(x, y); }
	static __m512d multiply(const __m512d& x, const __m512d& y) { return _mm512_mul_pd(x, y); }
	static __m512d divide(const __m512d& x, const __m512d& y) { return _mm512_div_pd(x, y); }
	static __m512d sine(const __m512d& x) { return _mm512_sin_pd(x); }
	static __m512d cosine(const __m512d& x) { return _mm512_cos_pd(x); }
	static __m512d tangent(const __m512d& x) { return _mm512_tan_pd(x); }
	static __m512d arc_sine(const __m512d& x) { return _mm512_asin_pd(x); }
	static __m512d arc_cosine(const __m512d& x) { return _mm512_acos_pd(x); }
	static __m512d arc_tangent(const __m512d& x) { return _mm512_atan_pd(x); }
	static __m512d logarithm(const __m512d& x) { return _mm512_log_pd(x); }
	static __m512d logarithm2(const __m512d& x) { return _mm512_log2_pd(x); }
	static __m512d logarithm10(const __m512d& x) { return _mm512_log10_pd(x); }
	static __m512d exponential(const __m512d& x) { return _mm512_exp_pd(x); }
	static __m512d hyperbolic_sine(const __m512d& x) { return _mm512_sinh_pd(x); }
	static __m512d hyperbolic_cosine(const __m512d& x) { return _mm512_cosh_pd(x); }
	static __m512d hyperbolic_tangent(const __m512d& x) { return _mm512_tanh_pd(x); }
	static __m512d squareroot(const __m512d& x) { return _mm512_sqrt_pd(x); }
	static __m512d complementary_errorfunction(const __m512d& x) { return _mm512_erfc_pd(x); }
	static __m512d ceiling(const __m512d& x) { return _mm512_ceil_pd(x); }
	static __m512d flooring(const __m512d& x) { return _mm512_floor_pd(x); }
	static __m512d heaviside_step(const __m512d& x) { return _mm512_hss_pd(x); }
	static __m512d power(const __m512d& x, const __m512d& y) { return _mm512_pow_pd(x, y); }
	static __m512d maximum(const __m512d& x, const __m512d& y) { return _mm512_max_pd(x, y); }
	static __m512d minimum(const __m512d& x, const __m512d& y) { return _mm512_min_pd(x, y); }
};

template<>
struct scalar_traits<__m512>
{
	typedef float type;
	static unsigned short alignment() { return 16; }

	static __m512 change_sign(const __m512& x) { return _mm512_sub_ps(_mm512_set1_ps(0), x); }
	static __m512 add(const __m512& x, const __m512& y) { return _mm512_add_ps(x, y); }
	static __m512 subtract(const __m512& x, const __m512& y) { return _mm512_sub_ps(x, y); }
	static __m512 multiply(const __m512& x, const __m512& y) { return _mm512_mul_ps(x, y); }
	static __m512 divide(const __m512& x, const __m512& y) { return _mm512_div_ps(x, y); }
	static __m512 sine(const __m512& x) { return _mm512_sin_ps(x); }
	static __m512 cosine(const __m512& x) { return _mm512_cos_ps(x); }
	static __m512 tangent(const __m512& x) { return _mm512_tan_ps(x); }
	static __m512 arc_sine(const __m512& x) { return _mm512_asin_ps(x); }
	static __m512 arc_cosine(const __m512& x) { return _mm512_acos_ps(x); }
	static __m512 arc_tangent(const __m512& x) { return _mm512_atan_ps(x); }
	static __m512 logarithm(const __m512& x) { return _mm512_log_ps(x); }
	static __m512 logarithm2(const __m512& x) { return _mm512_log2_ps(x); }
	static __m512 logarithm10(const __m512& x) { return _mm512_log10_ps(x); }
	static __m512 exponential(const __m512& x) { return _mm512_exp_ps(x); }
	static __m512 hyperbolic_sine(const __m512& x) { return _mm512_sinh_ps(x); }
	static __m512 hyperbolic_cosine(const __m512& x) { return _mm512_cosh_ps(x); }
	static __m512 hyperbolic_tangent(const __m512& x) { return _mm512_tanh_ps(x); }
	static __m512 squareroot(const __m512& x) { return _mm512_sqrt_ps(x); }
	static __m512 complementary_errorfunction(const __m512& x) { return _mm512_erfc_ps(x); }
	static __m512 ceiling(const __m512& x) { return _mm512_ceil_ps(x); }
	static __m512 flooring(const __m512& x) { return _mm512_floor_ps(x); }
	static __m512 heaviside_step(const __m512& x) { return _mm512_hss_ps(x); }
	static __m512 power(const __m512& x, const __m512& y) { return _mm512_pow_ps(x, y); }
	static __m512 maximum(const __m512& x, const __m512& y) { return _mm512_max_ps(x, y); }
	static __m512 minimum(const __m512& x, const __m512& y) { return _mm512_min_ps(x, y); }
};

template<>
struct scalar_traits<__m256d>
{
	typedef double type;
	static unsigned short alignment() { return 4; }

	static __m256d change_sign(const __m256d& x) { return _mm256_sub_pd(_mm256_set1_pd(0), x); }
	static __m256d add(const __m256d& x, const __m256d& y) { return _mm256_add_pd(x, y); }
	static __m256d subtract(const __m256d& x, const __m256d& y) { return _mm256_sub_pd(x, y); }
	static __m256d multiply(const __m256d& x, const __m256d& y) { return _mm256_mul_pd(x, y); }
	static __m256d divide(const __m256d& x, const __m256d& y) { return _mm256_div_pd(x, y); }
	static __m256d sine(const __m256d& x) { return _mm256_sin_pd(x); }
	static __m256d cosine(const __m256d& x) { return _mm256_cos_pd(x); }
	static __m256d tangent(const __m256d& x) { return _mm256_tan_pd(x); }
	static __m256d arc_sine(const __m256d& x) { return _mm256_asin_pd(x); }
	static __m256d arc_cosine(const __m256d& x) { return _mm256_acos_pd(x); }
	static __m256d arc_tangent(const __m256d& x) { return _mm256_atan_pd(x); }
	static __m256d logarithm(const __m256d& x) { return _mm256_log_pd(x); }
	static __m256d logarithm2(const __m256d& x) { return _mm256_log2_pd(x); }
	static __m256d logarithm10(const __m256d& x) { return _mm256_log10_pd(x); }
	static __m256d exponential(const __m256d& x) { return _mm256_exp_pd(x); }
	static __m256d hyperbolic_sine(const __m256d& x) { return _mm256_sinh_pd(x); }
	static __m256d hyperbolic_cosine(const __m256d& x) { return _mm256_cosh_pd(x); }
	static __m256d hyperbolic_tangent(const __m256d& x) { return _mm256_tanh_pd(x); }
	static __m256d squareroot(const __m256d& x) { return _mm256_sqrt_pd(x); }
	static __m256d complementary_errorfunction(const __m256d& x) { return _mm256_erfc_pd(x); }
	static __m256d ceiling(const __m256d& x) { return _mm256_ceil_pd(x); }
	static __m256d flooring(const __m256d& x) { return _mm256_floor_pd(x); }
	static __m256d heaviside_step(const __m256d& x) { return _mm256_hss_pd(x); }
	static __m256d power(const __m256d& x, const __m256d& y) { return _mm256_pow_pd(x, y); }
	static __m256d maximum(const __m256d& x, const __m256d& y) { return _mm256_max_pd(x, y); }
	static __m256d minimum(const __m256d& x, const __m256d& y) { return _mm256_min_pd(x, y); }
};

template<>
struct scalar_traits<__m256>
{
	typedef float type;
	static unsigned short alignment() { return 8; }

	static __m256 change_sign(const __m256& x) { return _mm256_sub_ps(_mm256_set1_ps(0), x); }
	static __m256 add(const __m256& x, const __m256& y) { return _mm256_add_ps(x, y); }
	static __m256 subtract(const __m256& x, const __m256& y) { return _mm256_sub_ps(x, y); }
	static __m256 multiply(const __m256& x, const __m256& y) { return _mm256_mul_ps(x, y); }
	static __m256 divide(const __m256& x, const __m256& y) { return _mm256_div_ps(x, y); }
	static __m256 sine(const __m256& x) { return _mm256_sin_ps(x); }
	static __m256 cosine(const __m256& x) { return _mm256_cos_ps(x); }
	static __m256 tangent(const __m256& x) { return _mm256_tan_ps(x); }
	static __m256 arc_sine(const __m256& x) { return _mm256_asin_ps(x); }
	static __m256 arc_cosine(const __m256& x) { return _mm256_acos_ps(x); }
	static __m256 arc_tangent(const __m256& x) { return _mm256_atan_ps(x); }
	static __m256 logarithm(const __m256& x) { return _mm256_log_ps(x); }
	static __m256 logarithm2(const __m256& x) { return _mm256_log2_ps(x); }
	static __m256 logarithm10(const __m256& x) { return _mm256_log10_ps(x); }
	static __m256 exponential(const __m256& x) { return _mm256_exp_ps(x); }
	static __m256 hyperbolic_sine(const __m256& x) { return _mm256_sinh_ps(x); }
	static __m256 hyperbolic_cosine(const __m256& x) { return _mm256_cosh_ps(x); }
	static __m256 hyperbolic_tangent(const __m256& x) { return _mm256_tanh_ps(x); }
	static __m256 squareroot(const __m256& x) { return _mm256_sqrt_ps(x); }
	static __m256 complementary_errorfunction(const __m256& x) { return _mm256_erfc_ps(x); }
	static __m256 ceiling(const __m256& x) { return _mm256_ceil_ps(x); }
	static __m256 flooring(const __m256& x) { return _mm256_floor_ps(x); }
	static __m256 heaviside_step(const __m256& x) { return _mm256_hss_ps(x); }
	static __m256 power(const __m256& x, const __m256& y) { return _mm256_pow_ps(x, y); }
	static __m256 maximum(const __m256& x, const __m256& y) { return _mm256_max_ps(x, y); }
	static __m256 minimum(const __m256& x, const __m256& y) { return _mm256_min_ps(x, y); }

};

template<>
struct scalar_traits<__m128d>
{
	typedef double type;
	static unsigned short alignment() { return 2; }

	static __m128d change_sign(const __m128d& x) { return _mm_sub_pd(_mm_set1_pd(0), x); }
	static __m128d add(const __m128d& x, const __m128d& y) { return _mm_add_pd(x, y); }
	static __m128d subtract(const __m128d& x, const __m128d& y) { return _mm_sub_pd(x, y); }
	static __m128d multiply(const __m128d& x, const __m128d& y) { return _mm_mul_pd(x, y); }
	static __m128d divide(const __m128d& x, const __m128d& y) { return _mm_div_pd(x, y); }
	static __m128d sine(const __m128d& x) { return _mm_sin_pd(x); }
	static __m128d cosine(const __m128d& x) { return _mm_cos_pd(x); }
	static __m128d tangent(const __m128d& x) { return _mm_tan_pd(x); }
	static __m128d arc_sine(const __m128d& x) { return _mm_asin_pd(x); }
	static __m128d arc_cosine(const __m128d& x) { return _mm_acos_pd(x); }
	static __m128d arc_tangent(const __m128d& x) { return _mm_atan_pd(x); }
	static __m128d logarithm(const __m128d& x) { return _mm_log_pd(x); }
	static __m128d logarithm2(const __m128d& x) { return _mm_log2_pd(x); }
	static __m128d logarithm10(const __m128d& x) { return _mm_log10_pd(x); }
	static __m128d exponential(const __m128d& x) { return _mm_exp_pd(x); }
	static __m128d hyperbolic_sine(const __m128d& x) { return _mm_sinh_pd(x); }
	static __m128d hyperbolic_cosine(const __m128d& x) { return _mm_cosh_pd(x); }
	static __m128d hyperbolic_tangent(const __m128d& x) { return _mm_tanh_pd(x); }
	static __m128d squareroot(const __m128d& x) { return _mm_sqrt_pd(x); }
	static __m128d complementary_errorfunction(const __m128d& x) { return _mm_erfc_pd(x); }
	static __m128d ceiling(const __m128d& x) { return _mm_ceil_pd(x); }
	static __m128d flooring(const __m128d& x) { return _mm_floor_pd(x); }
	static __m128d heaviside_step(const __m128d& x) { return _mm_hss_pd(x); }
	static __m128d power(const __m128d& x, const __m128d& y) { return _mm_pow_pd(x, y); }
	static __m128d maximum(const __m128d& x, const __m128d& y) { return _mm_max_pd(x, y); }
	static __m128d minimum(const __m128d& x, const __m128d& y) { return _mm_min_pd(x, y); }
};

template<>
struct scalar_traits<__m128>
{
	typedef float type;
	static unsigned short alignment() { return 4; }

	static __m128 change_sign(const __m128& x) { return _mm_sub_ps(_mm_set1_ps(0), x); }
	static __m128 add(const __m128& x, const __m128& y) { return _mm_add_ps(x, y); }
	static __m128 subtract(const __m128& x, const __m128& y) { return _mm_sub_ps(x, y); }
	static __m128 multiply(const __m128& x, const __m128& y) { return _mm_mul_ps(x, y); }
	static __m128 divide(const __m128& x, const __m128& y) { return _mm_div_ps(x, y); }
	static __m128 sine(const __m128& x) { return _mm_sin_ps(x); }
	static __m128 cosine(const __m128& x) { return _mm_cos_ps(x); }
	static __m128 tangent(const __m128& x) { return _mm_tan_ps(x); }
	static __m128 arc_sine(const __m128& x) { return _mm_asin_ps(x); }
	static __m128 arc_cosine(const __m128& x) { return _mm_acos_ps(x); }
	static __m128 arc_tangent(const __m128& x) { return _mm_atan_ps(x); }
	static __m128 logarithm(const __m128& x) { return _mm_log_ps(x); }
	static __m128 logarithm2(const __m128& x) { return _mm_log2_ps(x); }
	static __m128 logarithm10(const __m128& x) { return _mm_log10_ps(x); }
	static __m128 exponential(const __m128& x) { return _mm_exp_ps(x); }
	static __m128 hyperbolic_sine(const __m128& x) { return _mm_sinh_ps(x); }
	static __m128 hyperbolic_cosine(const __m128& x) { return _mm_cosh_ps(x); }
	static __m128 hyperbolic_tangent(const __m128& x) { return _mm_tanh_ps(x); }
	static __m128 squareroot(const __m128& x) { return _mm_sqrt_ps(x); }
	static __m128 complementary_errorfunction(const __m128& x) { return _mm_erfc_ps(x); }
	static __m128 ceiling(const __m128& x) { return _mm_ceil_ps(x); }
	static __m128 flooring(const __m128& x) { return _mm_floor_ps(x); }
	static __m128 heaviside_step(const __m128& x) { return _mm_hss_ps(x); }
	static __m128 power(const __m128& x, const __m128& y) { return _mm_pow_ps(x, y); }
	static __m128 maximum(const __m128& x, const __m128& y) { return _mm_max_ps(x, y); }
	static __m128 minimum(const __m128& x, const __m128& y) { return _mm_min_ps(x, y); }
};
//${end}