#include "qdefines.h"
#include "qalgorithm.h"
#include "qpci_pattern.h"
#include "qgraph_traits.h"
#include "qinteger_i.h"

PCI_PATTERN(qalgorithm)

template class VSGRAPH_API qalgorithm<double>;
template class VSGRAPH_API qalgorithm<float>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qalgorithm<__m512d>;
template class VSGRAPH_API qalgorithm<__m512>;
#endif
template class VSGRAPH_API qalgorithm<__m256d>;
template class VSGRAPH_API qalgorithm<__m256>;
template class VSGRAPH_API qalgorithm<__m128d>;
template class VSGRAPH_API qalgorithm<__m128>;

template<class T>
qalgorithm<T>::qalgorithm() : m_p(new qalgorithm_c<T>(std::shared_ptr<qalgorithm_i<T>>(new qalgorithm_i<T>())))
{
}

template<class T>
qiterator_base<T> qalgorithm<T>::lower_bound(const qscalar<T>& x) const
{
	return get_impl(m_p)->lower_bound(x);
}

template<class T>
qiterator_base<T> qalgorithm<T>::lower_bound(const T& x) const
{
	return get_impl(m_p)->lower_bound(x);
}

template<class T>
qiterator_base<T> qalgorithm<T>::max_element() const
{
	return get_impl(m_p)->max_element();
}

template<class T>
void qalgorithm<T>::add_compare(std::shared_ptr<qpredicate<T>> comp)
{
	get_impl(m_p)->add_compare(comp);
}

template<class T>
void qalgorithm<T>::add_element(const qscalar<T>& x)
{
	get_impl(m_p)->add_element(x);
}

template<class T>
void qalgorithm<T>::add_element(const T& x)
{
	get_impl(m_p)->add_element(x);
}

template<class T>
void qalgorithm<T>::add_element(const qnumber<typename number_traits<T>::type>& x)
{
	get_impl(m_p)->add_element(graph_traits<T>::cast(x.get_x()));
}

#include "qalgorithm_i.h"
#include "qiterator_i.h"
#include "qscalar_i.h"
#include <algorithm>
#include <cstring>

template<class T>
class qalgorithm_i {

	std::vector<qscalar_const_wrapper<T>> m_v;
	std::vector<T> m_s;
	std::shared_ptr<qpredicate<T>> m_comp;

public:

	qalgorithm_i() {}
	~qalgorithm_i() {}

	void add_element(const qscalar<T>& x)
	{
		m_v.push_back(x);
	}

	void add_element(const T& x)
	{
		m_s.push_back(x);
	}

	qiterator_base<T> lower_bound(const qscalar<T>& x) const
	{
		typedef typename qtype_traits<T>::mapped_type int_type;

		typename qinteger_traits<int_type>::storage_type s;

		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
		{
			if (m_v.size() != 0)
				integer_operation_traits<int_type>::bracket(s, j) = std::lower_bound(m_v.begin(), m_v.end(), x, [&](const qscalar_const_wrapper<T>& x, const qscalar_const_wrapper<T>& y) { return x.get_x()[j] < y.get_x()[j]; }) - m_v.begin();
			if (m_s.size() != 0)
				integer_operation_traits<int_type>::bracket(s, j) = std::lower_bound(m_s.begin(), m_s.end(), x.get_x(), [&](const T& x, const T& y) { return bracket(x, j) < bracket(y, j); }) - m_s.begin();
		}

		qinteger<int_type> i;

		memcpy(&i, &s, sizeof(qinteger<T>));

		return make_iterator(i, m_v, m_s);
	}

	qiterator_base<T> lower_bound(const T& x) const
	{
		typedef typename qtype_traits<T>::mapped_type int_type;

		typename qinteger_traits<int_type>::storage_type s;

		for (uint64_t j = 0; j < qtype_traits<T>::alignment(); ++j)
			integer_operation_traits<int_type>::bracket(s, j) = std::lower_bound(m_v.begin(), m_v.end(), x, [&](const qscalar_const_wrapper<T>& x, const T& y) { return x.get_x()[j] < bracket(y, j); }) - m_v.begin();

		qinteger<int_type> i;

		memcpy(&i, &s, sizeof(qinteger<int_type>));

		return make_iterator(i, m_v, m_s);
	}

	qiterator_base<T> max_element() const
	{
		return qiterator_base<T>();
	}

	void add_compare(std::shared_ptr<qpredicate<T>> comp)
	{
		m_comp = comp;
	}

};
