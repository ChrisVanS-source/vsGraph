#pragma once

#include "intrin.h"
#include <vector>
#include <memory>
#include "qtype_traits.h"
#include "qinteger_i.h"
using namespace vstech;

// The below class is required to avoid a compile issue on linux when compiling the operator<

template<class T>
class _m_wrapper {

public:

	T m_;

	_m_wrapper(const T& m) : m_(m) {}
	~_m_wrapper() {}

	_m_wrapper(const _m_wrapper<T>& rhs) : m_(rhs.m_) {}

	_m_wrapper<T>& operator=(const _m_wrapper<T>& rhs)
	{
		if (&rhs != this)
		{
			m_ = rhs.m_;
		}
		return *this;
	}

	operator T() const { return m_; }

};

template<class T>
struct graph_traits
{
	typedef double scalar_type;
	typedef double scalar_type_map;
	typedef bool boolean_type;
	typedef typename qinteger_traits<T>::storage_type integer_type;

	// Dummy mem type
	typedef char mem_type;

	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<double>& wksp)
	{
	}

	static const double& cast(const double& x) { return x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }
};


template<>
struct graph_traits<double*>
{
	typedef double scalar_type;
	typedef double scalar_type_map;
	typedef bool boolean_type;
	typedef int64_t integer_type;

	typedef std::shared_ptr<double[]> mem_type;

	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<double*>& wksp);

	static const double& cast(const double& x) { return x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }

};

template<>
struct graph_traits<float*>
{
	typedef float scalar_type;
	typedef float scalar_type_map;
	typedef bool boolean_type;
	typedef int64_t integer_type;

	typedef std::shared_ptr<float[]> mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<float*>& wksp);

	static float cast(const double& x) { return (float)x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }

};

#ifdef INSTANTIATE_AVX512
template<>
struct graph_traits<__m512d*>
{
	typedef double scalar_type;
	typedef double scalar_type_map;
	typedef bool boolean_type;
	typedef int64_t integer_type;

	typedef std::shared_ptr<double[]> mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<double*>& wksp);

	static const double& cast(const double& x) { return x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }
};
#endif

template<>
struct graph_traits<__m256d*>
{
	typedef double scalar_type;
	typedef double scalar_type_map;
	typedef bool boolean_type;
	typedef int64_t integer_type;

	typedef std::shared_ptr<double[]> mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<double*>& wksp);

	static const double& cast(const double& x) { return x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }
};

template<>
struct graph_traits<__m128d*>
{
	typedef double scalar_type;
	typedef double scalar_type_map;
	typedef bool boolean_type;
	typedef int64_t integer_type;

	typedef std::shared_ptr<double[]> mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<double*>& wksp);

	static const double& cast(const double& x) { return x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }
};

#ifdef INSTANTIATE_AVX512
template<>
struct graph_traits<__m512*>
{
	typedef float scalar_type;
	typedef float scalar_type_map;
	typedef bool boolean_type;
	typedef int64_t integer_type;

	typedef std::shared_ptr<float[]> mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<float*>& wksp);

	static float cast(const double& x) { return (float)x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }
};
#endif

template<>
struct graph_traits<__m256*>
{
	typedef float scalar_type;
	typedef float scalar_type_map;
	typedef bool boolean_type;
	typedef int64_t integer_type;

	typedef std::shared_ptr<float[]> mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<float*>& wksp);

	static float cast(const double& x) { return (float)x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }
};

template<>
struct graph_traits<__m128*>
{
	typedef float scalar_type;
	typedef float scalar_type_map;
	typedef bool boolean_type;
	typedef int64_t integer_type;

	typedef std::shared_ptr<float[]> mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<float*>& wksp);

	static float cast(const double& x) { return (float)x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }
};


template<>
struct graph_traits<double>
{
	typedef double scalar_type;
	typedef double scalar_type_map;
	typedef bool boolean_type;
	typedef int64_t integer_type;

	// Dummy mem type
	typedef char mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<double>& wksp);

	static const double& cast(const double& x) { return x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }
};

template<>
struct graph_traits<float>
{
	typedef float scalar_type;
	typedef float scalar_type_map;
	typedef bool boolean_type;
	typedef int64_t integer_type;

	// Dummy mem type
	typedef char mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<float>& wksp);

	static float cast(const double& x) { return (float)x; }

	static bool cast(bool b) { return b; }

	static const int64_t& cast(const int64_t& i) { return i; }
};

#ifdef INSTANTIATE_AVX512
template<>
struct graph_traits<__m512d>
{
	typedef __m512d scalar_type;
	typedef _m_wrapper<__m512d> scalar_type_map;
	typedef std::vector<bool> boolean_type;
	typedef qinteger_traits<scalar_type>::storage_type integer_type;

