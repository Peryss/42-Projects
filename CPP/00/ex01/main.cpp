/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:56:03 by pvass             #+#    #+#             */
/*   Updated: 2025/05/28 11:29:00 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main() {
	PhoneBook phonebook;
	std::string input;

	while (1)
	{
	    do
	    {
	        std::cout << std::endl << "Use one of the commands: ADD, SEARCH, EXIT" << std::endl;
	        if (!std::getline(std::cin, input))
	        {
		        std::cin.clear();
		        std::cin.ignore(0, '\n');
		        std::freopen("/dev/tty", "r", stdin);
		        std::cerr << "\nInput interrupted. Leaving...\n";
	            return (1);
	        }
	    } while (is_empty(input) == 1);
	    if (input.compare("ADD") == 0)
	    {
	        phonebook.add_contact();
	        phonebook.set_size();
	    }
	    else if (input.compare("SEARCH") == 0)
	        phonebook.search_contacts();
	    else if (input.compare("EXIT") == 0)
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

