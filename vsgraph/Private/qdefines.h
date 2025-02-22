#pragma once

#define INSTANTIATE_AVX512

#ifndef VSGRAPH_API
#ifdef __linux__
#define VSGRAPH_API
#else
#ifdef VSGRAPH_EXPORTS
#define VSGRAPH_API __declspec(dllexport)
#else
#define VSGRAPH_API __declspec(dllimport)
#endif
#endif
#endif
