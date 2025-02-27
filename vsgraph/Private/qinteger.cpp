#include "qdefines.h"
#include "qboolean_i.h"
#include "qinteger_i.h"
using namespace vstech;

template class VSGRAPH_API qinteger<double>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qinteger<__m512d>;
template class VSGRAPH_API qinteger<__m512>;
#endif
template class VSGRAPH_API qinteger<__m256d>;
template class VSGRAPH_API qinteger<__m256>;
template class VSGRAPH_API qinteger<__m128d>;
template class VSGRAPH_API qinteger<__m128>;

#include "qrecorder_i.h"

// Constructor

template<class T>
qinteger<T>::qinteger()
{}

template<class T>
qinteger<T>::qinteger(const int64_t& i)
{
	integer_operation_traits<T>::assign(m_i, i);
}


template<class T>
qinteger<T>::qinteger(const qinteger<T>& rhs)
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::assign(m_i, rhs.m_i);

	if (recorder)
		recorder->equal(*this,rhs);

}

// Destructor

template<class T>
qinteger<T>::~qinteger()
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->destroy(*this);
}

// Operator = 

template<class T>
qinteger<T>& qinteger<T>::operator=(const qinteger<T>& rhs)
{
	if (&rhs != this)
	{
		integer_operation_traits<T>::assign(m_i, rhs.m_i);

		auto recorder = recorder_ptr<T>();

		if (recorder)
			recorder->equal(*this, rhs);

	}

	return *this;
}

template<class T>
qinteger<T>& qinteger<T>::operator=(int64_t i)
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::assign(m_i, i);

	if (recorder)
		recorder->equal_int(*this,graph_traits<T>::cast(i));

	return *this;
}


// Basic arithmetic operations

#include <cstring>

template<class T>
qinteger<T> qinteger<T>::operator+(const qinteger<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::add(i.m_i, m_i, rhs.m_i);
	
	if (recorder)
		recorder->add(i, *this, rhs);

	return i;

}


template<class T>
qinteger<T> qinteger<T>::operator-(const qinteger<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::subtract(i.m_i, m_i, rhs.m_i);

	if (recorder)
		recorder->subtract(i, *this, rhs);

	return i;
}

template<class T>
qinteger<T> qinteger<T>::operator*(const qinteger<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::multiply(i.m_i, m_i, rhs.m_i);

	if (recorder)
		recorder->multiply(i, *this, rhs);

	return i;
}

template<class T>
qinteger<T> qinteger<T>::operator/(const qinteger<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::divide(i.m_i, m_i, rhs.m_i);

	if (recorder)
		recorder->divide(i, *this, rhs);

	return i;
}

template<class T>
qinteger<T>& qinteger<T>::operator+=(const qinteger<T>& rhs)
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::add(m_i, m_i, rhs.m_i);

	if (recorder)
		recorder->add(*this,rhs);

	return *this;
}

template<class T>
qinteger<T>& qinteger<T>::operator-=(const qinteger<T>& rhs)
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::subtract(m_i, m_i, rhs.m_i);

	if (recorder)
		recorder->subtract(*this, rhs);

	return *this;
}

template<class T>
qinteger<T>& qinteger<T>::operator*=(const qinteger<T>& rhs)
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::multiply(m_i, m_i, rhs.m_i);

	if (recorder)
		recorder->multiply(*this, rhs);

	return *this;
}

template<class T>
qinteger<T>& qinteger<T>::operator/=(const qinteger<T>& rhs)
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::divide(m_i, m_i, rhs.m_i);

	if (recorder)
		recorder->divide(*this, rhs);

	return *this;
}

template<class T>
qinteger<T> qinteger<T>::operator+(const int64_t& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::add(i.m_i, m_i, rhs);

	if (recorder)
		recorder->add(i,*this, graph_traits<T>::cast(rhs));

	return i;
}

template<class T>
qinteger<T> qinteger<T>::operator-(const int64_t& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::subtract(i.m_i, m_i, rhs);

	if (recorder)
		recorder->subtract(i,*this, graph_traits<T>::cast(rhs));

	return i;
}

template<class T>
qinteger<T> qinteger<T>::operator*(const int64_t& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::multiply(i.m_i, m_i, rhs);

	if (recorder)
		recorder->multiply(i,*this, graph_traits<T>::cast(rhs));

	return i;
}

