#pragma once

#include <cstdint>
#include <map>
#include "qgraph_traits.h"

class lifecycle {

	uint64_t m_created;
	uint64_t m_first_used;
	uint64_t m_last_used;
	uint64_t m_first_index;
	uint64_t m_last_index;
	bool m_is_param;

public:

	lifecycle(uint64_t created = (uint64_t)-1) : m_created(created), m_first_used((uint64_t)-1), m_last_used((uint64_t)-1), m_first_index((uint64_t)-1), m_last_index((uint64_t)-1), m_is_param(true) {}

	bool was_used() const { return m_created != (uint64_t)-1 && (m_first_used != (uint64_t)-1 || m_last_index != (uint64_t)-1); }
	uint64_t& first_used() { return m_first_used; }
	const uint64_t& first_used() const { return m_first_used; }
	uint64_t& created() { return m_created; }
	uint64_t& last_used() { return m_last_used; }
	const uint64_t& last_used() const { return m_last_used; }
	uint64_t& first_index() { return m_first_index; }
	const uint64_t& first_index() const { return m_first_index; }
	uint64_t& last_index() { return m_last_index; }
	const uint64_t& last_index() const { return m_last_index; }
	bool& is_param() { return m_is_param; }
	const bool& is_param() const { return m_is_param; }
	const uint64_t& created() const { return m_created; }


};

class boolean_value {

public:

	boolean_value() {}
	virtual ~boolean_value() {}

	virtual uint64_t get_index() const = 0;

};

template<class T>
class _boolean : public boolean_value {

	const typename graph_traits<T>::boolean_type& m_b;
	std::map<typename graph_traits<T>::boolean_type, uint64_t>& m_boolean_map;

public:

	_boolean(const typename graph_traits<T>::boolean_type& b, std::map<typename graph_traits<T>::boolean_type, uint64_t>& boolean_map) : m_b(b), m_boolean_map(boolean_map) {}

	uint64_t get_index() const
	{
		auto it = m_boolean_map.find(m_b);
		if (it == m_boolean_map.end())
			it = m_boolean_map.insert({ m_b, m_boolean_map.size() }).first;
		return it->second;
	}

};

class integer_value {

public:

	integer_value() {}
	virtual ~integer_value() {}

	virtual uint64_t get_index() const = 0;

};

template<class T>
class integer : public integer_value {

	const typename graph_traits<T>::integer_type& m_i;
	std::map<typename graph_traits<T>::integer_type, uint64_t, integer_type_predicate<T>>& m_integer_map;

public:

	integer(const typename graph_traits<T>::integer_type& i, std::map<typename graph_traits<T>::integer_type, uint64_t, integer_type_predicate<T>>& integer_map) : m_i(i), m_integer_map(integer_map) {}

	uint64_t get_index() const
	{
		auto it = m_integer_map.find(m_i);
		if (it == m_integer_map.end())
			it = m_integer_map.insert({ m_i, m_integer_map.size() }).first;
		return it->second;
	}

};


class scalar_value {

public:

	scalar_value() {}
	virtual ~scalar_value() {}

	virtual uint64_t get_index() const = 0;

};

template<class T>
class scalar : public scalar_value {

	const typename graph_traits<T>::scalar_type& m_x;
	std::map<typename graph_traits<T>::scalar_type_map, uint64_t>& m_scalar_map;

public:

	scalar(const typename graph_traits<T>::scalar_type& x, std::map<typename graph_traits<T>::scalar_type_map, uint64_t>& scalar_map) : m_x(x), m_scalar_map(scalar_map) {}

	uint64_t get_index() const
	{
		auto it = m_scalar_map.find(m_x);
		if (it == m_scalar_map.end())
			it = m_scalar_map.insert({ m_x, m_scalar_map.size() }).first;
		return it->second;
	}

};

#include <vector>
#include <boost/bimap.hpp>

#include "qgraph_enum.h"

class lifecycle_helper {

	const std::vector<std::vector<boost::bimap<uint64_t, uint64_t>>>& m_input_map;
	const std::vector<boost::bimap<uint64_t, uint64_t>>& m_output_map;
	bool m_lifecycle_input;

public:

	lifecycle_helper(const std::vector<std::vector<boost::bimap<uint64_t, uint64_t>>>& input_map,
		const std::vector<boost::bimap<uint64_t, uint64_t>>& output_map, bool lifecycle_input = true) : 
		m_input_map(input_map), 
		m_output_map(output_map),
		m_lifecycle_input(lifecycle_input)
	{}

	~lifecycle_helper() {}

	void update(std::vector<std::vector<lifecycle>>& lc, const uint64_t& now)
	{
		if (m_lifecycle_input)
			for (DataType dt = QFLOATING_POINT; dt != NUMBER_OF_TYPES; dt = next_data_type(dt))
				for (uint64_t j = 0; j < m_input_map[dt].size(); ++j)
					for (auto it = m_input_map[dt][j].left.begin(); it != m_input_map[dt][j].left.end(); ++it) if (lc[dt][it->second].first_used() != (uint64_t)-1)
					{
						lc[dt][it->second].first_used() = 0;
						lc[dt][it->second].last_used() = now;
					}


		for (uint64_t j = 0; j < m_output_map.size(); ++j)
			for (auto it = m_output_map[j].left.begin(); it != m_output_map[j].left.end(); ++it)
			{
				lc[QFLOATING_POINT][it->second].last_used() = now;
				if (lc[QFLOATING_POINT][it->second].first_used() == (uint64_t)-1)
					lc[QFLOATING_POINT][it->second].first_used() = lc[QFLOATING_POINT][it->second].last_used() - 1;
			}

	}

};
