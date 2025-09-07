#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    // Test with vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found " << *it << " in vector." << std::endl;
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test with a list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    try
    {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found " << *it << " in list.\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}