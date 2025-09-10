#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    try {
        Intern intern;
        Bureaucrat boss("Boss", 1);      // can sign & execute anything
        Bureaucrat low("Low", 150);      // cannot execute most things

        std::cout << "== Intern creates RobotomyRequestForm ==\n";
        AForm* r1 = 0;
        try {
            r1 = intern.makeForm("robotomy request", "Bender");
            boss.signAForm(*r1);
            // execute a few times to see ~50/50 outcomes
            for (int i = 0; i < 3; ++i)
                boss.executeForm(*r1);
            // low-grade try
            low.executeForm(*r1);
        } catch (const std::exception& e) {
            std::cout << "[robotomy] exception: " << e.what() << std::endl;
        }
        delete r1;

        std::cout << "\n== Intern creates ShrubberyCreationForm ==\n";
        AForm* s1 = 0;
        try {
            s1 = intern.makeForm("shrubbery creation", "backyard");
            boss.signAForm(*s1);
            boss.executeForm(*s1);   // should create backyard_shrubbery
            low.executeForm(*s1);    // expected to fail
        } catch (const std::exception& e) {
            std::cout << "[shrubbery] exception: " << e.what() << std::endl;
        }
        delete s1;

        std::cout << "\n== Intern creates PresidentialPardonForm ==\n";
        AForm* p1 = 0;
        try {
            p1 = intern.makeForm("presidential pardon", "Arthur Dent");
            boss.signAForm(*p1);
            boss.executeForm(*p1);   // should print Zaphod message
            low.executeForm(*p1);    // expected to fail
        } catch (const std::exception& e) {
            std::cout << "[pardon] exception: " << e.what() << std::endl;
        }
        delete p1;

        std::cout << "\n== Intern unknown form (should throw) ==\n";
        try {
            AForm* bad = intern.makeForm("time travel permit", "Morty");
            // If your makeForm throws, we never get here; if it returns NULL, guard:
            if (bad) delete bad;
        } catch (const Intern::UnknownFormException& e) {
            std::cout << "[unknown] caught UnknownFormException: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "[unknown] other exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
