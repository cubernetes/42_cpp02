// <GENERATED>
#include <iostream> /* std::cout, std::swap, std::ostream */
#include <string> /* std::string */
#include <sstream> /* std::stringstream */

#include "repr.hpp"
#include "Point.hpp"

using std::cout;
using std::swap;
using std::string;
using std::ostream;
using std::stringstream;

// De- & Constructors
Point::~Point() { cout << "~Point()\n"; }
Point::Point() : _x(), _y() { cout << "Point()\n"; }
Point::Point(const float x, const float y) : _x(x), _y(y) { cout << *this << '\n'; }
Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) { cout << *this << '\n'; }
Point::Point(const Point& other) : _x(), _y() { cout << "Point(" << ::repr(other) << ")\n"; }

// Copy-assignment operator (using copy-swap idiom)
Point& Point::operator=(Point other) /* noexcept */ {
	cout << "Point& Point::operator=(" << ::repr(other) << ")\n";
	::swap(*this, other);
	return *this;
}

// Generated getters
const Fixed& Point::get_x() const { return _x; }
const Fixed& Point::get_y() const { return _y; }

// Generated setters
void Point::set_x(const Fixed& value) { _x = value; }
void Point::set_y(const Fixed& value) { _y = value; }

// Generated member functions
string Point::repr() const {
	stringstream out;
	out << "Point(" << ::repr(_x) << ", " << ::repr(_y) << ")";
	return out.str();
}
void Point::swap(Point& other) /* noexcept */ {
	::swap(_x, other._x);
	::swap(_y, other._y);
}
Point::operator string() const { return ::repr(*this); }

// Generated free functions
void swap(Point& a, Point& b) /* noexcept */ { a.swap(b); }
ostream& operator<<(ostream& os, const Point& other) { return os << static_cast<string>(other); }
// </GENERATED>