	// Dummy mem type
	typedef char mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<__m512d>& wksp);

	static __m512d cast(const double& x) { return _mm512_set1_pd(x); }
	static const __m512d& cast(const __m512d& x) { return x; }

	static std::vector<bool> cast(bool b) { return std::vector<bool>(qtype_traits<scalar_type>::alignment(),b); }
	static const std::vector<bool>& cast(const std::vector<bool>& b) { return b; }

	static integer_type cast(const int64_t& i) { return integer_operation_traits<scalar_type>::create(i); }
	static const integer_type& cast(const integer_type& i) { return i; }
};

template<>
struct graph_traits<__m512>
{
	typedef __m512 scalar_type;
	typedef _m_wrapper<__m512> scalar_type_map;
	typedef std::vector<bool> boolean_type;
	typedef qinteger_traits<scalar_type>::storage_type integer_type;

	// Dummy mem type
	typedef char mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<__m512>& wksp);

	static __m512 cast(const double& x) { return _mm512_set1_ps((float)x); }
	static const __m512& cast(const __m512& x) { return x; }

	static std::vector<bool> cast(bool b) { return std::vector<bool>(qtype_traits<scalar_type>::alignment(), b); }
	static const std::vector<bool>& cast(const std::vector<bool>& b) { return b; }

	static integer_type cast(const int64_t& i) { return integer_operation_traits<scalar_type>::create(i); }
	static const integer_type& cast(const integer_type& i) { return i; }
};
#endif

template<>
struct graph_traits<__m256d>
{
	typedef __m256d scalar_type;
	typedef _m_wrapper<__m256d> scalar_type_map;
	typedef std::vector<bool> boolean_type;
	typedef qinteger_traits<scalar_type>::storage_type integer_type;

	// Dummy mem type
	typedef char mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<__m256d>& wksp);

	static __m256d cast(const double& x) { return _mm256_set1_pd(x); }
	static const __m256d& cast(const __m256d& x) { return x; }

	static std::vector<bool> cast(bool b) { return std::vector<bool>(qtype_traits<scalar_type>::alignment(), b); }
	static const std::vector<bool>& cast(const std::vector<bool>& b) { return b; }

	static integer_type cast(const int64_t& i) { return integer_operation_traits<scalar_type>::create(i); }
	static const integer_type& cast(const integer_type& i) { return i; }
};

template<>
struct graph_traits<__m256>
{
	typedef __m256 scalar_type;
	typedef _m_wrapper<__m256> scalar_type_map;
	typedef std::vector<bool> boolean_type;
	typedef qinteger_traits<scalar_type>::storage_type integer_type;

	// Dummy mem type
	typedef char mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<__m256>& wksp);

	static __m256 cast(const double& x) { return _mm256_set1_ps((float)x); }
	static const __m256& cast(const __m256& x) { return x; }

	static std::vector<bool> cast(bool b) { return std::vector<bool>(qtype_traits<scalar_type>::alignment(), b); }
	static const std::vector<bool>& cast(const std::vector<bool>& b) { return b; }

	static integer_type cast(const int64_t& i) { return integer_operation_traits<scalar_type>::create(i); }
	static const integer_type& cast(const integer_type& i) { return i; }
};

template<>
struct graph_traits<__m128d>
{
	typedef __m128d scalar_type;
	typedef _m_wrapper<__m128d> scalar_type_map;
	typedef std::vector<bool> boolean_type;
	typedef qinteger_traits<scalar_type>::storage_type integer_type;

	// Dummy mem type
	typedef char mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<__m128d>& wksp);

	static __m128d cast(const double& x) { return _mm_set1_pd(x); }
	static const __m128d& cast(const __m128d& x) { return x; }

	static std::vector<bool> cast(bool b) { return std::vector<bool>(qtype_traits<scalar_type>::alignment(), b); }
	static const std::vector<bool>& cast(const std::vector<bool>& b) { return b; }

	static integer_type cast(const int64_t& i) { return integer_operation_traits<scalar_type>::create(i); }
	static const integer_type& cast(const integer_type& i) { return i; }
};

template<>
struct graph_traits<__m128>
{
	typedef __m128 scalar_type;
	typedef _m_wrapper<__m128> scalar_type_map;
	typedef std::vector<bool> boolean_type;
	typedef qinteger_traits<scalar_type>::storage_type integer_type;

	// Dummy mem type
	typedef char mem_type;
	static void allocate_mem(uint64_t n, mem_type& mem, std::vector<__m128>& wksp);

	static __m128 cast(const double& x) { return _mm_set1_ps((float)x); }
	static const __m128& cast(const __m128& x) { return x; }

	static std::vector<bool> cast(bool b) { return std::vector<bool>(qtype_traits<scalar_type>::alignment(), b); }
	static const std::vector<bool>& cast(const std::vector<bool>& b) { return b; }

	static integer_type cast(const int64_t& i) { return integer_operation_traits<scalar_type>::create(i); }
	static const integer_type& cast(const integer_type& i) { return i; }
};
