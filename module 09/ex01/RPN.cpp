#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &o) : stack(o.stack) {}

RPN &RPN::operator=(const RPN &o) {
    stack = o.stack;
    return *this;
}

RPN::~RPN() {}

int RPN::calc(int n1, int n2, char op) {
    if (op == '*')
        return multi(n1, n2);
    if (op == '+')
        return plus(n1, n2);
    if (op == '-')
        return minus(n1, n2);
    return divid(n1, n2);
}

bool parsedigit(const std::string &str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void RPN::processInput(const std::string &input)
{
    std::string operators = "+-/*";
    std::stringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        if (parsedigit(token))
        {
            if (token.size() != 1)
                throw std::runtime_error("Only single-digit numbers allowed");

            stack.push(token[0] - '0');
        }
        else if (token.size() == 1 &&
                operators.find(token[0]) != std::string::npos)
        {
            if (stack.size() < 2)
                throw std::runtime_error("Not enough operands");

            int num2 = stack.top();
            stack.pop();

            int num1 = stack.top();
            stack.pop();

            stack.push(calc(num1, num2, token[0]));
        }
        else
        {
            throw std::runtime_error("Invalid input");
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Invalid input");

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

int RPN::divid(int n1, int n2) {
    if (n2 == 0)
        throw std::runtime_error("dvide by zero !!");
    return n1 / n2;
}