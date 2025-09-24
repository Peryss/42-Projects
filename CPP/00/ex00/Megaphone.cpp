/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:47:47 by pvass             #+#    #+#             */
/*   Updated: 2025/05/21 12:34:49 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string text;
	int	j;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	j = 1;
	while (argv[j] != NULL)
	{
		text = (std::string) argv[j];
		for ( std::string::iterator i = text.begin(); i != text.end(); ++i)
			std::cout << (unsigned char)(std::toupper(*i));
		j++;
	}
	std::cout << std::endl;
}
