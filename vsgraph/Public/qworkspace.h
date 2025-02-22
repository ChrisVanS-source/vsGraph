#pragma once

#include <cstdint>
#include "intrin.h"
#include "qscalar.h"
#include "qstring.h"

namespace vstech {

	enum QDevice {

		CPU = 0,
		NVIDIA = 1000, // 1000 + device number
		AMD = 2000,	   // 2000 + device number
		INTEL = 3000   // 3000 + device number
	};

	template<class T>
	class qworkspace_p;

	template<class T>
	struct workspace_traits
	{
		typedef T scalar_type;
		typedef T type;
		typedef typename workspace_traits<T*>::ptr_type ptr_type;
	};

	template<>
	struct workspace_traits<double*>
	{
		typedef double scalar_type;
		typedef double* type;
		typedef double* ptr_type;
	};

	template<>
	struct workspace_traits<float*>
	{
		typedef float scalar_type;
		typedef float* type;
		typedef float* ptr_type;
	};

	template<>
	struct workspace_traits<__m512d*>
	{
		typedef double scalar_type;
		typedef double* type;
		typedef double* ptr_type;
	};

	template<>
	struct workspace_traits<__m512*>
	{
		typedef float scalar_type;
		typedef float* type;
		typedef float* ptr_type;
	};

	template<>
	struct workspace_traits<__m256d*>
	{
		typedef double scalar_type;
		typedef double* type;
		typedef double* ptr_type;
	};

	template<>
	struct workspace_traits<__m256*>
	{
		typedef float scalar_type;
		typedef float* type;
		typedef float* ptr_type;
	};

	template<>
	struct workspace_traits<__m128d*>
	{
		typedef double scalar_type;
		typedef double* type;
		typedef double* ptr_type;
	};

	template<>
	struct workspace_traits<__m128*>
	{
		typedef float scalar_type;
		typedef float* type;
		typedef float* ptr_type;
	};

	template<class T>
	class qworkspace_view;

	template<class T>
	class qworkspace
	{
		qworkspace_p<T>* m_p;

	public:
		qworkspace();
		qworkspace(const qworkspace<T>& rhs);
		qworkspace<T>& operator=(const qworkspace<T>& rhs);
		~qworkspace();

		qworkspace_view<T> operator()(uint64_t n, uint64_t offset = 0);

		template<class U>
		uint64_t get_index(const qscalar<U>& x) const;

		template<class U>
		uint64_t get_input_index(const qscalar<U>& x) const;

		uint64_t get_index(const const_char_star& s) const;

		// Get value

		template<class U>
		const typename workspace_traits<T>::type& get_value(const qscalar<U>& x) const;

		const typename workspace_traits<T>::type& get_value(uint64_t x) const;

		const typename workspace_traits<T>::type& get_value(const const_char_star& s) const;

		template<class U>
		typename workspace_traits<T>::ptr_type get_value_ptr(const qscalar<U>& x);

		typename workspace_traits<T>::ptr_type get_value_ptr(uint64_t x);

		typename workspace_traits<T>::ptr_type get_value_ptr(const const_char_star& s);

		// Set value

		template<class U>
		void set_value(const qscalar<U>& x, const typename workspace_traits<T>::type& xv);

		template<class U>
		void set_value(const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv);

		void set_value(uint64_t x, const typename workspace_traits<T>::type& xv);

		void set_value(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv);

		void set_value(const const_char_star& s, const typename workspace_traits<T>::type& xv);

		void set_value(const const_char_star& s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv);

		// Get dual

		template<class U>
		const typename workspace_traits<T>::type& get_dual(const qscalar<U>& x, uint64_t order = 1) const;

		const typename workspace_traits<T>::type& get_dual(uint64_t x, uint64_t order = 1) const;

		const typename workspace_traits<T>::type& get_dual(const const_char_star& s, uint64_t order = 1) const;

		template<class U>
		typename workspace_traits<T>::ptr_type get_dual_ptr(const qscalar<U>& x, uint64_t order = 1);

		typename workspace_traits<T>::ptr_type get_dual_ptr(uint64_t x, uint64_t order = 1);

		typename workspace_traits<T>::ptr_type get_dual_ptr(const const_char_star& s, uint64_t order = 1);

		// Set dual

