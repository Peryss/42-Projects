/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:56:03 by pvass             #+#    #+#             */
/*   Updated: 2025/05/21 17:33:13 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook    add_contact(PhoneBook phonebook)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    
    std::cout << "First name:    ";
    do{
        std::cin >> first_name;
    } while(first_name.empty());
    std::cout << "Last name:     ";
    do{
        std::cin >> last_name;
    } while(last_name.empty());
    std::cout << "Nickname:      ";
    do{
        std::cin >> nickname;
    } while(nickname.empty());
    std::cout << "Phone number:  ";
    do{
        std::cin >> phone_number;
    } while(phone_number.empty());
    std::cout << "Darkest Secret:";
    do{
        std::cin >> darkest_secret;
    } while(darkest_secret.empty());
    phonebook.add(first_name, last_name, nickname, phone_number, darkest_secret);
    return (phonebook);
}

void printable(std::string str)
{
    std::string print;

    if (str.length() < 11)
    {
        for(int i = 0; i < 10 - (int)str.length(); i++)
            std::cout <<  " ";
        std::cout << str;
    }
    else
    {
        std::cout << str.substr(0, 9) + ".";
    }
}

void    search_contacts(PhoneBook phonebook)
{
    int size;
    std::string index;

    size = phonebook.get_size();
    if (size >= 8)
        size = 8;
    for(int i = 0; i < size; i++)
    {
        std::cout << "         " << i << "|";
        printable(phonebook.get_contact(i).get_first_name());
        std::cout << "|";
        printable(phonebook.get_contact(i).get_last_name());
        std::cout << "|";
        printable(phonebook.get_contact(i).get_nickname());
        std::cout << std::endl;
    }
    std::cout << "Index of the contact you are looking for: ";
    std::cin >> index;
    if (index.empty())
    {
        std::cout << "No contact information" << std::endl;
        return ;
    }
    else if (index.at(0) == '0' && index.length() == 1 && phonebook.get_size() > 0)
        phonebook.get_contact(0).print_contact();
    else if (index.at(0) == '1' && index.length() == 1 && phonebook.get_size() > 1)
        phonebook.get_contact(1).print_contact();
    else if (index.at(0) == '2' && index.length() == 1 && phonebook.get_size() > 2)
        phonebook.get_contact(2).print_contact();
    else if (index.at(0) == '3' && index.length() == 1 && phonebook.get_size() > 3)
        phonebook.get_contact(3).print_contact();
    else if (index.at(0) == '4' && index.length() == 1 && phonebook.get_size() > 4)
        phonebook.get_contact(4).print_contact();
    else if (index.at(0) == '5' && index.length() == 1 && phonebook.get_size() > 5)
        phonebook.get_contact(5).print_contact();
    else if (index.at(0) == '6' && index.length() == 1 && phonebook.get_size() > 6)
        phonebook.get_contact(6).print_contact();
    else if (index.at(0) == '7' && index.length() == 1 && phonebook.get_size() > 7)
        phonebook.get_contact(7).print_contact();
    else
        std::cout << "No contact information" << std::endl;
}

int main() {
    PhoneBook phonebook;
    std::string prompt;

    while (1)
    {
        std::cout << "Use one of the commands: ADD, SEARCH, EXIT" << std::endl;
        std::cin >> prompt;
        if (prompt.compare("ADD") == 0)
        {
            phonebook = add_contact(phonebook);
            phonebook.set_size();
        }
        else if (prompt.compare("SEARCH") == 0)
            search_contacts(phonebook);
        else if (prompt.compare("EXIT") == 0)
            break;
    }
    return 0;
}


/* int main() {
	PhoneBook pb;
	
	pb.add("John", "Doe", "JD", "12345", "Loves cats");
	pb.add("Jane", "Smith", "JS", "67890", "Afraid of heights");
	pb.add("Bob", "Brown", "BB", "22222", "Wears socks to bed");

	std::cout << "Size after 3 adds: " << pb.get_size() << std::endl; // Should print 3
} */

