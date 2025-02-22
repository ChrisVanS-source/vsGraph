#pragma once

#include <string>

namespace vstech {

	template<class T>
	class _qexception_p;

	template<class T>
	class _qexception {

		_qexception_p<T>* m_p;

	public:

		_qexception();
		_qexception(const char* what);
		~_qexception();

		_qexception(const _qexception& rhs);
		_qexception& operator=(const _qexception& rhs);

		const char* what() const;

		inline _qexception(const std::string& s) : _qexception(s.c_str()) {}

	};

	typedef _qexception<void> qexception;

}
