#pragma once

#include "qinteger.h"
#include "qscalar.h"

namespace vstech {

    template<class T>
    class qiterator_base_p;

    template<class T>
    class qiterator_base {

        qiterator_base_p<T>* m_p;

    public:

        qiterator_base();
        qiterator_base(const qiterator_base<T>& rhs);
        ~qiterator_base();

        qiterator_base<T>& operator=(const qiterator_base<T>& rhs);

        qscalar<T> operator*() const;

        qinteger<typename qtype_traits<T>::mapped_type> operator-(int64_t i) const;

    };

    template<typename ForwardIt, class T>
    class qiterator  
    {
        ForwardIt m_it;
        qiterator_base<T> m_base;

    public:

        qiterator(ForwardIt it, const qiterator_base<T>& base) : m_base(base), m_it(it) {}

        ~qiterator() {}

        qinteger<typename qtype_traits<T>::mapped_type> operator-(ForwardIt it) const
        {
            return m_base.operator-(it - m_it);
        }

        qscalar<T> operator*() const
        {
            return m_base.operator*();
        }

    };

}