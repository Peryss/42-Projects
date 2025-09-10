#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>

class AForm;

class Intern {
public:
    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;

    class UnknownFormException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
