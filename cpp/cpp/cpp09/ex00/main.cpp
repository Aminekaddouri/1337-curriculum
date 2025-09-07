#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: invalid number of arguments." << std::endl;
        return (1);
    }
    
    try
    {
        BitcoinExchange bc("data.csv");
        bc.processInputFile(av[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}
