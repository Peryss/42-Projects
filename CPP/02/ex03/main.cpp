/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:38:55 by pvass             #+#    #+#             */
/*   Updated: 2025/06/18 13:07:01 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

#include <iostream>

int main( void )
{
	Point A(Fixed (0), Fixed (0));
	Point B(Fixed (3), Fixed (0));
	Point C(Fixed (0), Fixed (4));
	Point p(Fixed (1), Fixed (1));
	Point p2(Fixed (3), Fixed (3));
	
	if (bsp(A, B, C, p) == 1)
		std::cout << "inside" << std::endl;
	else
		std::cout << "outside" << std::endl;
		
	if (bsp(A, B, C, p2) == 1)
		std::cout << "inside" << std::endl;
	else
		std::cout << "outside" << std::endl;
	return 0;
}
	
