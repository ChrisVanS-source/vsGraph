#include <hip/hip_runtime.h>
#include "qamd_utils.h"

int get_num_amd()
{
    int nDevices;
    if (hipSuccess != hipGetDeviceCount(&nDevices))
    	return 0;
    return nDevices;
}

__global__ void dummykernel_amd() {}

#include <vector>
#include <memory>

class amd_helper
{
    static std::shared_ptr<std::pair<std::vector<bool>, std::vector<int>>> m_fpo;

public:

    amd_helper() 
    {
        if (m_fpo.get() == 0)
        {
            m_fpo.reset(new std::pair<std::vector<bool>, std::vector<int>>());
            std::pair<std::vector<bool>, std::vector<int>>& fc = *m_fpo.get();
            for (int i = 0; i < get_num_amd(); ++i)
            {
                hipSetDevice(i);
                dummykernel_amd<<<1,1,0,0>>>();
                fc.first.push_back(hipGetLastError() == hipSuccess);
                if (fc.first[i])
                    fc.second.push_back(i);
            }
        }
    }

    ~amd_helper() {}
    
    int get_num_fpoc_amd() const 
    { 
        return (int)m_fpo->second.size(); 
    }

    int get_fpoc_amd_device(unsigned int n) const 
    {
    	return n < m_fpo->second.size() ? m_fpo->second[n] : -1;
    }

};

std::shared_ptr<std::pair<std::vector<bool>, std::vector<int>>> amd_helper::m_fpo;

int get_num_fpoc_amd()
{
    return amd_helper().get_num_fpoc_amd();
}

int get_fpoc_amd_device(unsigned int n)
{
    return amd_helper().get_fpoc_amd_device(n);
}



// Graph memory

