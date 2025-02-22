#include "qdefines.h"
#include "qboolean.h"
#include "qexception.h"
using namespace vstech;

template class VSGRAPH_API qboolean<double>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qboolean<__m512d>;
template class VSGRAPH_API qboolean<__m512>;
#endif
template class VSGRAPH_API qboolean<__m256d>;
template class VSGRAPH_API qboolean<__m256>;
template class VSGRAPH_API qboolean<__m128d>;
template class VSGRAPH_API qboolean<__m128>;

template class VSGRAPH_API qbool_ref<double>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qbool_ref<__m512d>;
template class VSGRAPH_API qbool_ref<__m512>;
#endif
template class VSGRAPH_API qbool_ref<__m256d>;
template class VSGRAPH_API qbool_ref<__m256>;
template class VSGRAPH_API qbool_ref<__m128d>;
template class VSGRAPH_API qbool_ref<__m128>;

#include "qboolean_i.h"

qboolean_i::qboolean_i(const uint64_t& dim, const bool& b) : m_b(dim, b) 
{
}

qboolean_i::qboolean_i(const std::vector<bool>& b) : m_b(b) 
{
}

qboolean_i::~qboolean_i() 
{
}

const std::vector<bool>& qboolean_i::get_b() const 
{ 
	return m_b; 
}

std::vector<bool>& qboolean_i::get_b() 
{ 
	return m_b; 
}

template<class T>
struct logical_traits {

	static qboolean_p* create(const bool& b)
	{
		return new qboolean_i(qtype_traits<T>::alignment(), b);
	}

	static qboolean_p* copy(const qboolean_p* p)
	{
		return new qboolean_i(dynamic_cast<const qboolean_i*>(p)->get_b());
	}

	static void destroy(qboolean_p* p)
	{
		if (p)
			delete p;
	}

	static bool bracket(const qboolean_p* p, const uint64_t& i)
	{
		return dynamic_cast<const qboolean_i*>(p)->get_b()[i];
	}

	static qbool_ref<T> ref(qboolean_p* p, const uint64_t& i)
	{
		return qbool_ref<T>(p, i);
	}

	static void assign(qboolean_p* p, bool f, const uint64_t& i)
	{
		dynamic_cast<qboolean_i*>(p)->get_b()[i] = f;
	}

	static qboolean_p* logical_and(qboolean_p* lhs_p, qboolean_p* rhs_p)
	{
		std::vector<bool> r = dynamic_cast<const qboolean_i*>(lhs_p)->get_b();
		const auto& rhs = dynamic_cast<const qboolean_i*>(rhs_p)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = r[i] && rhs[i];
		return new qboolean_i(r);
	}

	static qboolean_p* logical_and(qboolean_p* lhs_p, bool rhs)
	{
		std::vector<bool> r = dynamic_cast<const qboolean_i*>(lhs_p)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = r[i] && rhs;
		return new qboolean_i(r);
	}

	static qboolean_p* logical_or(qboolean_p* lhs_p, qboolean_p* rhs_p)
	{
		std::vector<bool> r = dynamic_cast<const qboolean_i*>(lhs_p)->get_b();
		const auto& rhs = dynamic_cast<const qboolean_i*>(rhs_p)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = r[i] || rhs[i];
		return new qboolean_i(r);
	}

	static qboolean_p* logical_or(qboolean_p* lhs_p, bool rhs)
	{
		std::vector<bool> r = dynamic_cast<const qboolean_i*>(lhs_p)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = r[i] || rhs;
		return new qboolean_i(r);
	}

	static qboolean_p* logical_not(qboolean_p* rhs_p)
	{
		std::vector<bool> r = dynamic_cast<const qboolean_i*>(rhs_p)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = !r[i];
		return new qboolean_i(r);
	}

	static qboolean_p* equal(qboolean_p* lhs_p, qboolean_p* rhs_p)
	{
		std::vector<bool> r = dynamic_cast<const qboolean_i*>(lhs_p)->get_b();
		const auto& rhs = dynamic_cast<const qboolean_i*>(rhs_p)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = r[i] == rhs[i];
		return new qboolean_i(r);
	}

	static qboolean_p* equal(qboolean_p* lhs_p, bool rhs)
	{
		std::vector<bool> r = dynamic_cast<const qboolean_i*>(lhs_p)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = r[i] == rhs;
		return new qboolean_i(r);
	}

	static qboolean_p* qif(const qboolean_p* cond, const qboolean_p* if_true, const qboolean_p* if_false)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		const auto& condition = dynamic_cast<const qboolean_i*>(cond)->get_b();
		const auto& iftrue = dynamic_cast<const qboolean_i*>(if_true)->get_b();
		const auto& iffalse = dynamic_cast<const qboolean_i*>(if_false)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = condition[i] ? iftrue[i] : iffalse[i];
		return new qboolean_i(r);
	}

	static qboolean_p* qif(const qboolean_p* cond, const qboolean_p* if_true, bool iffalse)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		const auto& condition = dynamic_cast<const qboolean_i*>(cond)->get_b();
		const auto& iftrue = dynamic_cast<const qboolean_i*>(if_true)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = condition[i] ? iftrue[i] : iffalse;
		return new qboolean_i(r);
	}

	static qboolean_p* qif(const qboolean_p* cond, bool iftrue, bool iffalse)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());
		const auto& condition = dynamic_cast<const qboolean_i*>(cond)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = condition[i] ? iftrue : iffalse;
		return new qboolean_i(r);
	}

};

