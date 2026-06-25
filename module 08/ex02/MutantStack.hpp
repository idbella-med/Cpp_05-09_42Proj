#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <stack>
#include <iostream>


template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        ~MutantStack() {}

        MutantStack& operator=(const MutantStack& other)                
        {
            std::stack<T>::operator=(other);
            return *this;
        }

        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }


};