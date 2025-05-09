#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeToHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeToLowException();
	std::cout << "AForm constructor called for \"" << this->name << "\"" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor called for \"" << this->name << "\"" << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "AForm copy assingment operator called" << std::endl;
	return *this;
}

const std::string& AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeToLowException();
	isSigned = true;
}

const char* AForm::GradeToHighException::what() const throw() {
	return "AForm grade is too high";
}

const char* AForm::GradeToLowException::what() const throw() {
	return "AForm grade is too low";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form is not signed and cannot be executed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm \"" << form.getName() << "\", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
	return os;
}