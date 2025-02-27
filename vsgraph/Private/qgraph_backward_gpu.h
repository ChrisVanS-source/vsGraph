#pragma once

template<class T>
class graph_backward_gpu {

	T** m_wksp;
	int64_t** m_integer_wksp;
	bool** m_boolean_wksp;

	uint64_t* m_wksp_index;
	uint64_t* m_integer_wksp_index;
	uint64_t* m_boolean_wksp_index;

	T* m_scalar;
	int64_t* m_integer;
	bool* m_boolean;

	uint64_t* m_skip_ops_init;
	uint64_t* m_skip_ops_arg_init;

	uint64_t m_var_counter;


public:

	graph_backward_gpu(const graph_gpu_memory<T>& graph_mem, workspace_gpu_memory<T>& workspace_mem) :
		m_wksp(workspace_mem.m_wksp.get()),
		m_integer_wksp(workspace_mem.m_integer_wksp.get()),
		m_boolean_wksp(workspace_mem.m_boolean_wksp.get()),
		m_wksp_index(graph_mem.m_wksp_index.get()),
		m_integer_wksp_index(graph_mem.m_integer_wksp_index.get()),
		m_boolean_wksp_index(graph_mem.m_boolean_wksp_index.get()),
		m_scalar(graph_mem.m_scalar.get()),
		m_integer(graph_mem.m_integer.get()),
		m_boolean(graph_mem.m_boolean.get()),
		m_var_counter(graph_mem.m_var_counter),
		m_skip_ops_init(graph_mem.m_skip_ops_init.get()),
		m_skip_ops_arg_init(graph_mem.m_skip_ops_arg_init.get())
	{}
	~graph_backward_gpu() {}

	void __device__ init_adjoint(const uint64_t& x_i, uint64_t clock, uint64_t& skip_index, uint64_t threadID)
	{
		if (clock == m_skip_ops_init[skip_index] && x_i == m_skip_ops_arg_init[skip_index])
			++skip_index;
		else
			m_wksp[m_wksp_index[x_i + m_var_counter]][threadID] = (T)0.0;
	}

	template<class Op>
	void __device__ process_func1(uint64_t clock, const uint64_t& r_i, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID, Op op)
	{
		init_adjoint(x_i, clock, skip_index, threadID);
	
		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]]);
	}

	template<class Op>
	void __device__ process_func2(uint64_t clock, const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID, Op op)
	{
		init_adjoint(x_i, clock, skip_index, threadID);
		if (x_i != y_i)
			init_adjoint(y_i, clock, skip_index, threadID);

		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]]);
	}

	template<class Op>
	void __device__ process_func2_px(uint64_t clock, const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID, Op op)
	{
		init_adjoint(y_i, clock, skip_index, threadID);

		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]]);
	}

	template<class Op>
	void __device__ process_func2_py(uint64_t clock, const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID, Op op)
	{
		init_adjoint(x_i, clock, skip_index, threadID);

		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]]);
	}

	template<class Op>
	void __device__ process_func2_sx(uint64_t clock, const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID, Op op)
	{
		init_adjoint(y_i, clock, skip_index, threadID);

		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_scalar[x_i], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]]);
	}

	template<class Op>
	void __device__ process_func2_sy(uint64_t clock, const uint64_t& r_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID, Op op)
	{
		init_adjoint(x_i, clock, skip_index, threadID);

		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_scalar[y_i]);
	}

	template<class Op>
	void __device__ process_iff(uint64_t clock, const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID, Op op)
	{
		init_adjoint(x_i, clock, skip_index, threadID);
		if (x_i != y_i)
			init_adjoint(y_i, clock, skip_index, threadID);

		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]]);
	}

	template<class Op>
	void __device__ process_iff_px(uint64_t clock, const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID, Op op)
	{
		init_adjoint(y_i, clock, skip_index, threadID);

		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[y_i]], m_wksp[m_wksp_index[y_i + m_var_counter]]);
	}

	template<class Op>
	void __device__ process_iff_py(uint64_t clock, const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID, Op op)
	{
		init_adjoint(x_i, clock, skip_index, threadID);

		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_wksp[m_wksp_index[y_i]]);
	}



	template<class Op>
	void __device__ process_iff_sy(uint64_t clock, const uint64_t& r_i, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID, Op op)
	{
		init_adjoint(x_i, clock, skip_index, threadID);

		op(m_wksp[m_wksp_index[r_i]], m_wksp[m_wksp_index[r_i + m_var_counter]], m_boolean_wksp[m_boolean_wksp_index[c_i]], m_wksp[m_wksp_index[x_i]], m_wksp[m_wksp_index[x_i + m_var_counter]], m_scalar[y_i]);
	}

