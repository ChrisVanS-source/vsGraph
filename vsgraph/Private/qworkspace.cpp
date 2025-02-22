#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include "qdefines.h"
#include "qworkspace.h"
#include "qworkspace_i.h"
#include "intrin.h"
#include "qscalar_i.h"
#include "qexception.h"

template class VSGRAPH_API qworkspace<double>;
template class VSGRAPH_API qworkspace<float>;

template class VSGRAPH_API qworkspace<double*>;
template class VSGRAPH_API qworkspace<float*>;

#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qworkspace<__m512d>;
template class VSGRAPH_API qworkspace<__m512>;
#endif
template class VSGRAPH_API qworkspace<__m256d>;
template class VSGRAPH_API qworkspace<__m256>;
template class VSGRAPH_API qworkspace<__m128d>;
template class VSGRAPH_API qworkspace<__m128>;

#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qworkspace<__m512d*>;
template class VSGRAPH_API qworkspace<__m512*>;
#endif
template class VSGRAPH_API qworkspace<__m256d*>;
template class VSGRAPH_API qworkspace<__m256*>;
template class VSGRAPH_API qworkspace<__m128d*>;
template class VSGRAPH_API qworkspace<__m128*>;

template class qworkspace_i<double>;
template class qworkspace_i<float>;

template class qworkspace_i<double*>;
template class qworkspace_i<float*>;

#ifdef INSTANTIATE_AVX512
template class qworkspace_i<__m512d>;
template class qworkspace_i<__m512>;
#endif
template class qworkspace_i<__m256d>;
template class qworkspace_i<__m256>;
template class qworkspace_i<__m128d>;
template class qworkspace_i<__m128>;

#ifdef INSTANTIATE_AVX512
template class qworkspace_i<__m512d*>;
template class qworkspace_i<__m512*>;
#endif
template class qworkspace_i<__m256d*>;
template class qworkspace_i<__m256*>;
template class qworkspace_i<__m128d*>;
template class qworkspace_i<__m128*>;

double* pointer(double& x) { return &x; }
float* pointer(float& x) { return &x; }
double* pointer(double* x) { return x; }
float* pointer(float* x) { return x; }
#ifdef INSTANTIATE_AVX512
double* pointer(__m512d& x) 
{ 
#ifdef __linux__	
	return &x[0];
#else
	return x.m512d_f64;
#endif
}
float* pointer(__m512& x) 
{ 
#ifdef __linux__	
	return &x[0];
#else
	return x.m512_f32;
#endif
}
#endif
double* pointer(__m256d& x) 
{ 
#ifdef __linux__	
	return &x[0];
#else
	return x.m256d_f64;
#endif
}
float* pointer(__m256& x) 
{ 
#ifdef __linux__	
	return &x[0];
#else
	return x.m256_f32;
#endif
}
double* pointer(__m128d& x) 
{ 
#ifdef __linux__	
	return &x[0];
#else
	return x.m128d_f64;
#endif
}
float* pointer(__m128& x) 
{ 
#ifdef __linux__	
	return &x[0];
#else
	return x.m128_f32;
#endif
}

template<class T>
qworkspace<T>::qworkspace() : m_p(0) {}

template<class T>
struct workspace_assign_traits {

	static void construct(std::vector<typename workspace_traits<T>::type>& wksp, const std::vector<uint64_t>& wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T>::scalar_type>& scalar)
	{
		for (auto it = assign_map.begin(); it != assign_map.end(); ++it)
			wksp[wksp_index[it->first]] = scalar[it->second];
	}

	static void construct(std::vector<typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& integer_wksp, const std::vector<uint64_t>& integer_wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T>::integer_type>& integer)
	{
		std::fill(integer_wksp.begin(), integer_wksp.end(), qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage(qtype_traits<T>::alignment()));

		for (auto it = assign_map.begin(); it != assign_map.end(); ++it)
			qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::assign(integer_wksp[integer_wksp_index[it->first]], integer[it->second]);

	}

	static void construct(std::vector<typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& boolean_wksp, const std::vector<uint64_t>& boolean_wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T>::boolean_type>& boolean)
	{
		std::fill(boolean_wksp.begin(), boolean_wksp.end(), qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage(qtype_traits<T>::alignment()));

		for (auto it = assign_map.begin(); it != assign_map.end(); ++it)
			boolean_wksp[boolean_wksp_index[it->first]] = boolean[it->second];
	}

	static void allocate(typename graph_traits<T>::mem_type& mem, std::vector<typename workspace_traits<T>::type>& wksp, const std::vector<uint64_t>& wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T>::scalar_type>& scalar, uint64_t n)
	{
	}

	static void allocate(std::vector<typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& integer_wksp, const std::vector<uint64_t>& integer_wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T>::integer_type>& integer, uint64_t n)
	{
	}

	static void allocate(std::vector<typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& boolean_wksp, const std::vector<uint64_t>& boolean_wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T>::boolean_type>& boolean, uint64_t n)
	{
	}

	static void allocate_host(std::vector<uint64_t>& output_wksp_index, typename graph_traits<T>::mem_type& mem, std::vector<typename workspace_traits<T>::type>& wksp, const std::vector<uint64_t>& wksp_index, const std::vector<boost::bimap<uint64_t, uint64_t>>& output_map, uint64_t n)
	{
	}

};

#include <algorithm>

template<class T>
struct workspace_assign_traits<T*> {

	static void construct(std::vector<typename workspace_traits<T*>::type>& wksp, const std::vector<uint64_t>& wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T*>::scalar_type>& scalar)
	{
	}

	static void construct(std::vector<typename qinteger_storage_traits<typename qtype_traits<T*>::mapped_type>::storage_type>& integer_wksp, const std::vector<uint64_t>& integer_wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T*>::integer_type>& integer)
	{
	}

	static void construct(std::vector<typename qboolean_storage_traits<typename qtype_traits<T*>::mapped_type>::storage_type>& boolean_wksp, const std::vector<uint64_t>& boolean_wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T*>::boolean_type>& boolean)
	{
	}

