#pragma once

#include "qpci_pattern.h"

PCI_PATTERN(qworkspace)

#include "qworkspace.h"
#include "qgraph_traits.h"
#include "qgraph_enum.h"
#include <vector>
#include <map>
#include <boost/bimap.hpp>
using namespace vstech;

#include "qinteger_i.h"
#include "qboolean_i.h"
#include "qgraph_i.h"
#include "qgpu_traits.h"

template<class T>
class qworkspace_i 
{
	typename gpu_traits<T>::workspace_memory m_gpu_memory;

	typename graph_traits<T>::mem_type m_mem;
	std::vector<typename workspace_traits<T>::type> m_wksp;
	std::vector<typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type> m_integer_wksp;
	std::vector<typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type> m_boolean_wksp;

	const std::vector<uint64_t>& m_wksp_index;
	const std::vector<uint64_t>& m_integer_wksp_index;
	const std::vector<uint64_t>& m_boolean_wksp_index;

	const std::vector<std::map<uint64_t, uint64_t>>& m_assign_map;
	const std::vector<typename workspace_traits<T>::scalar_type>& m_scalar;
	const std::vector<typename graph_traits<T>::integer_type>& m_integer;
	const std::vector<typename graph_traits<T>::boolean_type>& m_boolean;
	const std::map<uint64_t, uint64_t>& m_variable_map;
	const std::vector<boost::bimap<uint64_t, uint64_t>>& m_input_map;
	const std::vector<boost::bimap<uint64_t, uint64_t>>& m_output_map;
	const std::vector<ADType>& m_adtype;
	const uint64_t& m_var_counter;
	const std::vector<Operation>& m_ops;
	const boost::bimap<std::string, uint64_t>& m_variable_name_map;

	uint64_t m_n;

	uint64_t get_highest_backward_index(uint64_t x, uint64_t order) const;
	uint64_t get_highest_backward_index(uint64_t x, uint64_t order, uint64_t& idx) const;
	uint64_t get_value_input_index(uint64_t x) const;
	uint64_t get_value_output_index(uint64_t x) const;
	uint64_t get_dual_input_index(uint64_t x, uint64_t order) const;
	uint64_t get_dual_input_internal_index(uint64_t x, uint64_t order) const;
	uint64_t get_dual_output_index(uint64_t x, uint64_t order) const;
	uint64_t get_dual_output_internal_index(uint64_t x, uint64_t order) const;
	uint64_t get_adjoint_input_index(uint64_t x, uint64_t order) const;
	uint64_t get_adjoint_input_internal_index(uint64_t x, uint64_t order) const;
	uint64_t get_adjoint_output_index(uint64_t x, uint64_t order) const;
	uint64_t get_adjoint_output_internal_index(uint64_t x, uint64_t order) const;

	QDevice m_device;

	void set_wksp(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv);
	void set_wksp(uint64_t x, const typename workspace_traits<T>::type& xv);

public:

	qworkspace_i(QDevice device, const qgraph_i<T>& g);

	~qworkspace_i();

	void allocate(uint64_t n);

	QDevice vendor() const;
	int device_number() const;

	typename gpu_traits<T>::workspace_memory& get_gpu_memory() { return m_gpu_memory; }

	std::vector<typename workspace_traits<T>::type>& wksp() { return m_wksp; }
	const std::vector<uint64_t>& get_wksp_index() const { return m_wksp_index; }

	std::vector<typename qinteger_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& get_integer_wksp() { return m_integer_wksp; }
	const std::vector<uint64_t>& get_integer_wksp_index() const { return m_integer_wksp_index; }

	std::vector<typename qboolean_storage_traits<typename qtype_traits<T>::mapped_type>::storage_type>& get_boolean_wksp() { return m_boolean_wksp; }
	const std::vector<uint64_t>& get_boolean_wksp_index() const { return m_boolean_wksp_index; }

	const std::vector<typename workspace_traits<T>::scalar_type>& get_scalar() const { return m_scalar; }
	const std::vector<typename graph_traits<T>::integer_type>& get_integer() const { return m_integer; }
	const std::vector<typename graph_traits<T>::boolean_type>& get_boolean() const { return m_boolean; }

	uint64_t get_index(uint64_t x) const;
	uint64_t get_input_index(uint64_t x) const;
	uint64_t get_index(const char* s) const;

