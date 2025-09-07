/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 04:07:59 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/14 03:06:51 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _fixedPointValue;                   // Stores the fixed-point number value
	static const int _fractionalBits = 8;  // Number of fractional bits (always 8)

public:
	Fixed();                                // Default constructor
	Fixed(const Fixed &other);              // Copy constructor
	Fixed& operator=(const Fixed &other);   // Copy assignment operator
	~Fixed();                               // Destructor

	int     getRawBits(void) const;         // Returns the raw value of the fixed-point number
	void    setRawBits(int const raw);      // Sets the raw value of the fixed-point number
};

#endif