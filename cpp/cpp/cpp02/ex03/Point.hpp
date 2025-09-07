/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 03:28:36 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/15 00:51:08 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    Point(const float x_val, const float y_val);
    Point(const Point &other);
    Point &operator=(const Point &other);
    ~Point();

    Fixed const & getX(void) const;
    Fixed const & getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
