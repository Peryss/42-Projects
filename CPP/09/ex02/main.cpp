/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:56:09 by pvass             #+#    #+#             */
/*   Updated: 2025/09/30 10:56:11 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc == 1){
		std::cerr << "Please provide numbers to sort" << std::endl;
		return 0;
	}
	try {
		std::vector<Tracker> v;
		std::deque<Tracker> d;
		for (int i = 1; i < argc; i++)
		{
			parse_input(v, argv[i]);
			parse_input(d, argv[i]);
		}
		std::vector<Tracker*> v_2;
        v_2.reserve(v.size());
        for (std::vector<Tracker>::size_type i = 0; i < v.size(); ++i)
            v_2.push_back(&v[i]);

		std::deque<Tracker*> d_2;
        for (std::deque<Tracker>::size_type i = 0; i < d.size(); ++i)
            d_2.push_back(&d[i]);

		std::cout << "Before:	";
		for (std::vector<Tracker>::iterator it = v.begin(); it != v.end(); ++it)
			std::cout << " " << (*it).getValue();
		std::cout << std::endl;
		in_sort(v_2, "vector");
		in_sort(d_2, "deque");
	}
	catch(std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}