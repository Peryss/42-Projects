/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:38:30 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 11:25:32 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << "INCREMENT" << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "DECREMENT" << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << b << std::endl;
	std::cout << "Max: "<< Fixed::max(a, b) << ", Min: " << Fixed::min(a, b) << std::endl;

	std::cout << "-----------" << std::endl;
	Fixed* A = new Fixed();
	std::cout << *A << std::endl;
	std::cout << ++*A << std::endl;
	std::cout << *A << std::endl;
	std::cout << (*A)++ << std::endl;
	delete(A);

	std::cout << "OPERATORS" << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;

	std::cout << "COMPARISONS" << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a != b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a >= b) << std::endl;

	return 0;
}
	