template<class T>
qinteger<T> qinteger<T>::operator/(const int64_t& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::divide(i.m_i, m_i, rhs);

	if (recorder)
		recorder->divide(i,*this, graph_traits<T>::cast(rhs));

	return i;
}

template<class T>
qinteger<T>& qinteger<T>::operator+=(const int64_t& rhs)
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::add(m_i, m_i, rhs);

	if (recorder)
		recorder->add(*this, graph_traits<T>::cast(rhs));

	return *this;
}

template<class T>
qinteger<T>& qinteger<T>::operator-=(const int64_t& rhs)
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::subtract(m_i, m_i, rhs);

	if (recorder)
		recorder->subtract(*this, graph_traits<T>::cast(rhs));

	return *this;
}

template<class T>
qinteger<T>& qinteger<T>::operator*=(const int64_t& rhs)
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::multiply(m_i, m_i, rhs);

	if (recorder)
		recorder->multiply(*this, graph_traits<T>::cast(rhs));

	return *this;
}

template<class T>
qinteger<T>& qinteger<T>::operator/=(const int64_t& rhs)
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::divide(m_i, m_i, rhs);

	if (recorder)
		recorder->divide(*this, graph_traits<T>::cast(rhs));

	return *this;
}

// Change sign

template<class T>
qinteger<T> qinteger<T>::operator-() const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::chs(i.m_i, m_i);

	if (recorder)
		recorder->change_sign(i, *this);

	return i;
}

// Increment and decrement

template<class T>
qinteger<T>& qinteger<T>::operator++()
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::add(m_i, m_i, 1);

	if (recorder)
		recorder->add(*this, graph_traits<T>::cast((int64_t)1));

	return *this;
}

template<class T>
qinteger<T> qinteger<T>::operator++(int) const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::add(i.m_i, m_i, 1);

	if (recorder)
		recorder->add(i,*this, graph_traits<T>::cast((int64_t)1));

	return i;
}

template<class T>
qinteger<T>& qinteger<T>::operator--()
{
	auto recorder = recorder_ptr<T>();

	integer_operation_traits<T>::subtract(m_i, m_i, 1);

	if (recorder)
		recorder->subtract(*this, graph_traits<T>::cast((int64_t)1));

	return *this;
}

template<class T>
qinteger<T> qinteger<T>::operator--(int) const
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;
	integer_operation_traits<T>::subtract(i.m_i, m_i, 1);

	if (recorder)
		recorder->subtract(i,*this, graph_traits<T>::cast((int64_t)1));

	return i;
}

// Comparison operators

template<class T>
qboolean<T> qinteger<T>::operator==(const qinteger<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> b;
	typename qboolean_traits<T>::storage_type s = integer_operation_traits<T>::equal(m_i, rhs.m_i);
	memcpy(&b, &s, sizeof(qboolean<T>));

	if (recorder)
		recorder->equal_to(b, *this, rhs);

	return b;
}

template<class T>
qboolean<T> qinteger<T>::operator!=(const qinteger<T>& rhs) const
{
	return !(*this == rhs);
}

template<class T>
qboolean<T> qinteger<T>::operator>(const qinteger<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> b;
	typename qboolean_traits<T>::storage_type s = integer_operation_traits<T>::greater_than(m_i, rhs.m_i);
	memcpy(&b, &s, sizeof(qboolean<T>));

	if (recorder)
		recorder->greater_than(b, *this, rhs);

	return b;
}

template<class T>
qboolean<T> qinteger<T>::operator>=(const qinteger<T>& rhs) const
{
	return !(*this < rhs);
}

template<class T>
qboolean<T> qinteger<T>::operator<(const qinteger<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> b;
	typename qboolean_traits<T>::storage_type s = integer_operation_traits<T>::less_than(m_i, rhs.m_i);
	memcpy(&b, &s, sizeof(qboolean<T>));

	if (recorder)
		recorder->less_than(b, *this, rhs);

	return b;
}

template<class T>
qboolean<T> qinteger<T>::operator<=(const qinteger<T>& rhs) const
{
	return !(*this > rhs);
}

