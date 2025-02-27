#pragma once

#include "qgraph_gpu_memory.h"
#include "qworkspace_gpu_memory.h"

template<class T>
void run_backward_amd(int device, const graph_gpu_memory<T>& graph_mem, workspace_gpu_memory<T>& workspace_mem, ADType direction);
