#include <iostream>

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "Should print 0\n";
	std::cout << a << std::endl;
	std::cout << "Should print 0.00390625\n";
	std::cout << ++a << std::endl;
	std::cout << "Should print 0.00390625\n";
	std::cout << a << std::endl;
	std::cout << "Should print 0.00390625\n";
	std::cout << a++ << std::endl;
	std::cout << "Should print 0.0078125\n";
	std::cout << a << std::endl;

	std::cout << "Should print 10.1016\n";
	std::cout << b << std::endl;

	std::cout << "Should print 10.1016\n";
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
