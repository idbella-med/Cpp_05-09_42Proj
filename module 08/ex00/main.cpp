#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Value found: " << *it << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Value found: " << *it << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}