#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& other) : vec(other.vec), N(other.N) {}


Span::~Span() {}


Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        vec = other.vec;
        N = other.N;
    }
    return *this;
}


void Span::addNumber(int num)
{
    if (vec.size() >= N)
        throw std::out_of_range("Exceeding the maximum capacity of the span.");
    vec.push_back(num);
}


int Span::shortestSpan() const
{
    if (vec.size() < 2)
        throw NoSpanException();

    std::vector<int> sortedVec(vec);
    std::sort(sortedVec.begin(), sortedVec.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedVec.size(); ++i)
    {
        int span = sortedVec[i] - sortedVec[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}


int Span::longestSpan() const
{
    if (vec.size() < 2)
        throw NoSpanException();

    int minVal = *std::min_element(vec.begin(), vec.end());
    int maxVal = *std::max_element(vec.begin(), vec.end());

    return maxVal - minVal;
}


