#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	std::cout << "Testing constructors\n";
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	std::cout << "Assignment:\n";
	a = Fixed( 1234.4321f );
	std::cout << '\n';

	std::cout << "Testing functions and overloads\n";
	std::cout << "a is this float: " << a << std::endl;
	std::cout << "b is this float: " << b << std::endl;
	std::cout << "c is this float: " << c << std::endl;
	std::cout << "d is this float: " << d << std::endl;
	std::cout << '\n';

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
