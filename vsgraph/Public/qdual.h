#pragma once

namespace vstech {

	template<class T>
	struct qdual_helper {

		static T two() { return 2.0; }
		static T ten() { return 10.0; }
		static T pi() { return 3.14159265358979323846; }
		static T two_sqrtpi() { return 1.12837916709551257390; }

	};

	template<class T>
	struct qdual_helper<qscalar<T>> {

		static typename qtype_traits<typename qscalar<T>::value_type>::type two() { return qdual_helper<typename qtype_traits<typename qscalar<T>::value_type>::type>::two(); }
		static typename qtype_traits<typename qscalar<T>::value_type>::type ten() { return qdual_helper<typename qtype_traits<typename qscalar<T>::value_type>::type>::ten(); }
		static typename qtype_traits<typename qscalar<T>::value_type>::type pi() { return qdual_helper<typename qtype_traits<typename qscalar<T>::value_type>::type>::pi(); }
		static typename qtype_traits<typename qscalar<T>::value_type>::type two_sqrtpi() { return qdual_helper<typename qtype_traits<typename qscalar<T>::value_type>::type>::two_sqrtpi(); }

	};

	template<>
	struct qdual_helper<float> {

		static float two() { return 2.0f; }
		static float ten() { return 10.0f; }
		static float pi() { return 3.14159f; }
		static float two_sqrtpi() { return 1.12837916709551257390f; }

	};

	template<class T>
	class qdual
	{

		T m_x;
		T m_dx;

	public:

		qdual(const T& x, const T& dx) : m_x(x), m_dx(dx) {}
		qdual() {}
		~qdual() {}

		const T& x() const { return m_x; }
		const T& dx() const { return m_dx; }

		qdual<T>& operator=(const qdual<T>& d)
		{
			if (&d != this)
			{
				m_x = d.m_x;
				m_dx = d.m_dx;
			}
			return *this;
		}

		qdual<T> operator+(const qdual<T>& d)
		{
			return qdual<T>(m_x + d.m_x, m_dx + d.m_dx);
		}

		qdual<T> operator-(const qdual<T>& d)
		{
			return qdual<T>(m_x - d.m_x, m_dx - d.m_dx);
		}

		qdual<T> operator*(const qdual<T>& d)
		{
			return qdual<T>(m_x * d.m_x, m_x*d.m_dx + d.m_x*m_dx);
		}

		qdual<T> operator/(const qdual<T>& d)
		{
			auto y = m_x / d.m_x;
			return qdual<T>(y, (m_dx - y*d.m_dx)/d.m_x);
		}

		qdual<T>& operator+=(const qdual<T>& d)
		{
			m_x += d.m_x;
			m_dx += d.m_dx;
			return *this;
		}

		qdual<T>& operator-=(const qdual<T>& d)
		{
			m_x -= d.m_x;
			m_dx -= d.m_dx;
			return *this;
		}

		qdual<T>& operator*=(const qdual<T>& d)
		{
			m_dx = m_dx * d.m_x + d.m_dx * m_x;
			m_x *= d.m_x;
			return *this;
		}

		qdual<T>& operator/=(const qdual<T>& d)
		{
			m_x /= d.m_x;
			m_dx = (m_dx - m_x * d.m_dx) / d.m_x;
			return *this;
		}

		qdual<T> operator-()
		{
			return qdual<T>(-m_x, -m_dx);
		}

	};

}

namespace std 
{
	template<class T>
	vstech::qdual<T> sin(const vstech::qdual<T>& x)
	{
		return vstech::qdual<T>(std::sin(x.x()), std::cos(x.x())*x.dx());
	}

	template<class T>
	vstech::qdual<T> cos(const vstech::qdual<T>& x)
	{
		return vstech::qdual<T>(std::cos(x.x()), -std::sin(x.x())*x.dx());
	}

	template<class T>
	vstech::qdual<T> exp(const vstech::qdual<T>& x)
	{
		auto y = std::exp(x.x());
		return vstech::qdual<T>(y, y*x.dx());
	}

	template<class T>
	vstech::qdual<T> tan(const vstech::qdual<T>& x)
	{
		return vstech::qdual<T>(std::tan(x.x()), x.dx()/(std::cos(x.x())* std::cos(x.x())));
	}

	template<class T>
	vstech::qdual<T> sinh(const vstech::qdual<T>& x)
	{
		return vstech::qdual<T>(std::sinh(x.x()), std::cosh(x.x()) * x.dx());
	}

	template<class T>
	vstech::qdual<T> cosh(const vstech::qdual<T>& x)
	{
		return vstech::qdual<T>(std::cosh(x.x()), std::sinh(x.x()) * x.dx());
	}

	template<class T>
	vstech::qdual<T> log(const vstech::qdual<T>& x)
	{
		return vstech::qdual<T>(std::log(x.x()), x.dx() / x.x());
	}

	template<class T>
	vstech::qdual<T> log2(const vstech::qdual<T>& x)
	{
		return vstech::qdual<T>(std::log2(x.x()), x.dx() / (x.x() * std::log(vstech::qdual_helper<T>::two())));
	}

	template<class T>
	vstech::qdual<T> log10(const vstech::qdual<T>& x)
	{
		return vstech::qdual<T>(std::log10(x.x()), x.dx() / (x.x() * std::log(vstech::qdual_helper<T>::ten())));
	}

	template<class T>
	vstech::qdual<T> erfc(const vstech::qdual<T>& x)
	{
		return vstech::qdual<T>(std::erfc(x.x()), -x.dx() * std::exp(-x.x()*x.x())*vstech::qdual_helper<T>::two_sqrtpi());
	}

};

template<class T>
vstech::qdual<T> operator/(const T& x, const vstech::qdual<T>& y)
{
	auto z = x / y.x();
	return vstech::qdual<T>(z, -z * y.dx() / y.x());
}
