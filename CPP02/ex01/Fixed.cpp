#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int intVal) {
	_value = intVal << _fractionBits;
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float floatVal) {
	_value = roundf(floatVal * (1 << _fractionBits));
	std::cout << "Float constructor called" << std::endl;
}
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return os << fixed.toFloat();
}
int Fixed::getRawBits() const {
	return _value;
}
void Fixed::setRawBits(int raw) {
	_value = raw;
}
float Fixed::toFloat() const {
	return (float)_value / (1 << _fractionBits);
}
int Fixed::toInt() const {
	return _value >> _fractionBits;
}