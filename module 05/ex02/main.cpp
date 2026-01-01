#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl; 
    try {
        Bureaucrat gardener("Gardener", 130);
        ShrubberyCreationForm shrub("home");
        
        std::cout << gardener << std::endl;
        std::cout << shrub << std::endl;
        std::cout << std::endl;
        
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test 2: RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat engineer("Engineer", 40);
        RobotomyRequestForm robot("Bender");
        
        std::cout << engineer << std::endl;
        std::cout << robot << std::endl;
        std::cout << std::endl;
        
        engineer.signForm(robot);
        
        std::cout << "\n--- Attempting robotomy multiple times ---" << std::endl;
        engineer.executeForm(robot);
        engineer.executeForm(robot);
        engineer.executeForm(robot);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test 3: PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        std::cout << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test 4: Execute unsigned form ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 1);
        ShrubberyCreationForm unsignedForm("office");
        
        std::cout << "Trying to execute unsigned form..." << std::endl;
        intern.executeForm(unsignedForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}