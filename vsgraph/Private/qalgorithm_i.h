#pragma once

#include "qscalar.h"
using namespace vstech;

template<class T>
class qscalar_const_wrapper {

	const qscalar<T>& m_x;

public:

	qscalar_const_wrapper(const qscalar<T>& x) : m_x(x) {}
	~qscalar_const_wrapper() {}

	const qscalar<T>& get_x() const { return m_x; }

};


