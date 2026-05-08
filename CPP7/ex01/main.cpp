
#include "iter.hpp"
#include <iostream>

template <typename T>
void printElement(T& element)
{
	std::cout << element << std::endl;
}

int main() {
	int		arr[] = {0, 1, 2, 3, 4};
	float		f[] = {0.1, 1.2, 2.333, 3.001, 4.0};
	const char	s[] = {"Hola\n"};

	::iter(arr, 5, printElement<int>);
	::iter(s, 5, printElement<const char>);
	::iter(f, 5, printElement<float>);
	return 0;
}