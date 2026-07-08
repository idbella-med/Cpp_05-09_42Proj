#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sys/time.h>
#include <sstream>
#include <iomanip>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &o);
        PmergeMe &operator=(const PmergeMe &o);
        ~PmergeMe();
        
        bool parse(char **av, int ac);
        void start();

    private:
        std::vector<int> _vec;
        std::list<int>   _lst;

        std::vector<int> fordJohnsonVec(std::vector<int> vec);
        std::vector<int> buildInsertionOrder(int pendSize);
        std::vector<int> jacobsthalSequence(int n);

        std::list<int>   fordJohnsonLst(std::list<int> lst);

};