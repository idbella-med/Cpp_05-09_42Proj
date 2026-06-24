#include "iter.hpp"

void printInt(const int& n) {
    std::cout << n << " ";
}

void increment(int& n) {
    ++n;
}

void printString(const std::string& s) {
    std::cout << s << " ";
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "Original numbers: ";
    iter(numbers, 5, printInt);
    std::cout << std::endl;


    iter(numbers, 5, increment);
    std::cout << "After increment: ";
    iter(numbers, 5, printInt);
    std::cout << std::endl;

    std::string words[] = {"hello", "world", "C++", "templates"};
    std::cout << "Words: ";
    iter(words, 4, printString);
    std::cout << std::endl;

    return 0;
}