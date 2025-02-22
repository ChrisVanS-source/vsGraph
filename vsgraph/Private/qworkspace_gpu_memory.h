#pragma once

#include <memory>
#include <vector>

template<class T>
struct workspace_gpu_memory
{
	uint64_t m_n;

	std::shared_ptr<T*[]> m_wksp;
	std::shared_ptr<T[]> m_mem_wksp;

	std::shared_ptr<int64_t*[]> m_integer_wksp;
	std::shared_ptr<int64_t[]> m_mem_integer_wksp;

	std::shared_ptr<bool*[]> m_boolean_wksp;
	std::shared_ptr<bool[]> m_mem_boolean_wksp;

	// Host handle for easy retrieval of final results

	std::vector<T*> m_hh_wksp; 
	std::vector<int64_t*> m_hh_integer_wksp;
	std::vector<bool*> m_hh_boolean_wksp;

	std::shared_ptr<T[]> m_hh_mem;
	std::vector<uint64_t> m_output_wksp_index;
};

