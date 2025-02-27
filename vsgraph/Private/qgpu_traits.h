#pragma once

#pragma once

#include <memory>
#include "qtype_traits.h"
#include "qinteger.h"
using namespace vstech;

#include "qgraph_gpu_memory.h"
#include "qworkspace_gpu_memory.h"

template<class T>
struct gpu_traits {

	typedef char graph_memory;
	typedef char workspace_memory;

};

template<class T>
struct gpu_traits<T*> {

	typedef graph_gpu_memory<typename qtype_traits<T>::type> graph_memory;
	typedef workspace_gpu_memory<typename qtype_traits<T>::type> workspace_memory;

};


