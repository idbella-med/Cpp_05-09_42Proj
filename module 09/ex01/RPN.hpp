#pragma once

#include <iostream>
#include <stack>
#include <exception>
#include <limits>


class RPN {
    private:
        std::stack<int> stack;
        int multi(int n1, int n2);
        int plus(int n1, int n2);
        int minus(int n1, int n2);
        int dvid(int n1, int n2);
    public:
        // zid caronical form 

        int calc(int n1, int n2, char op);
        void processInput(const std::string &str);
};