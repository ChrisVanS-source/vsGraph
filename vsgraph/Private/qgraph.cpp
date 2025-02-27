#include "qgraph.h"
#include "qdefines.h"
#include "qpci_pattern.h"
#include "intrin.h"

PCI_PATTERN(qgraph)

template class VSGRAPH_API qgraph<double>;
template class VSGRAPH_API qgraph<float>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qgraph<__m512d>;
template class VSGRAPH_API qgraph<__m512>;
#endif
template class VSGRAPH_API qgraph<__m256d>;
template class VSGRAPH_API qgraph<__m256>;
template class VSGRAPH_API qgraph<__m128d>;
template class VSGRAPH_API qgraph<__m128>;

template class VSGRAPH_API qgraph<double*>;
template class VSGRAPH_API qgraph<float*>;
#ifdef INSTANTIATE_AVX512
template class VSGRAPH_API qgraph<__m512d*>;
template class VSGRAPH_API qgraph<__m512*>;
#endif
template class VSGRAPH_API qgraph<__m256d*>;
template class VSGRAPH_API qgraph<__m256*>;
template class VSGRAPH_API qgraph<__m128d*>;
template class VSGRAPH_API qgraph<__m128*>;

#include "qgraph_i.h"

template<class T>
qgraph<T>::qgraph() : m_p(0)
{}

template qgraph<double> make_graph(std::shared_ptr<qgraph_i<double>> i);
template qgraph<float> make_graph(std::shared_ptr<qgraph_i<float>> i);
#ifdef INSTANTIATE_AVX512
template qgraph<__m512d> make_graph(std::shared_ptr<qgraph_i<__m512d>> i);
template qgraph<__m512> make_graph(std::shared_ptr<qgraph_i<__m512>> i);
#endif
template qgraph<__m256d> make_graph(std::shared_ptr<qgraph_i<__m256d>> i);
template qgraph<__m256> make_graph(std::shared_ptr<qgraph_i<__m256>> i);
template qgraph<__m128d> make_graph(std::shared_ptr<qgraph_i<__m128d>> i);
template qgraph<__m128> make_graph(std::shared_ptr<qgraph_i<__m128>> i);

template qgraph<double*> make_graph(std::shared_ptr<qgraph_i<double*>> i);
template qgraph<float*> make_graph(std::shared_ptr<qgraph_i<float*>> i);
#ifdef INSTANTIATE_AVX512
template qgraph<__m512d*> make_graph(std::shared_ptr<qgraph_i<__m512d*>> i);
template qgraph<__m512*> make_graph(std::shared_ptr<qgraph_i<__m512*>> i);
#endif
template qgraph<__m256d*> make_graph(std::shared_ptr<qgraph_i<__m256d*>> i);
template qgraph<__m256*> make_graph(std::shared_ptr<qgraph_i<__m256*>> i);
template qgraph<__m128d*> make_graph(std::shared_ptr<qgraph_i<__m128d*>> i);
template qgraph<__m128*> make_graph(std::shared_ptr<qgraph_i<__m128*>> i);

#include <cstring>

template<class T>
qgraph<T> make_graph(std::shared_ptr<qgraph_i<T>> i)
{
	qgraph_p<T>* ptr = new qgraph_c<T>(i);
	qgraph<T> g;
	memcpy(&g, &ptr, sizeof(qgraph<T>));
	return g;
}

template std::shared_ptr<qgraph_i<double>> get_impl(const qgraph<double>& g);

template<class T>
std::shared_ptr<qgraph_i<T>> get_impl(const qgraph<T>& g)
{
	qgraph_p<T>* ptr;
	memcpy(&ptr,&g, sizeof(qgraph<T>));
	return dynamic_cast<qgraph_c<T>*>(ptr)->get_impl();
}


#include "qworkspace_i.h"

template<class T>
qworkspace<T> qgraph<T>::workspace(QDevice device) const
{
	auto g = get_impl(m_p).get();

	std::shared_ptr<qworkspace_i<T>> wi(new qworkspace_i<T>(device,*g));

	qworkspace<T> w;

	qworkspace_p<T>* p = new qworkspace_c<T>(wi);
	memcpy(&w, &p, sizeof(qworkspace<T>));

	return w;
}

template<class T>
void qgraph<T>::run(qworkspace_view<T> ws) const
{
	get_impl(m_p)->run(*get_impl(get_p(ws.get_ws())));
}

template<class T>
void qgraph<T>::forward(qworkspace_view<T> ws, uint64_t from, uint64_t to) const
{
	get_impl(m_p)->forward(*get_impl(get_p(ws.get_ws())),from,to);
}

