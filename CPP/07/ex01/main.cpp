/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:33:23 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 11:48:35 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main () {
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	double array2[] = {1.0, 1.1, 1.2, 1.3, 1.4};
	char array3[] = "Hello World";

	std::cout << "Int array: " << std::endl;
	iter(array, 10, print_elem);
	std::cout << std::endl;
	iter(array, 10, add5);
	iter(array, 10, print_elem);
	std::cout << std::endl;

	std::cout << "Double array: " << std::endl;
	iter(array2, 5, print_elem);
	std::cout << std::endl;
	iter(array2, 5, add5);
	iter(array2, 5, print_elem);
	std::cout << std::endl;

	std::cout << "Char array: " << std::endl;
	iter(array3, 12, print_elem);
	std::cout << std::endl;
	iter(array3, 5, add5);
	iter(array3, 12, print_elem);
	std::cout << std::endl;
}