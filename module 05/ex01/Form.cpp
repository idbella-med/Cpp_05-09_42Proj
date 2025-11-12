#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : Name("Default Form"), Is_Signed(false), G_required_Sign(150), G_required_Execute(150) {
    std::cout << "Form default constructor called" << std::endl;
}


Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : Name(name), Is_Signed(false), G_required_Sign(gradeToSign), G_required_Execute(gradeToExecute) {
    
    std::cout << "Form parametric constructor called" << std::endl;
    
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}


Form::Form(const Form& other)
    : Name(other.Name), Is_Signed(other.Is_Signed),
      G_required_Sign(other.G_required_Sign), G_required_Execute(other.G_required_Execute) {
    std::cout << "Form copy constructor called" << std::endl;
}


Form& Form::operator=(const Form& other) {
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other) {
        Is_Signed = other.Is_Signed;
    }
    return *this;
}


Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}


const std::string& Form::getName() const {
    return Name;
}

std::string Form::isSigned() const {
    if (Is_Signed)
        return "yes";
    else
        return "no";
}

int Form::getGradeToSign() const {
    return G_required_Sign;
}

int Form::getGradeToExecute() const {
    return G_required_Execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= G_required_Sign) {
        Is_Signed = true;
    } else {
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form: " << form.getName()
        << ", Signed: " << form.isSigned()
        << ", Grade to sign: " << form.getGradeToSign()
        << ", Grade to execute: " << form.getGradeToExecute();
    return out;
}