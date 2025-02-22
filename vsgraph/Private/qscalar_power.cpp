#include "qscalar_defines.h"
#include "qscalar.h"
#include "qscalar_traits.h"
using namespace vstech;

// Power

EXPLICIT_INSTANTATION_FUNC21_ALL(std::pow)

template<class T> qscalar<T> std::pow(const qscalar<T>& lhs, const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::power(lhs.get_x(), rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->power(r, lhs, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC22_ALL(std::pow)

template<class T> qscalar<T> std::pow(const qscalar<T>& lhs, const qnumber<typename number_traits<T>::type>& rhs)
{
	qscalar<T> r(scalar_traits<T>::power(lhs.get_x(), graph_traits<T>::cast(rhs.get_x())));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->power(r, lhs, graph_traits<T>::cast(rhs.get_x()));

	return r;
}

EXPLICIT_INSTANTATION_FUNC23_ALL(std::pow)

template<class T> qscalar<T> std::pow(const qscalar<T>& lhs, const T& rhs)
{
	qscalar<T> r(scalar_traits<T>::power(lhs.get_x(), rhs));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->power(r, lhs, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC24_ALL(std::pow)

template<class T> qscalar<T> std::pow(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::power(graph_traits<T>::cast(lhs.get_x()), rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->power(r, graph_traits<T>::cast(lhs.get_x()), rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC25_ALL(std::pow)

template<class T> qscalar<T> std::pow(const T& lhs, const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::power(lhs, rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->power(r, lhs, rhs);

	return r;
}
