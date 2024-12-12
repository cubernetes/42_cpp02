#include "Point.hpp"
#include "Fixed.hpp"

static int cross_sign(Point v1, Point v2) {
	Fixed a_1 = v1.x();
	Fixed a_2 = v1.y();
	// Fixed a_3 = 0;
	Fixed b_1 = v2.x();
	Fixed b_2 = v2.y();
	// Fixed b_3 = 0;
	Fixed c_3 = (a_1 * b_2) - (a_2 * b_1);
	if (c_3 < 0)
		return -1;
	else if (c_3 > 0)
		return 1;
	return 0;
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	int signa = cross_sign(Point(a.x() - point.x(), a.y() - point.y()),
	                       Point(a.x() -     b.x(), a.y() -     b.y()));
	int signb = cross_sign(Point(b.x() - point.x(), b.y() - point.y()),
	                       Point(b.x() -     c.x(), b.y() -     c.y()));
	int signc = cross_sign(Point(c.x() - point.x(), c.y() - point.y()),
	                       Point(c.x() -     a.x(), c.y() -     a.y()));
	if (signa < 0 && signb < 0 && signc < 0)
		return 1;
	else if (signa > 0 && signb > 0 && signc > 0)
		return 1;
	return 0;
}
