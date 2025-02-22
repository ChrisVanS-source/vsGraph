#include "qutils.h"
#include "qdefines.h"
using namespace vstech;

template class VSGRAPH_API _gpu_info<void>;

#include "qamd_utils.h"
#include "qnvidia_utils.cuh"

template<class T>
_gpu_info<T>::_gpu_info() {}

template<class T>
_gpu_info<T>::~_gpu_info() {}

template<class T>
int _gpu_info<T>::num_nvidia()
{
    return get_num_nvidia();
}

template<class T>
int _gpu_info<T>::num_fpoc_nvidia()
{
#ifdef __linux__
    return -1; // Unable to install ROCm on Ubuntu for some reason
#else
    return get_num_fpoc_nvidia();
#endif
}

template<class T>
int _gpu_info<T>::fpoc_nvidia_device(unsigned int n)
{
#ifdef __linux__
    return -1; // Unable to install ROCm on Ubuntu for some reason
#else
    return get_fpoc_nvidia_device(n);
#endif
}

template<class T>
int _gpu_info<T>::num_amd()
{
#ifdef __linux__
    return -1; // Unable to install ROCm on Ubuntu for some reason
#else
    return get_num_amd();
#endif
}

template<class T>
int _gpu_info<T>::num_fpoc_amd()
{
#ifdef __linux__
    return -1; // Unable to install ROCm on Ubuntu for some reason
#else
    return get_num_fpoc_amd();
#endif
}

template<class T>
int _gpu_info<T>::fpoc_amd_device(unsigned int n)
{
#ifdef __linux__
    return -1; // Unable to install ROCm on Ubuntu for some reason
#else
    return get_fpoc_amd_device(n);
#endif
}

