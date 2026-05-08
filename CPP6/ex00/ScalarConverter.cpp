#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
	std::string specialTypes[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};

	// Check for pseudo-literals
	for (int i = 0; i < 6; i++) {
		if (literal == specialTypes[i]) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (i < 3) {
				std::cout << "float: " << specialTypes[i] << std::endl;
				std::cout << "double: " << specialTypes[i + 3] << std::endl;
			} else {
				std::cout << "float: " << specialTypes[i - 3] << std::endl;
				std::cout << "double: " << specialTypes[i] << std::endl;
			}
			return;
		}
	}

	double double_val = 0.0;
	float float_val = 0.0f;

	// Single character literal
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
		return;
	}

	// Numeric conversion
	char* endptr;
	double_val = std::strtod(literal.c_str(), &endptr);

	// Check if float (ends with 'f' and has valid numeric before)
	if (*endptr == 'f' && *(endptr + 1) == '\0')
	{
		float_val = static_cast<float>(double_val);
	}
	else if (*endptr != '\0')
	{
		// If it's not a valid number or has extra junk
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}

	float_val = static_cast<float>(double_val);

	// Char output
	if (double_val < 0 || double_val > 127 || double_val != double_val) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<int>(double_val))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(double_val) << "'" << std::endl;
	}

	// Int output
	if (double_val < std::numeric_limits<int>::min() || double_val > std::numeric_limits<int>::max() || double_val != double_val) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(double_val) << std::endl;
	}

	// Float/Double output
	std::cout << "float: " << std::fixed << std::setprecision(1) << float_val << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << double_val << std::endl;
}
