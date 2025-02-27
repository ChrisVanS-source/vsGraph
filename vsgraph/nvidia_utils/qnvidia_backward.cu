#include "cuda_runtime.h"
#include "qnvidia_backward.cuh"
#include "qgraph_gpu.h"

template void run_backward_nvidia(int device, const graph_gpu_memory<double>& graph_mem, workspace_gpu_memory<double>& workspace_mem, ADType direction);
template void run_backward_nvidia(int device, const graph_gpu_memory<float>& graph_mem, workspace_gpu_memory<float>& workspace_mem, ADType direction);

#include "qgraph_backward_gpu.h"
#include "qgraph_function_gpu.h"

template<class T>
__global__ void run_backward_device(qgraph_gpu<T> g, graph_function_gpu<T> fwd, graph_backward_gpu<T> bkwd, size_t n, ADType direction)
{
	uint64_t threadID = blockDim.x * blockIdx.x + threadIdx.x;

	if (threadID >= n) return;

	uint64_t skip_index = 0;

	if (direction != BACKWARD)
		g.sweep_forward(fwd, threadID);
	if (direction != FORWARD)
		g.sweep_backward(bkwd, fwd, skip_index, threadID);
}

#include "qexception.h"
using namespace vstech;

template<class T>
void run_backward_nvidia(int device, const graph_gpu_memory<T>& graph_mem, workspace_gpu_memory<T>& workspace_mem, ADType direction)
{
	cudaSetDevice(device);

	uint64_t n = workspace_mem.m_n;
	
	dim3 blockSize(128, 1, 1);
	dim3 gridSize((unsigned int)n / 128 + 1, 1);

	run_backward_device<<<gridSize, blockSize>>>(
		
		qgraph_gpu<T>(graph_mem), 
		graph_function_gpu<T>(graph_mem, workspace_mem),
		graph_backward_gpu<T>(graph_mem, workspace_mem),
		n,
		direction

	);

	cudaError_t cudaStatus = cudaGetLastError();

	if (cudaStatus != cudaSuccess)
		throw qexception("Error running graph function on NVIDIA");

	const auto& wksp_index = workspace_mem.m_output_wksp_index;
	T* p = workspace_mem.m_hh_mem.get();

	for (uint64_t i = 0; i < wksp_index.size(); ++i)
	{
		cudaMemcpy(p, workspace_mem.m_hh_wksp[wksp_index[i]], n * sizeof(T), cudaMemcpyDeviceToHost);
		p += n;
	}
}

