#include "Array.hpp"

int main() {
    try {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        Array<int> numbers(5);
        std::cout << "Numbers array size: " << numbers.size() << std::endl;

        for (size_t i = 0; i < numbers.size(); ++i) {
            numbers[i] = i * 10;
        }

        std::cout << "Numbers: ";
        for (size_t i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;


        Array<int> copyNumbers(numbers);
        copyNumbers[0] = 999;

        std::cout << "Original after copy modification: ";
        for (size_t i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Copy: ";
        for (size_t i = 0; i < copyNumbers.size(); ++i) {
            std::cout << copyNumbers[i] << " ";
        }
        std::cout << std::endl;

        std::cout << numbers[10] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}