		template<class U>
		void set_dual(const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order = 1);

		template<class U>
		void set_dual(const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order = 1);

		void set_dual(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order = 1);

		void set_dual(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order = 1);

		void set_dual(const const_char_star& s, const typename workspace_traits<T>::type& xv, uint64_t order = 1);

		void set_dual(const const_char_star& s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order = 1);

		// Get adjoint

		template<class U>
		const typename workspace_traits<T>::type& get_adjoint(const qscalar<U>& x, uint64_t order = 1) const;

		const typename workspace_traits<T>::type& get_adjoint(uint64_t x, uint64_t order = 1) const;

		const typename workspace_traits<T>::type& get_adjoint(const const_char_star& s, uint64_t order = 1) const;

		template<class U>
		typename workspace_traits<T>::ptr_type get_adjoint_ptr(const qscalar<U>& x, uint64_t order = 1);

		typename workspace_traits<T>::ptr_type get_adjoint_ptr(uint64_t x, uint64_t order = 1);

		typename workspace_traits<T>::ptr_type get_adjoint_ptr(const const_char_star& s, uint64_t order = 1);

		// Set adjoint

		template<class U>
		void set_adjoint(const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order = 1);

		template<class U>
		void set_adjoint(const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order = 1);

		void set_adjoint(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order = 1);

		void set_adjoint(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order = 1);

		void set_adjoint(const const_char_star& s, const typename workspace_traits<T>::type& xv, uint64_t order = 1);

		void set_adjoint(const const_char_star& s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order = 1);

		// Get aux

		template<class U>
		const typename workspace_traits<T>::type& get_aux(const qscalar<U>& x, uint64_t order = 1) const;

		const typename workspace_traits<T>::type& get_aux(uint64_t x, uint64_t order = 1) const;

		const typename workspace_traits<T>::type& get_aux(const const_char_star& s, uint64_t order = 1) const;

		template<class U>
		typename workspace_traits<T>::ptr_type get_aux_ptr(const qscalar<U>& x, uint64_t order = 1);

		typename workspace_traits<T>::ptr_type get_aux_ptr(uint64_t x, uint64_t order = 1);

		typename workspace_traits<T>::ptr_type get_aux_ptr(const const_char_star& s, uint64_t order = 1);

		// Set aux

		template<class U>
		void set_aux(const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order = 1);

		template<class U>
		void set_aux(const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order = 1);

		void set_aux(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order = 1);

		void set_aux(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order = 1);

		void set_aux(const const_char_star& s, const typename workspace_traits<T>::type& xv, uint64_t order = 1);

		void set_aux(const const_char_star& s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order = 1);

	};

	template<class T, class U>
	struct qworkspace_helper
	{
		static uint64_t get_index(const qworkspace<T>& w, const qscalar<U>& x);
		static uint64_t get_input_index(const qworkspace<T>& w, const qscalar<U>& x);
		static const typename workspace_traits<T>::type& get_value(const qworkspace<T>& w, const qscalar<U>& x);
		static typename workspace_traits<T>::ptr_type get_value_ptr(const qworkspace<T>& w, const qscalar<U>& x);
		static void set_value(qworkspace<T>& w, const qscalar<U>& x, const typename workspace_traits<T>::type& xv);
		static void set_value(qworkspace<T>& w, const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv);
		static const typename workspace_traits<T>::type& get_dual(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order);
		static typename workspace_traits<T>::ptr_type get_dual_ptr(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order);
		static void set_dual(qworkspace<T>& w, const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order);
		static void set_dual(qworkspace<T>& w, const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);
		static const typename workspace_traits<T>::type& get_adjoint(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order);
		static typename workspace_traits<T>::ptr_type get_adjoint_ptr(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order);
		static void set_adjoint(qworkspace<T>& w, const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order);
		static void set_adjoint(qworkspace<T>& w, const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);
		static const typename workspace_traits<T>::type& get_aux(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order);
		static typename workspace_traits<T>::ptr_type get_aux_ptr(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order);
		static void set_aux(qworkspace<T>& w, const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order);
		static void set_aux(qworkspace<T>& w, const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);
	};

	template<class T>
	template<class U>
	uint64_t qworkspace<T>::get_index(const qscalar<U>& x) const
	{
		return qworkspace_helper<T, U>::get_index(*this, x);
	}

