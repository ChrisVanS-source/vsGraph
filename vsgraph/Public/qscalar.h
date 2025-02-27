#pragma once

#include "intrin.h"
#include <cstdint>
#include <initializer_list>
#include "qboolean.h"

namespace vstech {

	template<class T>
	class qnumber {

		const T& m_x;

	public:

		qnumber(const T& x) : m_x(x) {}
		~qnumber() {}

		const T& get_x() const { return m_x; }
	};

	template<class T>
	struct number_traits {

		typedef T type;

	};

	template<>
	struct number_traits<double> {

		typedef double type;

	};

	template<>
	struct number_traits<float> {

		typedef float type;

	};

	template<>
	struct number_traits<__m512d> {

		typedef double type;

	};

	template<>
	struct number_traits<__m512> {

		typedef float type;

	};

	template<>
	struct number_traits<__m256d> {

		typedef double type;

	};

	template<>
	struct number_traits<__m256> {

		typedef float type;

	};

	template<>
	struct number_traits<__m128d> {

		typedef double type;

	};

	template<>
	struct number_traits<__m128> {

		typedef float type;

	};


	template<class T>
	class qscalar {

		T m_x;

	public:

		typedef T value_type;

		qscalar();
		qscalar(const T& x);
		qscalar(const qnumber<typename number_traits<T>::type>& x);
		qscalar(const qscalar<T>& x);

		inline qscalar(std::initializer_list<typename number_traits<T>::type> l) : qscalar()
		{
			uint64_t i = 0;
			for (auto b : l)
				operator[](i++) = b;
		}

		~qscalar();

		static void checkpoint();

		// Operator=

		qscalar<T>& operator=(const T& rhs);
		qscalar<T>& operator=(const qnumber<typename number_traits<T>::type>& rhs);
		qscalar<T>& operator=(const qscalar<T>& rhs);

		// Addition

		qscalar<T> operator+(const T& rhs) const;
		qscalar<T> operator+(const qnumber<typename number_traits<T>::type>& rhs) const;
		qscalar<T> operator+(const qscalar<T>& rhs) const;

		qscalar<T>& operator+=(const T& rhs);
		qscalar<T>& operator+=(const qnumber<typename number_traits<T>::type>& rhs);
		qscalar<T>& operator+=(const qscalar<T>& rhs);

		// Subtraction

		qscalar<T> operator-(const T& rhs) const;
		qscalar<T> operator-(const qnumber<typename number_traits<T>::type>& rhs) const;
		qscalar<T> operator-(const qscalar<T>& rhs) const;

		qscalar<T>& operator-=(const T& rhs);
		qscalar<T>& operator-=(const qnumber<typename number_traits<T>::type>& rhs);
		qscalar<T>& operator-=(const qscalar<T>& rhs);

		// Multiplication

		qscalar<T> operator*(const T& rhs) const;
		qscalar<T> operator*(const qnumber<typename number_traits<T>::type>& rhs) const;
		qscalar<T> operator*(const qscalar<T>& rhs) const;

		qscalar<T>& operator*=(const T& rhs);
		qscalar<T>& operator*=(const qnumber<typename number_traits<T>::type>& rhs);
		qscalar<T>& operator*=(const qscalar<T>& rhs);

		// Division

		qscalar<T> operator/(const T& rhs) const;
		qscalar<T> operator/(const qnumber<typename number_traits<T>::type>& rhs) const;
		qscalar<T> operator/(const qscalar<T>& rhs) const;

		qscalar<T>& operator/=(const T& rhs);
		qscalar<T>& operator/=(const qnumber<typename number_traits<T>::type>& rhs);
		qscalar<T>& operator/=(const qscalar<T>& rhs);

		// Change sign

		qscalar<T> operator-() const;

		// Logical operators

