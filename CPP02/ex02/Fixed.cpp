#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n) {
	_value = n << _fractionalBits;
}
Fixed::Fixed(const float f) {
	_value = roundf(f * (1 << _fractionalBits));
}
Fixed::Fixed(const Fixed& other) {
	*this = other;
}
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}
Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return _value;
}
void Fixed::setRawBits(int const raw) {
	_value = raw;
}
float Fixed::toFloat() const {
	return (float)_value / (1 << _fractionalBits);
}
int Fixed::toInt() const {
	return _value >> _fractionalBits;
}
bool Fixed::operator>(const Fixed& other) const {
	return _value > other.getRawBits();
}
bool Fixed::operator<(const Fixed& other) const {
	return _value < other.getRawBits();
}
bool Fixed::operator>=(const Fixed& other) const {
	return _value >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed& other) const {
	return _value <= other.getRawBits();
}
bool Fixed::operator==(const Fixed& other) const {
	return _value == other.getRawBits();
}
bool Fixed::operator!=(const Fixed& other) const {
	return _value != other.getRawBits();
}
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}
Fixed& Fixed::operator++() {
	++this->_value;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}
Fixed& Fixed::operator--() {
	--this->_value;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
