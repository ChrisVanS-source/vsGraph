#pragma once

#include <vector>
#include "qscalar.h"
#include "qinteger.h"

template<class T>
class qvector : public std::vector<qscalar<T>> {

public:

	qvector() {}
	~qvector() {}

	qvector(const qvector<T>& rhs) : std::vector<qscalar<T>>(rhs) {}

	qvector<T>& operator=(const qvector<T>& rhs)
	{
		std::vector<qscalar<T>>::operator=(rhs);
		return *this;
	}

	const qscalar<T>& operator[](size_t i) const
	{
		return std::vector<qscalar<T>>::operator[](i);
	}

	qscalar<T>& operator[](size_t i)
	{
		return std::vector<qscalar<T>>::operator[](i);
	}

	qscalar<T> operator[](const qinteger<T>& i)
	{
		return qscalar<T>();
	}

};
