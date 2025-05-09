#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeToHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeToLowException();
	std::cout << "Form constructor called for \"" << this->name << "\"" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called for \"" << this->name << "\"" << std::endl;
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "Form copy assingment operator called" << std::endl;
	return *this;
}

const std::string& Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeToLowException();
	isSigned = true;
}

const char* Form::GradeToHighException::what() const throw() {
	return "Form grade is too high";
}

const char* Form::GradeToLowException::what() const throw() {
	return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form \"" << form.getName() << "\", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
	return os;
}