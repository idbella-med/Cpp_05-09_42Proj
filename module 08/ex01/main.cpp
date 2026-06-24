#include "Span.hpp"

int main() {
    Span sp = Span(5);
    std::vector<int> v;
    std::srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int n = std::rand();
        v.push_back(n);
        std::cout << n << std::endl;
    }
    sp.addNumbers(v.begin(), v.end());
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    return 0;
}