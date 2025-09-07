/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 06:47:06 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/15 01:02:01 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = intValue << _fractionalBits; // Convert int to fixed-point
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(floatValue * (1 << _fractionalBits)); 
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int    Fixed::getRawBits(void) const {
    return (this->_fixedPointValue);
}

void    Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const {
    return (_fixedPointValue >> _fractionalBits);
}

float   Fixed::toFloat(void) const{
    return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
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