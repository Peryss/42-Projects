/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:33:44 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 09:33:45 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat B1("Alan", 50);
		std::cout << B1 << std::endl;

		for (int i = 0; i < 49; i++)
			B1.incrementGrade();
		std::cout << B1 << std::endl;

		B1.incrementGrade();
		std::cout << B1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat B2("Bob", 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat B2("Bob", -5);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat B4("Josh", 100);
		std::cout << B4 << std::endl;

		for (int i = 0; i < 50; i++)
			B4.decrementGrade();
		std::cout << B4 << std::endl;

		B4.decrementGrade();
		std::cout << B4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}