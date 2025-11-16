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

    std::cout << "=== Test 5: Grade too low to execute ===" << std::endl;
    try {
        Bureaucrat lowGrade("LowGrade", 140);
        ShrubberyCreationForm shrub2("garden");
        
        std::cout << lowGrade << std::endl;
        std::cout << shrub2 << std::endl;
        std::cout << std::endl;
        
        lowGrade.signForm(shrub2);
        std::cout << "\nTrying to execute with low grade..." << std::endl;
        lowGrade.executeForm(shrub2);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test 6: All forms with CEO ===" << std::endl;
    try {
        Bureaucrat ceo("CEO", 1);
        
        ShrubberyCreationForm shrub3("park");
        RobotomyRequestForm robot2("Marvin");
        PresidentialPardonForm pardon2("Ford Prefect");
        
        std::cout << "--- Processing all forms ---" << std::endl;
        
        std::cout << "\n1. Shrubbery:" << std::endl;
        ceo.signForm(shrub3);
        ceo.executeForm(shrub3);
        
        std::cout << "\n2. Robotomy:" << std::endl;
        ceo.signForm(robot2);
        ceo.executeForm(robot2);
        
        std::cout << "\n3. Presidential Pardon:" << std::endl;
        ceo.signForm(pardon2);
        ceo.executeForm(pardon2);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test 7: Grade boundaries ===" << std::endl;
    try {
        Bureaucrat exact("Exact", 137);
        ShrubberyCreationForm shrub4("boundary");
        
        std::cout << "Required to execute: " << shrub4.getGradeToExecute() << std::endl;
        std::cout << "Bureaucrat grade: " << exact.getGrade() << std::endl;
        std::cout << std::endl;
        
        exact.signForm(shrub4);
        exact.executeForm(shrub4);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}