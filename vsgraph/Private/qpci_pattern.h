#pragma once

#include <memory>

#define PCI_PATTERN(qclass) \
namespace vstech { \
\
	template<class T> \
	class qclass##_p \
	{ \
	public: \
		virtual ~qclass##_p() {} \
	}; \
} \
\
using namespace vstech; \
\
template<class T> \
class qclass##_i; \
\
template<class T> \
class qclass##_c : public qclass##_p<T>{ \
\
	std::shared_ptr<qclass##_i<T>> m_i; \
\
public: \
\
	qclass##_c(std::shared_ptr<qclass##_i<T>> i); \
	~qclass##_c(); \
\
	std::shared_ptr<qclass##_i<T>>& get_impl(); \
\
}; \
\
template<class T> \
std::shared_ptr<qclass##_i<T>>& get_impl(qclass##_p<T>* p) \
{ \
	return dynamic_cast<qclass##_c<T>*>(p)->get_impl(); \
} \
template<class T> \
std::shared_ptr<qclass##_i<T>>& qclass##_c<T>::get_impl() \
{ \
	return m_i; \
} \
\
template<class T> \
qclass##_c<T>::qclass##_c(std::shared_ptr<qclass##_i<T>> i) : m_i(i) \
{ \
} \
\
template<class T> \
qclass##_c<T>::~qclass##_c() \
{ \
} \
template<class T> \
qclass<T>::qclass(const qclass<T>& rhs) : m_p(rhs.m_p ? new qclass##_c<T>(get_impl(rhs.m_p)) : 0) \
{ \
} \
\
template<class T> \
qclass<T>& qclass<T>::operator=(const qclass<T>& rhs) \
{ \
	if (&rhs != this) \
	{ \
		if (m_p) delete m_p; \
		if (rhs.m_p) m_p = new qclass##_c<T>(get_impl(rhs.m_p)); else m_p = 0; \
	} \
	return *this; \
} \
\
template<class T> \
qclass<T>::~qclass() \
{ \
	if (m_p) delete m_p; \
}

#define PCI_PATTERN_NOT(qclass) \
namespace vstech { \
	class qclass##_p \
	{ \
	public: \
		virtual ~qclass##_p() {} \
	}; \
} \
\
using namespace vstech; \
\
class qclass##_i; \
\
class qclass##_c : public qclass##_p { \
\
	std::shared_ptr<qclass##_i> m_i; \
\
public: \
\
	qclass##_c(std::shared_ptr<qclass##_i> i); \
	~qclass##_c(); \
\
	std::shared_ptr<qclass##_i>& get_impl(); \
\
}; \
\
std::shared_ptr<qclass##_i>& get_impl(qclass##_p* p) \
{ \
	return dynamic_cast<qclass##_c*>(p)->get_impl(); \
} \
\
std::shared_ptr<qclass##_i>& qclass##_c::get_impl() \
{ \
	return m_i; \
} \
\
qclass##_c::qclass##_c(std::shared_ptr<qclass##_i> i) : m_i(i) \
{ \
} \
\
qclass##_c::~qclass##_c() \
{ \
} \
\
qclass::qclass(const qclass& rhs) : m_p(rhs.m_p ? new qclass##_c(get_impl(rhs.m_p)) : 0) \
{ \
} \
\
qclass& qclass::operator=(const qclass& rhs) \
{ \
	if (&rhs != this) \
	{ \
		if (m_p) delete m_p; \
		if (rhs.m_p) m_p = new qclass##_c(get_impl(rhs.m_p)); else m_p = 0; \
	} \
	return *this; \
} \
\
qclass::~qclass() \
{ \
	if (m_p) delete m_p; \
}
