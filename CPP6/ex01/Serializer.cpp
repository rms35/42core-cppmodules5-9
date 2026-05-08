
#include "Serializer.hpp"

Serializer::Serializer(const Serializer &s)
{
	(void)s;
}

Serializer & Serializer::operator=(const Serializer &s)
{
	(void)s;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serializer::deserialize(const uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
