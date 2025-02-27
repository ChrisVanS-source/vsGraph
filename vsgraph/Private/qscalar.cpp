#include "qscalar_defines.h"
#include "qscalar.h"
#include "qgraph_traits.h"
#include "qrecorder_i.h"
#include "intrin.h"
using namespace vstech;

template class VSGRAPH_API qscalar<double>;
template class VSGRAPH_API qscalar<float>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qscalar<__m512d>;
template class VSGRAPH_API qscalar<__m512>;
#endif
template class VSGRAPH_API qscalar<__m256d>;
template class VSGRAPH_API qscalar<__m256>;
template class VSGRAPH_API qscalar<__m128d>;
template class VSGRAPH_API qscalar<__m128>;

template class VSGRAPH_API qnumber<double>;
template class VSGRAPH_API qnumber<float>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qnumber<__m512d>;
template class VSGRAPH_API qnumber<__m512>;
#endif
template class VSGRAPH_API qnumber<__m256d>;
template class VSGRAPH_API qnumber<__m256>;
template class VSGRAPH_API qnumber<__m128d>;
template class VSGRAPH_API qnumber<__m128>;


template<class T>
qscalar<T>::qscalar()
{
}

template<class T>
qscalar<T>::qscalar(const T& x) : m_x(x)
{
}

template<class T>
qscalar<T>::qscalar(const qnumber<typename number_traits<T>::type>& x) : m_x(graph_traits<T>::cast(x.get_x()))
{
}


template<class T>
qscalar<T>::qscalar(const qscalar<T>& x) : m_x(x.m_x)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->equal(*this, x);
}


template<class T>
qscalar<T>::~qscalar()
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->destroy(*this);
}

template<class T>
void qscalar<T>::checkpoint()
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->checkpoint();
}


// Operator=

template<class T>
qscalar<T>& qscalar<T>::operator=(const T& rhs)
{
	m_x = rhs;

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->equal_scalar(*this, rhs);

	return *this;
}

template<class T>
qscalar<T>& qscalar<T>::operator=(const qnumber<typename number_traits<T>::type>& rhs)
{
	m_x = graph_traits<T>::cast(rhs.get_x());

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->equal_scalar(*this, graph_traits<T>::cast(rhs.get_x()));

	return *this;
}

template<class T>
qscalar<T>& qscalar<T>::operator=(const qscalar<T>& rhs)
{
	if (&rhs != this) {

		m_x = rhs.m_x;

		auto recorder = recorder_ptr<T>();

		if (recorder)
			recorder->equal(*this, rhs);

	}
	return *this;
}


