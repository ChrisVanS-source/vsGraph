#pragma once

namespace vstech {

	class qboolean_p
	{
	public:

		virtual ~qboolean_p() {}
	};

}
using namespace vstech;

#include <memory>
#include <vector>

class qboolean_i : public qboolean_p {

	std::vector<bool> m_b;

public:

	qboolean_i(const uint64_t& dim, const bool& b);
	qboolean_i(const std::vector<bool>& b);
	~qboolean_i();

	const std::vector<bool>& get_b() const;
	std::vector<bool>& get_b();

};

#include "qboolean.h"
using namespace vstech;

template<class T>
uint64_t get_address(const qboolean<T>& x)
{
	return (uint64_t)&x;
}

template<class T>
struct qboolean_storage_traits {

	typedef std::vector<bool> storage_type;
	typedef std::vector<bool>& storage_type_ref;
	static const std::vector<bool>& get_data(typename qboolean_traits<T>::storage_type p) { return dynamic_cast<const qboolean_i*>(p)->get_b(); }
	static std::vector<bool> storage(uint64_t n) { return std::vector<bool>(n); }
	static void assign_bool(std::vector<bool>& x, bool y) { std::fill(x.begin(), x.end(), y); }
};

template<>
struct qboolean_storage_traits<double> {

	typedef bool storage_type;
	typedef std::vector<bool>::reference storage_type_ref;
	static bool get_data(bool b) { return b; }
	static bool storage(uint64_t) { return false; }
};


#include <cstring>

template<class T>
typename qboolean_storage_traits<T>::storage_type get_data_member(const qboolean<T>& b)
{
	typename qboolean_traits<T>::storage_type s;
	memcpy(&s, &b, sizeof(qboolean<T>));
	return qboolean_storage_traits<T>::get_data(s);
}