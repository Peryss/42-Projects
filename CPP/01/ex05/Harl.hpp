/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:18:55 by pvass             #+#    #+#             */
/*   Updated: 2025/06/17 17:43:18 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
	void	debug ( void );
	void	info ( void );
	void	warning ( void );
	void	error ( void );
public:
	Harl();
	~Harl();
	void	complain ( const std::string level);
};

#endif
