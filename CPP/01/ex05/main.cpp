/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:18:57 by pvass             #+#    #+#             */
/*   Updated: 2025/06/17 17:45:15 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

int main()
{
    Harl harl;

    harl.complain("DEBUG");

    harl.complain("INFO");

    harl.complain("WARNING");

    harl.complain("ERROR");

    harl.complain("SILLY");

	harl.complain("");

    return 0;
}
