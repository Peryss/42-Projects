/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:38:05 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 09:44:30 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
