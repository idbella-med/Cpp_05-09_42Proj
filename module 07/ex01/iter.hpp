#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename Func>
void iter(T* array, const size_t length, Func function) {
    for (size_t i = 0; i < length; i++) {
        function(array[i]);
    }
}


#endif