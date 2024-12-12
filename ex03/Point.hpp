// <GENERATED>
#pragma once /* Point.hpp */

#include <string> /* std::string */
#include <iostream> /* std::ostream */

#include "repr.hpp" /* repr<T> */
#include "Fixed.hpp"

using std::string;
using std::ostream;

class Point {
public:
	// <generated>
	~Point(); // consider virtual if it's a base class
	Point();
	Point(const Fixed&, const Fixed&);
	Point(const float, const float);
	Point(const Point&);
	Point& operator=(const Point&);
	string repr() const;
	operator string() const;

	const Fixed& x() const;
	const Fixed& y() const;
	// </generated>
private:
	/* const */ Fixed _x;
	/* const */ Fixed _y;
};

template <> inline string repr(const Point& value) { return value.repr(); }
ostream& operator<<(ostream&, const Point&);
// </GENERATED>