#define EXPLICIT_INSTANTATION_OPERATOR1(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const T& lhs, const qscalar<T>& rhs);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_OPERATOR1_ALL(name) \
EXPLICIT_INSTANTATION_OPERATOR1(name,double) \
EXPLICIT_INSTANTATION_OPERATOR1(name,float) \
EXPLICIT_INSTANTATION_OPERATOR1(name,__m512d) \
EXPLICIT_INSTANTATION_OPERATOR1(name,__m512) \
EXPLICIT_INSTANTATION_OPERATOR1(name,__m256d) \
EXPLICIT_INSTANTATION_OPERATOR1(name,__m256) \
EXPLICIT_INSTANTATION_OPERATOR1(name,__m128d) \
EXPLICIT_INSTANTATION_OPERATOR1(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_OPERATOR1_ALL(name) \
EXPLICIT_INSTANTATION_OPERATOR1(name,double) \
EXPLICIT_INSTANTATION_OPERATOR1(name,float) \
EXPLICIT_INSTANTATION_OPERATOR1(name,__m256d) \
EXPLICIT_INSTANTATION_OPERATOR1(name,__m256) \
EXPLICIT_INSTANTATION_OPERATOR1(name,__m128d) \
EXPLICIT_INSTANTATION_OPERATOR1(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_OPERATOR2(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_OPERATOR2_ALL(name) \
EXPLICIT_INSTANTATION_OPERATOR2(name,double) \
EXPLICIT_INSTANTATION_OPERATOR2(name,float) \
EXPLICIT_INSTANTATION_OPERATOR2(name,__m512d) \
EXPLICIT_INSTANTATION_OPERATOR2(name,__m512) \
EXPLICIT_INSTANTATION_OPERATOR2(name,__m256d) \
EXPLICIT_INSTANTATION_OPERATOR2(name,__m256) \
EXPLICIT_INSTANTATION_OPERATOR2(name,__m128d) \
EXPLICIT_INSTANTATION_OPERATOR2(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_OPERATOR2_ALL(name) \
EXPLICIT_INSTANTATION_OPERATOR2(name,double) \
EXPLICIT_INSTANTATION_OPERATOR2(name,float) \
EXPLICIT_INSTANTATION_OPERATOR2(name,__m256d) \
EXPLICIT_INSTANTATION_OPERATOR2(name,__m256) \
EXPLICIT_INSTANTATION_OPERATOR2(name,__m128d) \
EXPLICIT_INSTANTATION_OPERATOR2(name,__m128) 
#endif

#include "qscalar_traits.h"

// Addition

template<class T>
qscalar<T> qscalar<T>::operator+(const T& rhs) const
{
	qscalar<T> r(scalar_traits<T>::add(m_x, rhs));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->add(r, *this, rhs);

	return r;
}

template<class T>
qscalar<T> qscalar<T>::operator+(const qnumber<typename number_traits<T>::type>& rhs) const
{
	qscalar<T> r(scalar_traits<T>::add(m_x, graph_traits<T>::cast(rhs.get_x())));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->add(r, *this, graph_traits<T>::cast(rhs.get_x()));

	return r;
}


template<class T>
qscalar<T> qscalar<T>::operator+(const qscalar<T>& rhs) const
{
	qscalar<T> r(scalar_traits<T>::add(m_x, rhs.m_x));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->add(r, *this, rhs);

	return r;
}

template<class T>
qscalar<T>& qscalar<T>::operator+=(const T& rhs)
{
	m_x = scalar_traits<T>::add(m_x, rhs);

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->add(*this, rhs);

	return *this;
}

template<class T>
qscalar<T>& qscalar<T>::operator+=(const qnumber<typename number_traits<T>::type>& rhs)
{
	m_x = scalar_traits<T>::add(m_x, graph_traits<T>::cast(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->add(*this, graph_traits<T>::cast(rhs.get_x()));

	return *this;
}

template<class T>
qscalar<T>& qscalar<T>::operator+=(const qscalar<T>& rhs)
{
	m_x = scalar_traits<T>::add(m_x, rhs.m_x);

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->add(*this, rhs);

	return *this;
}

EXPLICIT_INSTANTATION_OPERATOR1_ALL(operator+)

template<class T> qscalar<T> operator+(const T& lhs, const qscalar<T>& rhs)
{
	return rhs + lhs;
}


EXPLICIT_INSTANTATION_OPERATOR2_ALL(operator+)

template<class T> qscalar<T> operator+(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	return rhs + lhs;
}

// Subtraction

template<class T>
qscalar<T> qscalar<T>::operator-(const T& rhs) const
{
	qscalar<T> r(scalar_traits<T>::subtract(m_x, rhs));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->subtract(r, *this, rhs);

	return r;
}

template<class T>
qscalar<T> qscalar<T>::operator-(const qnumber<typename number_traits<T>::type>& rhs) const
{
	qscalar<T> r(scalar_traits<T>::subtract(m_x, graph_traits<T>::cast(rhs.get_x())));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->subtract(r, *this, graph_traits<T>::cast(rhs.get_x()));

	return r;
}


template<class T>
qscalar<T> qscalar<T>::operator-(const qscalar<T>& rhs) const
{
	qscalar<T> r(scalar_traits<T>::subtract(m_x, rhs.m_x));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->subtract(r, *this, rhs);

	return r;
}

template<class T>
qscalar<T>& qscalar<T>::operator-=(const T& rhs)
{
	m_x = scalar_traits<T>::subtract(m_x, rhs);

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->subtract(*this, rhs);

	return *this;
}

template<class T>
qscalar<T>& qscalar<T>::operator-=(const qnumber<typename number_traits<T>::type>& rhs)
{
	m_x = scalar_traits<T>::subtract(m_x, graph_traits<T>::cast(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->subtract(*this, graph_traits<T>::cast(rhs.get_x()));

	return *this;
}

template<class T>
qscalar<T>& qscalar<T>::operator-=(const qscalar<T>& rhs)
{
	m_x = scalar_traits<T>::subtract(m_x, rhs.m_x);

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->subtract(*this, rhs);

	return *this;
}

EXPLICIT_INSTANTATION_OPERATOR1_ALL(operator-)

template<class T> qscalar<T> operator-(const T& lhs, const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::subtract(lhs, rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->subtract(r, lhs, rhs);

	return r;
}


EXPLICIT_INSTANTATION_OPERATOR2_ALL(operator-)

template<class T> qscalar<T> operator-(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::subtract(graph_traits<T>::cast(lhs.get_x()), rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->subtract(r, graph_traits<T>::cast(lhs.get_x()), rhs);

	return r;
}


// Multiplication

template<class T>
qscalar<T> qscalar<T>::operator*(const T& rhs) const
{
	qscalar<T> r(scalar_traits<T>::multiply(m_x, rhs));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->multiply(r, *this, rhs);

	return r;
}

template<class T>
qscalar<T> qscalar<T>::operator*(const qnumber<typename number_traits<T>::type>& rhs) const
{
	qscalar<T> r(scalar_traits<T>::multiply(m_x, graph_traits<T>::cast(rhs.get_x())));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->multiply(r, *this, graph_traits<T>::cast(rhs.get_x()));

	return r;
}


template<class T>
qscalar<T> qscalar<T>::operator*(const qscalar<T>& rhs) const
{
	qscalar<T> r(scalar_traits<T>::multiply(m_x,rhs.m_x));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->multiply(r, *this, rhs);

	return r;
}

template<class T>
qscalar<T>& qscalar<T>::operator*=(const T& rhs)
{
	m_x = scalar_traits<T>::multiply(m_x, rhs);

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->multiply(*this, rhs);

	return *this;
}

template<class T>
qscalar<T>& qscalar<T>::operator*=(const qnumber<typename number_traits<T>::type>& rhs)
{
	m_x = scalar_traits<T>::multiply(m_x, graph_traits<T>::cast(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->multiply(*this, graph_traits<T>::cast(rhs.get_x()));

	return *this;
}

template<class T>
qscalar<T>& qscalar<T>::operator*=(const qscalar<T>& rhs)
{
	m_x = scalar_traits<T>::multiply(m_x, rhs.m_x);

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->multiply(*this, rhs);

	return *this;
}

EXPLICIT_INSTANTATION_OPERATOR1_ALL(operator*)

template<class T> qscalar<T> operator*(const T& lhs, const qscalar<T>& rhs)
{
	return rhs * lhs;
}

EXPLICIT_INSTANTATION_OPERATOR2_ALL(operator*)

template<class T> qscalar<T> operator*(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	return rhs * lhs;
}

// Division

template<class T>
qscalar<T> qscalar<T>::operator/(const T& rhs) const
{
	qscalar<T> r(scalar_traits<T>::divide(m_x, rhs));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->divide(r, *this, rhs);

	return r;
}

template<class T>
qscalar<T> qscalar<T>::operator/(const qnumber<typename number_traits<T>::type>& rhs) const
{
	qscalar<T> r(scalar_traits<T>::divide(m_x, graph_traits<T>::cast(rhs.get_x())));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->divide(r, *this, graph_traits<T>::cast(rhs.get_x()));

	return r;
}


template<class T>
qscalar<T> qscalar<T>::operator/(const qscalar<T>& rhs) const
{
	qscalar<T> r(scalar_traits<T>::divide(m_x, rhs.m_x));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->divide(r, *this, rhs);

	return r;
}

template<class T>
qscalar<T>& qscalar<T>::operator/=(const T& rhs)
{
	m_x = scalar_traits<T>::divide(m_x, rhs);

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->divide(*this, rhs);

	return *this;
}

template<class T>
qscalar<T>& qscalar<T>::operator/=(const qnumber<typename number_traits<T>::type>& rhs)
{
	m_x = scalar_traits<T>::divide(m_x, graph_traits<T>::cast(rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->divide(*this, graph_traits<T>::cast(rhs.get_x()));

	return *this;
}

template<class T>
qscalar<T>& qscalar<T>::operator/=(const qscalar<T>& rhs)
{
	m_x = scalar_traits<T>::divide(m_x, rhs.m_x);

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->divide(*this, rhs);

	return *this;
}

EXPLICIT_INSTANTATION_OPERATOR1_ALL(operator/)

template<class T> qscalar<T> operator/(const T& lhs, const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::divide(lhs, rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->divide(r, lhs, rhs);

	return r;
}


EXPLICIT_INSTANTATION_OPERATOR2_ALL(operator/)

template<class T> qscalar<T> operator/(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	qscalar<T> r(scalar_traits<T>::divide(graph_traits<T>::cast(lhs.get_x()), rhs.get_x()));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->divide(r, graph_traits<T>::cast(lhs.get_x()), rhs);

	return r;
}

template<class T> qscalar<T> qscalar<T>::operator-() const
{
	qscalar<T> r(scalar_traits<T>::change_sign(m_x));

	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->change_sign(r, *this);

	return r;
}

#include "qexception.h"
using namespace vstech;

#include "qscalar_i.h"


template<> const double& bracket<__m512d>(const __m512d& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m512d_f64[i];
#endif
}

template<> const double& bracket<__m256d>(const __m256d& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m256d_f64[i];
#endif
}

template<> const double& bracket<__m128d>(const __m128d& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m128d_f64[i];
#endif
}

template<> const float& bracket<__m512>(const __m512& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m512_f32[i];
#endif
}

template<> const float& bracket<__m256>(const __m256& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m256_f32[i];
#endif
}

template<> const float& bracket<__m128>(const __m128& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m128_f32[i];
#endif
}

template<> double& bracket<double>(double& x, const uint64_t& i)
{
	return x;
}

template<> float& bracket<float>(float& x, const uint64_t& i)
{
	return x;
}

template<> double& bracket<__m512d>(__m512d& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m512d_f64[i];
#endif
}

template<> double& bracket<__m256d>(__m256d& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m256d_f64[i];
#endif
}

template<> double& bracket<__m128d>(__m128d& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m128d_f64[i];
#endif
}

template<> float& bracket<__m512>(__m512& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m512_f32[i];
#endif
}

template<> float& bracket<__m256>(__m256& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m256_f32[i];
#endif
}

template<> float& bracket<__m128>(__m128& x, const uint64_t& i)
{
#ifdef __linux__	
	return x[i];
#else
	return x.m128_f32[i];
#endif
}

#define CHECK_BOUNDS(A) \
	if (i >= scalar_traits<A>::alignment()) \
		throw qexception("Out of bounds")

template<class T>
const typename number_traits<T>::type& qscalar<T>::operator[](const uint64_t& i) const
{
	CHECK_BOUNDS(T);
	return bracket(m_x, i);
}

template<class T>
typename number_traits<T>::type& qscalar<T>::operator[](const uint64_t& i)
{
	CHECK_BOUNDS(T);
	return bracket(m_x, i);
}

// Logical operators

#include "qboolean_i.h"

template<class T>
struct logical_operator_traits 
{
	static qboolean_p* equal(const qscalar<T>& lhs, const qscalar<T>& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());

		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs[i] == rhs[i];

		return new qboolean_i(r);
	}

	static qboolean_p* equal(const qscalar<T>& lhs, const T& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());

		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs[i] == bracket(rhs,i);

		return new qboolean_i(r);
	}
	
	static qboolean_p* greater_than(const qscalar<T>& lhs, const qscalar<T>& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());

		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs[i] > rhs[i];

		return new qboolean_i(r);
	}

	static qboolean_p* greater_than(const qscalar<T>& lhs, const T& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());

		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs[i] > bracket(rhs, i);

		return new qboolean_i(r);
	}

	static qboolean_p* less_than(const qscalar<T>& lhs, const qscalar<T>& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());

		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs[i] < rhs[i];

		return new qboolean_i(r);
	}

	static qboolean_p* less_than(const qscalar<T>& lhs, const T& rhs)
	{
		std::vector<bool> r(qtype_traits<T>::alignment());

		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			r[i] = lhs[i] < bracket(rhs, i);

		return new qboolean_i(r);
	}

	static T qif(const qboolean_p* cond, const qscalar<T>& if_true, const qscalar<T>& if_false)
	{
		T r;
		const std::vector<bool>& condition = dynamic_cast<const qboolean_i*>(cond)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			bracket(r, i) = condition[i] ? if_true[i] : if_false[i];
		return r;
	}

	static T qif(const qboolean_p* cond, const qscalar<T>& if_true, const T& if_false)
	{
		T r;
		const std::vector<bool>& condition = dynamic_cast<const qboolean_i*>(cond)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			bracket(r, i) = condition[i] ? if_true[i] : bracket(if_false,i);
		return r;
	}

	static T qif(const qboolean_p* cond, const T& if_true, const T& if_false)
	{
		T r;
		const std::vector<bool>& condition = dynamic_cast<const qboolean_i*>(cond)->get_b();
		for (uint64_t i = 0; i < qtype_traits<T>::alignment(); ++i)
			bracket(r, i) = condition[i] ? bracket(if_true, i) : bracket(if_false, i);
		return r;
	}

};

template<>
struct logical_operator_traits<double>
{
	static bool equal(const qscalar<double>& lhs, const qscalar<double>& rhs) { return lhs.get_x() == rhs.get_x(); }
	static bool equal(const qscalar<double>& lhs, const double& rhs) { return lhs.get_x() == rhs; }
	static bool greater_than(const qscalar<double>& lhs, const qscalar<double>& rhs) { return lhs.get_x() > rhs.get_x(); }
	static bool greater_than(const qscalar<double>& lhs, const double& rhs) { return lhs.get_x() > rhs; }
	static bool less_than(const qscalar<double>& lhs, const qscalar<double>& rhs) { return lhs.get_x() < rhs.get_x(); }
	static bool less_than(const qscalar<double>& lhs, const double& rhs) { return lhs.get_x() < rhs; }
	static double qif(bool cond, const qscalar<double>& if_true, const qscalar<double>& if_false) { return (cond ? if_true : if_false).get_x(); }
	static double qif(bool cond, const qscalar<double>& if_true, const double& if_false) { return cond ? if_true.get_x() : if_false; }
	static double qif(bool cond, const double& if_true, const double& if_false) { return cond ? if_true : if_false; }
};

template<>
struct logical_operator_traits<float>
{
	static bool equal(const qscalar<float>& lhs, const qscalar<float>& rhs) { return lhs.get_x() == rhs.get_x(); }
	static bool equal(const qscalar<float>& lhs, const float& rhs) { return lhs.get_x() == rhs; }
	static bool greater_than(const qscalar<float>& lhs, const qscalar<float>& rhs) { return lhs.get_x() > rhs.get_x(); }
	static bool greater_than(const qscalar<float>& lhs, const float& rhs) { return lhs.get_x() > rhs; }
	static bool less_than(const qscalar<float>& lhs, const qscalar<float>& rhs) { return lhs.get_x() < rhs.get_x(); }
	static bool less_than(const qscalar<float>& lhs, const float& rhs) { return lhs.get_x() < rhs; }
	static float qif(bool cond, const qscalar<float>& if_true, const qscalar<float>& if_false) { return (cond ? if_true : if_false).get_x(); }
	static float qif(bool cond, const qscalar<float>& if_true, const float& if_false) { return cond ? if_true.get_x() : if_false; }
	static float qif(bool cond, const float& if_true, const float& if_false) { return cond ? if_true : if_false; }

};

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator==(const T& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<typename qtype_traits<T>::mapped_type> r;
	typename qboolean_traits<typename qtype_traits<T>::mapped_type>::storage_type p = logical_operator_traits<T>::equal(*this, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->equal_to(r, *this, rhs);

	return r;
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator==(const qnumber<typename number_traits<T>::type>& x) const
{
	auto recorder = recorder_ptr<T>();

	auto rhs = graph_traits<T>::cast(x.get_x());

	qboolean<typename qtype_traits<T>::mapped_type> r;
	typename qboolean_traits<typename qtype_traits<T>::mapped_type>::storage_type p = logical_operator_traits<T>::equal(*this, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->equal_to(r, *this, rhs);

	return r;
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator==(const qscalar<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<typename qtype_traits<T>::mapped_type> r;
	typename qboolean_traits<typename qtype_traits<T>::mapped_type>::storage_type p = logical_operator_traits<T>::equal(*this, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->equal_to(r, *this, rhs);

	return r;
}

#define EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,T) \
template qboolean<typename qtype_traits<T>::mapped_type> VSGRAPH_API name <T>(const T& lhs, const qscalar<T>& rhs);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1_ALL(name) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,double) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,float) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,__m512d) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,__m512) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,__m256d) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,__m256) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,__m128d) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1_ALL(name) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,double) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,float) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,__m256d) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,__m256) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,__m128d) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,T) \
template qboolean<typename qtype_traits<T>::mapped_type> VSGRAPH_API name <T>(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2_ALL(name) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,double) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,float) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,__m512d) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,__m512) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,__m256d) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,__m256) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,__m128d) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2_ALL(name) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,double) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,float) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,__m256d) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,__m256) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,__m128d) \
EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2(name,__m128) 
#endif


EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1_ALL(operator==)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator==(const T& lhs, const qscalar<T>& rhs)
{
	return rhs == lhs;
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2_ALL(operator==)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator==(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	return rhs == lhs;
}


template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator!=(const T& rhs) const
{
	return !(*this == rhs);
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator!=(const qnumber<typename number_traits<T>::type>& rhs) const
{
	return !(*this == rhs);
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator!=(const qscalar<T>& rhs) const
{
	return !(*this == rhs);
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1_ALL(operator!=)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator!=(const T& lhs, const qscalar<T>& rhs)
{
	return rhs != lhs;
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2_ALL(operator!=)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator!=(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	return rhs != lhs;
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator>(const T& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<typename qtype_traits<T>::mapped_type> r;
	typename qboolean_traits<typename qtype_traits<T>::mapped_type>::storage_type p = logical_operator_traits<T>::greater_than(*this, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->greater_than(r, *this, rhs);

	return r;
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator>(const qnumber<typename number_traits<T>::type>& x) const
{
	auto recorder = recorder_ptr<T>();

	auto rhs = graph_traits<T>::cast(x.get_x());

	qboolean<typename qtype_traits<T>::mapped_type> r;
	typename qboolean_traits<typename qtype_traits<T>::mapped_type>::storage_type p = logical_operator_traits<T>::greater_than(*this, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->greater_than(r, *this, rhs);

	return r;
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator>(const qscalar<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<typename qtype_traits<T>::mapped_type> r;
	typename qboolean_traits<typename qtype_traits<T>::mapped_type>::storage_type p = logical_operator_traits<T>::greater_than(*this, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->greater_than(r, *this, rhs);

	return r;
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1_ALL(operator>)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator>(const T& lhs, const qscalar<T>& rhs)
{
	return rhs < lhs;
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2_ALL(operator>)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator>(const qnumber<typename number_traits<T>::type>&lhs, const qscalar<T>&rhs)
{
	return rhs < lhs;
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator>=(const T& rhs) const
{
	return !(*this < rhs);
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator>=(const qnumber<typename number_traits<T>::type>& rhs) const
{
	return !(*this < rhs);
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator>=(const qscalar<T>& rhs) const
{
	return !(*this < rhs);
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1_ALL(operator>=)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator>=(const T& lhs, const qscalar<T>& rhs)
{
	return !(lhs < rhs);
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2_ALL(operator>=)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator>=(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	return !(lhs < rhs);
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator<(const T& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<typename qtype_traits<T>::mapped_type> r;
	typename qboolean_traits<typename qtype_traits<T>::mapped_type>::storage_type p = logical_operator_traits<T>::less_than(*this, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->less_than(r, *this, rhs);

	return r;
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator<(const qnumber<typename number_traits<T>::type>& x) const
{
	auto recorder = recorder_ptr<T>();

	auto rhs = graph_traits<T>::cast(x.get_x());

	qboolean<typename qtype_traits<T>::mapped_type> r;
	typename qboolean_traits<typename qtype_traits<T>::mapped_type>::storage_type p = logical_operator_traits<T>::less_than(*this, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->less_than(r, *this, rhs);

	return r;
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator<(const qscalar<T>& rhs) const
{
	auto recorder = recorder_ptr<T>();

	qboolean<typename qtype_traits<T>::mapped_type> r;
	typename qboolean_traits<typename qtype_traits<T>::mapped_type>::storage_type p = logical_operator_traits<T>::less_than(*this, rhs);
	memcpy(&r, &p, sizeof(qboolean<T>));

	if (recorder)
		recorder->less_than(r, *this, rhs);

	return r;
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1_ALL(operator<)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator<(const T& lhs, const qscalar<T>& rhs)
{
	return rhs > lhs;
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2_ALL(operator<)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator<(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	return rhs > lhs;
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator<=(const T& rhs) const
{
	return !(*this > rhs);
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator<=(const qnumber<typename number_traits<T>::type>& rhs) const
{
	return !(*this > rhs);
}

template<class T>
qboolean<typename qtype_traits<T>::mapped_type> qscalar<T>::operator<=(const qscalar<T>& rhs) const
{
	return !(*this > rhs);
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR1_ALL(operator<=)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator<=(const T& lhs, const qscalar<T>& rhs)
{
	return !(lhs > rhs);
}

EXPLICIT_INSTANTATION_LOGICAL_OPERATOR2_ALL(operator<=)

template<class T> qboolean<typename qtype_traits<T>::mapped_type> operator<=(const qnumber<typename number_traits<T>::type>& lhs, const qscalar<T>& rhs)
{
	return !(lhs > rhs);
}

#define EXPLICIT_INSTANTATION_IFF1(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qscalar<T>& if_true, const qscalar<T>& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF1_ALL(name) \
EXPLICIT_INSTANTATION_IFF1(name,double) \
EXPLICIT_INSTANTATION_IFF1(name,float) \
EXPLICIT_INSTANTATION_IFF1(name,__m512d) \
EXPLICIT_INSTANTATION_IFF1(name,__m512) \
EXPLICIT_INSTANTATION_IFF1(name,__m256d) \
EXPLICIT_INSTANTATION_IFF1(name,__m256) \
EXPLICIT_INSTANTATION_IFF1(name,__m128d) \
EXPLICIT_INSTANTATION_IFF1(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF1_ALL(name) \
EXPLICIT_INSTANTATION_IFF1(name,double) \
EXPLICIT_INSTANTATION_IFF1(name,float) \
EXPLICIT_INSTANTATION_IFF1(name,__m256d) \
EXPLICIT_INSTANTATION_IFF1(name,__m256) \
EXPLICIT_INSTANTATION_IFF1(name,__m128d) \
EXPLICIT_INSTANTATION_IFF1(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_IFF2(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qscalar<T>& if_true, const T& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF2_ALL(name) \
EXPLICIT_INSTANTATION_IFF2(name,double) \
EXPLICIT_INSTANTATION_IFF2(name,float) \
EXPLICIT_INSTANTATION_IFF2(name,__m512d) \
EXPLICIT_INSTANTATION_IFF2(name,__m512) \
EXPLICIT_INSTANTATION_IFF2(name,__m256d) \
EXPLICIT_INSTANTATION_IFF2(name,__m256) \
EXPLICIT_INSTANTATION_IFF2(name,__m128d) \
EXPLICIT_INSTANTATION_IFF2(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF2_ALL(name) \
EXPLICIT_INSTANTATION_IFF2(name,double) \
EXPLICIT_INSTANTATION_IFF2(name,float) \
EXPLICIT_INSTANTATION_IFF2(name,__m256d) \
EXPLICIT_INSTANTATION_IFF2(name,__m256) \
EXPLICIT_INSTANTATION_IFF2(name,__m128d) \
EXPLICIT_INSTANTATION_IFF2(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_IFF3(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qscalar<T>& if_true, const qnumber<typename number_traits<T>::type>& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF3_ALL(name) \
EXPLICIT_INSTANTATION_IFF3(name,double) \
EXPLICIT_INSTANTATION_IFF3(name,float) \
EXPLICIT_INSTANTATION_IFF3(name,__m512d) \
EXPLICIT_INSTANTATION_IFF3(name,__m512) \
EXPLICIT_INSTANTATION_IFF3(name,__m256d) \
EXPLICIT_INSTANTATION_IFF3(name,__m256) \
EXPLICIT_INSTANTATION_IFF3(name,__m128d) \
EXPLICIT_INSTANTATION_IFF3(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF3_ALL(name) \
EXPLICIT_INSTANTATION_IFF3(name,double) \
EXPLICIT_INSTANTATION_IFF3(name,float) \
EXPLICIT_INSTANTATION_IFF3(name,__m256d) \
EXPLICIT_INSTANTATION_IFF3(name,__m256) \
EXPLICIT_INSTANTATION_IFF3(name,__m128d) \
EXPLICIT_INSTANTATION_IFF3(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_IFF4(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const T& if_true, const qscalar<T>& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF4_ALL(name) \
EXPLICIT_INSTANTATION_IFF4(name,double) \
EXPLICIT_INSTANTATION_IFF4(name,float) \
EXPLICIT_INSTANTATION_IFF4(name,__m512d) \
EXPLICIT_INSTANTATION_IFF4(name,__m512) \
EXPLICIT_INSTANTATION_IFF4(name,__m256d) \
EXPLICIT_INSTANTATION_IFF4(name,__m256) \
EXPLICIT_INSTANTATION_IFF4(name,__m128d) \
EXPLICIT_INSTANTATION_IFF4(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF4_ALL(name) \
EXPLICIT_INSTANTATION_IFF4(name,double) \
EXPLICIT_INSTANTATION_IFF4(name,float) \
EXPLICIT_INSTANTATION_IFF4(name,__m256d) \
EXPLICIT_INSTANTATION_IFF4(name,__m256) \
EXPLICIT_INSTANTATION_IFF4(name,__m128d) \
EXPLICIT_INSTANTATION_IFF4(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_IFF5(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qnumber<typename number_traits<T>::type>& if_true, const qscalar<T>& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF5_ALL(name) \
EXPLICIT_INSTANTATION_IFF5(name,double) \
EXPLICIT_INSTANTATION_IFF5(name,float) \
EXPLICIT_INSTANTATION_IFF5(name,__m512d) \
EXPLICIT_INSTANTATION_IFF5(name,__m512) \
EXPLICIT_INSTANTATION_IFF5(name,__m256d) \
EXPLICIT_INSTANTATION_IFF5(name,__m256) \
EXPLICIT_INSTANTATION_IFF5(name,__m128d) \
EXPLICIT_INSTANTATION_IFF5(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF5_ALL(name) \
EXPLICIT_INSTANTATION_IFF5(name,double) \
EXPLICIT_INSTANTATION_IFF5(name,float) \
EXPLICIT_INSTANTATION_IFF5(name,__m256d) \
EXPLICIT_INSTANTATION_IFF5(name,__m256) \
EXPLICIT_INSTANTATION_IFF5(name,__m128d) \
EXPLICIT_INSTANTATION_IFF5(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_IFF6(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const T& if_true, const T& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF6_ALL(name) \
EXPLICIT_INSTANTATION_IFF6(name,double) \
EXPLICIT_INSTANTATION_IFF6(name,float) \
EXPLICIT_INSTANTATION_IFF6(name,__m512d) \
EXPLICIT_INSTANTATION_IFF6(name,__m512) \
EXPLICIT_INSTANTATION_IFF6(name,__m256d) \
EXPLICIT_INSTANTATION_IFF6(name,__m256) \
EXPLICIT_INSTANTATION_IFF6(name,__m128d) \
EXPLICIT_INSTANTATION_IFF6(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF6_ALL(name) \
EXPLICIT_INSTANTATION_IFF6(name,double) \
EXPLICIT_INSTANTATION_IFF6(name,float) \
EXPLICIT_INSTANTATION_IFF6(name,__m256d) \
EXPLICIT_INSTANTATION_IFF6(name,__m256) \
EXPLICIT_INSTANTATION_IFF6(name,__m128d) \
EXPLICIT_INSTANTATION_IFF6(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_IFF7(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const T& if_true, const qnumber<typename vstech::number_traits<T>::type>& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF7_ALL(name) \
EXPLICIT_INSTANTATION_IFF7(name,double) \
EXPLICIT_INSTANTATION_IFF7(name,float) \
EXPLICIT_INSTANTATION_IFF7(name,__m512d) \
EXPLICIT_INSTANTATION_IFF7(name,__m512) \
EXPLICIT_INSTANTATION_IFF7(name,__m256d) \
EXPLICIT_INSTANTATION_IFF7(name,__m256) \
EXPLICIT_INSTANTATION_IFF7(name,__m128d) \
EXPLICIT_INSTANTATION_IFF7(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF7_ALL(name) \
EXPLICIT_INSTANTATION_IFF7(name,double) \
EXPLICIT_INSTANTATION_IFF7(name,float) \
EXPLICIT_INSTANTATION_IFF7(name,__m256d) \
EXPLICIT_INSTANTATION_IFF7(name,__m256) \
EXPLICIT_INSTANTATION_IFF7(name,__m128d) \
EXPLICIT_INSTANTATION_IFF7(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_IFF8(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qnumber<typename number_traits<T>::type>& if_true, const T& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF8_ALL(name) \
EXPLICIT_INSTANTATION_IFF8(name,double) \
EXPLICIT_INSTANTATION_IFF8(name,float) \
EXPLICIT_INSTANTATION_IFF8(name,__m512d) \
EXPLICIT_INSTANTATION_IFF8(name,__m512) \
EXPLICIT_INSTANTATION_IFF8(name,__m256d) \
EXPLICIT_INSTANTATION_IFF8(name,__m256) \
EXPLICIT_INSTANTATION_IFF8(name,__m128d) \
EXPLICIT_INSTANTATION_IFF8(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF8_ALL(name) \
EXPLICIT_INSTANTATION_IFF8(name,double) \
EXPLICIT_INSTANTATION_IFF8(name,float) \
EXPLICIT_INSTANTATION_IFF8(name,__m256d) \
EXPLICIT_INSTANTATION_IFF8(name,__m256) \
EXPLICIT_INSTANTATION_IFF8(name,__m128d) \
EXPLICIT_INSTANTATION_IFF8(name,__m128) 
#endif

#define EXPLICIT_INSTANTATION_IFF9(name,T) \
template qscalar<T> VSGRAPH_API name<T>(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qnumber<typename number_traits<T>::type>& if_true, const qnumber<typename number_traits<T>::type>& if_false);

#ifdef INSTANTIATE_AVX512
#define EXPLICIT_INSTANTATION_IFF9_ALL(name) \
EXPLICIT_INSTANTATION_IFF9(name,double) \
EXPLICIT_INSTANTATION_IFF9(name,float) \
EXPLICIT_INSTANTATION_IFF9(name,__m512d) \
EXPLICIT_INSTANTATION_IFF9(name,__m512) \
EXPLICIT_INSTANTATION_IFF9(name,__m256d) \
EXPLICIT_INSTANTATION_IFF9(name,__m256) \
EXPLICIT_INSTANTATION_IFF9(name,__m128d) \
EXPLICIT_INSTANTATION_IFF9(name,__m128) 
#else
#define EXPLICIT_INSTANTATION_IFF9_ALL(name) \
EXPLICIT_INSTANTATION_IFF9(name,double) \
EXPLICIT_INSTANTATION_IFF9(name,float) \
EXPLICIT_INSTANTATION_IFF9(name,__m256d) \
EXPLICIT_INSTANTATION_IFF9(name,__m256) \
EXPLICIT_INSTANTATION_IFF9(name,__m128d) \
EXPLICIT_INSTANTATION_IFF9(name,__m128) 
#endif






EXPLICIT_INSTANTATION_IFF1_ALL(qif)

template<class T> qscalar<T> qif(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qscalar<T>& if_true, const qscalar<T>& if_false)
{
	auto recorder = recorder_ptr<T>();

	typename qboolean_traits<T>::storage_type p;
	memcpy(&p, &cond, sizeof(qboolean<typename qtype_traits<T>::mapped_type>));
	qscalar<T> r(logical_operator_traits<T>::qif(p, if_true, if_false));

	if (recorder)
		recorder->iff(r, cond, if_true, if_false);

	return r;
}

EXPLICIT_INSTANTATION_IFF2_ALL(qif)

template<class T> qscalar<T> qif(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qscalar<T>& if_true, const T& if_false)
{
	auto recorder = recorder_ptr<T>();

	typename qboolean_traits<T>::storage_type p;
	memcpy(&p, &cond, sizeof(qboolean<typename qtype_traits<T>::mapped_type>));
	qscalar<T> r(logical_operator_traits<T>::qif(p, if_true, if_false));

	if (recorder)
		recorder->iff(r, cond, if_true, if_false);

	return r;
}

EXPLICIT_INSTANTATION_IFF3_ALL(qif)

template<class T> qscalar<T> qif(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qscalar<T>& if_true, const qnumber<typename number_traits<T>::type>& if_false)
{
	auto recorder = recorder_ptr<T>();

	auto iffalse = graph_traits<T>::cast(if_false.get_x());

	typename qboolean_traits<T>::storage_type p;
	memcpy(&p, &cond, sizeof(qboolean<typename qtype_traits<T>::mapped_type>));
	qscalar<T> r(logical_operator_traits<T>::qif(p, if_true, iffalse));

	if (recorder)
		recorder->iff(r, cond, if_true, iffalse);

	return r;
}

EXPLICIT_INSTANTATION_IFF4_ALL(qif)

template<class T> qscalar<T> qif(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const T& if_true, const qscalar<T>& if_false)
{
	return qif(!cond, if_false, if_true);
}

EXPLICIT_INSTANTATION_IFF5_ALL(qif)

template<class T> qscalar<T> qif(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qnumber<typename number_traits<T>::type>& if_true, const qscalar<T>& if_false)
{
	return qif(!cond, if_false, if_true);
}

EXPLICIT_INSTANTATION_IFF6_ALL(qif)

template<class T> qscalar<T> qif(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const T& if_true, const T& if_false)
{
	auto recorder = recorder_ptr<T>();

	typename qboolean_traits<T>::storage_type p;
	memcpy(&p, &cond, sizeof(qboolean<typename qtype_traits<T>::mapped_type>));
	qscalar<T> r(logical_operator_traits<T>::qif(p, if_true, if_false));

	if (recorder)
		recorder->iff(r, cond, if_true, if_false);

	return r;
}

EXPLICIT_INSTANTATION_IFF7_ALL(qif)

template<class T> qscalar<T> qif(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const T& if_true, const qnumber<typename vstech::number_traits<T>::type>& if_false)
{
	return qif(cond, if_true, graph_traits<T>::cast(if_false.get_x()));
}

EXPLICIT_INSTANTATION_IFF8_ALL(qif)

template<class T> qscalar<T> qif(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qnumber<typename number_traits<T>::type>& if_true, const T& if_false)
{
	return qif(cond, graph_traits<T>::cast(if_true.get_x()), if_false);
}

EXPLICIT_INSTANTATION_IFF9_ALL(qif)

template<class T> qscalar<T> qif(const qboolean<typename qtype_traits<T>::mapped_type>& cond, const qnumber<typename number_traits<T>::type>& if_true, const qnumber<typename number_traits<T>::type>& if_false)
{
	return qif(cond, graph_traits<T>::cast(if_true.get_x()), graph_traits<T>::cast(if_false.get_x()));
}

template<class T>
qscalar<T>::operator int() const
{
	throw qexception("Conversion of qscalar to int not allowed");
	return 0;
}

