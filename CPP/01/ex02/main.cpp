/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:55:11 by pvass             #+#    #+#             */
/*   Updated: 2025/05/29 14:05:08 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;


	std::cout << "Memory address of str      : " << &str << std::endl;
    std::cout << "Memory address held by PTR : " << stringPTR << std::endl;
    std::cout << "Memory address held by REF : " << &stringREF << std::endl;

	std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Value of str               : " << str << std::endl;
    std::cout << "Value pointed to by PTR    : " << *stringPTR << std::endl;
    std::cout << "Value referenced by REF    : " << stringREF << std::endl;
}
