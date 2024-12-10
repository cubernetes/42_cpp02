#include <iostream>
#include <cmath>
#include <ostream>

#include "Fixed.hpp"

Fixed::Fixed() : _value()
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intVal) : _value(intVal << _point)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floatVal) : _value(static_cast<int>(roundf(floatVal * (1 << _point))))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &fixed)
		_value = fixed.getRawBits();
	return *this;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	/* std::cout << "getRawBits member function called\n"; */
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	return out << fixed.toFloat();
}

int Fixed::toInt(void) const
{
	return _value >> _point;
}

float Fixed::toFloat(void) const
{
	return float(_value) / (1 << _point);
}
