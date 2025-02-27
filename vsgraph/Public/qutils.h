#pragma once

#include <cstdint>

namespace vstech {

	template<class T>
	class _cpu_info {

		_cpu_info();
		~_cpu_info();

	public:

		static bool has_avx512();

	};

	typedef _cpu_info<void> cpu_info;

	template<class T>
	class _gpu_info {

		_gpu_info();
		~_gpu_info();

	public:

		// NVIDIA GPU

		static int num_nvidia();
		static int num_fpoc_nvidia();
		static int fpoc_nvidia_device(unsigned int n);

		// AMD GPU

		static int num_amd();
		static int num_fpoc_amd();
		static int fpoc_amd_device(unsigned int n);


	};

	typedef _gpu_info<void> gpu_info;

}