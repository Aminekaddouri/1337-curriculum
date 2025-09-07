/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 06:47:20 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/12 00:26:18 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

//Constructor for integer
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = intValue << _fractionalBits; // Convert int to fixed-point
}

//Constructor for float
Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(floatValue * (1 << _fractionalBits));  // Convert float to fixed-point
}

//Copy constructor
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return (*this);
}

//Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Getter for raw bits
int    Fixed::getRawBits(void) const {
    return (this->_fixedPointValue);
}

// Setter for raw bit
void    Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// Convert to int
int Fixed::toInt(void) const {
    return (_fixedPointValue >> _fractionalBits); // Convert fixed-point to int
}

// Convert to float
float   Fixed::toFloat(void) const{
    return ((float)(_fixedPointValue) / (1 << _fractionalBits)); // Convert fixed-point to float
}

// Overload insertion operator
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return (out);
}