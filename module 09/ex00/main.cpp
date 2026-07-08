#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: ./btc input.csv" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange bt;
        bt.loadDatabase("data.csv");
        bt.processInput(av[1]);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}