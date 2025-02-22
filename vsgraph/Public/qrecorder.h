#pragma once

#include "qscalar.h"
#include "qgraph.h"
#include "qstring.h"

namespace vstech {

	template<class T>
	class qrecorder_p;

	template<class T>
	class qrecorder 
	{
		qrecorder_p<T>* m_p;

	public:

		qrecorder();
		qrecorder(const qrecorder<T>& rhs);

		~qrecorder();

		qrecorder<T>& operator=(const qrecorder<T>& rhs);

		void start();
		void stop();

		void checkpoint();

		template<class U>
		qscalar<U>& input(qscalar<U>& x);

		template<class U>
		const qscalar<U>& input(const qscalar<U>& x);

		template<class U>
		qscalar<U>& input(qscalar<U>& x, const const_char_star& s);

		template<class U>
		const qscalar<U>& input(const qscalar<U>& x, const const_char_star& s);

		template<class U>
		qscalar<U>& param(qscalar<U>& x);

		template<class U>
		const qscalar<U>& param(const qscalar<U>& x);

		template<class U>
		qscalar<U>& param(qscalar<U>& x, const const_char_star& s);

		template<class U>
		const qscalar<U>& param(const qscalar<U>& x, const const_char_star& s);

		template<class U>
		qscalar<U>& output(qscalar<U>& x);

		template<class U>
		const qscalar<U>& output(const qscalar<U>& x);

		template<class U>
		qscalar<U>& output(qscalar<U>& x, const const_char_star& s);

		template<class U>
		const qscalar<U>& output(const qscalar<U>& x, const const_char_star& s);

		qgraph<T> graph() const;

	};

	template<class T, class U>
	struct qrecorder_helper
	{
		static qscalar<U>& input(qrecorder<T>& r, qscalar<U>& x);
		static const qscalar<U>& input(qrecorder<T>& r, const qscalar<U>& x);
		static qscalar<U>& input(qrecorder<T>& r, qscalar<U>& x, const const_char_star& s);
		static const qscalar<U>& input(qrecorder<T>& r, const qscalar<U>& x, const const_char_star& s);
		static qscalar<U>& param(qrecorder<T>& r, qscalar<U>& x);
		static const qscalar<U>& param(qrecorder<T>& r, const qscalar<U>& x);
		static qscalar<U>& param(qrecorder<T>& r, qscalar<U>& x, const const_char_star& s);
		static const qscalar<U>& param(qrecorder<T>& r, const qscalar<U>& x, const const_char_star& s);
		static qscalar<U>& output(qrecorder<T>& r, qscalar<U>& x);
		static const qscalar<U>& output(qrecorder<T>& r, const qscalar<U>& x);
		static qscalar<U>& output(qrecorder<T>& r, qscalar<U>& x, const const_char_star& s);
		static const qscalar<U>& output(qrecorder<T>& r, const qscalar<U>& x, const const_char_star& s);

	};

	template<class T>
	template<class U>
	qscalar<U>& qrecorder<T>::input(qscalar<U>& x) { return qrecorder_helper<T,U>::input(*this, x); }

	template<class T>
	template<class U>
	const qscalar<U>& qrecorder<T>::input(const qscalar<U>& x) { return qrecorder_helper<T, U>::input(*this, x); }

	template<class T>
	template<class U>
	qscalar<U>& qrecorder<T>::input(qscalar<U>& x, const const_char_star& s) { return qrecorder_helper<T, U>::input(*this, x, s); }

	template<class T>
	template<class U>
	const qscalar<U>& qrecorder<T>::input(const qscalar<U>& x, const const_char_star& s) { return qrecorder_helper<T, U>::input(*this, x, s); }

	template<class T>
	template<class U>
	qscalar<U>& qrecorder<T>::param(qscalar<U>& x) { return qrecorder_helper<T, U>::param(*this, x); }

	template<class T>
	template<class U>
	const qscalar<U>& qrecorder<T>::param(const qscalar<U>& x) { return qrecorder_helper<T, U>::param(*this, x); }

	template<class T>
	template<class U>
	qscalar<U>& qrecorder<T>::param(qscalar<U>& x, const const_char_star& s) { return qrecorder_helper<T, U>::param(*this, x, s); }

	template<class T>
	template<class U>
	const qscalar<U>& qrecorder<T>::param(const qscalar<U>& x, const const_char_star& s) { return qrecorder_helper<T, U>::param(*this, x, s); }

	template<class T>
	template<class U>
	qscalar<U>& qrecorder<T>::output(qscalar<U>& x) { return qrecorder_helper<T, U>::output(*this, x); }

	template<class T>
	template<class U>
	const qscalar<U>& qrecorder<T>::output(const qscalar<U>& x) { return qrecorder_helper<T, U>::output(*this, x); }

	template<class T>
	template<class U>
	qscalar<U>& qrecorder<T>::output(qscalar<U>& x, const const_char_star& s) { return qrecorder_helper<T,U>::output(*this, x, s); }

	template<class T>
	template<class U>
	const qscalar<U>& qrecorder<T>::output(const qscalar<U>& x, const const_char_star& s) { return qrecorder_helper<T, U>::output(*this, x, s); }
}
