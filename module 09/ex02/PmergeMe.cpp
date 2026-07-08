#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &o) : _vec(o._vec), _lst(o._lst) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &o) {
    _vec = o._vec;
    _lst = o._lst;
    return *this;
}

PmergeMe::~PmergeMe() {}

static bool isnumber(const std::string &str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.size(); i++)
        if (!std::isdigit(str[i])) return false;
    return true;
}

static int toInt(const std::string &s) {
    std::istringstream ss(s);
    long n;
    ss >> n;
    if (n < 0 || n > 2147483647)
        return -1;
    return static_cast<int>(n);
}

bool PmergeMe::parse(char **av, int ac) {
    for (int i = 1; i < ac; i++) {
        std::string s = av[i];
        if (!isnumber(s))
            return false;
        int val = toInt(s);
        if (val < 0)
            return false;
        _vec.push_back(val);
        _lst.push_back(val);
    }
    return true;
}

std::vector<int> PmergeMe::jacobsthalSequence(int n) {
    std::vector<int> seq;
    seq.push_back(0);
    seq.push_back(1);
    while (seq.back() < n) {
        int sz = static_cast<int>(seq.size());
        seq.push_back(seq[sz - 1] + 2 * seq[sz - 2]);
    }
    return seq;
}

std::vector<int> PmergeMe::buildInsertionOrder(int losersSize) {
    std::vector<int> jacob = jacobsthalSequence(losersSize);
    std::vector<int> order;

    for (size_t k = 2; k < jacob.size(); ++k) {
        int curr = jacob[k] - 1;
        int prev = jacob[k - 1];

        for (int i = curr; i >= prev; --i) {
            if (i >= 0 && i < losersSize)
                order.push_back(i);
        }
    }

    return order;
}


std::vector<int> PmergeMe::fordJohnsonVec(std::vector<int> vec) {
    if (vec.size() <= 1)
        return vec;

    bool hasRest = (vec.size() % 2 != 0);
    int  Rest    = hasRest ? vec.back() : 0;

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        if (vec[i] <= vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);
    winners = fordJohnsonVec(winners);

    std::vector<int> losers;
    std::vector<bool> used(pairs.size(), false);
    for (size_t i = 0; i < winners.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].second == winners[i])
            {
                losers.push_back(pairs[j].first);
                used[j] = true;
                break;
            }
        }
    }

    std::vector<int> sorted = winners;
    sorted.insert(sorted.begin(), losers[0]);

    std::vector<int> order = buildInsertionOrder(static_cast<int>(losers.size()));
    for (size_t k = 0; k < order.size(); ++k) {
        int idx = order[k];

        std::vector<int>::iterator bound =
            std::find(sorted.begin(), sorted.end(), winners[idx]);
    
        std::vector<int>::iterator pos =
            std::lower_bound(sorted.begin(), bound + 1, losers[idx]);
        
        sorted.insert(pos, losers[idx]);
    }

    if (hasRest) {
        std::vector<int>::iterator pos =
            std::lower_bound(sorted.begin(), sorted.end(), Rest);
        sorted.insert(pos, Rest);
    }

    return sorted;
}

std::list<int> PmergeMe::fordJohnsonLst(std::list<int> lst) {
    if (lst.size() <= 1)
        return lst;

    bool hasRest = (lst.size() % 2 != 0);
    int  Rest    = hasRest ? lst.back() : 0;

    std::list<std::pair<int, int> > pairs;
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        int a = *it; ++it;
        if (it == lst.end()) break;
        int b = *it; ++it;
        if (a <= b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    std::list<int> winners;
    for (std::list<std::pair<int,int> >::iterator p = pairs.begin();
         p != pairs.end(); ++p)
        winners.push_back(p->second);
    winners = fordJohnsonLst(winners);

    std::list<int> losers;
    std::vector<bool> used(pairs.size(), false);

    for (std::list<int>::iterator w = winners.begin(); w != winners.end(); ++w)
    {
        size_t index = 0;
        for (std::list<std::pair<int,int> >::iterator p = pairs.begin();
            p != pairs.end(); ++p, ++index)
        {
            if (!used[index] && p->second == *w)
            {
                losers.push_back(p->first);
                used[index] = true;
                break;
            }
        }
    }


    std::list<int> sorted = winners;
    sorted.insert(sorted.begin(), losers.front());

    std::vector<int> losersVec(losers.begin(), losers.end());
    std::vector<int> winnersVec(winners.begin(), winners.end());
    std::vector<int> order = buildInsertionOrder(static_cast<int>(losersVec.size()));

    for (size_t k = 0; k < order.size(); ++k) {
        int idx = order[k];

        std::list<int>::iterator bound =
            std::find(sorted.begin(), sorted.end(), winnersVec[idx]);
        
        if (bound != sorted.end())
            ++bound;

        std::list<int>::iterator pos =
            std::lower_bound(sorted.begin(), bound, losersVec[idx]);
        sorted.insert(pos, losersVec[idx]);
    }

    if (hasRest) {
        std::list<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), Rest);
        sorted.insert(pos, Rest);
    }

    return sorted;
}


void PmergeMe::start() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    struct timeval startVec, endVec;
    gettimeofday(&startVec, NULL);

    std::vector<int> sortedVec = fordJohnsonVec(_vec);

    gettimeofday(&endVec, NULL);
    double timeVec = (endVec.tv_sec - startVec.tv_sec) * 1000000.0
                   + (endVec.tv_usec - startVec.tv_usec);


    struct timeval startLst, endLst;
    gettimeofday(&startLst, NULL);

    std::list<int> sortedLst = fordJohnsonLst(_lst);
    
    gettimeofday(&endLst, NULL);
    double timeLst = (endLst.tv_sec - startLst.tv_sec) * 1000000.0
                   + (endLst.tv_usec - startLst.tv_usec);

    std::cout << "After:  ";
    for (size_t i = 0; i < sortedVec.size(); ++i)
        std::cout << sortedVec[i] << " ";
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _lst.size()
              << " elements with std::list   : " << timeLst << " us" << std::endl;
}