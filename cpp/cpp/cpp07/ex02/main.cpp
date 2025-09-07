#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    Array<int> intArray(5);
    std::cout << "Array size: " << intArray.size() << std::endl;

    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i * 2;
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    try
    {
        std::cout << intArray[10] << std::endl;
    }
    catch(std::out_of_range& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    

    // Test copy constructor
    Array<int> copyArray(intArray);
    std::cout << "Copy array size: " << copyArray.size() << std::endl;

    copyArray[0] = 100;
    std::cout << "Modified copyArray[0]: " << copyArray[0] << std::endl;
    std::cout << "Original intArray[0]: " << intArray[0] << std::endl;

    return (0);
}