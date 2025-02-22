#pragma once

template<class T>
class graph_function_gpu {

	T** m_wksp;
	int64_t** m_integer_wksp;
	bool** m_boolean_wksp;

	uint64_t* m_wksp_index;
	uint64_t* m_integer_wksp_index;
	uint64_t* m_boolean_wksp_index;

	T* m_scalar;
	int64_t* m_integer;
	bool* m_boolean;

public:

	graph_function_gpu(const graph_gpu_memory<T>& graph_mem, workspace_gpu_memory<T>& workspace_mem) :
		m_wksp(workspace_mem.m_wksp.get()),
		m_integer_wksp(workspace_mem.m_integer_wksp.get()),
		m_boolean_wksp(workspace_mem.m_boolean_wksp.get()),
		m_wksp_index(graph_mem.m_wksp_index.get()),
		m_integer_wksp_index(graph_mem.m_integer_wksp_index.get()),
		m_boolean_wksp_index(graph_mem.m_boolean_wksp_index.get()),
		m_scalar(graph_mem.m_scalar.get()),
		m_integer(graph_mem.m_integer.get()),
		m_boolean(graph_mem.m_boolean.get())
	{}
	~graph_function_gpu() {}

	template<class Op>
	void __device__ process_func1(const uint64_t& r_i, const uint64_t& x_i, Op op)
	{
		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[x_i]]);
	}

	template<class Op>
	void __device__ process_func1_sx(const uint64_t& r_i, const uint64_t& x_i, Op op)
	{
		op(m_wksp[m_wksp_index[r_i]], m_scalar[x_i]);
	}

	template<class Op>
	void __device__ process_func2(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_func2_sx(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_wksp[m_wksp_index[r_i]], m_scalar[x_i], m_wksp[m_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_func2_sy(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[x_i]], m_scalar[y_i]);
	}

	template<class Op>
	void __device__ process_func2_logical(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_func2_logical_sy(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_wksp[m_wksp_index[x_i]], m_scalar[y_i]);
	}

	template<class Op>
	void __device__ process_boolean1(const uint64_t& r_i, const uint64_t& x_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[x_i]]);
	}

	template<class Op>
	void __device__ process_boolean1_bx(const uint64_t& r_i, const uint64_t& x_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_boolean[x_i]);
	}

	template<class Op>
	void __device__ process_boolean2(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[x_i]], m_boolean_wksp[m_boolean_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_boolean2_by(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[x_i]], m_boolean[y_i]);
	}

	template<class Op>
	void __device__ process_iff(const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_wksp[m_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_iff_sy(const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_wksp[m_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_wksp[m_wksp_index[x_i]], m_scalar[y_i]);
	}

	template<class Op>
	void __device__ process_iff_sx_sy(const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_wksp[m_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_scalar[x_i], m_scalar[y_i]);
	}

	template<class Op>
	void __device__ process_integer1(const uint64_t& r_i, const uint64_t& x_i, Op op)
	{
		op(m_integer_wksp[m_integer_wksp_index[r_i]], m_integer_wksp[m_integer_wksp_index[x_i]]);
	}

	template<class Op>
	void __device__ process_integer1_ix(const uint64_t& r_i, const uint64_t& x_i, Op op)
	{
		op(m_integer_wksp[m_integer_wksp_index[r_i]], m_integer[x_i]);
	}

	template<class Op>
	void __device__ process_integer2(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_integer_wksp[m_integer_wksp_index[r_i]], m_integer_wksp[m_integer_wksp_index[x_i]], m_integer_wksp[m_integer_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_integer2_ix(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_integer_wksp[m_integer_wksp_index[r_i]], m_integer[x_i], m_integer_wksp[m_integer_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_integer2_iy(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_integer_wksp[m_integer_wksp_index[r_i]], m_integer_wksp[m_integer_wksp_index[x_i]], m_integer[y_i]);
	}

	template<class Op>
	void __device__ process_integer2_logical(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_integer_wksp[m_integer_wksp_index[x_i]], m_integer_wksp[m_integer_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_integer2_logical_iy(const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_integer_wksp[m_integer_wksp_index[x_i]], m_integer[y_i]);
	}

	template<class Op>
	void __device__ process_integer_iff(const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_integer_wksp[m_integer_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_integer_wksp[m_integer_wksp_index[x_i]], m_integer_wksp[m_integer_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_integer_iff_iy(const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_integer_wksp[m_integer_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_integer_wksp[m_integer_wksp_index[x_i]], m_integer[y_i]);
	}

	template<class Op>
	void __device__ process_integer_iff_ix_iy(const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_integer_wksp[m_integer_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_integer[x_i], m_integer[y_i]);
	}

	template<class Op>
	void __device__ process_boolean_iff(const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_boolean_wksp[m_boolean_wksp_index[x_i]], m_boolean_wksp[m_boolean_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_boolean_iff_by(const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_boolean_wksp[m_boolean_wksp_index[x_i]], m_boolean[y_i]);
	}

	template<class Op>
	void __device__ process_boolean_iff_bx_by(const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, Op op)
	{
		op(m_boolean_wksp[m_boolean_wksp_index[r_i]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_boolean[x_i], m_boolean[y_i]);
	}


//${begin}
	void __device__ equal_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1_sx(r_i, x_i,
			[&](T* r, const T& x)
			{
				r[threadID]=x;
			}
		);
	}

	void __device__ equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=x[threadID];
			}
		);
	}

	void __device__ equal_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=x[threadID];
			}
		);
	}

	void __device__ squareroot(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=sqrt(x[threadID]);
			}
		);
	}

	void __device__ squareroot_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=sqrt(x[threadID]);
			}
		);
	}

	void __device__ change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=-x[threadID];
			}
		);
	}

	void __device__ change_sign_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=-x[threadID];
			}
		);
	}

	void __device__ ceiling(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=ceil(x[threadID]);
			}
		);
	}

	void __device__ ceiling_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=ceil(x[threadID]);
			}
		);
	}

	void __device__ flooring(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=floor(x[threadID]);
			}
		);
	}

	void __device__ flooring_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=floor(x[threadID]);
			}
		);
	}

	void __device__ heaviside_step(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=hss(x[threadID]);
			}
		);
	}

	void __device__ heaviside_step_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=hss(x[threadID]);
			}
		);
	}

	void __device__ exponential(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=exp(x[threadID]);
			}
		);
	}

	void __device__ exponential_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=exp(x[threadID]);
			}
		);
	}

	void __device__ logarithm(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=log(x[threadID]);
			}
		);
	}

	void __device__ logarithm_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=log(x[threadID]);
			}
		);
	}

	void __device__ logarithm2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=log2(x[threadID]);
			}
		);
	}

	void __device__ logarithm2_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=log2(x[threadID]);
			}
		);
	}

	void __device__ logarithm10(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=log10(x[threadID]);
			}
		);
	}

	void __device__ logarithm10_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=log10(x[threadID]);
			}
		);
	}

	void __device__ complementary_errorfunc(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=erfc(x[threadID]);
			}
		);
	}

	void __device__ complementary_errorfunc_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=erfc(x[threadID]);
			}
		);
	}

	void __device__ sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=sin(x[threadID]);
			}
		);
	}

	void __device__ sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=sin(x[threadID]);
			}
		);
	}

	void __device__ cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=cos(x[threadID]);
			}
		);
	}

	void __device__ cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=cos(x[threadID]);
			}
		);
	}

	void __device__ tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=tan(x[threadID]);
			}
		);
	}

	void __device__ tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=tan(x[threadID]);
			}
		);
	}

	void __device__ arc_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=asin(x[threadID]);
			}
		);
	}

	void __device__ arc_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=asin(x[threadID]);
			}
		);
	}

	void __device__ arc_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=acos(x[threadID]);
			}
		);
	}

	void __device__ arc_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=acos(x[threadID]);
			}
		);
	}

	void __device__ arc_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=atan(x[threadID]);
			}
		);
	}

	void __device__ arc_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=atan(x[threadID]);
			}
		);
	}

	void __device__ hyperbolic_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=sinh(x[threadID]);
			}
		);
	}

	void __device__ hyperbolic_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=sinh(x[threadID]);
			}
		);
	}

	void __device__ hyperbolic_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=cosh(x[threadID]);
			}
		);
	}

	void __device__ hyperbolic_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=cosh(x[threadID]);
			}
		);
	}

	void __device__ hyperbolic_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=tanh(x[threadID]);
			}
		);
	}

	void __device__ hyperbolic_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_func1(r_i, x_i,
			[&](T* r, const T* x)
			{
				r[threadID]=tanh(x[threadID]);
			}
		);
	}

	void __device__ add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]+y[threadID];
			}
		);
	}

	void __device__ add_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]+y[threadID];
			}
		);
	}

	void __device__ add_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]+y[threadID];
			}
		);
	}

	void __device__ add_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]+y[threadID];
			}
		);
	}

	void __device__ subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]-y[threadID];
			}
		);
	}

	void __device__ subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]-y[threadID];
			}
		);
	}

	void __device__ subtract_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]-y[threadID];
			}
		);
	}

	void __device__ subtract_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]-y[threadID];
			}
		);
	}

	void __device__ multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]*y[threadID];
			}
		);
	}

	void __device__ multiply_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]*y[threadID];
			}
		);
	}

	void __device__ multiply_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]*y[threadID];
			}
		);
	}

	void __device__ multiply_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]*y[threadID];
			}
		);
	}

	void __device__ divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]/y[threadID];
			}
		);
	}

	void __device__ divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]/y[threadID];
			}
		);
	}

	void __device__ divide_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]/y[threadID];
			}
		);
	}

	void __device__ divide_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=x[threadID]/y[threadID];
			}
		);
	}

	void __device__ maximum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=max(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ maximum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=max(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ maximum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=max(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ maximum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=max(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ minimum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=min(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ minimum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=min(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ minimum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=min(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ minimum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=min(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=pow(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=pow(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ power_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=pow(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ power_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2(r_i,x_i,y_i,
			[&](T* r, const T* x, const T* y)
			{
				r[threadID]=pow(x[threadID],y[threadID]);
			}
		);
	}

	void __device__ add_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i, x_i, y_i, 
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=x[threadID]+y;
			}
		);
	}

	void __device__ add_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i,x_i,y_i,
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=x[threadID]+y;
			}
		);
	}

	void __device__ subtract_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i, x_i, y_i, 
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=x[threadID]-y;
			}
		);
	}

	void __device__ subtract_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i,x_i,y_i,
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=x[threadID]-y;
			}
		);
	}

	void __device__ scalar_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sx(r_i, x_i, y_i, 
			[&](T* r, const T& x, const T* y)
			{
				r[threadID]=x-y[threadID];
			}
		);
	}

	void __device__ scalar_subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sx(r_i,x_i,y_i,
			[&](T* r, const T& x, const T* y)
			{
				r[threadID]=x-y[threadID];
			}
		);
	}

	void __device__ multiply_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i, x_i, y_i, 
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=x[threadID]*y;
			}
		);
	}

	void __device__ multiply_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i,x_i,y_i,
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=x[threadID]*y;
			}
		);
	}

	void __device__ divide_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i, x_i, y_i, 
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=x[threadID]/y;
			}
		);
	}

	void __device__ divide_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i,x_i,y_i,
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=x[threadID]/y;
			}
		);
	}

	void __device__ scalar_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sx(r_i, x_i, y_i, 
			[&](T* r, const T& x, const T* y)
			{
				r[threadID]=x/y[threadID];
			}
		);
	}

	void __device__ scalar_divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sx(r_i,x_i,y_i,
			[&](T* r, const T& x, const T* y)
			{
				r[threadID]=x/y[threadID];
			}
		);
	}

	void __device__ maximum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i, x_i, y_i, 
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=max(x[threadID],y);
			}
		);
	}

	void __device__ maximum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i,x_i,y_i,
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=max(x[threadID],y);
			}
		);
	}

	void __device__ minimum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i, x_i, y_i, 
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=min(x[threadID],y);
			}
		);
	}

	void __device__ minimum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i,x_i,y_i,
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=min(x[threadID],y);
			}
		);
	}

	void __device__ power_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i, x_i, y_i, 
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=pow(x[threadID],y);
			}
		);
	}

	void __device__ power_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sy(r_i,x_i,y_i,
			[&](T* r, const T* x, const T& y)
			{
				r[threadID]=pow(x[threadID],y);
			}
		);
	}

	void __device__ scalar_power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sx(r_i, x_i, y_i, 
			[&](T* r, const T& x, const T* y)
			{
				r[threadID]=pow(x,y[threadID]);
			}
		);
	}

	void __device__ scalar_power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_sx(r_i,x_i,y_i,
			[&](T* r, const T& x, const T* y)
			{
				r[threadID]=pow(x,y[threadID]);
			}
		);
	}

	void __device__ greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_logical(r_i,x_i,y_i,
			[&](bool* r, const T* x, const T* y)
			{
				r[threadID] = x[threadID] > y[threadID];
			}
		);
	}

	void __device__ less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_logical(r_i,x_i,y_i,
			[&](bool* r, const T* x, const T* y)
			{
				r[threadID] = x[threadID] < y[threadID];
			}
		);
	}

	void __device__ equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_logical(r_i,x_i,y_i,
			[&](bool* r, const T* x, const T* y)
			{
				r[threadID] = x[threadID] == y[threadID];
			}
		);
	}

	void __device__ greater_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_logical_sy(r_i,x_i,y_i,
			[&](bool* r, const T* x, const T& y)
			{
				r[threadID] = x[threadID] > y;
			}
		);
	}

	void __device__ less_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_logical_sy(r_i,x_i,y_i,
			[&](bool* r, const T* x, const T& y)
			{
				r[threadID] = x[threadID] < y;
			}
		);
	}

	void __device__ equal_to_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_func2_logical_sy(r_i,x_i,y_i,
			[&](bool* r, const T* x, const T& y)
			{
				r[threadID] = x[threadID] == y;
			}
		);
	}

	void __device__ iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_iff(r_i,c_i,x_i,y_i,
			[&](T* r, const bool* c, const T* x, const T* y)
			{
				r[threadID] = c[threadID] ? x[threadID] : y[threadID];
			}
		);
	}


	void __device__ iff_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_iff(r_i,c_i,x_i,y_i,
			[&](T* r, const bool* c, const T* x, const T* y)
			{
				r[threadID] = c[threadID] ? x[threadID] : y[threadID];
			}
		);
	}

	void __device__ iff_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_iff(r_i,c_i,x_i,y_i,
			[&](T* r, const bool* c, const T* x, const T* y)
			{
				r[threadID] = c[threadID] ? x[threadID] : y[threadID];
			}
		);
	}

	void __device__ iff_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_iff(r_i,c_i,x_i,y_i,
			[&](T* r, const bool* c, const T* x, const T* y)
			{
				r[threadID] = c[threadID] ? x[threadID] : y[threadID];
			}
		);
	}

	void __device__ iff_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_iff_sy(r_i,c_i,x_i,y_i,
			[&](T* r, const bool* c, const T* x, const T& y)
			{
				r[threadID] = c[threadID] ? x[threadID] : y;
			}
		);
	}

	void __device__ iff_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_iff_sy(r_i,c_i,x_i,y_i,
			[&](T* r, const bool* c, const T* x, const T& y)
			{
				r[threadID] = c[threadID] ? x[threadID] : y;
			}
		);
	}

	void __device__ iff_scalar_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_iff_sx_sy(r_i,c_i,x_i,y_i,
			[&](T* r, const bool* c, const T& x, const T& y)
			{
				r[threadID] = c[threadID] ? x : y;
			}
		);
	}


	void __device__ integer_equal_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_integer1_ix(r_i,x_i,
			[&](int64_t* r, const int64_t& x)
			{
				r[threadID] = x;
			}
		);
	}

	void __device__ integer_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_integer1(r_i,x_i,
			[&](int64_t* r, const int64_t* x)
			{
				r[threadID] = x[threadID];
			}
		);
	}

	void __device__ integer_change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_integer1(r_i,x_i,
			[&](int64_t* r, const int64_t* x)
			{
				r[threadID] = -x[threadID];
			}
		);
	}

	void __device__ integer_add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2(r_i,x_i,y_i,
			[&](int64_t* r, const int64_t* x, const int64_t* y)
			{
				r[threadID] = x[threadID]+y[threadID];
			}
		);
	}

	void __device__ integer_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2(r_i,x_i,y_i,
			[&](int64_t* r, const int64_t* x, const int64_t* y)
			{
				r[threadID] = x[threadID]-y[threadID];
			}
		);
	}

	void __device__ integer_multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2(r_i,x_i,y_i,
			[&](int64_t* r, const int64_t* x, const int64_t* y)
			{
				r[threadID] = x[threadID]*y[threadID];
			}
		);
	}

	void __device__ integer_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2(r_i,x_i,y_i,
			[&](int64_t* r, const int64_t* x, const int64_t* y)
			{
				r[threadID] = x[threadID]/y[threadID];
			}
		);
	}

	void __device__ integer_add_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_iy(r_i,x_i,y_i,
			[&](int64_t* r, const int64_t* x, const int64_t& y)
			{
				r[threadID] = x[threadID]+y;
			}
		);
	}

	void __device__ integer_subtract_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_iy(r_i,x_i,y_i,
			[&](int64_t* r, const int64_t* x, const int64_t& y)
			{
				r[threadID] = x[threadID]-y;
			}
		);
	}

	void __device__ integer_int_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_ix(r_i,x_i,y_i,
			[&](int64_t* r, const int64_t& x, const int64_t* y)
			{
				r[threadID] = x-y[threadID];
			}
		);
	}

	void __device__ integer_multiply_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_iy(r_i,x_i,y_i,
			[&](int64_t* r, const int64_t* x, const int64_t& y)
			{
				r[threadID] = x[threadID]*y;
			}
		);
	}

	void __device__ integer_divide_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_iy(r_i,x_i,y_i,
			[&](int64_t* r, const int64_t* x, const int64_t& y)
			{
				r[threadID] = x[threadID]/y;
			}
		);
	}

	void __device__ integer_int_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_ix(r_i,x_i,y_i,
			[&](int64_t* r, const int64_t& x, const int64_t* y)
			{
				r[threadID] = x/y[threadID];
			}
		);
	}

	void __device__ integer_greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_logical(r_i,x_i,y_i,
			[&](bool* r, const int64_t* x, const int64_t* y)
			{
				r[threadID] = x[threadID]>y[threadID];
			}
		);
	}

	void __device__ integer_less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_logical(r_i,x_i,y_i,
			[&](bool* r, const int64_t* x, const int64_t* y)
			{
				r[threadID] = x[threadID]<y[threadID];
			}
		);
	}

	void __device__ integer_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_logical(r_i,x_i,y_i,
			[&](bool* r, const int64_t* x, const int64_t* y)
			{
				r[threadID] = x[threadID]==y[threadID];
			}
		);
	}

	void __device__ integer_greater_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_logical_iy(r_i,x_i,y_i,
			[&](bool* r, const int64_t* x, const int64_t& y)
			{
				r[threadID] = x[threadID]>y;
			}
		);
	}

	void __device__ integer_less_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_logical_iy(r_i,x_i,y_i,
			[&](bool* r, const int64_t* x, const int64_t& y)
			{
				r[threadID] = x[threadID]<y;
			}
		);
	}

	void __device__ integer_equal_to_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer2_logical_iy(r_i,x_i,y_i,
			[&](bool* r, const int64_t* x, const int64_t& y)
			{
				r[threadID] = x[threadID]==y;
			}
		);
	}

	void __device__ integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer_iff(r_i,c_i,x_i,y_i,
			[&](int64_t* r, const bool* c, const int64_t* x, const int64_t* y)
			{
				r[threadID] = c[threadID] ? x[threadID] : y[threadID];
			}
		);
	}

	void __device__ integer_iff_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer_iff_iy(r_i,c_i,x_i,y_i,
			[&](int64_t* r, const bool* c, const int64_t* x, const int64_t& y)
			{
				r[threadID] = c[threadID] ? x[threadID] : y;
			}
		);
	}

	void __device__ integer_iff_int_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_integer_iff_ix_iy(r_i,c_i,x_i,y_i,
			[&](int64_t* r, const bool* c, const int64_t& x, const int64_t& y)
			{
				r[threadID] = c[threadID] ? x : y;
			}
		);
	}

	void __device__ boolean_equal_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_boolean1_bx(r_i,x_i,
			[&](bool* r, bool x)
			{
				r[threadID] = x;
			}
		);
	}

	void __device__ boolean_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_boolean1(r_i,x_i,
			[&](bool* r, const bool* x)
			{
				r[threadID] = x[threadID];
			}
		);
	}

	void __device__ boolean_not(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t threadID)
	{
		process_boolean1(r_i,x_i,
			[&](bool* r, const bool* x)
			{
				r[threadID] = !x[threadID];
			}
		);
	}

	void __device__ boolean_and(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_boolean2(r_i,x_i,y_i,
			[&](bool* r, const bool* x, const bool* y)
			{
				r[threadID] = x[threadID] && y[threadID];
			}
		);
	}

	void __device__ boolean_or(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_boolean2(r_i,x_i,y_i,
			[&](bool* r, const bool* x, const bool* y)
			{
				r[threadID] = x[threadID] || y[threadID];
			}
		);
	}

	void __device__ boolean_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_boolean2(r_i,x_i,y_i,
			[&](bool* r, const bool* x, const bool* y)
			{
				r[threadID] = x[threadID] == y[threadID];
			}
		);
	}

	void __device__ boolean_and_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_boolean2_by(r_i,x_i,y_i,
			[&](bool* r, const bool* x, bool y)
			{
				r[threadID] = x[threadID] && y;
			}
		);
	}

	void __device__ boolean_or_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_boolean2_by(r_i,x_i,y_i,
			[&](bool* r, const bool* x, bool y)
			{
				r[threadID] = x[threadID] || y;
			}
		);
	}

	void __device__ boolean_equal_to_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_boolean2_by(r_i,x_i,y_i,
			[&](bool* r, const bool* x, bool y)
			{
				r[threadID] = x[threadID] == y;
			}
		);
	}

	void __device__ boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_boolean_iff(r_i,c_i,x_i,y_i,
			[&](bool* r, const bool* c, const bool* x, const bool* y)
			{
				r[threadID] = c[threadID] ? x[threadID] : y[threadID];
			}
		);
	}

	void __device__ boolean_iff_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_boolean_iff_by(r_i,c_i,x_i,y_i,
			[&](bool* r, const bool* c, const bool* x, bool y)
			{
				r[threadID] = c[threadID] ? x[threadID] : y;
			}
		);
	}

	void __device__ boolean_iff_bool_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t threadID)
	{
		process_boolean_iff_bx_by(r_i,c_i,x_i,y_i,
			[&](bool* r, const bool* c, bool x, bool y)
			{
				r[threadID] = c[threadID] ? x : y;
			}
		);
	}

//${end}
};