template<class T>
qboolean<T> qinteger<T>::operator==(const int64_t& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> b;
	typename qboolean_traits<T>::storage_type s = integer_operation_traits<T>::equal(m_i, rhs);
	memcpy(&b, &s, sizeof(qboolean<T>));

	if (recorder)
		recorder->equal_to(b, *this, graph_traits<T>::cast(rhs));

	return b;
}

template<class T>
qboolean<T> qinteger<T>::operator!=(const int64_t& rhs) const
{
	return !(*this == rhs);
}

template<class T>
qboolean<T> qinteger<T>::operator>(const int64_t& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> b;
	typename qboolean_traits<T>::storage_type s = integer_operation_traits<T>::greater_than(m_i, rhs);
	memcpy(&b, &s, sizeof(qboolean<T>));

	if (recorder)
		recorder->greater_than(b, *this, graph_traits<T>::cast(rhs));

	return b;
}

template<class T>
qboolean<T> qinteger<T>::operator>=(const int64_t& rhs) const
{
	return !(*this < rhs);
}

template<class T>
qboolean<T> qinteger<T>::operator<(const int64_t& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> b;
	typename qboolean_traits<T>::storage_type s = integer_operation_traits<T>::less_than(m_i, rhs);
	memcpy(&b, &s, sizeof(qboolean<T>));

	if (recorder)
		recorder->less_than(b, *this, graph_traits<T>::cast(rhs));

	return b;
}

template<class T>
qboolean<T> qinteger<T>::operator<=(const int64_t& rhs) const
{
	return !(*this > rhs);
}

// [] operator

template<class T>
const int64_t& qinteger<T>::operator[](const uint64_t& i) const
{
	return integer_operation_traits<T>::bracket(m_i, i);
}

template<class T>
int64_t& qinteger<T>::operator[](const uint64_t& i)
{
	return integer_operation_traits<T>::bracket(m_i, i);
}

#define EXPLICIT_INSTANTATION1(name,T) \
template qinteger<T> VSGRAPH_API name<T>(const int64_t& lhs, const qinteger<T>& rhs);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION1_ALL(name) \
EXPLICIT_INSTANTATION1(name,double) \
EXPLICIT_INSTANTATION1(name,__m512d) \
EXPLICIT_INSTANTATION1(name,__m512) \
EXPLICIT_INSTANTATION1(name,__m256d) \
EXPLICIT_INSTANTATION1(name,__m256) \
EXPLICIT_INSTANTATION1(name,__m128d) \
EXPLICIT_INSTANTATION1(name,__m128) 
#else
#define EXPLICIT_INSTANTATION1_ALL(name) \
EXPLICIT_INSTANTATION1(name,double) \
EXPLICIT_INSTANTATION1(name,__m256d) \
EXPLICIT_INSTANTATION1(name,__m256) \
EXPLICIT_INSTANTATION1(name,__m128d) \
EXPLICIT_INSTANTATION1(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION2(name,T) \
template qboolean<T> VSGRAPH_API name <T>(const int64_t& lhs, const qinteger<T>& rhs);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION2_ALL(name) \
EXPLICIT_INSTANTATION2(name,double) \
EXPLICIT_INSTANTATION2(name,__m512d) \
EXPLICIT_INSTANTATION2(name,__m512) \
EXPLICIT_INSTANTATION2(name,__m256d) \
EXPLICIT_INSTANTATION2(name,__m256) \
EXPLICIT_INSTANTATION2(name,__m128d) \
EXPLICIT_INSTANTATION2(name,__m128) 
#else
#define EXPLICIT_INSTANTATION2_ALL(name) \
EXPLICIT_INSTANTATION2(name,double) \
EXPLICIT_INSTANTATION2(name,__m256d) \
EXPLICIT_INSTANTATION2(name,__m256) \
EXPLICIT_INSTANTATION2(name,__m128d) \
EXPLICIT_INSTANTATION2(name,__m128) 
#endif


EXPLICIT_INSTANTATION1_ALL(operator+)

template<class T> qinteger<T> operator+(const int64_t& lhs, const qinteger<T>& rhs)
{
	return rhs + lhs;
}

EXPLICIT_INSTANTATION1_ALL(operator-)

template<class T> qinteger<T> operator-(const int64_t& x, const qinteger<T>& y)
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;

	typename qinteger_traits<T>::storage_type rhs;
	memcpy(&rhs, &y, sizeof(qinteger<T>));

	typename qinteger_traits<T>::storage_type s;
	integer_operation_traits<T>::subtract(s, x, rhs);
	memcpy(&i, &s, sizeof(qinteger<T>));

	if (recorder)
		recorder->subtract(i, graph_traits<T>::cast(x), y);

	return i;
}

