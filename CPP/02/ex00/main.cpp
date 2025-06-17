
#include "Fixed.hpp"

#include <iostream>

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "-------------------" << std::endl;

	Fixed d;
	d.setRawBits(11584);
	Fixed e( d );
	Fixed f;

	f = e;
	std::cout << d.getRawBits() << std::endl;
	std::cout << e.getRawBits() << std::endl;
	std::cout << f.getRawBits() << std::endl;

	return 0;
}
