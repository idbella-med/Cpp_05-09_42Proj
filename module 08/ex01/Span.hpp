#pragma once


#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        std::vector<int> vec;
        unsigned int N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);

        void addNumber(int num);
        template <typename InputIt>
        void addNumbers(InputIt first, InputIt last)
        {
            if (std::distance(first, last) + vec.size() > N)
                throw std::out_of_range("Exceeding the maximum capacity of the span.");
            vec.insert(vec.end(), first, last);
        }

        int shortestSpan() const;
        int longestSpan() const;

        class NoSpanException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Not enough numbers to find a span.";
                }
        };
};