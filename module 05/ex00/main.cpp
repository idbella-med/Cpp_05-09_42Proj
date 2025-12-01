#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Test 1: Creating valid bureaucrats ===" << std::endl;
    try {
        Bureaucrat mohamed0("mohamed0", 50);
        std::cout << mohamed0 << std::endl;
        
        Bureaucrat mohamed1("mohamed1", 1);
        std::cout << mohamed1 << std::endl;
        
        Bureaucrat mohamed2("mohamed2", 150);
        std::cout << mohamed2 << std::endl;
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
        Bureaucrat saad("saad", 3);
        std::cout << saad << std::endl;
        
        saad.incrementGrade();
        std::cout << "After increment: " << saad << std::endl;
        
        saad.incrementGrade();
        std::cout << "After increment: " << saad << std::endl;
        
        saad.incrementGrade();
        std::cout << "After increment: " << saad << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrement grade ===" << std::endl;
    try {
        Bureaucrat zakaria("zakaria", 148);
        std::cout << zakaria << std::endl;
        
        zakaria.decrementGrade();
        std::cout << "After decrement: " << zakaria << std::endl;
        
        zakaria.decrementGrade();
        std::cout << "After decrement: " << zakaria << std::endl;
        
        zakaria.decrementGrade(); 
        std::cout << "After decrement: " << zakaria << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}