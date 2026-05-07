
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& t);
		RobotomyRequestForm(const RobotomyRequestForm& s);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& s);
		~RobotomyRequestForm() {};

		void	execute(Bureaucrat const &executor) const;
};

#endif //ROBOTOMYREQUESTFORM_HPP
