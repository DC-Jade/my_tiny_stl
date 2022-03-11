#ifndef MY_TINY_STL_VECTOR_H_
#define MY_TINY_STL_VECTOR_H_

#include <initializer_list>

#include "iterator.h"
#include "memory.h"
#include "util.h"
#include "exceptdef.h"

namespace mystl {

#ifdef max
#pragma message("#undefing macro max")
#undef max //max
#endif

#ifdef min
#pragma message("#undefing macro min")
#undef min
#endif //min

// template class: vector
// template parameter type: T 
template <class T>
class vector{
    //static_assert(!std::is_same<bool, T>::value, "vector<bool> is abandoned in mystl");
public:
    // vector
    typedef mystl::allocator<T>                           allocator_type;
    typedef mystl::allocator<T>                           data_allocator;

    typedef typename allocator_type::value_type           value_type;
    typedef typename allocator_type::pointer              pointer;
    typedef typename allocator_type::const_pointer        const_pointer;
    typedef typename allocator_type::reference            reference;
    typedef typename allocator_type::const_reference      const_reference;
    typedef typename allocator_type::size_type            size_type;
    typedef typename allocator_type::difference_type      difference_type;

    typedef value_type                                    iterator;
    typedef const                                         value_type const_iterator;
    typedef mystl::reverse_iterator<iterator>             reverse_iterator;
    typedef mystl::reverse_iterator<const_iterator> const const_reverse_iterator;

private:
    iterator begin_;  // start
    iterator end_;    // end
    iterator cap_;    // capacity

public:
    // constructor copy_constructor deconstructor
    vector() noexcept {try_init}

    explicit vector(size_type n){
        fill_init(n, value_type());
    }
    
    vector(size_type n, const value_type &value){
        fill_init(n, value);
    }
    
};
}




#endif
