/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:19:16 by pvass             #+#    #+#             */
/*   Updated: 2025/06/17 17:48:49 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
	    std::cerr << "Usage: ./harlFilter <LEVEL>" << std::endl;
	    return 1;
	}
	std::string input = argv[1];
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;

	for (int i = 0; i < 4; ++i)
	{
	    if (input == levels[i])
		{
	        index = i;
	        break;
	    }
	}
	harl.complainFiltered(index);
	return 0;
}
