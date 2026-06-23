#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
    private:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    public:
        MutantStack() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        ~MutantStack() {}
        MutantStack& operator=(const MutantStack& other)                
        {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        }
        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }
        const_iterator begin() const { return std::stack<T>::c.begin(); }
        const_iterator end() const { return std::stack<T>::c.end(); }
        

};