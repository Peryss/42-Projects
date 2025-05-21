/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:37:54 by pvass             #+#    #+#             */
/*   Updated: 2025/05/21 17:24:48 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
	public:
	Contact();
	~Contact();
	void		setContact(std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string d_secret);
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_darkest_secret();
	void		print_contact();
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

Contact::Contact()
{}

Contact::~Contact()
{}

void	Contact::setContact (std::string f_name, std::string l_name, std::string n_name, std::string p_number, std::string d_secret)
{
	first_name = f_name;
	last_name = l_name;
	nickname = n_name;
	phone_number = p_number;
	darkest_secret = d_secret; 
}

std::string Contact::get_first_name()
{
	return (first_name);
}

std::string Contact::get_last_name()
{
	return (last_name);
}

std::string Contact::get_nickname()
{
	return (nickname);
}

std::string Contact::get_phone_number()
{
	return (phone_number);
}

std::string Contact::get_darkest_secret()
{
	return (darkest_secret);
}

void    Contact::print_contact()
{
    std::cout << "First name    :" << get_first_name() << std::endl;
    std::cout << "Last name     :" << get_last_name() << std::endl;
    std::cout << "Nickname      :" << get_nickname() << std::endl;
    std::cout << "Phone number  :" << get_phone_number() << std::endl;
    std::cout << "Darkest secret:" << get_darkest_secret() << std::endl;
}
