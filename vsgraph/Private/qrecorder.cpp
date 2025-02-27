#include "qdefines.h"
#include "qrecorder.h"
#include <memory>
#include "intrin.h"
#include "qpci_pattern.h"

PCI_PATTERN(qrecorder)

template class VSGRAPH_API qrecorder<double>;
template class VSGRAPH_API qrecorder<float>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qrecorder<__m512d>;
template class VSGRAPH_API qrecorder<__m512>;
#endif
template class VSGRAPH_API qrecorder<__m256d>;
template class VSGRAPH_API qrecorder<__m256>;
template class VSGRAPH_API qrecorder<__m128d>;
template class VSGRAPH_API qrecorder<__m128>;

template class VSGRAPH_API qrecorder<double*>;
template class VSGRAPH_API qrecorder<float*>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qrecorder<__m512d*>;
template class VSGRAPH_API qrecorder<__m512*>;
#endif
template class VSGRAPH_API qrecorder<__m256d*>;
template class VSGRAPH_API qrecorder<__m256*>;
template class VSGRAPH_API qrecorder<__m128d*>;
template class VSGRAPH_API qrecorder<__m128*>;

#include "qrecorder_i.h"

#include <thread>
#include <map>

template<class T>
static std::map<std::thread::id, std::shared_ptr<qrecorder_i<T>>> m_recorder;

#include <mutex>

std::mutex mutex;

template<class T>
std::shared_ptr<qrecorder_i<T>> recorder()
{
	std::lock_guard<std::mutex> guard(mutex);
	return m_recorder<T>[std::this_thread::get_id()];
}

// Not clear why we have to do this on linux and only for the non-pointer versions

#ifdef __linux__
#include "intrin.h"
template qrecorder_i<double>* recorder_ptr();
template qrecorder_i<float>* recorder_ptr();
#ifdef INSTANTIATE_AVX512
template qrecorder_i<__m512d>* recorder_ptr();
template qrecorder_i<__m512>* recorder_ptr();
#endif
template qrecorder_i<__m256d>* recorder_ptr();
template qrecorder_i<__m256>* recorder_ptr();
template qrecorder_i<__m128d>* recorder_ptr();
template qrecorder_i<__m128>* recorder_ptr();
#endif

template<class T>
qrecorder_i<T>* recorder_ptr()
{
	return recorder<T>().get();
}

template<class T>
void reset_recorder(qrecorder_i<T>* i)
{
	std::lock_guard<std::mutex> guard(mutex);
	m_recorder<T>[std::this_thread::get_id()].reset(i);
}

template<class T>
qrecorder<T>::qrecorder() : m_p(0)
{}

#include "qrecorder_traits.h"

template<class T>
void qrecorder<T>::start()
{
	if (m_p)
		delete m_p;
	reset_recorder(make_recorder<T>());
	recorder_traits<T>::redirect(recorder_ptr<T>());
	m_p = new qrecorder_c<T>(recorder<T>());
}

template<class T>
void qrecorder<T>::stop()
{
	reset_recorder<T>();
	recorder_traits<T>::undirect();
	get_impl(m_p)->post_process();
}

template<class T>
void qrecorder<T>::checkpoint()
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->checkpoint();
}

#include "qgraph_i.h"

template<class T>
qgraph<T> qrecorder<T>::graph() const
{
	return make_graph(get_impl(m_p)->m_g);
}


template struct VSGRAPH_API qrecorder_helper<double, double>;
template struct VSGRAPH_API qrecorder_helper<double, float>;

template struct VSGRAPH_API qrecorder_helper<float, float>;
template struct VSGRAPH_API qrecorder_helper<float, double>;

template struct VSGRAPH_API qrecorder_helper<double*, double>;
template struct VSGRAPH_API qrecorder_helper<double*, float>;

template struct VSGRAPH_API qrecorder_helper<float*, double>;
template struct VSGRAPH_API qrecorder_helper<float*, float>;

#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qrecorder_helper<__m512d, __m512d>;
template struct VSGRAPH_API qrecorder_helper<__m512d, double>;
template struct VSGRAPH_API qrecorder_helper<__m512d, float>;

template struct VSGRAPH_API qrecorder_helper<__m512, __m512>;
template struct VSGRAPH_API qrecorder_helper<__m512, double>;
template struct VSGRAPH_API qrecorder_helper<__m512, float>;
#endif

