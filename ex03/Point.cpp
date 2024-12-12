// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "Point.hpp"

using std::cout;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Point::~Point() { /* cout << "~Point()\n"; */ }
Point::Point() : _x(), _y() { /* cout << "Point()\n"; */ }
Point::Point(const float x, const float y) : _x(x), _y(y) { /* cout << *this << '\n'; */ }
Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) { /* cout << *this << '\n'; */ }
Point::Point(const Point& other) : _x(other._x), _y(other._y) { /* cout << "Point(" << ::repr(other) << ")\n"; */ }

// Copy-assignment operator
Point& Point::operator=(const Point& other) /* noexcept */ {
	/* cout << "Point& Point::operator=(" << ::repr(other) << ")\n"; */
	_x = other._x;
	_y = other._y;
	return *this;
}

// Generated getters
const Fixed& Point::x() const { return _x; }
const Fixed& Point::y() const { return _y; }

// Generated member functions
string Point::repr() const {
	stringstream out;
	out << "Point(" << ::repr(_x) << ", " << ::repr(_y) << ")";
	return out.str();
}
Point::operator string() const { return ::repr(*this); }

// Generated free functions
ostream& operator<<(ostream& os, const Point& other) { return os << static_cast<string>(other); }
// </GENERATED>
