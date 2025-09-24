/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:16:22 by pvass             #+#    #+#             */
/*   Updated: 2025/05/28 11:29:33 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool get_input(const std::string &prompt, std::string &input)
{
	std::cout << prompt;
	if (!std::getline(std::cin, input)) {
		std::cin.clear();
		std::cin.ignore(0, '\n');
		std::freopen("/dev/tty", "r", stdin);
		std::cerr << "\nInput interrupted. Leaving...\n";
		return false;
	}
	if (input == "") {
		std::cerr << "Cannot be empty!" << std::endl;
		get_input(prompt, input);
	}
	return true;
}

void printable(std::string str)
{
	std::string print;

	if (str.length() < 11)
	{
	    for(int i = 0; i < 10 - (int)str.length(); i++)
	        std::cout <<  " ";
	    std::cout << str;
	}
	else
	{
	    std::cout << str.substr(0, 9) + ".";
	}
}

bool	is_empty(std::string str)
{
	if (str.empty() == 1)
		return (1);
	for ( std::string::iterator i = str.begin(); i != str.end(); ++i)
		if (std::isspace((unsigned char)*i) == 0)
			return (0);
	return (1);
}
