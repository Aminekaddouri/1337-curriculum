#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack() {};
    ~MutantStack() {};
    MutantStack(const MutantStack& other) {*this = other;}
    MutantStack& operator=(const MutantStack& other)
    {
        if (this != &other)
            std::stack<T, Container>::operator=(other);
        return (*this);
    }

    // Typedef for iterator types based on Container
    typedef typename Container::iterator iterator;
    typedef typename Container::reverse_iterator reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
};

#endif