EXPLICIT_INSTANTATION1_ALL(operator*)

template<class T> qinteger<T> operator*(const int64_t& lhs, const qinteger<T>& rhs)
{
	return rhs*lhs;
}

EXPLICIT_INSTANTATION1_ALL(operator/)

template<class T> qinteger<T> operator/(const int64_t& x, const qinteger<T>& y)
{
	auto recorder = recorder_ptr<T>();

	qinteger<T> i;

	typename qinteger_traits<T>::storage_type rhs;
	memcpy(&rhs, &y, sizeof(qinteger<T>));

	typename qinteger_traits<T>::storage_type s;
	integer_operation_traits<T>::divide(s, x, rhs);
	memcpy(&i, &s, sizeof(qinteger<T>));
	
	if (recorder)
		recorder->divide(i, graph_traits<T>::cast(x), y);

	return i;
}

EXPLICIT_INSTANTATION2_ALL(operator==)

template<class T> qboolean<T> operator==(const int64_t& lhs, const qinteger<T>& rhs)
{
	return rhs == lhs;
}

EXPLICIT_INSTANTATION2_ALL(operator!=)

template<class T> qboolean<T> operator!=(const int64_t& lhs, const qinteger<T>& rhs)
{
	return rhs != lhs;
}

EXPLICIT_INSTANTATION2_ALL(operator>)

template<class T> qboolean<T> operator>(const int64_t& lhs, const qinteger<T>& rhs)
{
	return rhs < lhs;
}

EXPLICIT_INSTANTATION2_ALL(operator>=)

template<class T> qboolean<T> operator>=(const int64_t& lhs, const qinteger<T>& rhs)
{
	return rhs <= lhs;
}

EXPLICIT_INSTANTATION2_ALL(operator<)

template<class T> qboolean<T> operator<(const int64_t& lhs, const qinteger<T>& rhs)
{
	return rhs > lhs;
}

EXPLICIT_INSTANTATION2_ALL(operator<=)

template<class T> qboolean<T> operator<=(const int64_t& lhs, const qinteger<T>& rhs)
{
	return rhs >= lhs;
}


