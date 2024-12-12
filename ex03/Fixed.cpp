#include <iostream>
#include <cmath>
#include <ostream>

#include "Fixed.hpp"

Fixed::Fixed() : _value()
{
	/* std::cout << "Default constructor called\n"; */
}

Fixed::Fixed(const int intVal) : _value(intVal << _point)
{
	/* std::cout << "Int constructor called\n"; */
}

Fixed::Fixed(const float floatVal) : _value(static_cast<int>(roundf(floatVal * (1 << _point))))
{
	/* std::cout << "Float constructor called\n"; */
}

Fixed::Fixed(const Fixed& fixed)
{
	/* std::cout << "Copy constructor called\n"; */
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this != &fixed)
		_value = fixed.getRawBits();
	return *this;
}
Fixed::~Fixed()
{
	/* std::cout << "Destructor called\n"; */
}

int Fixed::getRawBits(void) const
{
	/* std::cout << "getRawBits member function called\n"; */
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	/* std::cout << "setRawBits member function called\n"; */
	_value = raw;
}

bool Fixed::operator>(const Fixed& fixed) const {
	return _value > fixed._value;
}

bool Fixed::operator>=(const Fixed& fixed) const {
	return _value >= fixed._value;
}

bool Fixed::operator<(const Fixed& fixed) const {
	return _value < fixed._value;
}

bool Fixed::operator<=(const Fixed& fixed) const {
	return _value <= fixed._value;
}

bool Fixed::operator==(const Fixed& fixed) const {
	return _value == fixed._value;
}

bool Fixed::operator!=(const Fixed& fixed) const {
	return _value != fixed._value;
}

Fixed Fixed::operator+(const Fixed& fixed) const {
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const {
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const {
	Fixed ret;
	ret._value = static_cast<int>(static_cast<long>(_value) * static_cast<long>(fixed._value) >> _point);
	return ret;
}

Fixed Fixed::operator/(const Fixed& fixed) const {
	Fixed ret;
	ret._value = static_cast<int>((static_cast<long>(_value) << _point) / static_cast<long>(fixed._value));
	return ret;
}

Fixed& Fixed::operator++() {
	_value++;
	return *this;
}

Fixed& Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed ret(*this);
	this->_value++;
	return ret;
}

Fixed Fixed::operator--(int) {
	Fixed ret(*this);
	this->_value--;
	return ret;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed& b) {
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed& b) {
	return a > b ? a : b;
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
	return static_cast<float>(_value) / (1 << _point);
}
