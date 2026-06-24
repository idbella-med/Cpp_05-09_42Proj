#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& str) {
    if (str.size() == 1) {
        if (isdigit(str[0]))
            return false;
        return true;
    }
    return (str.size() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& str) {
    if (str.empty())
        return false;
    
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    if (i >= str.size())
        return false;
    
    while (i < str.size()) {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
    if (str.empty() || str[str.size() - 1] != 'f')
        return false;

    std::string s = str.substr(0, str.size() - 1);
    if (s.empty())
        return false;

    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;

    bool has_digit = false;
    bool has_dot = false;

    for (; i < s.size(); i++) {
        if (isdigit(s[i]))
            has_digit = true;
        else if (s[i] == '.' && !has_dot)
            has_dot = true;
        else
            return false;
    }

    return has_digit;
}

bool ScalarConverter::isDouble(const std::string& str) {
    if (str.empty())
        return false;
    
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    bool has_dot = false;
    bool has_digit = false;
    
    while (i < str.size()) {
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
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(int num) {
    if (num < 0 || num > 127)
        std::cout << "char: impossible" << std::endl;
    else if (num < 32 || num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void ScalarConverter::convertFromFloat(float num) {
    if (num < 0 || num > 127)
        std::cout << "char: impossible" << std::endl;
    else if (num < 32 || num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;

    if (num < std::numeric_limits<int>::min() || 
        num > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    
        std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void ScalarConverter::convertFromDouble(double num) {
    if (num < 0 || num > 127)
        std::cout << "char: impossible" << std::endl;
    else if (num < 32 || num == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    
    if (num < std::numeric_limits<int>::min() || 
        num > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << num << std::endl;
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
        if (literal.size() == 1)
            convertFromChar(literal[0]);
        else
            convertFromChar(literal[1]);
        return;
    }

    if (isInt(literal)) {
        long long num = std::atoll(literal.c_str());
        if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) {
            convertFromDouble(std::atof(literal.c_str()));
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