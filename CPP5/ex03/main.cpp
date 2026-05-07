#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    Intern someRandomIntern;

	std::cout << "--- Test 1: Robotomy Request ---" << std::endl;
    AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        std::cout << "Successfully created " << rrf->getName() << std::endl;
        delete rrf;
    }
    std::cout << std::endl;

    std::cout << "--- Test 2: Shrubbery Creation ---" << std::endl;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (rrf)
    {
        std::cout << "Successfully created " << rrf->getName() << std::endl;
        delete rrf;
    }
    std::cout << std::endl;

    std::cout << "--- Test 3: Presidential Pardon ---" << std::endl;
    rrf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (rrf)
    {
        std::cout << "Successfully created " << rrf->getName() << std::endl;
        delete rrf;
    }
    std::cout << std::endl;

    std::cout << "--- Test 4: Invalid Form ---" << std::endl;
    rrf = someRandomIntern.makeForm("invalid form", "Target");
    if (!rrf)
    {
        std::cout << "Correctly failed to create invalid form" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 5: Integration with Bureaucrat ---" << std::endl;
    Bureaucrat boss("Boss", 1);
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    return 0;
}
