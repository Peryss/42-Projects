/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:44:24 by pvass             #+#    #+#             */
/*   Updated: 2025/05/28 10:55:39 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include "Contact.hpp"

class PhoneBook
{
	public:
	PhoneBook();
	~PhoneBook();
	int		get_size();
	void	set_size();
	Contact	get_contact(int i);
	Contact *add(std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string d_secret);
	void	add_contact();
	void	search_contacts();
	private:
	int	size;
	Contact contacts[8];
};

#endif
