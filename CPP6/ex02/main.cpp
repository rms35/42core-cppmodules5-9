
#include <iostream>
#include "Base.hpp"

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <typeinfo>

Base* generate()
{
	static int count;

	if (count == 0)
	{
		std::srand(time(NULL));
		count++;
	}

	const int r = rand();
	const int	third = RAND_MAX / 3;
	Base *ret = NULL;
	if (r <= third)
		ret = new A();
	else if (r <= (2 * third))
		ret = new B();
	else
		ret = new C();
	return (ret);
}

void	identify(Base* p)
{
	char c = '\0';

	if (dynamic_cast<A*>(p))
		c = 'A';
	else if (dynamic_cast<B*>(p))
		c = 'B';
	else if (dynamic_cast<C*>(p))
		c = 'C';
	if (c == '\0')
		std::cout << "Unknown";
	std::cout << c << " pointer identified" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A reference identified" << std::endl;
		return;
	}
	catch (const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B reference identified" << std::endl;
		return;
	}
	catch (const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C reference identified" << std::endl;
		return;
	}
	catch
	(const std::exception& e) {}

	std::cout << "Unknown  reference identified" << std::endl;

}

int main()
{
	Base *a = generate();
	identify(a);
	if (a)
	{
		identify(*a);
	}
	delete a;
}