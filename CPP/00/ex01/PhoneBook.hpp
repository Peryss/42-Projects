/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:44:24 by pvass             #+#    #+#             */
/*   Updated: 2025/05/21 17:07:30 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
	private:
	int	size;
	Contact contacts[8];
};

PhoneBook::PhoneBook()
{
	size = 0;
}

PhoneBook::~PhoneBook()
{}

int		PhoneBook::get_size()
{
	return (size);
}

void		PhoneBook::set_size()
{
	size++;
}

Contact		PhoneBook::get_contact(int i)
{
	return (contacts[i]);
}

Contact	*PhoneBook::add(std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string d_secret)
{
	contacts[size % 8].setContact(f_name, l_name, n_name, p_number, d_secret);
	std::cout << "--Contact added--" << std::endl;
	return (contacts);
}