	static void allocate(typename graph_traits<T*>::mem_type& mem, std::vector<typename workspace_traits<T*>::type>& wksp, const std::vector<uint64_t>& wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T*>::scalar_type>& scalar, uint64_t n)
	{
		graph_traits<T*>::allocate_mem(n, mem, wksp);
		for (auto it = assign_map.begin(); it != assign_map.end(); ++it)
			std::fill(wksp[wksp_index[it->first]], wksp[wksp_index[it->first]] + n, scalar[it->second]);

	}

	static void allocate(std::vector<typename qinteger_storage_traits<typename qtype_traits<T*>::mapped_type>::storage_type>& integer_wksp, const std::vector<uint64_t>& integer_wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T*>::integer_type>& integer, uint64_t n)
	{
		std::fill(integer_wksp.begin(), integer_wksp.end(), qinteger_storage_traits<typename qtype_traits<T*>::mapped_type>::storage(n));

		for (auto it = assign_map.begin(); it != assign_map.end(); ++it)
			qinteger_storage_traits<typename qtype_traits<T*>::mapped_type>::assign_int(integer_wksp[integer_wksp_index[it->first]], integer[it->second]);
	}

	static void allocate(std::vector<typename qboolean_storage_traits<typename qtype_traits<T*>::mapped_type>::storage_type>& boolean_wksp, const std::vector<uint64_t>& boolean_wksp_index, const std::map<uint64_t, uint64_t>& assign_map, const std::vector<typename graph_traits<T*>::boolean_type>& boolean, uint64_t n)
	{
		std::fill(boolean_wksp.begin(), boolean_wksp.end(), qboolean_storage_traits<typename qtype_traits<T*>::mapped_type>::storage(n));

		for (auto it = assign_map.begin(); it != assign_map.end(); ++it)
			qboolean_storage_traits<typename qtype_traits<T*>::mapped_type>::assign_bool(boolean_wksp[boolean_wksp_index[it->first]], boolean[it->second]);
	}

	static void allocate_host(std::vector<uint64_t>& output_wksp_index, typename graph_traits<T*>::mem_type& mem, std::vector<typename workspace_traits<T*>::type>& wksp, const std::vector<uint64_t>& wksp_index, const std::vector<boost::bimap<uint64_t, uint64_t>>& output_map, uint64_t n)
	{
		uint64_t count = 0;
		for (uint64_t i = 0; i < output_map.size(); ++i)
			count += output_map[i].size();

		std::vector<typename workspace_traits<T*>::type> h_wksp(count,0);

		graph_traits<T*>::allocate_mem(n, mem, h_wksp);

		count = 0;

		for (uint64_t i = 0; i < output_map.size(); ++i)
			for (auto it = output_map[i].left.begin(); it != output_map[i].left.end(); ++it)
			{
				wksp[wksp_index[it->second]] = h_wksp[count++];
				output_wksp_index.push_back(wksp_index[it->second]);
			}


	}

};

// Dummy out non-pointer use cases

template<class T>
void allocate_amd(uint64_t, int, char,
	const std::vector<uint64_t>& output_wksp_index,
	std::vector<T>& wksp, 
	char,
	std::vector<typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& integer_wskp,
	std::vector<typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& boolean_wksp,
	const std::vector<uint64_t>& wksp_index,
	const std::vector<uint64_t>& integer_wksp_index,
	const std::vector<uint64_t>& boolean_wksp_index,
	const std::vector<std::map<uint64_t, uint64_t>>& assign_map,
	const std::vector<T>& scalar,
	const std::vector<typename graph_traits<T>::integer_type>& integer,
	const std::vector<typename graph_traits<T>::boolean_type>& boolean)
{}

template<class T>
void allocate_nvidia(uint64_t, int, char, 
	const std::vector<uint64_t>& output_wksp_index,
	std::vector<T>& wksp,
	char,
	std::vector<typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& integer_wskp,
	std::vector<typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& boolean_wksp,
	const std::vector<uint64_t>& wksp_index,
	const std::vector<uint64_t>& integer_wksp_index,
	const std::vector<uint64_t>& boolean_wksp_index,
	const std::vector<std::map<uint64_t, uint64_t>>& assign_map,
	const std::vector<T>& scalar,
	const std::vector<typename graph_traits<T>::integer_type>& integer,
	const std::vector<typename graph_traits<T>::boolean_type>& boolean)
{}

template<class T>
void set_wksp_amd(int, char, uint64_t, const T& xv) {}

template<class T>
void set_wksp_nvidia(int, char, uint64_t, const T& xv) {}

template<class T>
void set_wksp_amd(int, char, uint64_t, const T* xv) {}

template<class T>
void set_wksp_nvidia(int, char, uint64_t, const T* xv) {}

#include "qnvidia_utils.cuh"
#include "qamd_utils.h"

template<class T>
QDevice qworkspace_i<T>::vendor() const
{
	return (QDevice)(1000 * (m_device / 1000));
}

template<class T>
int qworkspace_i<T>::device_number() const
{
	int device = (int)(m_device - vendor());
	
	switch (vendor())
	{
#ifndef __linux__
	case AMD: return get_fpoc_amd_device(device);
#endif
	case NVIDIA: return get_fpoc_nvidia_device(device);
	default: return -1;
	}
}

