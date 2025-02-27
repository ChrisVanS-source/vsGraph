#pragma once

#include <cstdint> // for uint64_t
#include "qscalar.h"
using namespace vstech;

template<class T>
uint64_t get_address(const qscalar<T>& x)
{
	return (uint64_t)&x;
}

template<class T>
const typename number_traits<T>::type& bracket(const T& x, const uint64_t& i)
{
	return x;
}

template<> const double& bracket<__m512d>(const __m512d& x, const uint64_t& i);
template<> const double& bracket<__m256d>(const __m256d& x, const uint64_t& i);
template<> const double& bracket<__m128d>(const __m128d& x, const uint64_t& i);
template<> const float& bracket<__m512>(const __m512& x, const uint64_t& i);
template<> const float& bracket<__m256>(const __m256& x, const uint64_t& i);
template<> const float& bracket<__m128>(const __m128& x, const uint64_t& i);

template<class T>
typename number_traits<T>::type& bracket(T& x, const uint64_t& i)
{
	return x;
}

template<> double& bracket<__m512d>(__m512d& x, const uint64_t& i);
template<> double& bracket<__m256d>(__m256d& x, const uint64_t& i);
template<> double& bracket<__m128d>(__m128d& x, const uint64_t& i);
template<> float& bracket<__m512>(__m512& x, const uint64_t& i);
template<> float& bracket<__m256>(__m256& x, const uint64_t& i);
template<> float& bracket<__m128>(__m128& x, const uint64_t& i);