		qboolean<typename qtype_traits<T>::mapped_type> operator==(const T& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator==(const qnumber<typename number_traits<T>::type>& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator==(const qscalar<T>& rhs) const;

		qboolean<typename qtype_traits<T>::mapped_type> operator!=(const T& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator!=(const qnumber<typename number_traits<T>::type>& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator!=(const qscalar<T>& rhs) const;

		qboolean<typename qtype_traits<T>::mapped_type> operator>(const T& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator>(const qnumber<typename number_traits<T>::type>& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator>(const qscalar<T>& rhs) const;

		qboolean<typename qtype_traits<T>::mapped_type> operator>=(const T& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator>=(const qnumber<typename number_traits<T>::type>& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator>=(const qscalar<T>& rhs) const;

		qboolean<typename qtype_traits<T>::mapped_type> operator<(const T& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator<(const qnumber<typename number_traits<T>::type>& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator<(const qscalar<T>& rhs) const;

		qboolean<typename qtype_traits<T>::mapped_type> operator<=(const T& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator<=(const qnumber<typename number_traits<T>::type>& rhs) const;
		qboolean<typename qtype_traits<T>::mapped_type> operator<=(const qscalar<T>& rhs) const;

		// Data access

		const T& get_x() const { return m_x; }

		// operator[] - no recording

		const typename number_traits<T>::type& operator[](const uint64_t& i) const;
		typename number_traits<T>::type& operator[](const uint64_t& i);

		// Conversion

		explicit operator int() const; // This will always throw an exception

	};

	typedef qscalar<double> qdouble;
	typedef qscalar<float> qfloat;

}

namespace vstech {

	template<class T> qscalar<T> heaviside(const qscalar<T>& rhs);

}

// Addition

template<class T> vstech::qscalar<T> operator+(const T& lhs, const vstech::qscalar<T>& rhs);
template<class T> vstech::qscalar<T> operator+(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);

// Subtraction

template<class T> vstech::qscalar<T> operator-(const T& lhs, const vstech::qscalar<T>& rhs);
template<class T> vstech::qscalar<T> operator-(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);

// Multiplication

template<class T> vstech::qscalar<T> operator*(const T& lhs, const vstech::qscalar<T>& rhs);
template<class T> vstech::qscalar<T> operator*(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);

// Division

template<class T> vstech::qscalar<T> operator/(const T& lhs, const vstech::qscalar<T>& rhs);
template<class T> vstech::qscalar<T> operator/(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);

// Logical operator

template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator==(const T& lhs, const vstech::qscalar<T>& rhs);
template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator==(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);

template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator!=(const T& lhs, const vstech::qscalar<T>& rhs);
template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator!=(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);

template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator>(const T& lhs, const vstech::qscalar<T>& rhs);
template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator>(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);

template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator>=(const T& lhs, const vstech::qscalar<T>& rhs);
template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator>=(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);

template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator<(const T& lhs, const vstech::qscalar<T>& rhs);
template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator<(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);

template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator<=(const T& lhs, const vstech::qscalar<T>& rhs);
template<class T> vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type> operator<=(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);

// Iff statement

template<class T> vstech::qscalar<T> qif(const vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type>& cond, const vstech::qscalar<T>& if_true, const vstech::qscalar<T>& if_false);
template<class T> vstech::qscalar<T> qif(const vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type>& cond, const vstech::qscalar<T>& if_true, const T& if_false);
template<class T> vstech::qscalar<T> qif(const vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type>& cond, const vstech::qscalar<T>& if_true, const vstech::qnumber<typename vstech::number_traits<T>::type>& if_false);
template<class T> vstech::qscalar<T> qif(const vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type>& cond, const T& if_true, const vstech::qscalar<T>& if_false);
template<class T> vstech::qscalar<T> qif(const vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type>& cond, const vstech::qnumber<typename vstech::number_traits<T>::type>& if_true, const vstech::qscalar<T>& if_false);
template<class T> vstech::qscalar<T> qif(const vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type>& cond, const T& if_true, const T& if_false);
template<class T> vstech::qscalar<T> qif(const vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type>& cond, const T& if_true, const vstech::qnumber<typename vstech::number_traits<T>::type>& if_false);
template<class T> vstech::qscalar<T> qif(const vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type>& cond, const vstech::qnumber<typename vstech::number_traits<T>::type>& if_true, const T& if_false);
template<class T> vstech::qscalar<T> qif(const vstech::qboolean<typename vstech::qtype_traits<T>::mapped_type>& cond, const vstech::qnumber<typename vstech::number_traits<T>::type>& if_true, const vstech::qnumber<typename vstech::number_traits<T>::type>& if_false);

// Functions of 1 argument

namespace std {

	template<class T> vstech::qscalar<T> sin(const vstech::qscalar<T>& rhs);
	template<class T> vstech::qscalar<T> cos(const vstech::qscalar<T>& rhs);
	template<class T> vstech::qscalar<T> tan(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> asin(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> acos(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> atan(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> log(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> log2(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> log10(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> exp(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> sinh(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> cosh(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> tanh(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> sqrt(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> erfc(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> ceil(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> floor(const vstech::qscalar<T>& x);
	template<class T> vstech::qscalar<T> normal_cdf(const vstech::qscalar<T>& x);

}


// Function of 2 arguments

namespace std {

	template<class T> vstech::qscalar<T> pow(const vstech::qscalar<T>& lhs, const T& rhs);
	template<class T> vstech::qscalar<T> pow(const vstech::qscalar<T>& lhs, const vstech::qnumber<typename vstech::number_traits<T>::type>& rhs);
	template<class T> vstech::qscalar<T> pow(const vstech::qscalar<T>& lhs, const vstech::qscalar<T>& rhs);
	template<class T> vstech::qscalar<T> pow(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);
	template<class T> vstech::qscalar<T> pow(const T& lhs, const vstech::qscalar<T>& rhs);

	template<class T> vstech::qscalar<T> max(const vstech::qscalar<T>& lhs, const T& rhs);
	template<class T> vstech::qscalar<T> max(const vstech::qscalar<T>& lhs, const vstech::qnumber<typename vstech::number_traits<T>::type>& rhs);
	template<class T> vstech::qscalar<T> max(const vstech::qscalar<T>& lhs, const vstech::qscalar<T>& rhs);
	template<class T> vstech::qscalar<T> max(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);
	template<class T> vstech::qscalar<T> max(const T& lhs, const vstech::qscalar<T>& rhs);

	template<class T> vstech::qscalar<T> min(const vstech::qscalar<T>& lhs, const T& rhs);
	template<class T> vstech::qscalar<T> min(const vstech::qscalar<T>& lhs, const vstech::qnumber<typename vstech::number_traits<T>::type>& rhs);
	template<class T> vstech::qscalar<T> min(const vstech::qscalar<T>& lhs, const vstech::qscalar<T>& rhs);
	template<class T> vstech::qscalar<T> min(const vstech::qnumber<typename vstech::number_traits<T>::type>& lhs, const vstech::qscalar<T>& rhs);
	template<class T> vstech::qscalar<T> min(const T& lhs, const vstech::qscalar<T>& rhs);


}

