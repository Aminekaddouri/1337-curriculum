#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>

class NotFoundException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Element not found in the container";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);

    if (it == container.end())
        throw NotFoundException();
    return(it);
}

#endif