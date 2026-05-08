
#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data d = {"Hola", 10};
	uintptr_t p = Serializer::serialize(&d);
	Data *c = Serializer::deserialize(p);

	std::cout << "p =" << &d << "; s = "<< d.s << "; n = " << d.n <<  std::endl;
	std::cout << "p =" << p << std::endl;
	std::cout << "p =" << c << "; s = "<< c->s << "; n = " << c->n <<
		std::endl;
}