/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 03:33:59 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/15 00:50:37 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x_val, const float y_val) : x(Fixed(x_val)), y(Fixed(y_val)) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other) {
    (void)other;
    return *this;
}

Point::~Point() {}

Fixed const & Point::getX(void) const { 
    return (x); 
}
Fixed const & Point::getY(void) const { 
    return (y); 
}
