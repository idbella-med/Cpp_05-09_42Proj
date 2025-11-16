#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static bool isChar(const std::string& str);
        static bool isInt(const std::string& str);
        static bool isFloat(const std::string& str);
        static bool isDouble(const std::string& str);
        static bool isSpecial(const std::string& str);
        
        static void convertFromChar(char c);
        static void convertFromInt(int num);
        static void convertFromFloat(float num);
        static void convertFromDouble(double num);
        static void handleSpecial(const std::string& str);

    public:
        static void convert(const std::string& literal);
};

#endif