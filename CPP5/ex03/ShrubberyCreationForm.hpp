
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:
		static void	printTree(const std::string& target) ;
		const std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& t);
		ShrubberyCreationForm(const ShrubberyCreationForm& s);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& s);
		~ShrubberyCreationForm() {};

		void	execute(Bureaucrat const &executor) const;
};

#endif //SHRUBBERYCREATIONFORM_HPP
