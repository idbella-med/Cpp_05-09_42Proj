#include "RPN.hpp"


int RPN::calc(int n1, int n2, char op) {
    if (op == '*')
        return multi(n1, n2);
    if (op == '+')
        return plus(n1, n2);
    if (op == '-')
        return minus(n1, n2);
    return dvid(n1, n2);
}

void RPN::processInput(const std::string &str) {
    std::string tokens = "+-/*";
    for (size_t i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            stack.push(str[i] - '0');
        }
        else if (tokens.find(str[i]) != std::string::npos) {
            if (stack.size() < 2)
                throw std::runtime_error("number of num wrong");
            int num2 = stack.top();
            stack.pop();
            int num1 = stack.top();
            stack.pop();
            stack.push(calc(num1, num2, str[i]));
        }
        else if (isspace(str[i]))
            continue;
        else 
            throw std::runtime_error("invalid input");
    }
    if (stack.size() != 1)
        throw std::runtime_error("invalid expression");
    std::cout << stack.top() << std::endl;
}

int RPN::multi(int n1, int n2) {
    long long res = static_cast<long long>(n1) * n2;
    if (res > INT_MAX || res < INT_MIN)
        throw std::runtime_error("overflow !");
    return static_cast<int>(res);
}

int RPN::plus(int n1, int n2) {
    long long res = static_cast<long long>(n1) + n2;
    if (res > INT_MAX || res < INT_MIN)
        throw std::runtime_error("overflow !");
    return static_cast<int>(res);
}

int RPN::minus(int n1, int n2) {
    long long res = static_cast<long long>(n1) - n2;
    if (res > INT_MAX || res < INT_MIN)
        throw std::runtime_error("overflow !");
    return static_cast<int>(res);
}

int RPN::dvid(int n1, int n2) {
    if (n2 == 0)
        throw std::runtime_error("dvide by zero !!");
    return n1 / n2;
}