template struct VSGRAPH_API qrecorder_helper<__m256d, __m256d>;
template struct VSGRAPH_API qrecorder_helper<__m256d, double>;
template struct VSGRAPH_API qrecorder_helper<__m256d, float>;

template struct VSGRAPH_API qrecorder_helper<__m256, __m256>;
template struct VSGRAPH_API qrecorder_helper<__m256, double>;
template struct VSGRAPH_API qrecorder_helper<__m256, float>;

template struct VSGRAPH_API qrecorder_helper<__m128d, __m128d>;
template struct VSGRAPH_API qrecorder_helper<__m128d, double>;
template struct VSGRAPH_API qrecorder_helper<__m128d, float>;

template struct VSGRAPH_API qrecorder_helper<__m128, __m128>;
template struct VSGRAPH_API qrecorder_helper<__m128, double>;
template struct VSGRAPH_API qrecorder_helper<__m128, float>;

#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qrecorder_helper<__m512d*, double>;
template struct VSGRAPH_API qrecorder_helper<__m512d*, float>;
#endif

template struct VSGRAPH_API qrecorder_helper<__m256d*, double>;
template struct VSGRAPH_API qrecorder_helper<__m256d*, float>;

template struct VSGRAPH_API qrecorder_helper<__m128d*, double>;
template struct VSGRAPH_API qrecorder_helper<__m128d*, float>;

#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qrecorder_helper<__m512*, double>;
template struct VSGRAPH_API qrecorder_helper<__m512*, float>;
#endif

template struct VSGRAPH_API qrecorder_helper<__m256*, double>;
template struct VSGRAPH_API qrecorder_helper<__m256*, float>;

template struct VSGRAPH_API qrecorder_helper<__m128*, double>;
template struct VSGRAPH_API qrecorder_helper<__m128*, float>;

template<class T, class U>
qscalar<U>& qrecorder_helper<T, U>::input(qrecorder<T>& r, qscalar<U>& x)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->input(x);

	return x;
}

template<class T, class U>
const qscalar<U>& qrecorder_helper<T, U>::input(qrecorder<T>& r, const qscalar<U>& x)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->input(x);

	return x;
}

template<class T, class U>
qscalar<U>& qrecorder_helper<T, U>::input(qrecorder<T>& r, qscalar<U>& x, const const_char_star& s)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->input(x, s.m_s);

	return x;
}

template<class T, class U>
const qscalar<U>& qrecorder_helper<T, U>::input(qrecorder<T>& r, const qscalar<U>& x, const const_char_star& s)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->input(x, s.m_s);

	return x;
}

template<class T, class U>
qscalar<U>& qrecorder_helper<T, U>::param(qrecorder<T>& r, qscalar<U>& x)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->param(x);

	return x;
}

template<class T, class U>
const qscalar<U>& qrecorder_helper<T, U>::param(qrecorder<T>& r, const qscalar<U>& x)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->param(x);

	return x;
}

template<class T, class U>
qscalar<U>& qrecorder_helper<T, U>::param(qrecorder<T>& r, qscalar<U>& x, const const_char_star& s)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->param(x, s.m_s);

	return x;
}

template<class T, class U>
const qscalar<U>& qrecorder_helper<T, U>::param(qrecorder<T>& r, const qscalar<U>& x, const const_char_star& s)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->param(x, s.m_s);

	return x;
}

template<class T, class U>
qscalar<U>& qrecorder_helper<T, U>::output(qrecorder<T>& r, qscalar<U>& x)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->output(x);

	return x;
}

template<class T, class U>
const qscalar<U>& qrecorder_helper<T, U>::output(qrecorder<T>& r, const qscalar<U>& x)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->output(x);

	return x;
}

template<class T, class U>
qscalar<U>& qrecorder_helper<T, U>::output(qrecorder<T>& r, qscalar<U>& x, const const_char_star& s)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->output(x, s.m_s);

	return x;
}

template<class T, class U>
const qscalar<U>& qrecorder_helper<T, U>::output(qrecorder<T>& r, const qscalar<U>& x, const const_char_star& s)
{
	auto recorder = recorder_ptr<T>();

	if (recorder)
		recorder->output(x, s.m_s);

	return x;
}