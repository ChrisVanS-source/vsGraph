#pragma once

#include "qgraph_gpu_memory.h"
#include "qworkspace_gpu_memory.h"
#include <vector>
#include <map>

int get_num_amd();
int get_num_fpoc_amd();
int get_fpoc_amd_device(unsigned int n);

// Graph memory allocation

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
	const std::vector<uint64_t>& checkpoint_ops_arg_index);

// Workspace memory allocation

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
	const std::vector<bool>& boolean);

// Set workspace

template<class T>
void set_wksp_amd(int device, workspace_gpu_memory<T>& memory, uint64_t x, const T& xv);

template<class T>
void set_wksp_amd(int device, workspace_gpu_memory<T>& memory, uint64_t x, const T* xv);