	const typename workspace_traits<T>::type& get_value(uint64_t x) const;
	const typename workspace_traits<T>::type& get_value_byindex(uint64_t x) const;
	const typename workspace_traits<T>::type& get_value_byname(const char* s) const;

	typename workspace_traits<T>::ptr_type get_value_ptr(uint64_t x);
	typename workspace_traits<T>::ptr_type get_value_ptr_byindex(uint64_t x);
	typename workspace_traits<T>::ptr_type get_value_ptr_byname(const char* s);

	void set_value(uint64_t x, const typename workspace_traits<T>::type& xv);
	void set_value(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv);
	void set_value_byindex(uint64_t x, const typename workspace_traits<T>::type& xv);
	void set_value_byindex(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv);
	void set_value_byname(const char* s, const typename workspace_traits<T>::type& xv);
	void set_value_byname(const char* s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv);

	const typename workspace_traits<T>::type& get_dual(uint64_t x, uint64_t order) const;
	const typename workspace_traits<T>::type& get_dual_byindex(uint64_t x, uint64_t order) const;
	const typename workspace_traits<T>::type& get_dual_byname(const char* s, uint64_t order) const;

	typename workspace_traits<T>::ptr_type get_dual_ptr(uint64_t x, uint64_t order);
	typename workspace_traits<T>::ptr_type get_dual_ptr_byindex(uint64_t x, uint64_t order);
	typename workspace_traits<T>::ptr_type get_dual_ptr_byname(const char* s, uint64_t order);

	void set_dual(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order);
	void set_dual(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);
	void set_dual_byindex(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order);
	void set_dual_byindex(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);
	void set_dual_byname(const char* s, const typename workspace_traits<T>::type& xv, uint64_t order);
	void set_dual_byname(const char* s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);

	const typename workspace_traits<T>::type& get_adjoint(uint64_t x, uint64_t order) const;
	const typename workspace_traits<T>::type& get_adjoint_byindex(uint64_t x, uint64_t order) const;
	const typename workspace_traits<T>::type& get_adjoint_byname(const char* s, uint64_t order) const;

	typename workspace_traits<T>::ptr_type get_adjoint_ptr(uint64_t x, uint64_t order);
	typename workspace_traits<T>::ptr_type get_adjoint_ptr_byindex(uint64_t x, uint64_t order);
	typename workspace_traits<T>::ptr_type get_adjoint_ptr_byname(const char* s, uint64_t order);

	void set_adjoint(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order);
	void set_adjoint(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);
	void set_adjoint_byindex(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order);
	void set_adjoint_byindex(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);
	void set_adjoint_byname(const char* s, const typename workspace_traits<T>::type& xv, uint64_t order);
	void set_adjoint_byname(const char* s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);

	const typename workspace_traits<T>::type& get_aux(uint64_t x, uint64_t order) const;
	const typename workspace_traits<T>::type& get_aux_byindex(uint64_t x, uint64_t order) const;
	const typename workspace_traits<T>::type& get_aux_byname(const char* s, uint64_t order) const;

	typename workspace_traits<T>::ptr_type get_aux_ptr(uint64_t x, uint64_t order);
	typename workspace_traits<T>::ptr_type get_aux_ptr_byindex(uint64_t x, uint64_t order);
	typename workspace_traits<T>::ptr_type get_aux_ptr_byname(const char* s, uint64_t order);

	void set_aux(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order);
	void set_aux(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);
	void set_aux_byindex(uint64_t x, const typename workspace_traits<T>::type& xv, uint64_t order);
	void set_aux_byindex(uint64_t x, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);
	void set_aux_byname(const char* s, const typename workspace_traits<T>::type& xv, uint64_t order);
	void set_aux_byname(const char* s, const qnumber<typename number_traits<typename workspace_traits<T>::scalar_type>::type>& xv, uint64_t order);

	const uint64_t& get_var_counter() const { return m_var_counter; }

	const uint64_t& get_n() const { return m_n; }

};

template<class T>
qworkspace_p<T>* get_p(qworkspace<T>& w)
{
	qworkspace_p<T>* p;
	memcpy(&p, &w, sizeof(qworkspace<T>));
	return p;
}

template<class T>
qworkspace_p<T>* get_p(const qworkspace<T>& w)
{
	qworkspace_p<T>* p;
	memcpy(&p, &w, sizeof(qworkspace<T>));
	return p;
}
