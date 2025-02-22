#include "qdefines.h"
#include "qiterator.h"
#include "qpci_pattern.h"

PCI_PATTERN(qiterator_base)

template class VSGRAPH_API qiterator_base<double>;
template class VSGRAPH_API qiterator_base<float>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qiterator_base<__m512d>;
template class VSGRAPH_API qiterator_base<__m512>;
#endif
template class VSGRAPH_API qiterator_base<__m256d>;
template class VSGRAPH_API qiterator_base<__m256>;
template class VSGRAPH_API qiterator_base<__m128d>;
template class VSGRAPH_API qiterator_base<__m128>;

#include "qiterator_i.h"

template<class T>
qiterator_base<T>::qiterator_base() : m_p(0)
{
}

template<class T>
qinteger<typename qtype_traits<T>::mapped_type> qiterator_base<T>::operator-(int64_t i) const
{
	return get_impl(m_p)->operator-(i);
}

template<class T>
qscalar<T> qiterator_base<T>::operator*() const
{
	return get_impl(m_p)->operator*();
}

#define EXPLICIT_INSTANTIATION(T) \
template qiterator_base<T> make_iterator<T>(const qinteger<typename qtype_traits<T>::mapped_type>& i, const std::vector<qscalar_const_wrapper<T>>& v, const std::vector<T>& s);

EXPLICIT_INSTANTIATION(double)
EXPLICIT_INSTANTIATION(float)
#ifdef INSTANTIATE_AVX512
EXPLICIT_INSTANTIATION(__m512d)
EXPLICIT_INSTANTIATION(__m512)
#endif
EXPLICIT_INSTANTIATION(__m256d)
EXPLICIT_INSTANTIATION(__m256)
EXPLICIT_INSTANTIATION(__m128d)
EXPLICIT_INSTANTIATION(__m128)

#include <cstring>

template<class T>
qiterator_base<T> make_iterator(const qinteger<typename qtype_traits<T>::mapped_type>& i, const std::vector<qscalar_const_wrapper<T>>& v, const std::vector<T>& s)
{
	typedef typename qtype_traits<T>::mapped_type int_type;
	qiterator_base<T> it;
	qiterator_base_p<T>* p = new qiterator_base_c<T>(std::shared_ptr<qiterator_base_i<T>>(new qiterator_base_i<T>(i,v,s)));
	memcpy(&it, &p, sizeof(qiterator_base<T>));
	return it;
}

template<class T>
qiterator_base_i<T>::qiterator_base_i(const qinteger<typename qtype_traits<T>::mapped_type>& i, const std::vector<qscalar_const_wrapper<T>>& v, const std::vector<T>& s) : m_i(i), m_v(v), m_s(s) 
{
}

template<class T>
qiterator_base_i<T>::~qiterator_base_i() 
{
}

#include "qscalar_i.h"

template<class T>
qscalar<T> qiterator_base_i<T>::operator*() const
{
	qscalar<T> x;
	for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
	{
		if (m_s.size() > 0)
			x[i] = bracket(m_s[m_i[i]], i);
		if (m_v.size() > 0)
			x[i] = m_v[m_i[i]].get_x()[i];
	}

	return x;
}

template<class T>
qinteger<typename qtype_traits<T>::mapped_type> qiterator_base_i<T>::operator-(int64_t i) const
{
	return m_i - i;
}




