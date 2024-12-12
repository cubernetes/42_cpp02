#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

using std::cout;

bool bsp(const Point a, const Point b, const Point c, const Point point);

void check(const Point a, const Point b, const Point c, const Point p) {
	if (bsp(a, b, c, p))
		cout << "Point " << p << " is inside the triangle " << a << ", " << b << ", " << c << '\n';
	else
		cout << "Point " << p << " is NOT inside the triangle " << a << ", " << b << ", " << c << '\n';
}

int main( void ) {
	Point a, b, c, p;

	a = Point(1, 0);
	b = Point(3, 0);
	c = Point(2, 3);
	p = Point(1, 0);
	check(a, b, c, p);

	a = Point(1, 0);
	b = Point(3, 0);
	c = Point(2, 3);
	p = Point(2, 0);
	check(a, b, c, p);

	a = Point(1, 0);
	b = Point(3, 0);
	c = Point(2, 3);
	p = Point(2.0f, 0.1f);
	check(a, b, c, p);

	a = Point(1, 0);
	b = Point(3, 0);
	c = Point(2, 3);
	p = Point(2, 1);
	check(a, b, c, p);

	a = Point(0, 0);
	b = Point(0, 0);
	c = Point(0, 0);
	p = Point(0, 0);
	check(a, b, c, p);
	return 0;
}
