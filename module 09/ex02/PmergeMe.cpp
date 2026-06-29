#include "PmergeMe.hpp"

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

std::vector<int> PmergeMe::buildInsertionOrder(int pendSize) {
    std::vector<int> jacob = jacobsthalSequence(pendSize);
    std::vector<int> order;
    std::vector<bool> inserted(pendSize, false);

    for (size_t k = 2; k < jacob.size(); ++k) {
        int curr = jacob[k] - 1;
        int prev = jacob[k - 1];
        for (int i = curr; i >= prev && i >= 0 && i < pendSize; --i) {
            if (!inserted[i]) {
                order.push_back(i);
                inserted[i] = true;
            }
        }
    }
    for (int i = 0; i < pendSize; ++i)
        if (!inserted[i])
            order.push_back(i);
    return order;
}

void PmergeMe::binaryInsertVec(std::vector<int> &sorted, int value, int bound) {
    int lo = 0, hi = bound;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (sorted[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    sorted.insert(sorted.begin() + lo, value);
}

std::vector<int> PmergeMe::fordJohnsonVec(std::vector<int> vec) {
    if (vec.size() <= 1)
        return vec;

    // Step 1: pair up elements
    bool hasStraggler = (vec.size() % 2 != 0);
    int  straggler    = hasStraggler ? vec.back() : 0;

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        if (vec[i] <= vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }

    // Step 2: sort winners recursively
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].second);
    winners = fordJohnsonVec(winners);

    // Step 3: rebuild pend aligned to sorted winners
    std::vector<int> pend;
    for (size_t i = 0; i < winners.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].second == winners[i]) {
                pend.push_back(pairs[j].first);
                break;
            }
        }
    }

    // Step 4: main chain = winners; prepend pend[0] for free
    std::vector<int> sorted = winners;
    sorted.insert(sorted.begin(), pend[0]);

    // Step 5: insert remaining pend in Jacobsthal order
    std::vector<int> order = buildInsertionOrder(static_cast<int>(pend.size()));
    for (size_t k = 0; k < order.size(); ++k) {
        int idx = order[k];
        if (idx == 0) continue;

        // Find paired winner's position as upper bound
        int bound = static_cast<int>(sorted.size());
        for (int m = 0; m < bound; ++m) {
            if (sorted[m] == winners[idx]) { bound = m; break; }
        }
        binaryInsertVec(sorted, pend[idx], bound + 1);
    }

    // Step 6: straggler
    if (hasStraggler)
        binaryInsertVec(sorted, straggler, static_cast<int>(sorted.size()));

    return sorted;
}

void PmergeMe::binaryInsertLst(std::list<int> &sorted, int value,
                                 std::list<int>::iterator bound) {
    // Binary search using an advance-based approach on list iterators
    std::list<int>::iterator lo = sorted.begin();
    int size = static_cast<int>(std::distance(lo, bound));
    int left = 0, right = size;

    while (left < right) {
        int mid = (left + right) / 2;
        std::list<int>::iterator it = sorted.begin();
        std::advance(it, mid);
        if (*it < value) left  = mid + 1;
        else             right = mid;
    }
    std::list<int>::iterator pos = sorted.begin();
    std::advance(pos, left);
    sorted.insert(pos, value);
}

std::list<int> PmergeMe::fordJohnsonLst(std::list<int> lst) {
    if (lst.size() <= 1)
        return lst;

    // Step 1: pair up elements
    bool hasStraggler = (lst.size() % 2 != 0);
    int  straggler    = hasStraggler ? lst.back() : 0;

    std::list<std::pair<int, int> > pairs;
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        int a = *it; ++it;
        if (it == lst.end()) break;
        int b = *it; ++it;
        if (a <= b) pairs.push_back(std::make_pair(a, b));
        else        pairs.push_back(std::make_pair(b, a));
    }

    // Step 2: sort winners recursively
    std::list<int> winners;
    for (std::list<std::pair<int,int> >::iterator p = pairs.begin();
         p != pairs.end(); ++p)
        winners.push_back(p->second);
    winners = fordJohnsonLst(winners);

    // Step 3: rebuild pend aligned to sorted winners
    std::list<int> pend;
    for (std::list<int>::iterator w = winners.begin(); w != winners.end(); ++w) {
        for (std::list<std::pair<int,int> >::iterator p = pairs.begin();
             p != pairs.end(); ++p) {
            if (p->second == *w) {
                pend.push_back(p->first);
                break;
            }
        }
    }

    // Step 4: main chain = winners; prepend pend.front() for free
    std::list<int> sorted = winners;
    sorted.insert(sorted.begin(), pend.front());

    // Step 5: insert remaining pend in Jacobsthal order
    // Convert pend to vector for index-based Jacobsthal access
    std::vector<int> pendVec(pend.begin(), pend.end());
    std::vector<int> winnersVec(winners.begin(), winners.end());
    std::vector<int> order = buildInsertionOrder(static_cast<int>(pendVec.size()));

    for (size_t k = 0; k < order.size(); ++k) {
        int idx = order[k];
        if (idx == 0) continue;

        // Find bound: position just after the paired winner
        std::list<int>::iterator bound = sorted.begin();
        while (bound != sorted.end() && *bound != winnersVec[idx])
            ++bound;
        if (bound != sorted.end())
            ++bound; // include the winner itself as searchable upper bound

        binaryInsertLst(sorted, pendVec[idx], bound);
    }

    // Step 6: straggler
    if (hasStraggler)
        binaryInsertLst(sorted, straggler, sorted.end());

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