//${begin}
	void __device__ equal_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID];
			}
		);
	}

	void __device__ equal_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ squareroot(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]*(T)0.5/r[threadID];
			}
		);
	}

	void __device__ squareroot_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]-=wr[threadID];
			}
		);
	}

	void __device__ change_sign_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ ceiling(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ ceiling_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ flooring(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ flooring_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ heaviside_step(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ heaviside_step_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ exponential(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]*r[threadID];
			}
		);
	}

	void __device__ exponential_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ logarithm(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]/x[threadID];
			}
		);
	}

	void __device__ logarithm_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ logarithm2(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]/(x[threadID]*(T)0.69314718055994529);
			}
		);
	}

	void __device__ logarithm2_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ logarithm10(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]/(x[threadID]*(T)2.3025850929940459);
			}
		);
	}

	void __device__ logarithm10_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ complementary_errorfunc(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]-=wr[threadID]*exp(-x[threadID]*x[threadID])*(T)1.1283791670955126;
			}
		);
	}

	void __device__ complementary_errorfunc_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]*cos(x[threadID]);
			}
		);
	}

	void __device__ sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=-wr[threadID]*sin(x[threadID]);
			}
		);
	}

	void __device__ cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]/(cos(x[threadID])*cos(x[threadID]));
			}
		);
	}

	void __device__ tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ arc_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]/sqrt((T)1.0-x[threadID]*x[threadID]);
			}
		);
	}

	void __device__ arc_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ arc_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=-wr[threadID]/sqrt((T)1.0-x[threadID]*x[threadID]);
			}
		);
	}

	void __device__ arc_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ arc_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]/(x[threadID]*x[threadID]+(T)1.0);
			}
		);
	}

	void __device__ arc_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ hyperbolic_sine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]*cosh(x[threadID]);
			}
		);
	}

	void __device__ hyperbolic_sine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ hyperbolic_cosine(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]*sinh(x[threadID]);
			}
		);
	}

	void __device__ hyperbolic_cosine_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ hyperbolic_tangent(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func1(clock, r_i, x_i, skip_index, threadID,
			[&](const T* r, const T* wr, const T* x, T* wx)
			{
				wx[threadID]+=wr[threadID]*((T)1.0-r[threadID]*r[threadID]);
			}
		);
	}

	void __device__ hyperbolic_tangent_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y, T* wy)
			{
				wx[threadID]+=wr[threadID];
				wy[threadID]+=wr[threadID];
			}
		);
	}

	void __device__ add_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_px(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, const T* y, T* wy)
			{
				wy[threadID]+=wr[threadID];
			}
		);
	}

	void __device__ add_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_py(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y)
			{
				wx[threadID]+=wr[threadID];
			}
		);
	}

	void __device__ add_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y, T* wy)
			{
				wx[threadID]+=wr[threadID];
				wy[threadID]-=wr[threadID];
			}
		);
	}

	void __device__ subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_px(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, const T* y, T* wy)
			{
				wy[threadID]-=wr[threadID];
			}
		);
	}

	void __device__ subtract_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_py(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y)
			{
				wx[threadID]+=wr[threadID];
			}
		);
	}

	void __device__ subtract_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y, T* wy)
			{
				wx[threadID]+=y[threadID]*wr[threadID];
				wy[threadID]+=x[threadID]*wr[threadID];
			}
		);
	}

	void __device__ multiply_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_px(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, const T* y, T* wy)
			{
				wy[threadID]+=x[threadID]*wr[threadID];
			}
		);
	}

	void __device__ multiply_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_py(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y)
			{
				wx[threadID]+=y[threadID]*wr[threadID];
			}
		);
	}

	void __device__ multiply_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y, T* wy)
			{
				wx[threadID]+=wr[threadID]/y[threadID];
				wy[threadID]+=-r[threadID]*wr[threadID]/y[threadID];
			}
		);
	}

	void __device__ divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_px(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, const T* y, T* wy)
			{
				wy[threadID]+=-r[threadID]*wr[threadID]/y[threadID];
			}
		);
	}

	void __device__ divide_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_py(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y)
			{
				wx[threadID]+=wr[threadID]/y[threadID];
			}
		);
	}

	void __device__ divide_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ maximum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y, T* wy)
			{
				wx[threadID]+=hss(x[threadID]-y[threadID])*wr[threadID];
				wy[threadID]+=hss(y[threadID]-x[threadID])*wr[threadID];
			}
		);
	}

	void __device__ maximum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_px(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, const T* y, T* wy)
			{
				wy[threadID]+=hss(y[threadID]-x[threadID])*wr[threadID];
			}
		);
	}

	void __device__ maximum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_py(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y)
			{
				wx[threadID]+=hss(x[threadID]-y[threadID])*wr[threadID];
			}
		);
	}

	void __device__ maximum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ minimum(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y, T* wy)
			{
				wx[threadID]+=hss(y[threadID]-x[threadID])*wr[threadID];
				wy[threadID]+=hss(x[threadID]-y[threadID])*wr[threadID];
			}
		);
	}

	void __device__ minimum_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_px(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, const T* y, T* wy)
			{
				wy[threadID]+=hss(x[threadID]-y[threadID])*wr[threadID];
			}
		);
	}

	void __device__ minimum_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_py(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y)
			{
				wx[threadID]+=hss(y[threadID]-x[threadID])*wr[threadID];
			}
		);
	}

	void __device__ minimum_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y, T* wy)
			{
				wx[threadID]+=wr[threadID]*pow(x[threadID],y[threadID]-(T)1.0)*y[threadID];
				wy[threadID]+=wr[threadID]*log(x[threadID])*r[threadID];
			}
		);
	}

	void __device__ power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_px(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, const T* y, T* wy)
			{
				wy[threadID]+=wr[threadID]*log(x[threadID])*r[threadID];
			}
		);
	}

	void __device__ power_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_py(clock, r_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const T* x, T* wx, const T* y)
			{
				wx[threadID]+=wr[threadID]*pow(x[threadID],y[threadID]-(T)1.0)*y[threadID];
			}
		);
	}

	void __device__ power_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ add_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_sy(clock, r_i, x_i, y_i, skip_index, threadID, 
			[&](const T* r, const T* wr, const T* x, T* wx, const T& y)
			{
				wx[threadID]+=wr[threadID];
			}
		);
	}

	void __device__ add_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ subtract_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_sy(clock, r_i, x_i, y_i, skip_index, threadID, 
			[&](const T* r, const T* wr, const T* x, T* wx, const T& y)
			{
				wx[threadID]+=wr[threadID];
			}
		);
	}

	void __device__ subtract_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ scalar_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_sx(clock, r_i, x_i, y_i, skip_index, threadID, 
			[&](const T* r, const T* wr, const T& x, const T* y, T* wy)
			{
				wy[threadID]-=wr[threadID];
			}
		);
	}

	void __device__ scalar_subtract_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ multiply_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_sy(clock, r_i, x_i, y_i, skip_index, threadID, 
			[&](const T* r, const T* wr, const T* x, T* wx, const T& y)
			{
				wx[threadID]+=y*wr[threadID];
			}
		);
	}

	void __device__ multiply_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ divide_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_sy(clock, r_i, x_i, y_i, skip_index, threadID, 
			[&](const T* r, const T* wr, const T* x, T* wx, const T& y)
			{
				wx[threadID]+=wr[threadID]/y;
			}
		);
	}

	void __device__ divide_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ scalar_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_sx(clock, r_i, x_i, y_i, skip_index, threadID, 
			[&](const T* r, const T* wr, const T& x, const T* y, T* wy)
			{
				wy[threadID]+=-r[threadID]*wr[threadID]/y[threadID];
			}
		);
	}

	void __device__ scalar_divide_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ maximum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_sy(clock, r_i, x_i, y_i, skip_index, threadID, 
			[&](const T* r, const T* wr, const T* x, T* wx, const T& y)
			{
				wx[threadID]+=hss(x[threadID]-y)*wr[threadID];
			}
		);
	}

	void __device__ maximum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ minimum_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_sy(clock, r_i, x_i, y_i, skip_index, threadID, 
			[&](const T* r, const T* wr, const T* x, T* wx, const T& y)
			{
				wx[threadID]+=hss(y-x[threadID])*wr[threadID];
			}
		);
	}

	void __device__ minimum_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ power_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_sy(clock, r_i, x_i, y_i, skip_index, threadID, 
			[&](const T* r, const T* wr, const T* x, T* wx, const T& y)
			{
				wx[threadID]+=pow(x[threadID],y-(T)1.0)*y*wr[threadID];
			}
		);
	}

	void __device__ power_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ scalar_power(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_func2_sx(clock, r_i, x_i, y_i, skip_index, threadID, 
			[&](const T* r, const T* wr, const T& x, const T* y, T* wy)
			{
				wy[threadID]+=log(x)*r[threadID]*wr[threadID];
			}
		);
	}

	void __device__ scalar_power_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ greater_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ less_than_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ equal_to_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_iff(clock, r_i,c_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const bool* c, const T* x, T* wx, const T* y, T* wy)
			{
				if (c[threadID])
					wx[threadID] += wr[threadID];
				else
					wy[threadID] += wr[threadID];
			}
		);
	}


	void __device__ iff_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_iff_px(clock, r_i,c_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const bool* c, const T* x, const T* y, T* wy)
			{
				if (!c[threadID])
					wy[threadID] += wr[threadID];
			}
		);
	}

	void __device__ iff_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_iff_py(clock, r_i,c_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const bool* c, const T* x, T* wx, const T* y)
			{
				if (c[threadID])
					wx[threadID] += wr[threadID];
			}
		);
	}

	void __device__ iff_px_py(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ iff_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
		process_iff_sy(clock, r_i,c_i,x_i,y_i,skip_index,threadID,
			[&](const T* r, const T* wr, const bool* c, const T* x, T* wx, const T& y)
			{
				if (c[threadID])
					wx[threadID] += wr[threadID];
			}
		);
	}

	void __device__ iff_scalar_px(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ iff_scalar_scalar(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_equal_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_change_sign(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_add(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_multiply(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_add_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_subtract_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_int_subtract(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_multiply_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_divide_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_int_divide(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_greater_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_less_than(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_greater_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_less_than_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_equal_to_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_iff_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ integer_iff_int_int(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_equal_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_equal(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_not(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_and(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_or(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_equal_to(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_and_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_or_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_equal_to_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_iff(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_iff_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

	void __device__ boolean_iff_bool_bool(uint64_t clock, const uint64_t& r_i, Operation op, const uint64_t& c_i, const uint64_t& x_i, const uint64_t& y_i, uint64_t& skip_index, uint64_t threadID)
	{
	}

//${end}
};

