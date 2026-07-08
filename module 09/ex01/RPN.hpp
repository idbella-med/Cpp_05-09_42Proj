#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <exception>
#include <limits>


class RPN {
    private:
        std::stack<int> stack;
        int multi(int n1, int n2);
        int plus(int n1, int n2);
        int minus(int n1, int n2);
        int divid(int n1, int n2);
    public:
        RPN();
        RPN(const RPN &o);
        RPN &operator=(const RPN &o);
        ~RPN();

        int calc(int n1, int n2, char op);
        void processInput(const std::string &str);
};