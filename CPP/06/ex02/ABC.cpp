/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABC.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:13:09 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 11:29:07 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"

Base *generate(void)
{
	int nr = std::rand() % 3;
	switch (nr){
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
		default: return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Type C" << std::endl;
	else 
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
	}
	catch (std::exception &e) {
		try{
			(void)dynamic_cast<B&>(p);
			std::cout << "Type B" << std::endl;
		}
		catch (std::exception &e) {
			try{
				(void)dynamic_cast<C&>(p);
				std::cout << "Type C" << std::endl;
			}
			catch (std::exception &e) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}