
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
		AForm("PresidentialPardonForm", 25, 5), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& t) :
		AForm("PresidentialPardonForm", 25, 5), target(t) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s) :
		AForm(s), target(s.target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& s)
{
	(void)s;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw FormNotSigned();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" <<
		std::endl;
}