template<class T>
void qgraph<T>::backward(qworkspace_view<T> ws, uint64_t from, uint64_t to) const
{
	get_impl(m_p)->backward(*get_impl(get_p(ws.get_ws())), from, to);
}

template<class T>
qgraph<T> qgraph<T>::forwardAD() const
{
	qgraph_p<T>* p = new qgraph_c<T>(get_impl(m_p)->forwardAD());

	qgraph<T> g;
	memcpy(&g, &p, sizeof(qgraph<T>));

	return g;
}

template<class T>
void qgraph<T>::make_forwardAD()
{
	get_impl(m_p)->make_forwardAD();
}

template<class T>
qgraph<T> qgraph<T>::backwardAD() const
{
	qgraph_p<T>* p = new qgraph_c<T>(get_impl(m_p)->backwardAD());

	qgraph<T> g;
	memcpy(&g, &p, sizeof(qgraph<T>));

	return g;
}

template<class T>
void qgraph<T>::make_backwardAD()
{
	get_impl(m_p)->make_backwardAD();
}

template<class T>
void qgraph<T>::allocate(qworkspace<T>& ws, uint64_t n)
{
	get_impl(m_p)->allocate(*get_impl(get_p(ws)), n);
}

template struct VSGRAPH_API qgraph_helper<double, double>;
template struct VSGRAPH_API qgraph_helper<float, double>;
#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qgraph_helper<__m512d, double>;
template struct VSGRAPH_API qgraph_helper<__m512, double>;
#endif
template struct VSGRAPH_API qgraph_helper<__m256d, double>;
template struct VSGRAPH_API qgraph_helper<__m256, double>;
template struct VSGRAPH_API qgraph_helper<__m128d, double>;
template struct VSGRAPH_API qgraph_helper<__m128, double>;

template struct VSGRAPH_API qgraph_helper<double*, double>;
template struct VSGRAPH_API qgraph_helper<float*, double>;
#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qgraph_helper<__m512d*, double>;
template struct VSGRAPH_API qgraph_helper<__m512*, double>;
#endif
template struct VSGRAPH_API qgraph_helper<__m256d*, double>;
template struct VSGRAPH_API qgraph_helper<__m256*, double>;
template struct VSGRAPH_API qgraph_helper<__m128d*, double>;
template struct VSGRAPH_API qgraph_helper<__m128*, double>;

template struct VSGRAPH_API qgraph_helper<double, float>;
template struct VSGRAPH_API qgraph_helper<float, float>;
#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qgraph_helper<__m512d, float>;
template struct VSGRAPH_API qgraph_helper<__m512, float>;
#endif
template struct VSGRAPH_API qgraph_helper<__m256d, float>;
template struct VSGRAPH_API qgraph_helper<__m256, float>;
template struct VSGRAPH_API qgraph_helper<__m128d, float>;
template struct VSGRAPH_API qgraph_helper<__m128, float>;

template struct VSGRAPH_API qgraph_helper<double*, float>;
template struct VSGRAPH_API qgraph_helper<float*, float>;
#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qgraph_helper<__m512d*, float>;
template struct VSGRAPH_API qgraph_helper<__m512*, float>;
#endif
template struct VSGRAPH_API qgraph_helper<__m256d*, float>;
template struct VSGRAPH_API qgraph_helper<__m256*, float>;
template struct VSGRAPH_API qgraph_helper<__m128d*, float>;
template struct VSGRAPH_API qgraph_helper<__m128*, float>;

#ifdef INSTANTIATE_AVX512
template struct VSGRAPH_API qgraph_helper<__m512d, __m512d>;
template struct VSGRAPH_API qgraph_helper<__m512, __m512>;
#endif
template struct VSGRAPH_API qgraph_helper<__m256d, __m256d>;
template struct VSGRAPH_API qgraph_helper<__m256, __m256>;
template struct VSGRAPH_API qgraph_helper<__m128d, __m128d>;
template struct VSGRAPH_API qgraph_helper<__m128, __m128>;

template<class T>
qgraph_p<T>* get_p(const qgraph<T>& g)
{
	qgraph_p<T>* p;
	memcpy(&p, &g, sizeof(qgraph<T>));
	return p;
}

#include "qscalar_i.h"

template<class T, class U>
uint64_t qgraph_helper<T, U>::get_index(const qgraph<T>& g, const qscalar<U>& x)
{
	return get_impl(get_p(g))->get_index(get_address(x));
}

template<class T, class U>
uint64_t qgraph_helper<T, U>::get_input_index(const qgraph<T>& g, const qscalar<U>& x)
{
	return get_impl(get_p(g))->get_input_index(get_address(x));
}

template<class T>
uint64_t qgraph<T>::get_index(const const_char_star& s) const
{
	return get_impl(m_p)->get_index(s.m_s);
}
