/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:34:41 by pvass             #+#    #+#             */
/*   Updated: 2025/09/10 11:48:44 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
	    // --- ShrubberyCreationForm tests ---
	    std::cout << std::endl << "== ShrubberyCreationForm tests ==" << std::endl;
	    Bureaucrat bob("Bob", 100);           // ok for sign(145) & exec(137)
	    ShrubberyCreationForm garden("garden");

	    // 1) Execute before sign -> expect NotSignedException
	    try {
	        bob.executeForm(garden);
	    } catch (const std::exception& e) {
	        std::cout << "[expected] shrubbery not signed: " << e.what() << "\n";
	    }

	    // 2) Sign then execute -> should create garden_shrubbery file
	    bob.signAForm(garden);
	    try {
	        bob.executeForm(garden);
	        std::cout << "Shrubbery created: garden_shrubbery\n";
	    } catch (const std::exception& e) {
	        std::cout << "[unexpected] shrubbery exec failed: " << e.what() << "\n";
	    }

	    // 3) Too-low grade execute
	    Bureaucrat joe("Joe", 150);

	    joe.executeForm(garden);

	    // --- RobotomyRequestForm tests ---
	    std::cout << std::endl << "== RobotomyRequestForm tests ==" << std::endl;
	    Bureaucrat alice("Alice", 45);        // sign<=72, exec<=45 -> perfect
	    RobotomyRequestForm robo("Marvin");

	    // 1) Execute before sign -> expect NotSignedException
	    alice.executeForm(robo);

	    // 2) Sign then execute several times to observe ~50% success/fail
	    alice.signAForm(robo);
	    for (int i = 0; i < 10; ++i)
		{
	        alice.executeForm(robo);
	    }

	    // 3) Too-low grade execute
		joe.executeForm(robo); // grade 150 -> should fail

	    // 4) Too-low grade sign (optional)
	    Bureaucrat dave("Dave", 100);         // >72, cannot sign robotomy
	    try {
	        dave.signAForm(robo);              // depending on your signForm, this prints or throws
	    } catch (const std::exception& e) {
	        std::cout << "[expected] robotomy low-grade sign: " << e.what() << "\n";
	    }

		std::cout << std::endl << "== PresidentialPardonForm tests ==" << std::endl;
		PresidentialPardonForm pardon("Arthur Dent");

		// Execute before signing -> expect NotSignedException
		Bureaucrat exec("Exec", 5); // enough to execute
		exec.executeForm(pardon);

		// Sign with a good grade (<=25), then execute with a very high rank (<=5)
		Bureaucrat signer("Signer", 20);
		signer.signAForm(pardon);

		Bureaucrat president("President", 1);
		president.executeForm(pardon);

		// Too-low grade execute
		Bureaucrat low("Low", 150);
		low.executeForm(pardon);

	} catch (const std::exception& e) {
	    std::cerr << "Fatal error: " << e.what() << "\n";
	    return 1;
	}
	return 0;
}