template void allocate_amd<double>(int device, 
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


template void allocate_amd<float>(int device, 
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

// Workspace

template void allocate_amd<double>(uint64_t n, int device, 
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

template void allocate_amd<float>(uint64_t n, int device, 
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

hipError_t freeDeviceMemory(void* devPtr)
{
    return hipFree(devPtr);
}


template<class T>
hipError_t allocate_copy(std::shared_ptr<T[]>& vd, const std::vector<T>& vh)
{
    hipError_t hipStatus;
    T* p = 0;
    hipStatus = hipMalloc((void**)&p, vh.size() * sizeof(T));
    if (hipStatus != hipSuccess)
        return hipStatus;
    vd.reset(p, freeDeviceMemory);

    if (vh.size() == 0)
        return hipStatus;

    hipStatus = hipMemcpy(p, &vh[0], vh.size() * sizeof(T), hipMemcpyHostToDevice);
    return hipStatus;
}

template<>
hipError_t allocate_copy<bool>(std::shared_ptr<bool[]>& vd, const std::vector<bool>& _vh)
{
    std::shared_ptr<bool[]> vh(new bool[_vh.size()]);

    for (uint64_t i = 0; i < _vh.size(); ++i)
        vh.get()[i] = _vh[i];

    hipError_t hipStatus;
    bool* p = 0;
    hipStatus = hipMalloc((void**)&p, _vh.size() * sizeof(bool));
    if (hipStatus != hipSuccess)
        return hipStatus;
    vd.reset(p, freeDeviceMemory);

    if (_vh.size() == 0)
        return hipStatus;

    hipStatus = hipMemcpy(p, vh.get(), _vh.size() * sizeof(bool), hipMemcpyHostToDevice);
    return hipStatus;
}

#include "qexception.h"
using namespace vstech;

#define HIP_CHECK(status) if (status != hipSuccess) throw qexception("Memory allocation/copy failed on AMD GPU")

// Graph

template<class T>
void allocate_amd(int device, 
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
    hipSetDevice(device);

    memory.m_n_ops = ops.size();
    memory.m_n_ops_arg_index = ops_arg_index.size();
    memory.m_var_counter = var_counter;
    memory.m_n_checkpoint_ops_index = checkpoint_ops_index.size();

    HIP_CHECK(allocate_copy<Operation>(memory.m_ops, ops));
    HIP_CHECK(allocate_copy<uint64_t>(memory.m_ops_arg_index, ops_arg_index));
    HIP_CHECK(allocate_copy<uint64_t>(memory.m_wksp_index, wksp_index[QFLOATING_POINT]));
    HIP_CHECK(allocate_copy<uint64_t>(memory.m_integer_wksp_index, wksp_index[QINTEGER]));
    HIP_CHECK(allocate_copy<uint64_t>(memory.m_boolean_wksp_index, wksp_index[QBOOLEAN]));
    HIP_CHECK(allocate_copy<T>(memory.m_scalar, scalar));
    HIP_CHECK(allocate_copy<int64_t>(memory.m_integer, integer));
    HIP_CHECK(allocate_copy<bool>(memory.m_boolean, boolean));
    HIP_CHECK(allocate_copy<uint64_t>(memory.m_skip_ops_init, skip_ops_init));
    HIP_CHECK(allocate_copy<uint64_t>(memory.m_skip_ops_arg_init, skip_ops_arg_init));
    HIP_CHECK(allocate_copy<uint64_t>(memory.m_checkpoint_ops_index, checkpoint_ops_index));
    HIP_CHECK(allocate_copy<uint64_t>(memory.m_checkpoint_ops_arg_index, checkpoint_ops_arg_index));
}

// Workspace
// Not using thrust as it seems to clash with CUDA



template<class T>
void assign_amd(T* x, const T& x0, size_t n)
{
    std::shared_ptr<T[]> v(new T[n]);
    std::fill(v.get(),v.get()+n,x0);
    hipMemcpy(x, v.get(), n * sizeof(T), hipMemcpyHostToDevice);
}

template<class T>
void allocate_amd(uint64_t n, int device, 
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
    hipSetDevice(device);

    memory.m_n = n;
    memory.m_hh_mem = mem;
    memory.m_output_wksp_index = output_wksp_index;

    // Scalar

    T* p = 0;

    HIP_CHECK(hipMalloc((void**)&p, n * wksp.size() * sizeof(T)));
    memory.m_mem_wksp.reset(p, freeDeviceMemory);

    memory.m_hh_wksp.resize(wksp.size());

    for (uint64_t i = 0; i < wksp.size(); ++i) {
        memory.m_hh_wksp[i] = p;
        p += n;
    }

    HIP_CHECK(allocate_copy<T*>(memory.m_wksp, memory.m_hh_wksp));

    for (auto it = assign_map[QFLOATING_POINT].begin(); it != assign_map[QFLOATING_POINT].end(); ++it)
        assign_amd(memory.m_hh_wksp[wksp_index[it->first]], scalar[it->second], n);

    // Integer

    int64_t* integer_p = 0;

    HIP_CHECK(hipMalloc((void**)&integer_p, n * integer_wksp.size() * sizeof(int64_t)));

    memory.m_mem_integer_wksp.reset(integer_p, freeDeviceMemory);

    memory.m_hh_integer_wksp.resize(integer_wksp.size());

    for (size_t i = 0; i < integer_wksp.size(); ++i) {
        memory.m_hh_integer_wksp[i] = integer_p;
        integer_p += n;
    }

    HIP_CHECK(allocate_copy<int64_t*>(memory.m_integer_wksp, memory.m_hh_integer_wksp));

    for (auto it = assign_map[QINTEGER].begin(); it != assign_map[QINTEGER].end(); ++it)
        assign_amd(memory.m_hh_integer_wksp[integer_wksp_index[it->first]], integer[it->second], n);

    // Boolean

    bool* boolean_p = 0;

    HIP_CHECK(hipMalloc((void**)&boolean_p, n * boolean_wksp.size() * sizeof(bool)));

    memory.m_mem_boolean_wksp.reset(boolean_p, freeDeviceMemory);

    memory.m_hh_boolean_wksp.resize(boolean_wksp.size());

    for (size_t i = 0; i < boolean_wksp.size(); ++i) {
        memory.m_hh_boolean_wksp[i] = boolean_p;
        boolean_p += n;
    }

    HIP_CHECK(allocate_copy<bool*>(memory.m_boolean_wksp, memory.m_hh_boolean_wksp));

    for (auto it = assign_map[QBOOLEAN].begin(); it != assign_map[QBOOLEAN].end(); ++it)
        assign_amd(memory.m_hh_boolean_wksp[boolean_wksp_index[it->first]], boolean[it->second], n);
}

// Set workspace

template void set_wksp_amd(int device, workspace_gpu_memory<double>& memory, uint64_t x, const double& xv);
template void set_wksp_amd(int device, workspace_gpu_memory<float>& memory, uint64_t x, const float& xv);

template<class T>
void set_wksp_amd(int device, workspace_gpu_memory<T>& memory, uint64_t x, const T& xv)
{
    hipSetDevice(device);
    assign_amd(memory.m_hh_wksp[x], xv, memory.m_n);
}

template void set_wksp_amd(int device, workspace_gpu_memory<double>& memory, uint64_t x, const double* xv);
template void set_wksp_amd(int device, workspace_gpu_memory<float>& memory, uint64_t x, const float* xv);

template<class T>
void set_wksp_amd(int device, workspace_gpu_memory<T>& memory, uint64_t x, const T* xv)
{
    hipSetDevice(device);
    hipMemcpy(memory.m_hh_wksp[x], xv, memory.m_n * sizeof(T), hipMemcpyHostToDevice);
}
