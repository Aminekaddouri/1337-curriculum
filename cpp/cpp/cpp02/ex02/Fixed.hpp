/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 06:46:59 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/12 00:26:43 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _fixedPointValue;                   // Stores the fixed-point number value
	static const int _fractionalBits = 8;  // Number of fractional bits (always 8)

public:
	Fixed();                                // Default constructor
	Fixed(const int intValue);              // Constructor for integer
	Fixed(const float floatValue);          // Constructor for float
	Fixed(const Fixed &other);              // Copy constructor
	Fixed& operator=(const Fixed &other);   // Copy assignment operator
	~Fixed();                               // Destructor

	int     getRawBits(void) const;         // Returns the raw value of the fixed-point number
	void    setRawBits(int const raw);      // Sets the raw value of the fixed-point number

	float   toFloat( void ) const;          // Converts fixed-point value to floating-point
	int     toInt( void ) const;            // Converts fixed-point value to integer

	// Comparison operators
	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	// Arithmetic operators
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	// Increment/Decrement operators
	Fixed&	operator++(void);	// Pre-increment
	Fixed	operator++(int);	// Post-increment
	Fixed&	operator--(void);	// Pre-decrement
	Fixed	operator--(int);	// Post-decrement

	// Static min/max functions
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream&   operator<<(std::ostream &out, const Fixed &fixed);  // Overload insertion operator

#endif