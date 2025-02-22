#pragma once

#include "qscalar.h"
#include "qalgorithm_i.h"
#include <vector>

template<class T>
class qiterator_base_i {

	qinteger<typename qtype_traits<T>::mapped_type> m_i;
	std::vector<qscalar_const_wrapper<T>> m_v;
	std::vector<T> m_s;

public:

	qiterator_base_i(const qinteger<typename qtype_traits<T>::mapped_type>& i, const std::vector<qscalar_const_wrapper<T>>& v, const std::vector<T>& s);
	~qiterator_base_i();

	qscalar<T> operator*() const;

	qinteger<typename qtype_traits<T>::mapped_type> operator-(int64_t i) const;

};

#include "qalgorithm_i.h"

template<class T>
qiterator_base<T> make_iterator(const qinteger<typename qtype_traits<T>::mapped_type>& i, const std::vector<qscalar_const_wrapper<T>>& v, const std::vector<T>& s);