template<class T>
void qworkspace_i<T>::allocate(uint64_t n)
{
	m_n = n;

	// For GPU, we have to allocate memory on the host for the outputs (for now, assume only scalar)
	// Function is dummied out for non-pointer use cases

	std::vector<uint64_t> output_wksp_index;

	if (vendor() != CPU)
		workspace_assign_traits<T>::allocate_host(output_wksp_index, m_mem, m_wksp, m_wksp_index, m_output_map, n);

	switch (vendor())
	{
	case CPU:
		workspace_assign_traits<T>::allocate(m_mem, m_wksp, m_wksp_index, m_assign_map[QFLOATING_POINT], m_scalar, n);
		workspace_assign_traits<T>::allocate(m_integer_wksp, m_integer_wksp_index, m_assign_map[QINTEGER], m_integer, n);
		workspace_assign_traits<T>::allocate(m_boolean_wksp, m_boolean_wksp_index, m_assign_map[QBOOLEAN], m_boolean, n);
		break;
	case AMD:
#ifndef __linux__
		allocate_amd(n, device_number(), m_gpu_memory, output_wksp_index, m_wksp, m_mem, m_integer_wksp, m_boolean_wksp, m_wksp_index, m_integer_wksp_index, m_boolean_wksp_index, m_assign_map, m_scalar, m_integer, m_boolean);
#endif
		break;
	case NVIDIA:
		allocate_nvidia(n, device_number(), m_gpu_memory, output_wksp_index, m_wksp, m_mem, m_integer_wksp, m_boolean_wksp, m_wksp_index, m_integer_wksp_index, m_boolean_wksp_index, m_assign_map, m_scalar, m_integer, m_boolean);
		break;
	default:
		throw qexception("Unsupported GPU vendor");
	}

}

#include "qscalar_traits.h"

template<class T>
qworkspace_i<T>::qworkspace_i(QDevice device, const qgraph_i<T>& g) :
	m_ops(g.get_ops()),
	m_var_counter(g.get_var_counter()),
	m_wksp_index(g.get_wksp_index()),
	m_integer_wksp_index(g.get_integer_wksp_index()),
	m_boolean_wksp_index(g.get_boolean_wksp_index()),
	m_wksp(g.get_wksp_size()),
	m_integer_wksp(g.get_integer_wksp_size()),
	m_boolean_wksp(g.get_boolean_wksp_size()),
	m_assign_map(g.get_assign_map()),
	m_scalar(g.get_scalar()),
	m_integer(g.get_integer()),
	m_boolean(g.get_boolean()),
	m_variable_map(g.get_variable_map()),
	m_input_map(g.get_input_map()[0]),
	m_output_map(g.get_output_map()),
	m_adtype(g.get_adtype()),
	m_n(scalar_traits<T>::alignment()),
	m_device(device),
	m_variable_name_map(g.get_variable_name_map())
{
	workspace_assign_traits<T>::construct(m_wksp, m_wksp_index, m_assign_map[QFLOATING_POINT], m_scalar);
	workspace_assign_traits<T>::construct(m_integer_wksp, m_integer_wksp_index, m_assign_map[QINTEGER], m_integer);
	workspace_assign_traits<T>::construct(m_boolean_wksp, m_boolean_wksp_index, m_assign_map[QBOOLEAN], m_boolean);
}

template<class T>
qworkspace_i<T>::~qworkspace_i() {}

template struct VSGRAPH_API qworkspace_helper<double, double>;
template struct VSGRAPH_API qworkspace_helper<float, double>;
#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qworkspace_helper<__m512d, double>;
template struct VSGRAPH_API qworkspace_helper<__m512, double>;
#endif
template struct VSGRAPH_API qworkspace_helper<__m256d, double>;
template struct VSGRAPH_API qworkspace_helper<__m256, double>;
template struct VSGRAPH_API qworkspace_helper<__m128d, double>;
template struct VSGRAPH_API qworkspace_helper<__m128, double>;

template struct VSGRAPH_API qworkspace_helper<double*, double>;
template struct VSGRAPH_API qworkspace_helper<float*, double>;
#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qworkspace_helper<__m512d*, double>;
template struct VSGRAPH_API qworkspace_helper<__m512*, double>;
#endif
template struct VSGRAPH_API qworkspace_helper<__m256d*, double>;
template struct VSGRAPH_API qworkspace_helper<__m256*, double>;
template struct VSGRAPH_API qworkspace_helper<__m128d*, double>;
template struct VSGRAPH_API qworkspace_helper<__m128*, double>;

template struct VSGRAPH_API qworkspace_helper<double, float>;
template struct VSGRAPH_API qworkspace_helper<float, float>;
#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qworkspace_helper<__m512d, float>;
template struct VSGRAPH_API qworkspace_helper<__m512, float>;
#endif
template struct VSGRAPH_API qworkspace_helper<__m256d, float>;
template struct VSGRAPH_API qworkspace_helper<__m256, float>;
template struct VSGRAPH_API qworkspace_helper<__m128d, float>;
template struct VSGRAPH_API qworkspace_helper<__m128, float>;

template struct VSGRAPH_API qworkspace_helper<double*, float>;
template struct VSGRAPH_API qworkspace_helper<float*, float>;
#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qworkspace_helper<__m512d*, float>;
template struct VSGRAPH_API qworkspace_helper<__m512*, float>;
#endif
template struct VSGRAPH_API qworkspace_helper<__m256d*, float>;
template struct VSGRAPH_API qworkspace_helper<__m256*, float>;
template struct VSGRAPH_API qworkspace_helper<__m128d*, float>;
template struct VSGRAPH_API qworkspace_helper<__m128*, float>;

#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qworkspace_helper<__m512d, __m512d>;
template struct VSGRAPH_API qworkspace_helper<__m512, __m512>;
#endif
template struct VSGRAPH_API qworkspace_helper<__m256d, __m256d>;
template struct VSGRAPH_API qworkspace_helper<__m256, __m256>;
template struct VSGRAPH_API qworkspace_helper<__m128d, __m128d>;
template struct VSGRAPH_API qworkspace_helper<__m128, __m128>;

template<class T, class U>
uint64_t qworkspace_helper<T, U>::get_index(const qworkspace<T>& w, const qscalar<U>& x)
{
	return get_impl(get_p(w))->get_index(get_address(x));
}

template<class T, class U>
uint64_t qworkspace_helper<T, U>::get_input_index(const qworkspace<T>& w, const qscalar<U>& x)
{
	return get_impl(get_p(w))->get_input_index(get_address(x));
}

