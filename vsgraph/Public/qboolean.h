#pragma once

#include <cstdint>
#include "qtype_traits.h"
#include <initializer_list>

namespace vstech {

	class qboolean_p;

	template<class T>
	struct qboolean_traits {

		typedef qboolean_p* storage_type;
		typedef qboolean_p* storage_type_ref;

	};

	template<>
	struct qboolean_traits<double> {

		typedef bool storage_type;
		typedef bool& storage_type_ref;

	};

	template<>
	struct qboolean_traits<float> {

		typedef bool storage_type;
		typedef bool& storage_type_ref;

	};

	template<class T>
	class qbool_ref {

		typename qboolean_traits<T>::storage_type_ref m_ref;
		uint64_t m_i;

	public:

		qbool_ref(typename qboolean_traits<T>::storage_type_ref ref, const uint64_t& i);
		~qbool_ref();

		qbool_ref<T>& operator=(bool f);
		qbool_ref<T>& operator=(const qbool_ref<T>& rhs);

		operator bool() const;

	};

	template<class T>
	class qboolean {

		typename qboolean_traits<T>::storage_type m_b;

	public:

		qboolean(bool f = false);
		qboolean(const qboolean<T>& rhs);

		inline qboolean(std::initializer_list<bool> l) : qboolean()
		{
			uint64_t i = 0;
			for (auto b : l)
				operator[](i++) = b;
		}

		~qboolean();

		qboolean<T>& operator=(const qboolean<T>& rhs);
		qboolean<T>& operator=(bool rhs);

		bool operator[](const uint64_t& i) const;
		qbool_ref<T> operator[](const uint64_t& i);

		qboolean<T> operator&&(const qboolean<T>& rhs) const;
		qboolean<T> operator&&(bool rhs) const;

		qboolean<T> operator||(const qboolean<T>& rhs) const;
		qboolean<T> operator||(bool rhs) const;

		qboolean<T> operator!() const;

		qboolean<T> operator==(const qboolean<T>& rhs) const;
		qboolean<T> operator!=(const qboolean<T>& rhs) const;

		qboolean<T> operator==(bool rhs) const;
		qboolean<T> operator!=(bool rhs) const;

		operator bool() const; // This will always throw an exception

	};

	template<class T>
	qboolean<T> operator&&(bool lhs, const qboolean<T>& rhs)
	{
		return rhs && lhs;
	}

	template<class T>
	qboolean<T> operator||(bool lhs, const qboolean<T>& rhs)
	{
		return rhs || lhs;
	}

	template<class T>
	qboolean<T> operator==(bool lhs, const qboolean<T>& rhs)
	{
		return rhs == lhs;
	}

	template<class T>
	qboolean<T> operator!=(bool lhs, const qboolean<T>& rhs)
	{
		return rhs != lhs;
	}


	typedef qboolean<double> qbool; 

}

template<class T>
vstech::qboolean<T> qif(const vstech::qboolean<T>& cond, const vstech::qboolean<T>& if_true, const vstech::qboolean<T>& if_false);

template<class T>
vstech::qboolean<T> qif(const vstech::qboolean<T>& cond, const vstech::qboolean<T>& if_true, bool if_false);

template<class T>
vstech::qboolean<T> qif(const vstech::qboolean<T>& cond, bool if_true, const vstech::qboolean<T>& if_false);

template<class T>
vstech::qboolean<T> qif(const vstech::qboolean<T>& cond, bool if_true, bool if_false);
