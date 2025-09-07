/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 06:47:06 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/15 01:01:20 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _fixedPointValue(0) {
}

// Integer constructor
Fixed::Fixed(const int intValue) {
    _fixedPointValue = intValue << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float floatValue) {
    _fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
    *this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
}

// Raw bits getter
int Fixed::getRawBits() const {
    return this->_fixedPointValue;
}

// Raw bits setter
void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// Convert to float
float Fixed::toFloat() const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

// Convert to int
int Fixed::toInt() const {
    return _fixedPointValue >> _fractionalBits;
}

//----------------- Comparison operators -----------------//

bool    Fixed::operator>( const Fixed &other ) const {
    return (this->getRawBits() > other.getRawBits());
}

bool    Fixed::operator<( const Fixed &other ) const {
    return (this->getRawBits() < other.getRawBits());
}

bool    Fixed::operator>=( const Fixed &other ) const {
    return (this->getRawBits() >= other.getRawBits());
}

bool   Fixed::operator<=( const Fixed &other ) const {
    return (this->getRawBits() <= other.getRawBits());
}

bool  Fixed::operator==( const Fixed &other ) const {
    return (this->getRawBits() == other.getRawBits());
}

bool    Fixed::operator!=( const Fixed &other ) const {
    return (this->getRawBits() != other.getRawBits());
}

//------------------ Arithmetic operators ------------------//

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixedPointValue - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->_fixedPointValue * other.getRawBits()) >> _fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.getRawBits() == 0) {
        std::cerr << "Division by zero!" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits(this->toFloat() / other.toFloat());
    return (result);
}

//------------------ Increment/Decrement operators ------------------//

Fixed&   Fixed::operator++( void ) {
    ++this->_fixedPointValue;
    return (*this);
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    this->_fixedPointValue++;
    return (tmp);
}

Fixed& Fixed::operator--( void ) {
    --this->_fixedPointValue;
    return (*this);
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    this->_fixedPointValue--;
    return (tmp);
}

//----------------------- Max and Min ----------------------//

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return (a);
    return (b);
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return (a);
    return (b);
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return (a);
    return (b);
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return (a);
    return (b);
}

// Overload insertion operator
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return (out);
}