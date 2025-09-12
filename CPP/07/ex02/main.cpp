/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:07:26 by pvass             #+#    #+#             */
/*   Updated: 2025/09/12 14:50:51 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"



int main()
{
	try 
	{
		unsigned int idx = 10;
		Array<int>	int_array(idx);
		Array<double>	double_array(idx);

		for(unsigned int i = 0; i < idx; i++)
		{
			int_array[i] = i * 10;
			double_array[i] = i * 1.1;
		}

		std::cout << "Int array[" << int_array.size() << "]: ";
		for(unsigned int i = 0; i < idx; i++)
		{
			std::cout << int_array[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Double array[" << double_array.size() << "]: ";
		for(unsigned int i = 0; i < idx; i++)
		{
			std::cout << double_array[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "----- ERROR -----" << std::endl;

		try{
			int_array[11] = 1;
			std::cout << "You shouldn't see this massage" << std::endl;
		} catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	catch(const std::exception& e){
		std::cerr << "Fatal error: " << e.what() << std::endl;
	}
}
