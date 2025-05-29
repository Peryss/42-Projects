/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:27:24 by pvass             #+#    #+#             */
/*   Updated: 2025/05/28 11:29:18 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "main.hpp"

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

void	PhoneBook::add_contact()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    
	get_input("First name:    ", first_name);
    get_input("Last name:     ", last_name);
	get_input("Nickname:      ", nickname);
    get_input("Phone number:  ", phone_number);
	get_input("Darkest secret:", darkest_secret);
    PhoneBook::add(first_name, last_name, nickname, phone_number, darkest_secret);
}


void    PhoneBook::search_contacts()
{
    int size;
    std::string index;

    size = PhoneBook::get_size();
	if (size == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}
    if (size >= 8)
        size = 8;
    for(int i = 0; i < size; i++)
    {
        std::cout << "         " << i << "|";
        printable(PhoneBook::get_contact(i).get_first_name());
        std::cout << "|";
        printable(PhoneBook::get_contact(i).get_last_name());
        std::cout << "|";
        printable(PhoneBook::get_contact(i).get_nickname());
        std::cout << std::endl;
    }
    std::cout << "Index of the contact you are looking for: ";
     if (!std::getline(std::cin, index))
	{
	    std::cin.clear();
	    std::cin.ignore(0, '\n');
    	std::freopen("/dev/tty", "r", stdin);
		std::cerr << "\nInput interrupted. Leaving process...\n";
        return ;
	}
    if (is_empty(index) == 1)
    {
        std::cout << "No contact information" << std::endl;
        return ;
    }
    else if (index.at(0) == '0' && index.length() == 1 && PhoneBook::get_size() > 0)
        PhoneBook::get_contact(0).print_contact();
    else if (index.at(0) == '1' && index.length() == 1 && PhoneBook::get_size() > 1)
        PhoneBook::get_contact(1).print_contact();
    else if (index.at(0) == '2' && index.length() == 1 && PhoneBook::get_size() > 2)
        PhoneBook::get_contact(2).print_contact();
    else if (index.at(0) == '3' && index.length() == 1 && PhoneBook::get_size() > 3)
        PhoneBook::get_contact(3).print_contact();
    else if (index.at(0) == '4' && index.length() == 1 && PhoneBook::get_size() > 4)
        PhoneBook::get_contact(4).print_contact();
    else if (index.at(0) == '5' && index.length() == 1 && PhoneBook::get_size() > 5)
        PhoneBook::get_contact(5).print_contact();
    else if (index.at(0) == '6' && index.length() == 1 && PhoneBook::get_size() > 6)
        PhoneBook::get_contact(6).print_contact();
    else if (index.at(0) == '7' && index.length() == 1 && PhoneBook::get_size() > 7)
        PhoneBook::get_contact(7).print_contact();
    else
        std::cout << "No contact information" << std::endl;
}
