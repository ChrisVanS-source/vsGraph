#pragma once

#include "qscalar.h"
#include <complex>

namespace std {

	template<class T>
	class complex<vstech::qscalar<T>> {

		typedef vstech::qscalar<T> type;

	public:

		complex() {}

		complex(const type& re) : m_re(re), m_im(0.0)
		{
		}

		complex(const type& re, const type& im) : m_re(re), m_im(im)
		{}

		complex(const double& rhs) : m_re(rhs), m_im(0.0)
		{}


		~complex() {}

		complex<type>& operator=(const complex<type>& rhs)
		{
			if (&rhs != this)
			{
				m_re = rhs.m_re;
				m_im = rhs.m_im;
			}
			return *this;
		}

		complex<type>& operator=(const double& rhs)
		{
			m_re = rhs;
			m_im = 0.0;
			return *this;
		}

		complex<type>& operator*=(const type& rhs)
		{
			m_re *= rhs;
			m_im *= rhs;
			return *this;
		}

		complex<type>& operator*=(const complex<type>& rhs)
		{
			type re = m_re * rhs.m_re - m_im * rhs.m_im;
			m_im = m_im * rhs.m_re + m_re * rhs.m_im;
			m_re = re;
			return *this;
		}

		complex<type>& operator/=(const complex<type>& rhs)
		{
			auto norm = rhs.real() * rhs.real() + rhs.imag() * rhs.imag();
			auto re = (real() * rhs.real() + imag() * rhs.imag()) / norm;
			m_im = (-re * rhs.imag() + m_im * rhs.real()) / norm;
			m_re = re;
			return *this;
		}

		complex<type>& operator-=(const complex<type>& rhs)
		{
			m_re -= rhs.m_re;
			m_im -= rhs.m_im;
			return *this;
		}

		complex<type>& operator-=(const type& rhs)
		{
			m_re -= rhs;
			return *this;
		}

		complex<type>& operator-=(const double& rhs)
		{
			m_re -= rhs;
			return *this;
		}

		complex<type> operator-(const vstech::qnumber<typename vstech::number_traits<T>::type>& rhs)
		{
			return complex<type>(m_re - rhs, m_im);
		}

		complex<type>& operator+=(const double& rhs)
		{
			m_re += rhs;
			m_im = 0.0;
			return *this;
		}

		complex<type>& operator+=(const complex<type>& rhs)
		{
			m_re += rhs.m_re;
			m_im += rhs.m_im;
			return *this;
		}

		complex<type> operator/(const vstech::qnumber<typename vstech::number_traits<T>::type>& rhs)
		{
			return complex<type>(m_re/rhs, m_im/rhs);
		}

		complex<type> operator*(const complex<type>& rhs)
		{
			complex<type> r = *this;
			r *= rhs;
			return r;
		}

		complex<type> operator*(const double& rhs)
		{
			return complex<type>(m_re * rhs, m_im * rhs);
		}


		const type& real() const
		{
			return m_re;
		}

		const type& imag() const
		{
			return m_im;
		}

	private:

		type m_re;
		type m_im;

	};

	template<class T>
	complex<vstech::qscalar<T>> sin(const complex<vstech::qscalar<T>>& rhs)
	{
		return complex<vstech::qscalar<T>>(sin(rhs.real()) * cosh(rhs.imag()), cos(rhs.real()) * sinh(rhs.imag()));
	}

	template<class T>
	complex<vstech::qscalar<T>> cos(const complex<vstech::qscalar<T>>& rhs)
	{
		return complex<vstech::qscalar<T>>(cos(rhs.real()) * cosh(rhs.imag()), -sin(rhs.real()) * sinh(rhs.imag()));
	}

};
