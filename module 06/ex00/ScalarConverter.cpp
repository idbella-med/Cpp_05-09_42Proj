#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& str) {
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& str) {
    if (str.empty())
        return false;
    
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    if (i >= str.length())
        return false;
    
    while (i < str.length()) {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
    if (str.empty() || str[str.length() - 1] != 'f')
        return false;
    
    std::string without_f = str.substr(0, str.length() - 1);
    if (without_f.empty())
        return false;
    
    size_t i = 0;
    if (without_f[i] == '+' || without_f[i] == '-')
        i++;
    
    bool has_dot = false;
    bool has_digit = false;
    
    while (i < without_f.length()) {
        if (without_f[i] == '.') {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else if (isdigit(without_f[i]))
            has_digit = true;
        else
            return false;
        i++;
    }
    return has_digit && has_dot;
}

bool ScalarConverter::isDouble(const std::string& str) {
    if (str.empty())
        return false;
    
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    bool has_dot = false;
    bool has_digit = false;
    
    while (i < str.length()) {
        if (str[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
        }
        else if (isdigit(str[i]))
            has_digit = true;
        else
            return false;
        i++;
    }
    return has_digit && has_dot;
}

bool ScalarConverter::isSpecial(const std::string& str) {
    return (str == "nan" || str == "nanf" || 
            str == "+inf" || str == "-inf" || 
            str == "+inff" || str == "-inff" ||
            str == "inf" || str == "inff");
}

void ScalarConverter::convertFromChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int num) {
    if (num < 0 || num > 127)
        std::cout << "char: impossible" << std::endl;
    else if (num < 32 || num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(float num) {
    if (std::isnan(num) || std::isinf(num) || num < 0 || num > 127)
        std::cout << "char: impossible" << std::endl;
    else if (num < 32 || num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;

    if (std::isnan(num) || std::isinf(num) || 
        num < std::numeric_limits<int>::min() || 
        num > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    
    std::cout << "float: " << num;
    if (num == static_cast<int>(num) && !std::isnan(num) && !std::isinf(num))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    
    std::cout << "double: " << static_cast<double>(num);
    if (num == static_cast<int>(num) && !std::isnan(num) && !std::isinf(num))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(double num) {
    if (std::isnan(num) || std::isinf(num) || num < 0 || num > 127)
        std::cout << "char: impossible" << std::endl;
    else if (num < 32 || num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    
    if (std::isnan(num) || std::isinf(num) || 
        num < std::numeric_limits<int>::min() || 
        num > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    
    std::cout << "float: " << static_cast<float>(num);
    if (num == static_cast<int>(num) && !std::isnan(num) && !std::isinf(num))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << num;
    if (num == static_cast<int>(num) && !std::isnan(num) && !std::isinf(num))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::handleSpecial(const std::string& str) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (str == "nanf" || str == "nan") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (str == "-inff" || str == "-inf") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: empty string" << std::endl;
        return;
    }

    if (isSpecial(literal)) {
        handleSpecial(literal);
        return;
    }

    if (isChar(literal)) {
        convertFromChar(literal[1]);
        return;
    }

    if (isInt(literal)) {
        long long num = std::atoll(literal.c_str());
        if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
            std::cout << "Error: int overflow" << std::endl;
            return;
        }
        convertFromInt(static_cast<int>(num));
        return;
    }

    if (isFloat(literal)) {
        float num = std::atof(literal.c_str());
        convertFromFloat(num);
        return;
    }

    if (isDouble(literal)) {
        double num = std::atof(literal.c_str());
        convertFromDouble(num);
        return;
    }
    
    std::cout << "Error: invalid literal" << std::endl;
}