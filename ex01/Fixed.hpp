#pragma once

#include <ostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int intVal);
	Fixed(const float floatVal);
	Fixed(const Fixed& fixed);
	~Fixed();
	Fixed& operator=(const Fixed& fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
private:
	int _value;
	static const int _point = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
