#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Test 1: Creating valid bureaucrats ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
        
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        
        Bureaucrat john("John", 150);
        std::cout << john << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade too high (< 1) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low (> 150) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Increment grade ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 3);
        std::cout << charlie << std::endl;
        
        charlie.incrementGrade();
        std::cout << "After increment: " << charlie << std::endl;
        
        charlie.incrementGrade();
        std::cout << "After increment: " << charlie << std::endl;
        
        charlie.incrementGrade();
        std::cout << "After increment: " << charlie << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrement grade ===" << std::endl;
    try {
        Bureaucrat diana("Diana", 14);
        std::cout << diana << std::endl;
        
        diana.decrementGrade();
        std::cout << "After decrement: " << diana << std::endl;
        
        diana.decrementGrade();
        std::cout << "After decrement: " << diana << std::endl;
        
        diana.decrementGrade(); 
        std::cout << "After decrement: " << diana << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}