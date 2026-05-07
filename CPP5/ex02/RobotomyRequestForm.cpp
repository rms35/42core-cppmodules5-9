
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
		AForm("RobotomyRequestForm", "Default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& t) :
		AForm("RobotomyRequestForm", t, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) :
		AForm(s) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& s)
{
	(void)s;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	static int count;

	if (count == 0)
	{
		std::srand(time(NULL));
		count++;
	}
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw FormNotSigned();
	for (int i = 0; i < 5; i++)
		std::cout << "Drill!! Drill!!" << std::endl;
	if (std::rand() % 2)
		std::cout << this->getTarget() << " robotomy failed" << std::endl;
	else
		std::cout << this->getTarget() << " has been robotomized successfully"
				<< std::endl;
}