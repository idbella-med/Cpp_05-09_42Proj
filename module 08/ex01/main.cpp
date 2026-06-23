#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumbers(1, 1000);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    return 0;
}