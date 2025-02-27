#pragma once

#include "qworkspace.h"

namespace vstech {

	template<class T>
	class qgraph_p;

	template<class T>
	class qgraph {

		qgraph_p<T>* m_p;

	public:

		qgraph();
		qgraph(const qgraph<T>& rhs);

		~qgraph();

		qgraph<T>& operator=(const qgraph<T>& rhs);

		qworkspace<T> workspace(QDevice device = CPU) const;

		void run(qworkspace_view<T> ws) const;
		void forward(qworkspace_view<T> ws, uint64_t from = (uint64_t)-1, uint64_t to = (uint64_t)-1) const;
		void backward(qworkspace_view<T> ws, uint64_t from = (uint64_t)-1, uint64_t to = (uint64_t)-1) const;

		qgraph<T> forwardAD() const;
		void make_forwardAD();

		qgraph<T> backwardAD() const;
		void make_backwardAD();

		void allocate(qworkspace<T>& ws, uint64_t n);

		template<class U>
		uint64_t get_index(const qscalar<U>& x) const;

		template<class U>
		uint64_t get_input_index(const qscalar<U>& x) const;

		uint64_t get_index(const const_char_star& s) const;

	};

	template<class T, class U>
	struct qgraph_helper
	{
		static uint64_t get_index(const qgraph<T>& w, const qscalar<U>& x);
		static uint64_t get_input_index(const qgraph<T>& w, const qscalar<U>& x);
	};

	template<class T>
	template<class U>
	uint64_t qgraph<T>::get_index(const qscalar<U>& x) const
	{
		return qgraph_helper<T, U>::get_index(*this, x);
	}

	template<class T>
	template<class U>
	uint64_t qgraph<T>::get_input_index(const qscalar<U>& x) const
	{
		return qgraph_helper<T, U>::get_input_index(*this, x);
	}

}