template<class T>
uint64_t qworkspace<T>::get_index(const const_char_star& s) const
{
	return get_impl(m_p)->get_index(s.m_s);
}

// Get value

template<class T, class U>
const typename workspace_traits<T>::type& qworkspace_helper<T,U>::get_value(const qworkspace<T>& w, const qscalar<U>& x)
{
	return get_impl(get_p(w))->get_value(get_address(x));
}

template<class T>
const typename workspace_traits<T>::type& qworkspace<T>::get_value(uint64_t x) const
{
	return get_impl(m_p)->get_value_byindex(x);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace<T>::get_value(const const_char_star& s) const
{
	return get_impl(m_p)->get_value_byname(s.m_s);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace<T>::get_value_ptr(uint64_t x)
{
	return get_impl(m_p)->get_value_ptr_byindex(x);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace<T>::get_value_ptr(const const_char_star& s)
{
	return get_impl(m_p)->get_value_ptr_byname(s.m_s);
}

template<class T, class U>
typename workspace_traits<T>::ptr_type qworkspace_helper<T, U>::get_value_ptr(const qworkspace<T>& w, const qscalar<U>& x)
{
	return get_impl(get_p(w))->get_value_ptr(get_address(x));
}

// Set value

template<class T, class U>
void qworkspace_helper<T, U>::set_value(qworkspace<T>& w, const qscalar<U>& x, const typename workspace_traits<T>::type& xv)
{
	get_impl(get_p(w))->set_value(get_address(x), xv);
}

template<class T, class U>
void qworkspace_helper<T, U>::set_value(qworkspace<T>& w, const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv)
{
	get_impl(get_p(w))->set_value(get_address(x), xv);
}

template<class T>
void qworkspace<T>::set_value(uint64_t x, const typename workspace_traits<T>::type& xv)
{
	get_impl(m_p)->set_value_byindex(x, xv);
}

template<class T>
void qworkspace<T>::set_value(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv)
{
	get_impl(m_p)->set_value_byindex(x, xv);
}

template<class T>
void qworkspace<T>::set_value(const const_char_star& s, const typename workspace_traits<T>::type& xv)
{
	get_impl(m_p)->set_value_byname(s.m_s, xv);
}

template<class T>
void qworkspace<T>::set_value(const const_char_star& s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv)
{
	get_impl(m_p)->set_value_byname(s.m_s, xv);
}

// Get dual

template<class T, class U>
const typename workspace_traits<T>::type& qworkspace_helper<T, U>::get_dual(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order)
{
	return get_impl(get_p(w))->get_dual(get_address(x), order);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace<T>::get_dual(uint64_t x, uint64_t order) const
{
	return get_impl(m_p)->get_dual_byindex(x, order);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace<T>::get_dual(const const_char_star& s, uint64_t order) const
{
	return get_impl(m_p)->get_dual_byname(s.m_s, order);
}

template<class T, class U>
typename workspace_traits<T>::ptr_type qworkspace_helper<T, U>::get_dual_ptr(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order)
{
	return get_impl(get_p(w))->get_dual_ptr(get_address(x), order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace<T>::get_dual_ptr(uint64_t x, uint64_t order)
{
	return get_impl(m_p)->get_dual_ptr_byindex(x, order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace<T>::get_dual_ptr(const const_char_star& s, uint64_t order)
{
	return get_impl(m_p)->get_dual_ptr_byname(s.m_s, order);
}

// Set dual

template<class T, class U>
void qworkspace_helper<T, U>::set_dual(qworkspace<T>& w, const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	get_impl(get_p(w))->set_dual(get_address(x), xv, order);
}

template<class T, class U>
void qworkspace_helper<T, U>::set_dual(qworkspace<T>& w, const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	get_impl(get_p(w))->set_dual(get_address(x), xv, order);
}

template<class T>
void qworkspace<T>::set_dual(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	get_impl(m_p)->set_dual_byindex(x, xv, order);
}

template<class T>
void qworkspace<T>::set_dual(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	get_impl(m_p)->set_dual_byindex(x, xv, order);
}

template<class T>
void qworkspace<T>::set_dual(const const_char_star& s, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	get_impl(m_p)->set_dual_byname(s.m_s, xv, order);
}

template<class T>
void qworkspace<T>::set_dual(const const_char_star& s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	get_impl(m_p)->set_dual_byname(s.m_s, xv, order);
}

// Get adjoint

template<class T, class U>
const typename workspace_traits<T>::type& qworkspace_helper<T, U>::get_adjoint(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order)
{
	return get_impl(get_p(w))->get_adjoint(get_address(x), order);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace<T>::get_adjoint(uint64_t x, uint64_t order) const
{
	return get_impl(m_p)->get_adjoint_byindex(x, order);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace<T>::get_adjoint(const const_char_star& s, uint64_t order) const
{
	return get_impl(m_p)->get_adjoint_byname(s.m_s, order);
}

template<class T, class U>
typename workspace_traits<T>::ptr_type qworkspace_helper<T, U>::get_adjoint_ptr(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order)
{
	return get_impl(get_p(w))->get_adjoint_ptr(get_address(x), order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace<T>::get_adjoint_ptr(uint64_t x, uint64_t order)
{
	return get_impl(m_p)->get_adjoint_ptr_byindex(x, order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace<T>::get_adjoint_ptr(const const_char_star& s, uint64_t order)
{
	return get_impl(m_p)->get_adjoint_ptr_byname(s.m_s, order);
}

// Set adjoint

template<class T, class U>
void qworkspace_helper<T, U>::set_adjoint(qworkspace<T>& w, const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	get_impl(get_p(w))->set_adjoint(get_address(x), xv, order);
}

template<class T, class U>
void qworkspace_helper<T, U>::set_adjoint(qworkspace<T>& w, const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	get_impl(get_p(w))->set_adjoint(get_address(x), xv, order);
}

template<class T>
void qworkspace<T>::set_adjoint(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	get_impl(m_p)->set_adjoint_byindex(x, xv, order);
}

template<class T>
void qworkspace<T>::set_adjoint(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	get_impl(m_p)->set_adjoint_byindex(x, xv, order);
}

template<class T>
void qworkspace<T>::set_adjoint(const const_char_star& s, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	get_impl(m_p)->set_adjoint_byname(s.m_s, xv, order);
}

template<class T>
void qworkspace<T>::set_adjoint(const const_char_star& s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	get_impl(m_p)->set_adjoint_byname(s.m_s, xv, order);
}

// Get aux

template<class T, class U>
const typename workspace_traits<T>::type& qworkspace_helper<T, U>::get_aux(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order)
{
	return get_impl(get_p(w))->get_aux(get_address(x), order);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace<T>::get_aux(uint64_t x, uint64_t order) const
{
	return get_impl(m_p)->get_aux_byindex(x, order);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace<T>::get_aux(const const_char_star& s, uint64_t order) const
{
	return get_impl(m_p)->get_aux_byname(s.m_s, order);
}

template<class T, class U>
typename workspace_traits<T>::ptr_type qworkspace_helper<T, U>::get_aux_ptr(const qworkspace<T>& w, const qscalar<U>& x, uint64_t order)
{
	return get_impl(get_p(w))->get_aux_ptr(get_address(x), order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace<T>::get_aux_ptr(uint64_t x, uint64_t order)
{
	return get_impl(m_p)->get_aux_ptr_byindex(x, order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace<T>::get_aux_ptr(const const_char_star& s, uint64_t order)
{
	return get_impl(m_p)->get_aux_ptr_byname(s.m_s, order);
}

// Set aux

template<class T, class U>
void qworkspace_helper<T, U>::set_aux(qworkspace<T>& w, const qscalar<U>& x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	get_impl(get_p(w))->set_aux(get_address(x), xv, order);
}

template<class T, class U>
void qworkspace_helper<T, U>::set_aux(qworkspace<T>& w, const qscalar<U>& x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	get_impl(get_p(w))->set_aux(get_address(x), xv, order);
}

template<class T>
void qworkspace<T>::set_aux(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	get_impl(m_p)->set_aux_byindex(x, xv, order);
}

template<class T>
void qworkspace<T>::set_aux(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	get_impl(m_p)->set_aux_byindex(x, xv, order);
}

template<class T>
void qworkspace<T>::set_aux(const const_char_star& s, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	get_impl(m_p)->set_aux_byname(s.m_s, xv, order);
}

template<class T>
void qworkspace<T>::set_aux(const const_char_star& s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	get_impl(m_p)->set_aux_byname(s.m_s, xv, order);
}

template<class T>
uint64_t qworkspace_i<T>::get_value_output_index(uint64_t x) const
{
	auto it = m_variable_map.find(x);
	if (it == m_variable_map.end())
		throw qexception("Attempt to retrieve non-recorded variable");
	return m_wksp_index[it->second];
}

template<class T>
uint64_t qworkspace_i<T>::get_input_index(uint64_t x) const
{
	auto it = m_input_map[0].left.find(x);
	if (it != m_input_map[0].left.end())
		return it->second;
	throw qexception("Attempt to access unrecorded variable");
	return (uint64_t)-1;
}

template<class T>
uint64_t qworkspace_i<T>::get_index(uint64_t x) const
{
	auto it = m_variable_map.find(x);
	if (it != m_variable_map.end())
		return it->second;
	else
		return get_input_index(x);
}

template<class T>
uint64_t qworkspace_i<T>::get_index(const char* s) const
{
	auto it = m_variable_name_map.left.find(s);
	return it == m_variable_name_map.left.end() ? (uint64_t)-1 : it->second;
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_value(uint64_t x) const
{
	return m_wksp[get_value_output_index(x)];
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_value_ptr(uint64_t x)
{
	return pointer(m_wksp[get_value_output_index(x)]);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_value_byindex(uint64_t x) const
{
	return m_wksp[m_wksp_index[x]];
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_value_byname(const char* s) const
{
	return get_value_byindex(get_index(s));}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_value_ptr_byindex(uint64_t x)
{
	return pointer(m_wksp[m_wksp_index[x]]);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_value_ptr_byname(const char* s)
{
	return get_value_ptr_byindex(get_index(s));
}

// Get dual

template<class T>
uint64_t qworkspace_i<T>::get_dual_output_index(uint64_t x, uint64_t order) const
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	if (m_adtype[order - 1] != FORWARD)
		throw qexception("Derivative type is not a dual");

	uint64_t idx;

	uint64_t idx_bkwd = get_highest_backward_index(x, order, idx);

	for (uint64_t j = idx_bkwd; j <= order; ++j)
	{
		auto jt = m_output_map[j].left.find(idx);
		if (jt == m_output_map[j].left.end())
			throw qexception("Graph is in a bad state, this should not happen, contact support");
		idx = jt->second;
	}
	return m_wksp_index[idx];

}

template<class T>
uint64_t qworkspace_i<T>::get_dual_output_internal_index(uint64_t x, uint64_t order) const
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	if (m_adtype[order - 1] != FORWARD)
		throw qexception("Derivative type is not a dual");

	uint64_t idx = x;

	uint64_t idx_bkwd = get_highest_backward_index(x, order);

	for (uint64_t j = idx_bkwd; j <= order; ++j)
	{
		auto jt = m_output_map[j].left.find(idx);
		if (jt == m_output_map[j].left.end())
			throw qexception("Graph is in a bad state, this should not happen, contact support");
		idx = jt->second;
	}
	return m_wksp_index[idx];

}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_dual(uint64_t x, uint64_t order) const
{
	return m_wksp[get_dual_output_index(x,order)];
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_dual_byindex(uint64_t x, uint64_t order) const
{
	return m_wksp[get_dual_output_internal_index(x, order)];
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_dual_byname(const char* s, uint64_t order) const
{
	return get_dual_byindex(get_index(s), order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_dual_ptr(uint64_t x, uint64_t order)
{
	return pointer(m_wksp[get_dual_output_index(x, order)]);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_dual_ptr_byindex(uint64_t x, uint64_t order)
{
	return pointer(m_wksp[get_dual_output_internal_index(x, order)]);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_dual_ptr_byname(const char* s, uint64_t order)
{
	return get_dual_ptr_byindex(get_index(s), order);
}


template<class T>
uint64_t qworkspace_i<T>::get_adjoint_output_index(uint64_t x, uint64_t order) const
{
	auto it = m_input_map[0].left.find(x);
	if (it == m_input_map[0].left.end())
		throw qexception("Attempt to retrieve adjoint of non-recorded input variable");
	return get_adjoint_output_internal_index(it->second, order);
}

template<class T>
uint64_t qworkspace_i<T>::get_adjoint_output_internal_index(uint64_t x, uint64_t order) const
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	if (m_adtype[order - 1] != BACKWARD)
		throw qexception("Derivative type is not an adjoint");

	auto jt = m_output_map[order].left.find(x);
	if (jt == m_output_map[order].left.end())
		throw qexception("Attempt to retrieve an adjoint of a parameter");
	return m_wksp_index[jt->second];
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_adjoint(uint64_t x, uint64_t order) const
{
	return m_wksp[get_adjoint_output_index(x,order)];
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_adjoint_byindex(uint64_t x, uint64_t order) const
{
	return m_wksp[get_adjoint_output_internal_index(x, order)];
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_adjoint_byname(const char* s, uint64_t order) const
{
	return get_adjoint_byindex(get_index(s), order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_adjoint_ptr(uint64_t x, uint64_t order)
{
	return pointer(m_wksp[get_adjoint_output_index(x, order)]);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_adjoint_ptr_byindex(uint64_t x, uint64_t order)
{
	return pointer(m_wksp[get_adjoint_output_internal_index(x, order)]);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_adjoint_ptr_byname(const char* s, uint64_t order)
{
	return get_adjoint_ptr_byindex(get_index(s), order);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_aux(uint64_t x, uint64_t order) const
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	return m_adtype[order-1] == FORWARD ? get_dual(x,order) : get_adjoint(x,order);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_aux_byindex(uint64_t x, uint64_t order) const
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	return m_adtype[order - 1] == FORWARD ? get_dual_byindex(x, order) : get_adjoint_byindex(x, order);
}

template<class T>
const typename workspace_traits<T>::type& qworkspace_i<T>::get_aux_byname(const char* s, uint64_t order) const
{
	return get_aux_byindex(get_index(s), order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_aux_ptr(uint64_t x, uint64_t order)
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	return m_adtype[order - 1] == FORWARD ? get_dual_ptr(x, order) : get_adjoint_ptr(x, order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_aux_ptr_byindex(uint64_t x, uint64_t order)
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	return m_adtype[order - 1] == FORWARD ? get_dual_ptr_byindex(x, order) : get_adjoint_ptr_byindex(x, order);
}

template<class T>
typename workspace_traits<T>::ptr_type qworkspace_i<T>::get_aux_ptr_byname(const char* s, uint64_t order)
{
	return get_aux_ptr_byindex(get_index(s), order);
}

#include "qgraph_operation.h"

template<class T>
uint64_t qworkspace_i<T>::get_value_input_index(uint64_t x) const
{
	auto it = m_input_map[0].left.find(x);
	if (it == m_input_map[0].left.end())
		throw qexception("Attempt to set an input that has not been recorded as input");
	return m_wksp_index[it->second];
}

// Dummy out non-pointer types


template<class T>
void qworkspace_i<T>::set_wksp(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv)
{
	switch (vendor())
	{
#ifndef __linux__
	case AMD:
		set_wksp_amd(device_number(), m_gpu_memory, x, graph_traits<T>::cast(xv.get_x()));
		break;
#endif
	case NVIDIA:
		set_wksp_nvidia(device_number(), m_gpu_memory, x, graph_traits<T>::cast(xv.get_x()));
		break;
	case CPU:
		graph_op_traits<T>::equal_scalar(m_wksp[x], graph_traits<T>::cast(xv.get_x()), 0, m_n);
		break;
	default:
		throw qexception("Unsupported vendor");
	}
}

template<class T>
void qworkspace_i<T>::set_wksp(uint64_t x, const typename workspace_traits<T>::type& xv)
{
	switch (vendor())
	{
#ifndef __linux__
	case AMD:
		set_wksp_amd(device_number(), m_gpu_memory, x, xv);
		break;
#endif
	case NVIDIA:
		set_wksp_nvidia(device_number(), m_gpu_memory, x, xv);
		break;
	case CPU:
		// Here we use typename workspace_traits<T>::type instead of just T because xv may not be aligned memory
		graph_op_traits<typename workspace_traits<T>::type>::equal(m_wksp[x], xv, 0, m_n);
		break;
	default:
		throw qexception("Unsupported vendor");
	}
}

// Set value

template<class T>
void qworkspace_i<T>::set_value(uint64_t x, const typename workspace_traits<T>::type& xv)
{
	set_wksp(get_value_input_index(x), xv);
}

template<class T>
void qworkspace_i<T>::set_value(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv)
{
	set_wksp(get_value_input_index(x),xv);
}

template<class T>
void qworkspace_i<T>::set_value_byindex(uint64_t x, const typename workspace_traits<T>::type& xv)
{
	set_wksp(m_wksp_index[x], xv);
}

template<class T>
void qworkspace_i<T>::set_value_byindex(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv)
{
	set_wksp(m_wksp_index[x], xv);
}

template<class T>
void qworkspace_i<T>::set_value_byname(const char* s, const typename workspace_traits<T>::type& xv)
{
	set_value_byindex(get_index(s), xv);
}

template<class T>
void qworkspace_i<T>::set_value_byname(const char* s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv)
{
	set_value_byindex(get_index(s), xv);
}

template<class T>
uint64_t qworkspace_i<T>::get_dual_input_index(uint64_t x, uint64_t order) const
{
	auto it = m_input_map[0].left.find(x);
	if (it == m_input_map[0].left.end())
		throw qexception("Attempt to set a dual to a variable that has not been recorded as input");
	return get_dual_input_internal_index(it->second, order);
}

template<class T>
uint64_t qworkspace_i<T>::get_dual_input_internal_index(uint64_t x, uint64_t order) const
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	if (m_adtype[order - 1] != FORWARD)
		throw qexception("Derivative type is not an adjoint");

	auto it = m_input_map[order].left.find(x);
	if (it == m_input_map[order].left.end())
		throw qexception("Graph is in a bad state, this should not happen, contact support");
	return m_wksp_index[it->second];
}

template<class T>
void qworkspace_i<T>::set_dual(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	set_wksp(get_dual_input_index(x, order), xv);
}

template<class T>
void qworkspace_i<T>::set_dual(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	set_wksp(get_dual_input_index(x, order), xv);
}

template<class T>
void qworkspace_i<T>::set_dual_byindex(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	set_wksp(get_dual_input_internal_index(x, order), xv);
}

template<class T>
void qworkspace_i<T>::set_dual_byindex(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	set_wksp(get_dual_input_internal_index(x, order), xv);
}

template<class T>
void qworkspace_i<T>::set_dual_byname(const char* s, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	set_dual_byindex(get_index(s), xv, order);
}

template<class T>
void qworkspace_i<T>::set_dual_byname(const char* s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	set_dual_byindex(get_index(s), xv, order);
}


template<class T>
uint64_t qworkspace_i<T>::get_highest_backward_index(uint64_t x, uint64_t order) const
{
	// Detect if there was a BACKWARD in a lower derivative

	uint64_t idx_bkwd = order - 1; // if order = 1 -> this will be -1

	while (idx_bkwd != 0 && m_adtype[idx_bkwd - 1] != BACKWARD)
		--idx_bkwd;

	if (idx_bkwd == 0)
		++idx_bkwd;

	return idx_bkwd;

}

template<class T>
uint64_t qworkspace_i<T>::get_highest_backward_index(uint64_t x, uint64_t order, uint64_t& idx) const
{
	// Detect if there was a BACKWARD in a lower derivative

	uint64_t idx_bkwd = order - 1; // if order = 1 -> this will be -1

	while (idx_bkwd != 0 && m_adtype[idx_bkwd - 1] != BACKWARD)
		--idx_bkwd;

	if (idx_bkwd == 0)
	{
		// Dual references an output

		auto it = m_variable_map.find(x);
		if (it == m_variable_map.end())
			throw qexception("Attempt to retrieve non-recorded variable");
		idx = it->second;
		++idx_bkwd;
	}
	else
	{

		// Dual references an input

		auto it = m_input_map[0].left.find(x);
		if (it == m_input_map[0].left.end())
			throw qexception("Attempt to retrieve non-recorded variable");
		idx = it->second;
	}

	return idx_bkwd;

}


template<class T>
uint64_t qworkspace_i<T>::get_adjoint_input_index(uint64_t x, uint64_t order) const
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	if (m_adtype[order - 1] != BACKWARD)
		throw qexception("Derivative type is not an adjoint");

	uint64_t idx;

	uint64_t idx_bkwd = get_highest_backward_index(x, order, idx);

	for (uint64_t j = idx_bkwd; j < order; ++j)
	{
		auto it = m_output_map[j].left.find(idx);
		if (it == m_output_map[j].left.end())
			throw qexception("Graph is in a bad state, this should not happen, contact support");
		idx = it->second;
	}

	auto it = m_input_map[order].left.find(idx);

	if (it == m_input_map[order].left.end())
		throw qexception("Bad code state : please call support");

	return m_wksp_index[it->second];

}

template<class T>
uint64_t qworkspace_i<T>::get_adjoint_input_internal_index(uint64_t x, uint64_t order) const
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	if (m_adtype[order - 1] != BACKWARD)
		throw qexception("Derivative type is not an adjoint");

	uint64_t idx = x;

	uint64_t idx_bkwd = get_highest_backward_index(x, order);

	for (uint64_t j = idx_bkwd; j < order; ++j)
	{
		auto it = m_output_map[j].left.find(idx);
		if (it == m_output_map[j].left.end())
			throw qexception("Graph is in a bad state, this should not happen, contact support");
		idx = it->second;
	}

	auto it = m_input_map[order].left.find(idx);

	if (it == m_input_map[order].left.end())
		throw qexception("Bad code state : please call support");

	return m_wksp_index[it->second];

}

// Set adjoint

template<class T>
void qworkspace_i<T>::set_adjoint(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	set_wksp(get_adjoint_input_index(x, order),xv);
}

template<class T>
void qworkspace_i<T>::set_adjoint(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	set_wksp(get_adjoint_input_index(x, order), xv);
}

template<class T>
void qworkspace_i<T>::set_adjoint_byindex(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	set_wksp(get_adjoint_input_internal_index(x, order), xv);
}

template<class T>
void qworkspace_i<T>::set_adjoint_byindex(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	set_wksp(get_adjoint_input_internal_index(x, order), xv);
}

template<class T>
void qworkspace_i<T>::set_adjoint_byname(const char* s, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	set_adjoint_byindex(get_index(s), xv, order);
}

template<class T>
void qworkspace_i<T>::set_adjoint_byname(const char* s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	set_adjoint_byindex(get_index(s), xv, order);
}

// Set aux

template<class T>
void qworkspace_i<T>::set_aux(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	m_adtype[order - 1] == FORWARD ? set_dual(x, xv, order) : set_adjoint(x, xv, order);
}

template<class T>
void qworkspace_i<T>::set_aux(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	m_adtype[order - 1] == FORWARD ? set_dual(x, xv, order) : set_adjoint(x, xv, order);
}

template<class T>
void qworkspace_i<T>::set_aux_byindex(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	m_adtype[order - 1] == FORWARD ? set_dual_byindex(x, xv, order) : set_adjoint_byindex(x, xv, order);
}

template<class T>
void qworkspace_i<T>::set_aux_byindex(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	if (order > m_adtype.size())
		throw qexception("Graph has derivatives up to and including " + boost::lexical_cast<std::string>(m_adtype.size()));

	m_adtype[order - 1] == FORWARD ? set_dual_byindex(x, xv, order) : set_adjoint_byindex(x, xv, order);
}

template<class T>
void qworkspace_i<T>::set_aux_byname(const char* s, const typename workspace_traits<T>::type& xv, uint64_t order)
{
	set_aux_byindex(get_index(s), xv, order);
}

template<class T>
void qworkspace_i<T>::set_aux_byname(const char* s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order)
{
	set_aux_byindex(get_index(s), xv, order);
}


#ifdef __linux__
inline void* _aligned_malloc(size_t size, size_t align) {
	void* mem = malloc(size + align + sizeof(void*));
	void** ptr = (void**)((uintptr_t)((uintptr_t)mem + align + sizeof(void*)) & ~(align - 1));
	ptr[-1] = mem;
	return ptr;
}

inline void _aligned_free(void* ptr) {
	free(((void**)ptr)[-1]);
}
#endif

template<class T>
void allocate_memory(uint64_t n, unsigned short align, typename graph_traits<T*>::mem_type& mem, std::vector<T*>& wksp)
{
	T* p = 0;

	size_t n_alloc = align * ((n + align - 1) / align);

	mem.reset(p = (T*)_aligned_malloc(n_alloc * wksp.size() * sizeof(T), align * sizeof(T)), _aligned_free);

	for (size_t i = 0; i < wksp.size(); ++i) {
		wksp[i] = p;
		p += n_alloc;
	}
}

#include "qscalar_traits.h"

void graph_traits<double*>::allocate_mem(uint64_t n, std::shared_ptr<double[]>& mem, std::vector<double*>& wksp)
{
	allocate_memory(n, 1, mem, wksp);

}

void graph_traits<float*>::allocate_mem(uint64_t n, std::shared_ptr<float[]>& mem, std::vector<float*>& wksp)
{
	allocate_memory(n, 1, mem, wksp);
}

#ifdef INSTANTIATE_AVX512
void graph_traits<__m512d*>::allocate_mem(uint64_t n, std::shared_ptr<double[]>& mem, std::vector<double*>& wksp)
{
	allocate_memory(n, scalar_traits<__m512d>::alignment(), mem, wksp);
}
#endif

void graph_traits<__m256d*>::allocate_mem(uint64_t n, std::shared_ptr<double[]>& mem, std::vector<double*>& wksp)
{
	allocate_memory(n, scalar_traits<__m256d>::alignment(), mem, wksp);
}

void graph_traits<__m128d*>::allocate_mem(uint64_t n, std::shared_ptr<double[]>& mem, std::vector<double*>& wksp)
{
	allocate_memory(n, scalar_traits<__m128d>::alignment(), mem, wksp);
}

#ifdef INSTANTIATE_AVX512
void graph_traits<__m512*>::allocate_mem(uint64_t n, std::shared_ptr<float[]>& mem, std::vector<float*>& wksp)
{
	allocate_memory(n, scalar_traits<__m512>::alignment(), mem, wksp);
}
#endif

void graph_traits<__m256*>::allocate_mem(uint64_t n, std::shared_ptr<float[]>& mem, std::vector<float*>& wksp)
{
	allocate_memory(n, scalar_traits<__m256>::alignment(), mem, wksp);
}

void graph_traits<__m128*>::allocate_mem(uint64_t n, std::shared_ptr<float[]>& mem, std::vector<float*>& wksp)
{
	allocate_memory(n, scalar_traits<__m128>::alignment(), mem, wksp);
}

template<class T>
qworkspace_view<T>::qworkspace_view(qworkspace<T>& ws, uint64_t n, uint64_t offset) :
	m_n(n),
	m_offset(offset),
	m_ws(ws)
{
}

template class VSGRAPH_API qworkspace_view<double>;
template class VSGRAPH_API qworkspace_view<float>;

template class VSGRAPH_API qworkspace_view<double*>;
template class VSGRAPH_API qworkspace_view<float*>;

#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qworkspace_view<__m512d>;
template class VSGRAPH_API qworkspace_view<__m512>;
#endif
template class VSGRAPH_API qworkspace_view<__m256d>;
template class VSGRAPH_API qworkspace_view<__m256>;
template class VSGRAPH_API qworkspace_view<__m128d>;
template class VSGRAPH_API qworkspace_view<__m128>;

#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qworkspace_view<__m512d*>;
template class VSGRAPH_API qworkspace_view<__m512*>;
#endif
template class VSGRAPH_API qworkspace_view<__m256d*>;
template class VSGRAPH_API qworkspace_view<__m256*>;
template class VSGRAPH_API qworkspace_view<__m128d*>;
template class VSGRAPH_API qworkspace_view<__m128*>;

template<class T>
qworkspace_view<T>::~qworkspace_view()
{
}

template<class T>
const uint64_t& qworkspace_view<T>::get_n() const
{
	return m_n;
}

template<class T>
const uint64_t& qworkspace_view<T>::get_offset() const
{
	return m_offset;
}

template<class T>
qworkspace<T>& qworkspace_view<T>::get_ws()
{
	return m_ws;
}

template<class T>
qworkspace_view<T> qworkspace<T>::operator()(uint64_t n, uint64_t offset)
{
	return qworkspace_view<T>(*this, n, offset);
}

