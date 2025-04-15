#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		static bool printSpecialCases(const std::string &convert);
		static void printChar(char c);
		static void printInt(long int i);
		static void printFloat(float f);
		static void printDouble(double d);
		static void printImpossible();

	public:
		static void convert(std::string convert);
};

#endif
