#include <iostream>
#include <cmath>

class Fixed {
private:
	int _value;
	static const int _fractionBits = 8;
public:
	Fixed();
	Fixed(const int intVal);
	Fixed(const float floatVal);
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	int getRawBits() const;
	void setRawBits(int raw);
	float toFloat() const;
	int toInt() const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);