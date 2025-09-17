/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:35:21 by pvass             #+#    #+#             */
/*   Updated: 2025/09/17 15:51:41 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2 || bad_filename(argv[1]))
		std::cerr << "Please provide a filename" << std::endl;
	std::map<std::string, float> map;
	

}