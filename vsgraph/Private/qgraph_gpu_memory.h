#pragma once

#include <memory>
#include "qgraph_enum.h"

template<class T>
struct graph_gpu_memory
{
	uint64_t m_n_ops;
	std::shared_ptr<Operation[]> m_ops;
	uint64_t m_n_ops_arg_index;
	std::shared_ptr<uint64_t[]> m_ops_arg_index;
	std::shared_ptr<uint64_t[]> m_wksp_index;
	std::shared_ptr<uint64_t[]> m_integer_wksp_index;
	std::shared_ptr<uint64_t[]> m_boolean_wksp_index;
	std::shared_ptr<T[]> m_scalar;
	std::shared_ptr<int64_t[]> m_integer;
	std::shared_ptr<bool[]> m_boolean;
	std::shared_ptr<uint64_t[]> m_skip_ops_init;
	std::shared_ptr<uint64_t[]> m_skip_ops_arg_init;
	uint64_t m_var_counter;
	std::shared_ptr<uint64_t[]> m_checkpoint_ops_index;
	std::shared_ptr<uint64_t[]> m_checkpoint_ops_arg_index;
	uint64_t m_n_checkpoint_ops_index;

};


