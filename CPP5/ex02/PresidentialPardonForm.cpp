
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() :
		AForm("PresidentialPardonForm", "Default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& t) :
		AForm("PresidentialPardonForm", t, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s) :
		AForm(s) {}

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
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" <<
		std::endl;
}