	template<class T>
	template<class U>
	uint64_t qworkspace<T>::get_input_index(const qscalar<U>& x) const
	{
		return qworkspace_helper<T, U>::get_input_index(*this, x);
	}

	template<class T>
	template<class U>
	const typename workspace_traits<T>::type& qworkspace<T>::get_value(const qscalar<U>& x) const
	{
		return qworkspace_helper<T,U>::get_value(*this, x);
	}

	template<class T>
	template<class U>
	typename workspace_traits<T>::ptr_type qworkspace<T>::get_value_ptr(const qscalar<U>& x)
	{
		return qworkspace_helper<T, U>::get_value_ptr(*this, x);
	}

	template<class T>
	template<class U>
	void qworkspace<T>::set_value(const qscalar<U>& x, const typename workspace_traits<T>::type& xv)
	{
		qworkspace_helper<T, U>::set_value(*this, x, xv);
	}

	template<class T>
	template<class U>
	void qworkspace<T>::set_value(const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv)
	{
		qworkspace_helper<T, U>::set_value(*this, x, xv);
	}

	template<class T>
	template<class U>
	const typename workspace_traits<T>::type& qworkspace<T>::get_dual(const qscalar<U>& x, uint64_t order) const
	{
		return qworkspace_helper<T, U>::get_dual(*this, x, order);
	}

	template<class T>
	template<class U>
	typename workspace_traits<T>::ptr_type qworkspace<T>::get_dual_ptr(const qscalar<U>& x, uint64_t order)
	{
		return qworkspace_helper<T, U>::get_dual_ptr(*this, x, order);
	}

	template<class T>
	template<class U>
	void qworkspace<T>::set_dual(const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order)
	{
		qworkspace_helper<T, U>::set_dual(*this, x, xv, order);
	}

	template<class T>
	template<class U>
	void qworkspace<T>::set_dual(const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
	{
		qworkspace_helper<T, U>::set_dual(*this, x, xv, order);
	}

	template<class T>
	template<class U>
	const typename workspace_traits<T>::type& qworkspace<T>::get_adjoint(const qscalar<U>& x, uint64_t order) const
	{
		return qworkspace_helper<T, U>::get_adjoint(*this, x, order);
	}

	template<class T>
	template<class U>
	typename workspace_traits<T>::ptr_type qworkspace<T>::get_adjoint_ptr(const qscalar<U>& x, uint64_t order)
	{
		return qworkspace_helper<T, U>::get_adjoint_ptr(*this, x, order);
	}

	template<class T>
	template<class U>
	void qworkspace<T>::set_adjoint(const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order)
	{
		qworkspace_helper<T, U>::set_adjoint(*this, x, xv, order);
	}

	template<class T>
	template<class U>
	void qworkspace<T>::set_adjoint(const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
	{
		qworkspace_helper<T, U>::set_adjoint(*this, x, xv, order);
	}

	template<class T>
	template<class U>
	const typename workspace_traits<T>::type& qworkspace<T>::get_aux(const qscalar<U>& x, uint64_t order) const
	{
		return qworkspace_helper<T, U>::get_aux(*this, x, order);
	}

	template<class T>
	template<class U>
	typename workspace_traits<T>::ptr_type qworkspace<T>::get_aux_ptr(const qscalar<U>& x, uint64_t order)
	{
		return qworkspace_helper<T, U>::get_aux_ptr(*this, x, order);
	}

	template<class T>
	template<class U>
	void qworkspace<T>::set_aux(const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order)
	{
		qworkspace_helper<T, U>::set_aux(*this, x, xv, order);
	}

	template<class T>
	template<class U>
	void qworkspace<T>::set_aux(const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
	{
		qworkspace_helper<T, U>::set_aux(*this, x, xv, order);
	}

	template<class T>
	class qworkspace_view {

		qworkspace<T>& m_ws;
		uint64_t m_n;
		uint64_t m_offset;

	public:

		qworkspace_view(qworkspace<T>& m_ws, uint64_t n = (uint64_t)-1, uint64_t offset = 0);
		~qworkspace_view();

		const uint64_t& get_n() const;
		const uint64_t& get_offset() const;

		qworkspace<T>& get_ws();

	};

}
