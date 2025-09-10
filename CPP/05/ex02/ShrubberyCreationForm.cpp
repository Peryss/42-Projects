#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "target", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
	if (getSigned() == false)
		throw AForm::NotSignedException();
	if (bureaucrat.getGrade() > getToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file((getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr <<"Failed to open file" << std::endl;
		return;
	}
	file << "         v .   ._, |_  .,\n"
        "           -._\\/  .  \\\\ /    |/_\n"
        "               \\\\  _\\\\, y | \\\\//\n"
        "         _\\\\_.___\\\\, \\\\/ -.\\\\||\n"
        "           `7-,--. ._||  / / ,\n"
        "           /       -.  ./ / |/_.\n"
        "                     |    |//\n"
        "                     |_    /\n"
        "                     |-   |\n"
        "                     |   =|\n"
        "                     |    |\n"
        "--------------------/ ,  . \\\\--------._";

	file.close();
}