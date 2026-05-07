//
// Created by rafael on 5/7/26.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm  : public AForm
{
private:
		const std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& t);
		PresidentialPardonForm(const PresidentialPardonForm& s);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& s);
		~PresidentialPardonForm() {};

		void	execute(Bureaucrat const &executor) const;
};

#endif //PRESIDENTIALPARDONFORM_HPP
