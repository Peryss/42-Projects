/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:13:24 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 10:13:28 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"

int main()
{
	Base *obj;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "--New--"<< std::endl;
		obj = generate();
		std::cout << "pointer:";
		identify(obj);
		std::cout << "reference:";
		identify(*obj);
		delete obj;
	}
}