#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(1);
        sp.addNumber(4);
        sp.addNumber(5);
        sp.addNumber(2);
        sp.addNumber(3);
    
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        int s = 10;
        Span sp = Span(s);

        std::vector<int> vec;
        std::srand(time(0));
        for (int i = 0; i < s; i++) {
            vec.push_back(std::rand());
        }

        sp.addNumbers(vec.begin(), vec.end());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}