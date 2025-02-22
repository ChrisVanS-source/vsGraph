#pragma once

#include <ostream>
#include "qtype_traits.h"

namespace vstech
{
	template<class T>
	class qscalar;

	template<class T>
	class qinteger;

	template<class T>
	class qboolean;
}

template<class T>
inline std::ostream& operator<<(std::ostream& os, const vstech::qscalar<T>& x)
{
	auto dim = vstech::qtype_traits<T>::alignment();
	if (dim > 1) os << "[";
	for (uint64_t i = 0; i < dim; ++i)
	{
		if (i > 0) os << ",";
		os << x[i];
	}
	if (dim > 1) os << "]";
	return os;
}

template<class T>
inline std::ostream& operator<<(std::ostream& os, const vstech::qinteger<T>& x)
{
	auto dim = vstech::qtype_traits<T>::alignment();
	if (dim > 1) os << "[";
	for (uint64_t i = 0; i < dim; ++i)
	{
		if (i > 0) os << ",";
		os << x[i];
	}
	if (dim > 1) os << "]";
	return os;
}

template<class T>
inline std::ostream& operator<<(std::ostream& os, const vstech::qboolean<T>& x)
{
	auto dim = vstech::qtype_traits<T>::alignment();
	if (dim > 1) os << "[";
	for (uint64_t i = 0; i < dim; ++i)
	{
		if (i > 0) os << ",";
		os << x[i];
	}
	if (dim > 1) os << "]";
	return os;
}
