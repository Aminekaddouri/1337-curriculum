#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

// Adds a range of numbers using iterators
template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
    if (std::distance(begin, end) + _numbers.size() > _maxSize)
        throw SpanFullException();
    _numbers.insert(_numbers.end(), begin, end);
}

#endif