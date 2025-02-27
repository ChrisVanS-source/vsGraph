#include "cuda_runtime.h"
#include "qnvidia_utils.cuh"

int get_num_nvidia()
{
    int nDevices;
    if (cudaSuccess != cudaGetDeviceCount(&nDevices))
    	return 0;
    return nDevices;
}

__global__ void dummykernel_nvidia() {}

#include <vector>
#include <memory>

class nvidia_helper
{
    static std::shared_ptr<std::pair<std::vector<bool>, std::vector<int>>> m_fpo;

public:

    nvidia_helper() 
    {
        if (m_fpo.get() == 0)
        {
            m_fpo.reset(new std::pair<std::vector<bool>, std::vector<int>>());
            std::pair<std::vector<bool>, std::vector<int>>& fc = *m_fpo.get();
            for (int i = 0; i < get_num_nvidia(); ++i)
            {
                cudaSetDevice(i);
                dummykernel_nvidia<<<1,1>>>();
                fc.first.push_back(cudaGetLastError() == cudaSuccess);
                if (fc.first[i])
                    fc.second.push_back(i);
            }
        }
    }

    ~nvidia_helper() {}
    
    int get_num_fpoc_nvidia() const 
    { 
       	return (int)m_fpo->second.size(); 	
    }

    int get_fpoc_nvidia_device(unsigned int n) const 
    {
    	return n < m_fpo->second.size() ? m_fpo->second[n] : -1;
    }

};

std::shared_ptr<std::pair<std::vector<bool>, std::vector<int>>> nvidia_helper::m_fpo;

int get_num_fpoc_nvidia()
{
    return nvidia_helper().get_num_fpoc_nvidia();
}

int get_fpoc_nvidia_device(unsigned int n)
{
    return nvidia_helper().get_fpoc_nvidia_device(n);
}



// Graph memory

template void allocate_nvidia<double>(int device,
    graph_gpu_memory<double>& memory,
    uint64_t var_counter,
    const std::vector<Operation>& ops,
    const std::vector<uint64_t>& ops_arg_index,
    const std::vector<std::vector<uint64_t>>& wksp_index,
    const std::vector<double>& scalar,
    const std::vector<int64_t>& integer,
    const std::vector<bool>& boolean,
    const std::vector<uint64_t>& skip_ops_init,
    const std::vector<uint64_t>& skip_ops_arg_init,
    const std::vector<uint64_t>& checkpoint_ops_index,
    const std::vector<uint64_t>& checkpoint_ops_arg_index);

template void allocate_nvidia<float>(int device,
    graph_gpu_memory<float>& memory,
    uint64_t var_counter,
    const std::vector<Operation>& ops,
    const std::vector<uint64_t>& ops_arg_index,
    const std::vector<std::vector<uint64_t>>& wksp_index,
    const std::vector<float>& scalar,
    const std::vector<int64_t>& integer,
    const std::vector<bool>& boolean,
    const std::vector<uint64_t>& skip_ops_init,
    const std::vector<uint64_t>& skip_ops_arg_init,
    const std::vector<uint64_t>& checkpoint_ops_index,
    const std::vector<uint64_t>& checkpoint_ops_arg_index);

// Workspace memory

template void allocate_nvidia<double>(uint64_t n, int device,
    workspace_gpu_memory<double>& memory,
    const std::vector<uint64_t>& output_wksp_index,
    std::vector<double*>& wksp,
    std::shared_ptr<double[]> mem,
    std::vector<std::vector<int64_t>>& integer_wksp,
    std::vector<std::vector<bool>>& boolean_wksp,
    const std::vector<uint64_t>& wksp_index,
    const std::vector<uint64_t>& integer_wksp_index,
    const std::vector<uint64_t>& boolean_wksp_index,
    const std::vector<std::map<uint64_t, uint64_t>>& assign_map,
    const std::vector<double>& scalar,
    const std::vector<int64_t>& integer,
    const std::vector<bool>& boolean);

template void allocate_nvidia<float>(uint64_t n, int device,
    workspace_gpu_memory<float>& memory,
    const std::vector<uint64_t>& output_wksp_index,
    std::vector<float*>& wksp,
    std::shared_ptr<float[]> mem,
    std::vector<std::vector<int64_t>>& integer_wksp,
    std::vector<std::vector<bool>>& boolean_wksp,
    const std::vector<uint64_t>& wksp_index,
    const std::vector<uint64_t>& integer_wksp_index,
    const std::vector<uint64_t>& boolean_wksp_index,
    const std::vector<std::map<uint64_t, uint64_t>>& assign_map,
    const std::vector<float>& scalar,
    const std::vector<int64_t>& integer,
    const std::vector<bool>& boolean);

