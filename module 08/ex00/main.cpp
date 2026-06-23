#include "easyfind.hpp"

int main() {
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    try {
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "Value found: " << *it << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 6);
        std::cout << "Value found: " << *it << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}