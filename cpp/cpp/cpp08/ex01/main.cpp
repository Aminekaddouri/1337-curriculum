#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Testing range-based addition
        Span largeSpan(10000);
        std::vector<int> range(10000);
        for (int i = 0; i < 10000; i++)
            range[i] = i * 2;
        largeSpan.addNumber(range.begin(), range.end());

        std::cout << "Shortest span in largeSpan: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span in largeSpan: " << largeSpan.longestSpan() << std::endl;
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}