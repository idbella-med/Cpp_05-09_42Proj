#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./btc input.txt" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange bt;
        bt.loadDatabase("data.csv");
        bt.processInput(av[1]);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}