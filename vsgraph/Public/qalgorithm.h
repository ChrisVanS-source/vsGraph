#pragma once

#include "qscalar.h"
#include "qiterator.h"
#include <iterator>
#include <memory>

namespace vstech {

    template<class T> 
    class qalgorithm_p;

    template<class T>
    class qpredicate {

    public:

        qpredicate() {}
        virtual ~qpredicate() {}

        virtual qboolean<T> operator()(const qscalar<T>& x, const qscalar<T>& rhs) = 0;

    };

    template<class T, class Compare>
    class qpredicate_container : public qpredicate<T>
    {

        Compare& m_comp;

    public:

        qpredicate_container(Compare& comp) : m_comp(comp) {}
        ~qpredicate_container() {}

        qboolean<T> operator()(const qscalar<T>& x, const qscalar<T>& y)
        {
            return m_comp(x, y);
        }

    };

    template<class T>
    class qalgorithm
    {
        qalgorithm_p<T>* m_p;

        qalgorithm<T>& operator=(const qalgorithm<T>& rhs);

        qalgorithm(const qalgorithm<T>& rhs);

    public:

        qalgorithm();
        ~qalgorithm();

        qiterator_base<T> lower_bound(const qscalar<T>& x) const;
        qiterator_base<T> lower_bound(const T& x) const;
        qiterator_base<T> max_element() const;

        void add_element(const qscalar<T>& x);
        void add_element(const T& x);
        void add_element(const qnumber<typename number_traits<T>::type>& x);

        void add_compare(std::shared_ptr<qpredicate<T>> comp);

        template<typename ForwardIt>
        qalgorithm<T>& iterate(ForwardIt _first, ForwardIt _last)
        {
            auto _next = _first;

            while (_next != _last)
                add_element(*_next++);

            return *this;
        }

        template<typename ForwardIt, class Compare>
        qalgorithm<T>& iterate(ForwardIt _first, ForwardIt _last, Compare comp)
        {
            add_compare(std::static_pointer_cast<qpredicate<T>>(std::make_shared<qpredicate_container<T, Compare>>(comp)));
            
            auto _next = _first;

            while (_next != _last)
                add_element(*_next++);

            return *this;
        }

    };

    template<typename ForwardIt, class T>
    qiterator<ForwardIt, T> qlower_bound(ForwardIt _first, ForwardIt _last, const qscalar<T>& x)
    {
        return qiterator<ForwardIt, T>(_first, qalgorithm<T>().iterate(_first, _last).lower_bound(x));
    }

    template<typename ForwardIt, class T>
    qiterator<ForwardIt, T> qlower_bound(ForwardIt _first, ForwardIt _last, const T& x)
    {
        return qiterator<ForwardIt,T>(_first, qalgorithm<T>().iterate(_first, _last).lower_bound(x));
    }

    template<typename ForwardIt, class T, class Compare>
    qiterator<ForwardIt, T> qlower_bound(ForwardIt _first, ForwardIt _last, const T& x, Compare comp)
    {
        return qiterator<ForwardIt, T>(_first,qalgorithm<T>().iterate(_first, _last, comp).lower_bound(x));
    }

    template<typename ForwardIt>
    qiterator<ForwardIt, typename qtype_traits<typename std::iterator_traits<ForwardIt>::value_type::value_type>::mapped_type> qmax_element(ForwardIt _first, ForwardIt _last)
    {
        typedef typename std::iterator_traits<ForwardIt>::value_type::value_type value_type;
        return qiterator<ForwardIt, value_type>(_first, qalgorithm<value_type>().iterate(_first, _last).max_element());
    }

};