template<>
struct logical_traits<double> {

	static const bool& create(const bool& b)
	{
		return b;
	}

	static bool copy(const bool& p)
	{
		return p;
	}

	static void destroy(const bool&)
	{
	}

	static const bool& bracket(const bool& b, const uint64_t& i)
	{
		return b;
	}

	static bool& bracket(bool& b, const uint64_t& i)
	{
		return b;
	}

	static qbool_ref<double> ref(bool& p, const uint64_t& i)
	{
		return qbool_ref<double>(p, i);
	}

	static void assign(bool& b, bool f, const uint64_t& i)
	{
		b = f;
	}

	static bool logical_and(bool lhs, bool rhs)
	{
		return lhs && rhs;
	}

	static bool logical_or(bool lhs, bool rhs)
	{
		return lhs || rhs;
	}

	static bool logical_not(bool rhs)
	{
		return !rhs;
	}

	static bool equal(bool lhs, bool rhs)
	{
		return lhs == rhs;
	}

	static bool qif(bool cond, bool if_true, bool if_false)
	{
		return cond ? if_true : if_false;
	}

};

template<class T>
qboolean<T>::qboolean(bool f) : m_b(logical_traits<T>::create(f))
{}

template<class T>
qboolean<T>::operator bool() const
{
	throw qexception("Conversion of qlogical to bool not allowed");
	return false;
}

#include "qrecorder_i.h"

template<class T>
qboolean<T>::qboolean(const qboolean<T>& rhs) : m_b(logical_traits<T>::copy(rhs.m_b))
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->equal(*this, rhs);
}

template<class T>
qboolean<T>::~qboolean()
{
	auto recorder = recorder_ptr<T>();

	logical_traits<T>::destroy(m_b);

	if (recorder)
		recorder->destroy(*this);

}

template<class T>
qboolean<T>& qboolean<T>::operator=(const qboolean<T>& rhs)
{
	if (&rhs != this)
	{
		logical_traits<T>::destroy(m_b);
		m_b = logical_traits<T>::copy(rhs.m_b);

		auto recorder = recorder_ptr<T>();

		if (recorder)
			recorder->equal(*this, rhs);

	}
	return *this;
}

template<class T>
qboolean<T>& qboolean<T>::operator=(bool rhs)
{
	logical_traits<T>::destroy(m_b);
	m_b = logical_traits<T>::create(rhs);

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->equal_bool(*this, graph_traits<T>::cast(rhs));

	return *this;
}


template<class T>
bool qboolean<T>::operator[](const uint64_t& i) const
{
	return logical_traits<T>::bracket(m_b, i);
}

template<class T>
qbool_ref<T>::qbool_ref(typename qboolean_traits<T>::storage_type_ref ref, const uint64_t& i) : m_ref(ref), m_i(i)
{
}

template<class T>
qbool_ref<T>::~qbool_ref()
{}


template<class T>
qbool_ref<T>& qbool_ref<T>::operator=(bool f)
{
	logical_traits<T>::assign(m_ref, f, m_i);
	return *this;
}

template<class T>
qbool_ref<T>& qbool_ref<T>::operator=(const qbool_ref<T>& rhs)
{
	logical_traits<T>::assign(m_ref, rhs, m_i);
	return *this;
}

template<class T>
qbool_ref<T>::operator bool() const
{
	return logical_traits<T>::bracket(m_ref, m_i);
}

template<class T>
qbool_ref<T> qboolean<T>::operator[](const uint64_t& i)
{
	return logical_traits<T>::ref(m_b, i);
}

#include <cstring>

template<class T>
qboolean<T> qboolean<T>::operator&&(const qboolean<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> r;
	typename qboolean_traits<T>::storage_type p = logical_traits<T>::logical_and(m_b, rhs.m_b);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->logical_and(r, *this, rhs);

	return r;
}

