
#include "Point.hpp"

#include <iostream>

int main( void )
{
	Point A(Fixed ( 0 ), Fixed (0));
	Point B(Fixed ( 3 ), Fixed (0));
	Point C(Fixed ( 0 ), Fixed (4));
	Point p(Fixed ( 1 ), Fixed (1));
	
	if (bsp(A, B, C, p) == 1)
		std::cout << "inside" << std::endl;
	else
		std::cout << "outside" << std::endl;	
	return 0;
}
	
