#pragma once

#include "intrin.h"
#include <cstdint>

namespace vstech {

	template<class T>
	struct qtype_traits {

		typedef T type;
		typedef T mapped_type;
		static uint64_t alignment() { return 1; }

	};

	template<>
	struct qtype_traits<float> {

		typedef float type;
		typedef double mapped_type;
		static uint64_t alignment() { return 1; }

	};

	template<>
	struct qtype_traits<__m512d> {

		typedef double type;
		typedef __m512d mapped_type;
		static uint64_t alignment() { return 8; }

	};

	template<>
	struct qtype_traits<__m512> {

		typedef float type;
		typedef __m512 mapped_type;
		static uint64_t alignment() { return 16; }

	};

	template<>
	struct qtype_traits<__m256d> {

		typedef double type;
		typedef __m256d mapped_type;
		static uint64_t alignment() { return 4; }

	};

	template<>
	struct qtype_traits<__m256> {

		typedef float type;
		typedef __m256 mapped_type;
		static uint64_t alignment() { return 8; }

	};

	template<>
	struct qtype_traits<__m128d> {

		typedef double type;
		typedef __m128d mapped_type;
		static uint64_t alignment() { return 2; }

	};

	template<>
	struct qtype_traits<__m128> {

		typedef float type;
		typedef __m128 mapped_type;
		static uint64_t alignment() { return 4; }

	};

}