template<class T>
qboolean<T> qboolean<T>::operator&&(bool rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> r;
	typename qboolean_traits<T>::storage_type p = logical_traits<T>::logical_and(m_b, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->logical_and(r, *this, graph_traits<T>::cast(rhs));

	return r;
}

template<class T>
qboolean<T> qboolean<T>::operator||(const qboolean<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> r;
	typename qboolean_traits<T>::storage_type p = logical_traits<T>::logical_or(m_b, rhs.m_b);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->logical_or(r, *this, rhs);

	return r;
}

template<class T>
qboolean<T> qboolean<T>::operator||(bool rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> r;
	typename qboolean_traits<T>::storage_type p = logical_traits<T>::logical_or(m_b, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->logical_or(r, *this, graph_traits<T>::cast(rhs));

	return r;
}

template<class T>
qboolean<T> qboolean<T>::operator!() const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> r;
	typename qboolean_traits<T>::storage_type p = logical_traits<T>::logical_not(m_b);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->logical_not(r, *this);

	return r;
}

template<class T>
qboolean<T> qboolean<T>::operator==(const qboolean<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> r;
	typename qboolean_traits<T>::storage_type p = logical_traits<T>::equal(m_b, rhs.m_b);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->equal_to(r, *this, rhs);

	return r;
}

template<class T>
qboolean<T> qboolean<T>::operator!=(const qboolean<T>& rhs) const
{
	return *this == !rhs;
}

template<class T>
qboolean<T> qboolean<T>::operator==(bool rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<T> r;
	typename qboolean_traits<T>::storage_type p = logical_traits<T>::equal(m_b, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->equal_to(r, *this, graph_traits<T>::cast(rhs));

	return r;
}

template<class T>
qboolean<T> qboolean<T>::operator!=(bool rhs) const
{
	return *this == !rhs;
}

#define EXPLICIT_INSTANTATION_IFF1(name,T) \
template qboolean<T> VSGRAPH_API name<T>(const qboolean<T>& cond, const qboolean<T>& if_true, const qboolean<T>& if_false);

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
template qboolean<T> VSGRAPH_API name<T>(const qboolean<T>& cond, const qboolean<T>& if_true, bool if_false);

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
template qboolean<T> VSGRAPH_API name<T>(const qboolean<T>& cond, bool if_true, const qboolean<T>& if_false);

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

#define EXPLICIT_INSTANTATION_IFF4(name,T) \
template qboolean<T> VSGRAPH_API name<T>(const qboolean<T>& cond, bool if_true, bool if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF4_ALL(name) \
EXPLICIT_INSTANTATION_IFF4(name,double) \
EXPLICIT_INSTANTATION_IFF4(name,__m512d) \
EXPLICIT_INSTANTATION_IFF4(name,__m512) \
EXPLICIT_INSTANTATION_IFF4(name,__m256d) \
EXPLICIT_INSTANTATION_IFF4(name,__m256) \
EXPLICIT_INSTANTATION_IFF4(name,__m128d) \
EXPLICIT_INSTANTATION_IFF4(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF4_ALL(name) \
EXPLICIT_INSTANTATION_IFF4(name,double) \
EXPLICIT_INSTANTATION_IFF4(name,__m256d) \
EXPLICIT_INSTANTATION_IFF4(name,__m256) \
EXPLICIT_INSTANTATION_IFF4(name,__m128d) \
EXPLICIT_INSTANTATION_IFF4(name,__m128) 
#endif



EXPLICIT_INSTANTATION_IFF1_ALL(qif)

template<class T>
qboolean<T> qif(const qboolean<T>& cond, const qboolean<T>& if_true, const qboolean<T>& if_false)
{
	auto recorder = recorder_ptr<T>();

	typename qboolean_traits<T>::storage_type iftrue;
	memcpy(&iftrue, &if_true, sizeof(qboolean<T>));

	typename qboolean_traits<T>::storage_type iffalse;
	memcpy(&iffalse, &if_false, sizeof(qboolean<T>));

	typename qboolean_traits<T>::storage_type condition;
	memcpy(&condition, &cond, sizeof(qboolean<T>));

	qboolean<T> r;
	typename qboolean_traits<T>::storage_type p = logical_traits<T>::qif(condition,iftrue,iffalse);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->iff(r, cond, if_true, if_false);

	return r;
}

EXPLICIT_INSTANTATION_IFF2_ALL(qif)

template<class T>
qboolean<T> qif(const qboolean<T>& cond, const qboolean<T>& if_true, bool if_false)
{
	auto recorder = recorder_ptr<T>();

	typename qboolean_traits<T>::storage_type iftrue;
	memcpy(&iftrue, &if_true, sizeof(qboolean<T>));

	typename qboolean_traits<T>::storage_type condition;
	memcpy(&condition, &cond, sizeof(qboolean<T>));

	qboolean<T> r;
	typename qboolean_traits<T>::storage_type p = logical_traits<T>::qif(condition, iftrue, if_false);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->iff(r, cond, if_true, graph_traits<T>::cast(if_false));

	return r;
}

EXPLICIT_INSTANTATION_IFF3_ALL(qif)

template<class T>
qboolean<T> qif(const qboolean<T>& cond, bool if_true, const qboolean<T>& if_false)
{
	return qif(!cond, if_false, if_true);
}

EXPLICIT_INSTANTATION_IFF4_ALL(qif)

template<class T>
qboolean<T> qif(const qboolean<T>& cond, bool if_true, bool if_false)
{
	auto recorder = recorder_ptr<T>();

	typename qboolean_traits<T>::storage_type condition;
	memcpy(&condition, &cond, sizeof(qboolean<T>));

	qboolean<T> r;
	typename qboolean_traits<T>::storage_type p = logical_traits<T>::qif(condition, if_true, if_false);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->iff(r, cond, graph_traits<T>::cast(if_true), graph_traits<T>::cast(if_false));

	return r;
}

