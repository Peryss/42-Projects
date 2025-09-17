/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:33:13 by pvass             #+#    #+#             */
/*   Updated: 2025/09/17 10:33:14 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//max_size: 1073741823 vector

int main() {
    try {
        std::cout << "=== Test addNumber ===" << std::endl;
        Span sp1(5);
        sp1.addNumber(6);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
        std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp1.longestSpan() << std::endl;

        std::cout << std::endl << "=== Test addNumber overfill ===" << std::endl;
        try {
            sp1.addNumber(42);
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << std::endl << "=== Test not enough numbers ===" << std::endl;
        Span sp2(3);
        try {
            std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        sp2.addNumber(10);
        try {
            std::cout << "Longest: " << sp2.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << std::endl << "=== Test addNumbers (range insert) ===" << std::endl;
        std::vector<int> v;
        v.push_back(100);
        v.push_back(200);
        v.push_back(150);
        v.push_back(400);
        v.push_back(250);

        Span sp3(10);
        sp3.addNumbers(v.begin(), v.end());
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp3.longestSpan() << std::endl;

        std::cout << std::endl << "=== Test addNumbers overfill ===" << std::endl;
        Span sp4(3);
        std::vector<int> small;
        small.push_back(1);
        small.push_back(2);
        small.push_back(3);
        try {
            sp4.addNumbers(small.begin(), small.end());
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

		std::cout << std::endl << "=== 10000 elements ===" << std::endl;
        std::vector<int> ve;
        ve.reserve(10000);
        for (unsigned int i = 0; i < 10000; ++i) {
            ve.push_back((int)i);
        }

        Span sp5(10000);
        sp5.addNumbers(ve.begin(), ve.end());

        std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp5.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
