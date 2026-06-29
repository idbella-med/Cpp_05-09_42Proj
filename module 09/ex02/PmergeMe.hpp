#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sys/time.h>
#include <sstream>
#include <iomanip>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::list<int>   _lst;

    public:
        bool parse(char **av, int ac);
        void start();

    private:
        // Vector 
        std::vector<int> fordJohnsonVec(std::vector<int> vec);
        void             binaryInsertVec(std::vector<int> &sorted, int value, int bound);
        std::vector<int> buildInsertionOrder(int pendSize);
        std::vector<int> jacobsthalSequence(int n);

        // List
        std::list<int>   fordJohnsonLst(std::list<int> lst);
        void             binaryInsertLst(std::list<int> &sorted, int value,
                                         std::list<int>::iterator bound);
};