#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " \"expression\"" << std::endl;
        return (1);
    }

    RPN rpnCalculator;
    try
    {
        rpnCalculator.evaluate(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    
    
    return (0);
}
