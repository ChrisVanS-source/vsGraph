#include "qdefines.h"
#include "qexception.h"
#include "qpci_pattern.h"
using namespace vstech;

PCI_PATTERN(_qexception)

template class VSGRAPH_API _qexception<void>;

#include <string>

template<class T>
class _qexception_i {

	std::string m_what;

public:

	_qexception_i(const std::string& s) : m_what(s) {}
	~_qexception_i() {}

	const char* what() const { return m_what.c_str(); }
};
 
template<class T>
_qexception<T>::_qexception() : m_p(0)
{
}

template<class T>
_qexception<T>::_qexception(const char* what)
{
	std::shared_ptr<_qexception_i<T>> i(new _qexception_i<T>(what));
	m_p = new _qexception_c<T>(i);
}

template<class T>
const char* _qexception<T>::what() const
{
	return get_impl(m_p)->what();
}