#define EXPLICIT_INSTANTATION_IFF1(name,T) \
template qinteger<T> VSGRAPH_API name<T>(const qboolean<T>& cond, const qinteger<T>& if_true, const qinteger<T>& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF1_ALL(name) \
EXPLICIT_INSTANTATION_IFF1(name,double) \
EXPLICIT_INSTANTATION_IFF1(name,__m512d) \
EXPLICIT_INSTANTATION_IFF1(name,__m512) \
EXPLICIT_INSTANTATION_IFF1(name,__m256d) \
EXPLICIT_INSTANTATION_IFF1(name,__m256) \
EXPLICIT_INSTANTATION_IFF1(name,__m128d) \
EXPLICIT_INSTANTATION_IFF1(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF1_ALL(name) \
EXPLICIT_INSTANTATION_IFF1(name,double) \
EXPLICIT_INSTANTATION_IFF1(name,__m256d) \
EXPLICIT_INSTANTATION_IFF1(name,__m256) \
EXPLICIT_INSTANTATION_IFF1(name,__m128d) \
EXPLICIT_INSTANTATION_IFF1(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_IFF2(name,T) \
template qinteger<T> VSGRAPH_API name<T>(const qboolean<T>& cond, const qinteger<T>& if_true, const int64_t& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF2_ALL(name) \
EXPLICIT_INSTANTATION_IFF2(name,double) \
EXPLICIT_INSTANTATION_IFF2(name,__m512d) \
EXPLICIT_INSTANTATION_IFF2(name,__m512) \
EXPLICIT_INSTANTATION_IFF2(name,__m256d) \
EXPLICIT_INSTANTATION_IFF2(name,__m256) \
EXPLICIT_INSTANTATION_IFF2(name,__m128d) \
EXPLICIT_INSTANTATION_IFF2(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF2_ALL(name) \
EXPLICIT_INSTANTATION_IFF2(name,double) \
EXPLICIT_INSTANTATION_IFF2(name,__m256d) \
EXPLICIT_INSTANTATION_IFF2(name,__m256) \
EXPLICIT_INSTANTATION_IFF2(name,__m128d) \
EXPLICIT_INSTANTATION_IFF2(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_IFF3(name,T) \
template qinteger<T> VSGRAPH_API name<T>(const qboolean<T>& cond, const int64_t& if_true, const qinteger<T>& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF3_ALL(name) \
EXPLICIT_INSTANTATION_IFF3(name,double) \
EXPLICIT_INSTANTATION_IFF3(name,__m512d) \
EXPLICIT_INSTANTATION_IFF3(name,__m512) \
EXPLICIT_INSTANTATION_IFF3(name,__m256d) \
EXPLICIT_INSTANTATION_IFF3(name,__m256) \
EXPLICIT_INSTANTATION_IFF3(name,__m128d) \
EXPLICIT_INSTANTATION_IFF3(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF3_ALL(name) \
EXPLICIT_INSTANTATION_IFF3(name,double) \
EXPLICIT_INSTANTATION_IFF3(name,__m256d) \
EXPLICIT_INSTANTATION_IFF3(name,__m256) \
EXPLICIT_INSTANTATION_IFF3(name,__m128d) \
EXPLICIT_INSTANTATION_IFF3(name,__m128) 
#endif

EXPLICIT_INSTANTATION_IFF1_ALL(qif)

template<class T>
qinteger<T> qif(const qboolean<T>& cond, const qinteger<T>& if_true, const qinteger<T>& if_false)
{
	auto recorder = recorder_ptr<T>();

	typename qboolean_traits<T>::storage_type condition;
	memcpy(&condition, &cond, sizeof(qboolean<T>));

	typename qinteger_traits<T>::storage_type iftrue;
	memcpy(&iftrue, &if_true, sizeof(qinteger<T>));

	typename qinteger_traits<T>::storage_type iffalse;
	memcpy(&iffalse, &if_false, sizeof(qinteger<T>));

	qinteger<T> i;

	typename qinteger_traits<T>::storage_type r;
	integer_operation_traits<T>::qif(r, condition, iftrue, iffalse);

	memcpy(&i, &r, sizeof(qinteger<T>));

	if (recorder)
		recorder->iff(i, cond, iftrue, iffalse);

	return i;
}

EXPLICIT_INSTANTATION_IFF2_ALL(qif)

template<class T>
qinteger<T> qif(const qboolean<T>& cond, const qinteger<T>& if_true, const int64_t& if_false)
{
	auto recorder = recorder_ptr<T>();

	typename qboolean_traits<T>::storage_type condition;
	memcpy(&condition, &cond, sizeof(qboolean<T>));

	typename qinteger_traits<T>::storage_type iftrue;
	memcpy(&iftrue, &if_true, sizeof(qinteger<T>));

	qinteger<T> i;

	typename qinteger_traits<T>::storage_type r;
	integer_operation_traits<T>::qif(r, condition, iftrue, if_false);

	memcpy(&i, &r, sizeof(qinteger<T>));

	if (recorder)
		recorder->iff(i, cond, iftrue, graph_traits<T>::cast(if_false));

	return i;
}

EXPLICIT_INSTANTATION_IFF3_ALL(qif)

template<class T>
qinteger<T> qif(const qboolean<T>& cond, const int64_t& if_true, const qinteger<T>& if_false)
{
	return qif(!cond, if_false, if_true);
}

template<class T>
qinteger<T> qif(const qboolean<T>& cond, const int64_t& if_true, const int64_t& if_false)
{
	auto recorder = recorder_ptr<T>();

	typename qboolean_traits<T>::storage_type condition;
	memcpy(&condition, &cond, sizeof(qboolean<T>));

	qinteger<T> i;

	typename qinteger_traits<T>::storage_type r;
	integer_operation_traits<T>::qif(r, condition, if_true, if_false);

	memcpy(&i, &r, sizeof(qinteger<T>));

	if (recorder)
		recorder->iff(i, cond, graph_traits<T>::cast(if_true), graph_traits<T>::cast(if_false));

	return i;
}
