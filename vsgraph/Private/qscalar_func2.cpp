#include "qscalar_defines.h"
#include "qscalar.h"
#include "qscalar_traits.h"
using namespace vstech;

// Maximum

EXPLICIT_INSTANTATION_FUNC21_ALL(std::max)

template<class T> qscalar<T> std::max(const qscalar<T>& lhs, const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::maximum(lhs.get_x(), rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->maximum(r, lhs, rhs);

	return r;
}


EXPLICIT_INSTANTATION_FUNC22_ALL(std::max)

template<class T> qscalar<T> std::max(const qscalar<T>& lhs, const qnumber<typename number_traits<T>::type>& rhs)
{
	qscalar<T> r(scalar_traits<T>::maximum(lhs.get_x(), graph_traits<T>::cast(rhs.get_x())));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->maximum(r, lhs, graph_traits<T>::cast(rhs.get_x()));

	return r;
}

EXPLICIT_INSTANTATION_FUNC23_ALL(std::max)

template<class T> qscalar<T> std::max(const qscalar<T>& lhs, const T& rhs)
{
	qscalar<T> r(scalar_traits<T>::maximum(lhs.get_x(), rhs));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->maximum(r, lhs, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC24_ALL(std::max)

template<class T> qscalar<T> std::max(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	return std::max(rhs, lhs);
}

EXPLICIT_INSTANTATION_FUNC25_ALL(std::max)

template<class T> qscalar<T> std::max(const T& lhs, const qscalar<T>& rhs)
{
	return std::max(rhs, lhs);
}

// Minimum

EXPLICIT_INSTANTATION_FUNC21_ALL(std::min)

template<class T> qscalar<T> std::min(const qscalar<T>& lhs, const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::minimum(lhs.get_x(), rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->minimum(r, lhs, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC22_ALL(std::min)

template<class T> qscalar<T> std::min(const qscalar<T>& lhs, const qnumber<typename number_traits<T>::type>& rhs)
{
	qscalar<T> r(scalar_traits<T>::minimum(lhs.get_x(), graph_traits<T>::cast(rhs.get_x())));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->minimum(r, lhs, graph_traits<T>::cast(rhs.get_x()));

	return r;
}

EXPLICIT_INSTANTATION_FUNC23_ALL(std::min)

template<class T> qscalar<T> std::min(const qscalar<T>& lhs, const T& rhs)
{
	qscalar<T> r(scalar_traits<T>::minimum(lhs.get_x(), rhs));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->minimum(r, lhs, rhs);

	return r;
}

EXPLICIT_INSTANTATION_FUNC24_ALL(std::min)

template<class T> qscalar<T> std::min(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	return std::min(rhs, lhs);
}

EXPLICIT_INSTANTATION_FUNC25_ALL(std::min)

template<class T> qscalar<T> std::min(const T& lhs, const qscalar<T>& rhs)
{
	return std::min(rhs, lhs);
}
