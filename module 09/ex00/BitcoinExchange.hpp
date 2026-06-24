#pragma once

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>


class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

        void    loadDatabase(const std::string& filename);
        void    processInput(const std::string& filename);
};