cudaError_t freeDeviceMemory(void* devPtr)
{
    return cudaFree(devPtr);
}


template<class T>
cudaError_t allocate_copy(std::shared_ptr<T[]>& vd, const std::vector<T>& vh)
{
    cudaError_t cudaStatus;
    T* p = 0;
    cudaStatus = cudaMalloc((void**)&p, vh.size() * sizeof(T));
    if (cudaStatus != cudaSuccess)
        return cudaStatus;
    vd.reset(p, freeDeviceMemory);

    if (vh.size() == 0)
        return cudaStatus;

    cudaStatus = cudaMemcpy(p, &vh[0], vh.size() * sizeof(T), cudaMemcpyHostToDevice);
    return cudaStatus;
}

template<>
cudaError_t allocate_copy<bool>(std::shared_ptr<bool[]>& vd, const std::vector<bool>& _vh)
{
    std::shared_ptr<bool[]> vh(new bool[_vh.size()]);

    for (uint64_t i = 0; i < _vh.size(); ++i)
        vh.get()[i] = _vh[i];

    cudaError_t cudaStatus;
    bool* p = 0;
    cudaStatus = cudaMalloc((void**)&p, _vh.size() * sizeof(bool));
    if (cudaStatus != cudaSuccess)
        return cudaStatus;
    vd.reset(p, freeDeviceMemory);

    if (_vh.size() == 0)
        return cudaStatus;

    cudaStatus = cudaMemcpy(p, vh.get(), _vh.size() * sizeof(bool), cudaMemcpyHostToDevice);
    return cudaStatus;
}

#include "qexception.h"
using namespace vstech;

#define CUDA_CHECK(status) if (status != cudaSuccess) throw qexception("Memory allocation/copy failed on NVIDIA GPU")

// Graph

template<class T>
void allocate_nvidia(int device,
    graph_gpu_memory<T>& memory,
    uint64_t var_counter,
    const std::vector<Operation>& ops,
    const std::vector<uint64_t>& ops_arg_index,
    const std::vector<std::vector<uint64_t>>& wksp_index,
    const std::vector<T>& scalar,
    const std::vector<int64_t>& integer,
    const std::vector<bool>& boolean,
    const std::vector<uint64_t>& skip_ops_init,
    const std::vector<uint64_t>& skip_ops_arg_init,
    const std::vector<uint64_t>& checkpoint_ops_index,
    const std::vector<uint64_t>& checkpoint_ops_arg_index)
{
    cudaSetDevice(device);

    memory.m_n_ops = ops.size();
    memory.m_n_ops_arg_index = ops_arg_index.size();
    memory.m_var_counter = var_counter;
    memory.m_n_checkpoint_ops_index = checkpoint_ops_index.size();

    CUDA_CHECK(allocate_copy<Operation>(memory.m_ops, ops));
    CUDA_CHECK(allocate_copy<uint64_t>(memory.m_ops_arg_index, ops_arg_index));
    CUDA_CHECK(allocate_copy<uint64_t>(memory.m_wksp_index, wksp_index[QFLOATING_POINT]));
    CUDA_CHECK(allocate_copy<uint64_t>(memory.m_integer_wksp_index, wksp_index[QINTEGER]));
    CUDA_CHECK(allocate_copy<uint64_t>(memory.m_boolean_wksp_index, wksp_index[QBOOLEAN]));
    CUDA_CHECK(allocate_copy<T>(memory.m_scalar, scalar));
    CUDA_CHECK(allocate_copy<int64_t>(memory.m_integer, integer));
    CUDA_CHECK(allocate_copy<bool>(memory.m_boolean, boolean));
    CUDA_CHECK(allocate_copy<uint64_t>(memory.m_skip_ops_init, skip_ops_init));
    CUDA_CHECK(allocate_copy<uint64_t>(memory.m_skip_ops_arg_init, skip_ops_arg_init));
    CUDA_CHECK(allocate_copy<uint64_t>(memory.m_checkpoint_ops_index, checkpoint_ops_index));
    CUDA_CHECK(allocate_copy<uint64_t>(memory.m_checkpoint_ops_arg_index, checkpoint_ops_arg_index));
}

// Workspace

#include <thrust/fill.h>
#include <thrust/device_vector.h>

template<class T>
void assign_nvidia(T* x, const T& x0, size_t n)
{
    thrust::device_ptr<T> ptr(x);
    thrust::fill(ptr, ptr + n, x0);
}


