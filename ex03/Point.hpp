// <GENERATED>
#pragma once /* Point.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */

using std::string;
using std::ostream;

class Point {
public:
	// <generated>
	~Point(); // consider virtual if it's a base class
	Point();
	Point(const Fixed&, const Fixed&);
	Point(const Point&);
	Point& operator=(Point);
	void swap(Point&);
	string repr() const;
	operator string() const;

	const Fixed& get_x() const;
	const Fixed& get_y() const;

	void set_x(const Fixed&);
	void set_y(const Fixed&);
	// </generated>
private:
	const Fixed _x;
	const Fixed _y;
};

template <>
inline string repr(const Point& value) {
	return value.repr();
}

void swap(Point&, Point&) /* noexcept */;
ostream& operator<<(ostream&, const Point&);
// </GENERATED>
