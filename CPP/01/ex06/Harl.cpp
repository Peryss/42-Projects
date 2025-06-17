/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:19:11 by pvass             #+#    #+#             */
/*   Updated: 2025/06/17 17:48:34 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
    std::cout << "[DEBUG]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; // array of functions

    for (int i = 0; i < 4; ++i)
	{
        if (level == levels[i])
		{
            (this->*funcs[i])();
            return;
        }
    }
    std::cout << "[HARL DID NOT UNDERSTAND]\n";
}

void Harl::complainFiltered(int index)
{
    switch (index)
	{
        case 0:
            debug();
			// fall through
        case 1:
            info();
			// fall through
        case 2:
            warning();
			// fall through
        case 3:
            error();
            break;
        default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
