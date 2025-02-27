#pragma once

#include "qrecorder_i.h"
#include "immintrin.h"

template<class T>
struct recorder_traits
{
	static void redirect(qrecorder_i<T>* i) {}
	static void undirect() {}

};

template<>
struct recorder_traits<double>
{
	static void redirect(qrecorder_i<double>* i);
	static void undirect();
};

template<>
struct recorder_traits<float>
{
	static void redirect(qrecorder_i<float>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m512d>
{
	static void redirect(qrecorder_i<__m512d>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m512>
{
	static void redirect(qrecorder_i<__m512>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m256d>
{
	static void redirect(qrecorder_i<__m256d>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m256>
{
	static void redirect(qrecorder_i<__m256>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m128d>
{
	static void redirect(qrecorder_i<__m128d>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m128>
{
	static void redirect(qrecorder_i<__m128>* i);
	static void undirect();
};

template<>
struct recorder_traits<double*>
{
	static void redirect(qrecorder_i<double*>* i);
	static void undirect();
};

template<>
struct recorder_traits<float*>
{
	static void redirect(qrecorder_i<float*>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m512d*>
{
	static void redirect(qrecorder_i<__m512d*>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m512*>
{
	static void redirect(qrecorder_i<__m512*>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m256d*>
{
	static void redirect(qrecorder_i<__m256d*>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m256*>
{
	static void redirect(qrecorder_i<__m256*>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m128d*>
{
	static void redirect(qrecorder_i<__m128d*>* i);
	static void undirect();
};

template<>
struct recorder_traits<__m128*>
{
	static void redirect(qrecorder_i<__m128*>* i);
	static void undirect();
};
