#include "AForm.hpp"


AForm::AForm() : Name("Default AForm"), Is_Signed(false), G_required_Sign(150), G_required_Execute(150) {
    std::cout << "AForm default constructor called" << std::endl;
}


AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : Name(name), Is_Signed(false), G_required_Sign(gradeToSign), G_required_Execute(gradeToExecute) {
    
    std::cout << "AForm parametric constructor called" << std::endl;
    
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}


AForm::AForm(const AForm& other)
    : Name(other.Name), Is_Signed(other.Is_Signed),
      G_required_Sign(other.G_required_Sign), G_required_Execute(other.G_required_Execute) {
    std::cout << "AForm copy constructor called" << std::endl;
}


AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &other) {
        Is_Signed = other.Is_Signed;
    }
    return *this;
}


AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}


const std::string& AForm::getName() const {
    return Name;
}

std::string AForm::isSigned() const {
    if (Is_Signed)
        return "yes";
    else
        return "no";
}

int AForm::getGradeToSign() const {
    return G_required_Sign;
}

int AForm::getGradeToExecute() const {
    return G_required_Execute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= G_required_Sign) {
        Is_Signed = true;
    } else {
        throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const AForm& Aform) {
    out << "AForm: " << Aform.getName()
        << ", Signed: " << Aform.isSigned()
        << ", Grade to sign: " << Aform.getGradeToSign()
        << ", Grade to execute: " << Aform.getGradeToExecute();
    return out;
}