template<class T>
void allocate_nvidia(uint64_t n, int device,
    workspace_gpu_memory<T>& memory,
    const std::vector<uint64_t>& output_wksp_index,
    std::vector<T*>& wksp,
    std::shared_ptr<T[]> mem,
    std::vector<std::vector<int64_t>>& integer_wksp,
    std::vector<std::vector<bool>>& boolean_wksp,
    const std::vector<uint64_t>& wksp_index,
    const std::vector<uint64_t>& integer_wksp_index,
    const std::vector<uint64_t>& boolean_wksp_index,
    const std::vector<std::map<uint64_t, uint64_t>>& assign_map,
    const std::vector<T>& scalar,
    const std::vector<int64_t>& integer,
    const std::vector<bool>& boolean)
{
    cudaSetDevice(device);

    memory.m_n = n;
    memory.m_hh_mem = mem;
    memory.m_output_wksp_index = output_wksp_index;

    // Scalar

    T* p = 0;

    CUDA_CHECK(cudaMalloc((void**)&p, n * wksp.size() * sizeof(T)));
    memory.m_mem_wksp.reset(p, freeDeviceMemory);

    memory.m_hh_wksp.resize(wksp.size());

    for (uint64_t i = 0; i < wksp.size(); ++i) {
        memory.m_hh_wksp[i] = p;
        p += n;
    }

    CUDA_CHECK(allocate_copy<T*>(memory.m_wksp, memory.m_hh_wksp));

    for (auto it = assign_map[QFLOATING_POINT].begin(); it != assign_map[QFLOATING_POINT].end(); ++it)
        assign_nvidia(memory.m_hh_wksp[wksp_index[it->first]], scalar[it->second], n);

    // Integer

    int64_t* integer_p = 0;

    CUDA_CHECK(cudaMalloc((void**)&integer_p, n * integer_wksp.size() * sizeof(int64_t)));

    memory.m_mem_integer_wksp.reset(integer_p, freeDeviceMemory);

    memory.m_hh_integer_wksp.resize(integer_wksp.size());

    for (size_t i = 0; i < integer_wksp.size(); ++i) {
        memory.m_hh_integer_wksp[i] = integer_p;
        integer_p += n;
    }

    CUDA_CHECK(allocate_copy<int64_t*>(memory.m_integer_wksp, memory.m_hh_integer_wksp));

    for (auto it = assign_map[QINTEGER].begin(); it != assign_map[QINTEGER].end(); ++it)
        assign_nvidia(memory.m_hh_integer_wksp[integer_wksp_index[it->first]], integer[it->second], n);

    // Boolean

    bool* boolean_p = 0;

    CUDA_CHECK(cudaMalloc((void**)&boolean_p, n * boolean_wksp.size() * sizeof(bool)));

    memory.m_mem_boolean_wksp.reset(boolean_p, freeDeviceMemory);

    memory.m_hh_boolean_wksp.resize(boolean_wksp.size());

    for (size_t i = 0; i < boolean_wksp.size(); ++i) {
        memory.m_hh_boolean_wksp[i] = boolean_p;
        boolean_p += n;
    }

    CUDA_CHECK(allocate_copy<bool*>(memory.m_boolean_wksp, memory.m_hh_boolean_wksp));

    for (auto it = assign_map[QBOOLEAN].begin(); it != assign_map[QBOOLEAN].end(); ++it)
        assign_nvidia(memory.m_hh_boolean_wksp[boolean_wksp_index[it->first]], boolean[it->second], n);
}

// Set workspace

template void set_wksp_nvidia(int device, workspace_gpu_memory<double>& memory, uint64_t x, const double& xv);
template void set_wksp_nvidia(int device, workspace_gpu_memory<float>& memory, uint64_t x, const float& xv);

template<class T>
void set_wksp_nvidia(int device, workspace_gpu_memory<T>& memory, uint64_t x, const T& xv)
{
    cudaSetDevice(device);
    assign_nvidia(memory.m_hh_wksp[x], xv, memory.m_n);
}

template void set_wksp_nvidia(int device, workspace_gpu_memory<double>& memory, uint64_t x, const double* xv);
template void set_wksp_nvidia(int device, workspace_gpu_memory<float>& memory, uint64_t x, const float* xv);

template<class T>
void set_wksp_nvidia(int device, workspace_gpu_memory<T>& memory, uint64_t x, const T* xv)
{
    cudaSetDevice(device);
    cudaMemcpy(memory.m_hh_wksp[x], xv, memory.m_n * sizeof(T), cudaMemcpyHostToDevice);
}
