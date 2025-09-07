#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(const T& element)
{
	std::cout << element << std::endl;
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
	
	std::cout << "Integer array:" << std::endl;
	iter(intArray, intArrayLength, printElement<int>);

	std::string stringArray[] = {"Hello", "World", "C++", "Templates"};
	size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);

	std::cout << "\nString array:" << std::endl;
	iter(stringArray, stringArrayLength, printElement<std::string>);

	return (0);
}
