/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:33:10 by pvass             #+#    #+#             */
/*   Updated: 2025/10/07 15:39:24 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	try {
		std::cout << "Testing with vector:" << std::endl;
	    std::vector<int> v;
	    v.push_back(1);
	    v.push_back(2);
	    v.push_back(3);
	    v.push_back(4);

	    std::cout << "Searching 3 in vector..." << std::endl;
	    std::vector<int>::iterator it = easyfind(v, 3);
	    std::cout << "Found: " << *it << std::endl;

	    std::cout << "Searching 42 in vector..." << std::endl;
	    it = easyfind(v, 42);
	    std::cout << "Found: " << *it << std::endl;
	}
	catch (const NotFoundException& e) {
	    std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Testing with list:" << std::endl;
	try {
	    std::list<int> l;
	    l.push_back(10);
	    l.push_back(20);
	    l.push_back(30);

	    std::list<int>::iterator it = easyfind(l, 20);
	    std::cout << "Found in list: " << *it << std::endl;

	    easyfind(l, 99);
	}
	catch (const std::exception& e) {
	    std::cerr << e.what() << std::endl;
	}

	std::cout << "Testing with deque" << std::endl;
	try {
		std::deque<int> d;
		d.push_back(11);
	    d.push_back(22);
	    d.push_back(33);

		std::deque<int>::iterator it = easyfind(d, 11);
		std::cout << "Found in deque: " << *it << std::endl;

		easyfind(d, 0);

	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
