#include <hip/hip_runtime.h>
#include "qamd_forward.h"
#include "qgraph_gpu.h"

template void run_forward_amd(int device, const graph_gpu_memory<double>& graph_mem, workspace_gpu_memory<double>& workspace_mem);
template void run_forward_amd(int device, const graph_gpu_memory<float>& graph_mem, workspace_gpu_memory<float>& workspace_mem);

#include "qgraph_forward_gpu.h"

template<class T>
__global__ void run_forward_device(qgraph_gpu<T> g, graph_forward_gpu<T> visitor, size_t n)
{
	uint64_t threadID = blockDim.x * blockIdx.x + threadIdx.x;

	if (threadID >= n) return;

	g.sweep_forward(visitor, threadID);

}

#include "qexception.h"
using namespace vstech;

template<class T>
void run_forward_amd(int device, const graph_gpu_memory<T>& graph_mem, workspace_gpu_memory<T>& workspace_mem)
{
	hipSetDevice(device);

	uint64_t n = workspace_mem.m_n;
	
	dim3 blockSize(128, 1, 1);
	dim3 gridSize((unsigned int)n / 128 + 1, 1);

	run_forward_device<<<gridSize, blockSize>>>(qgraph_gpu<T>(graph_mem), graph_forward_gpu<T>(graph_mem, workspace_mem), n);

	hipError_t hipStatus = hipGetLastError();

	if (hipStatus != hipSuccess)
		throw qexception("Error running graph function on AMD");

	const auto& wksp_index = workspace_mem.m_output_wksp_index;
	T* p = workspace_mem.m_hh_mem.get();

	for (uint64_t i = 0; i < wksp_index.size(); ++i)
	{
		hipMemcpy(p, workspace_mem.m_hh_wksp[wksp_index[i]], n * sizeof(T), hipMemcpyDeviceToHost);
		p += n;
	}
}


