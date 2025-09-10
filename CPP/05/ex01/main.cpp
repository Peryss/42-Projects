/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:34:11 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 09:34:14 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat B1("Alan", 50);
		std::cout << B1 << std::endl;

		Form F1("Important Form", 1, 1);
		std::cout << F1 << std::endl;

		Form F2("Not so important Form", 50, 50);
		std::cout << F2 << std::endl;

		B1.signForm(F1);
		std::cout << F1 << std::endl;

		B1.signForm(F2);
		std::cout << F2 << std::endl;

		Form F3("A Form", 5, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Form F4("A Form", 5, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Form F5("A Form", -1, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Form F6("A Form", 555, 5);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Form F6("A Form", 555, 555);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}