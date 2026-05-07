#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "===========================================" << std::endl;
    std::cout << "         TESTING STANDARD BEHAVIOR         " << std::endl;
    std::cout << "===========================================" << std::endl;
    try
    {
        Bureaucrat albert("Albert", 150);
        ShrubberyCreationForm s("Garden");
        RobotomyRequestForm r("Monkey");
        PresidentialPardonForm p(albert.getName());

        std::cout << "-------- Testing exec without grade --------" << std::endl;
        albert.executeForm(s);
        albert.executeForm(r);
        albert.executeForm(p);
        std::cout << std::endl;

        std::cout << "-------- Testing sign without grade --------" << std::endl;
        albert.signForm(s);
        albert.signForm(r);
        albert.signForm(p);
        std::cout << std::endl;

        Bureaucrat boss("Boss", 1);
        std::cout << "-------- Testing exec without sign --------" << std::endl;
        boss.executeForm(s);
        boss.executeForm(r);
        boss.executeForm(p);
        std::cout << std::endl;

        std::cout << "-------- Testing sign with grade --------" << std::endl;
        boss.signForm(s);
        boss.signForm(r);
        boss.signForm(p);
        std::cout << std::endl;

        std::cout << "-------- Testing exec with grade and sign --------" << std::endl;
        boss.executeForm(s);
        boss.executeForm(r);
        boss.executeForm(p);
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "===========================================" << std::endl;
    std::cout << "         TESTING EDGE CASES & BOUNDARIES   " << std::endl;
    std::cout << "===========================================" << std::endl;

    std::cout << "\n--- Edge Case 1: Bureaucrat grade limits ---" << std::endl;
    try {
        Bureaucrat tooHigh("TooHigh", 0);
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat tooLow("TooLow", 151);
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Edge Case 2: Form limits (Shrubbery: sign 145, exec 137) ---" << std::endl;
    try {
        Bureaucrat b146("B146", 146);
        Bureaucrat b145("B145", 145);
        Bureaucrat b138("B138", 138);
        Bureaucrat b137("B137", 137);
        ShrubberyCreationForm form("EdgeTree");

        b146.signForm(form); // Should fail
        b145.signForm(form); // Should succeed

        b138.executeForm(form); // Should fail
        b137.executeForm(form); // Should succeed
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Edge Case 3: Form limits (Presidential: sign 25, exec 5) ---" << std::endl;
    try {
        Bureaucrat b26("B26", 26);
        Bureaucrat b25("B25", 25);
        Bureaucrat b6("B6", 6);
        Bureaucrat b5("B5", 5);
        PresidentialPardonForm form("EdgePardon");

        b26.signForm(form); // Should fail
        b25.signForm(form); // Should succeed

        b6.executeForm(form); // Should fail
        b5.executeForm(form); // Should succeed
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Edge Case 4: Form limits (Robotomy: sign 72, exec 45) ---" << std::endl;
    try {
        Bureaucrat b73("B73", 73);
        Bureaucrat b72("B72", 72);
        Bureaucrat b46("B46", 46);
        Bureaucrat b45("B45", 45);
        RobotomyRequestForm form("EdgeRobot");

        b73.signForm(form); // Should fail
        b72.signForm(form); // Should succeed

        b46.executeForm(form); // Should fail
        b45.executeForm(form); // Should succeed
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
