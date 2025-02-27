#pragma once

#include <cstdint>
#include "qtype_traits.h"
#include <initializer_list>
#include "qboolean.h"

namespace vstech {

	template<unsigned short N>
	struct qinteger_storage
	{
		int64_t m_x[N];
	};

	template<class T>
	struct qinteger_traits {

		typedef int64_t storage_type;

	};

	template<>
	struct qinteger_traits<__m512d> {

		typedef qinteger_storage<8> storage_type;

	};

	template<>
	struct qinteger_traits<__m512> {

		typedef qinteger_storage<16> storage_type;

	};

	template<>
	struct qinteger_traits<__m256d> {

		typedef qinteger_storage<4> storage_type;

	};

	template<>
	struct qinteger_traits<__m256> {

		typedef qinteger_storage<8> storage_type;

	};

	template<>
	struct qinteger_traits<__m128d> {

		typedef qinteger_storage<2> storage_type;

	};

	template<>
	struct qinteger_traits<__m128> {

		typedef qinteger_storage<4> storage_type;

	};

	template<class T>
	class qinteger {

		typename qinteger_traits<T>::storage_type m_i;

	public:

		// Constructor

		qinteger();
		qinteger(const int64_t& i);

		inline qinteger(std::initializer_list<int64_t> l) : qinteger()
		{
			uint64_t i = 0;
			for (auto b : l)
				operator[](i++) = b;
		}

		qinteger(const qinteger<T>& rhs);
		
		// = operator

		qinteger<T>& operator=(const qinteger<T>& rhs);
		qinteger<T>& operator=(int64_t rhs);

		// Destructor

		~qinteger();

		// Basic arithmetic operations

		qinteger<T> operator+(const qinteger<T>& rhs) const;
		qinteger<T> operator-(const qinteger<T>& rhs) const;
		qinteger<T> operator*(const qinteger<T>& rhs) const;
		qinteger<T> operator/(const qinteger<T>& rhs) const;

		qinteger<T>& operator+=(const qinteger<T>& rhs);
		qinteger<T>& operator-=(const qinteger<T>& rhs);
		qinteger<T>& operator*=(const qinteger<T>& rhs);
		qinteger<T>& operator/=(const qinteger<T>& rhs);

		qinteger<T> operator+(const int64_t& rhs) const;
		qinteger<T> operator-(const int64_t& rhs) const;
		qinteger<T> operator*(const int64_t& rhs) const;
		qinteger<T> operator/(const int64_t& rhs) const;

		qinteger<T>& operator+=(const int64_t& rhs);
		qinteger<T>& operator-=(const int64_t& rhs);
		qinteger<T>& operator*=(const int64_t& rhs);
		qinteger<T>& operator/=(const int64_t& rhs);

		// Change sign

		qinteger<T> operator-() const;

		// Increment and decrement

		qinteger<T>& operator++();
		qinteger<T> operator++(int) const;
		qinteger<T>& operator--();
		qinteger<T> operator--(int) const;

		// Comparison operators

		qboolean<T> operator==(const qinteger<T>& rhs) const;
		qboolean<T> operator!=(const qinteger<T>& rhs) const;
		qboolean<T> operator>(const qinteger<T>& rhs) const;
		qboolean<T> operator>=(const qinteger<T>& rhs) const;
		qboolean<T> operator<(const qinteger<T>& rhs) const;
		qboolean<T> operator<=(const qinteger<T>& rhs) const;

		qboolean<T> operator==(const int64_t& rhs) const;
		qboolean<T> operator!=(const int64_t& rhs) const;
		qboolean<T> operator>(const int64_t& rhs) const;
		qboolean<T> operator>=(const int64_t& rhs) const;
		qboolean<T> operator<(const int64_t& rhs) const;
		qboolean<T> operator<=(const int64_t& rhs) const;

		// [] operator

		const int64_t& operator[](const uint64_t& i) const;
		int64_t& operator[](const uint64_t& i);


	};

	typedef qinteger<double> qint;

}

template<class T> vstech::qinteger<T> operator+(const int64_t& lhs, const vstech::qinteger<T>& rhs);
template<class T> vstech::qinteger<T> operator-(const int64_t& lhs, const vstech::qinteger<T>& rhs);
template<class T> vstech::qinteger<T> operator*(const int64_t& lhs, const vstech::qinteger<T>& rhs);
template<class T> vstech::qinteger<T> operator/(const int64_t& lhs, const vstech::qinteger<T>& rhs);

template<class T> vstech::qboolean<T> operator==(const int64_t& lhs, const vstech::qinteger<T>& rhs);
template<class T> vstech::qboolean<T> operator!=(const int64_t& lhs, const vstech::qinteger<T>& rhs);
template<class T> vstech::qboolean<T> operator>(const int64_t& lhs, const vstech::qinteger<T>& rhs);
template<class T> vstech::qboolean<T> operator>=(const int64_t& lhs, const vstech::qinteger<T>& rhs);
template<class T> vstech::qboolean<T> operator<(const int64_t& lhs, const vstech::qinteger<T>& rhs);
template<class T> vstech::qboolean<T> operator<=(const int64_t& lhs, const vstech::qinteger<T>& rhs);

template<class T>
vstech::qinteger<T> qif(const vstech::qboolean<T>& cond, const vstech::qinteger<T>& if_true, const vstech::qinteger<T>& if_false);

template<class T>
vstech::qinteger<T> qif(const vstech::qboolean<T>& cond, const vstech::qinteger<T>& if_true, const int64_t& if_false);

template<class T>
vstech::qinteger<T> qif(const vstech::qboolean<T>& cond, const int64_t& if_true, const vstech::qinteger<T>& if_false);

template<class T>
vstech::qinteger<T> qif(const vstech::qboolean<T>& cond, const int64_t& if_true, const int64_t& if_false);
