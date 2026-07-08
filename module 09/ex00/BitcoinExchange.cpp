#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _data(src._data) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
    _data = src._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("invalid data.csv");
    }

    std::string line;
    getline(file, line);

    while (getline(file, line)) {
        std::string date;
        std::string rate;
        std::stringstream ss(line);

        if (!getline(ss, date, ','))
            continue;
        if (!getline(ss, rate))
            continue;

        float value = atof(rate.c_str());

        this->_data[date] = value;
    }
}

std::string Trim(std::string &a) {
    size_t start = a.find_first_not_of(" \t\r");
    if (start == std::string::npos)
        return "";
    size_t end = a.find_last_not_of(" \t\r");
    return a.substr(start, end - start + 1);
}

bool isLeapYear(int year) {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

bool parse_dash(const std::string &date) {
    if (date.size() < 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    return true;
}

std::string parse_years(std::string &a) {
    for (int i = 0; i < 4; i++) {
        if (!isdigit(a[i]))
            return "";
    }
    return a.substr(0, 4);
}

std::string parse_month(const std::string &date) {
    if (!isdigit(date[5]) || !isdigit(date[6]))
        return "";
    int month = strtol(date.substr(5, 2).c_str(), NULL, 10);
    if (month < 1 || month > 12)
        return "";
    return date.substr(5, 2);
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}

std::string parse_day(const std::string &date, int month, int year) {
    if (!isdigit(date[8]) || !isdigit(date[9]))
        return "";
    int day = strtol(date.substr(8, 2).c_str(), NULL, 10);
    if (day < 1 || day > daysInMonth(month, year))
        return "";
    return date.substr(8, 2);
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("invalid input");
    }
    std::string line;
    getline(file, line);

    while (getline(file, line)) {
        std::string date;
        std::string value;
        std::stringstream ss(line);

        if (!getline(ss, date, '|'))  {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!getline(ss, value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = Trim(date);
        value = Trim(value);

        std::string yearStr = parse_years(date);
        if (yearStr.empty()) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        int year = strtol(yearStr.c_str(), NULL, 10);

        if (!parse_dash(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        std::string monthStr = parse_month(date);
        if (monthStr.empty()) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        int month = strtol(monthStr.c_str(), NULL, 10);

        std::string dayStr = parse_day(date, month, year);
        if (dayStr.empty()) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        char* end;
        float amount = strtof(value.c_str(), &end);

        if (*end != '\0') {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (amount < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (amount > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _data.lower_bound(date);

        if (it == _data.end())
            --it;
        else if (it->first == date)
            ;
        else if (it == _data.begin()) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        else
            --it;
        float result = it->second * amount;
        std::cout << date << " => " << amount << " = " << result << std::endl;
    }
}