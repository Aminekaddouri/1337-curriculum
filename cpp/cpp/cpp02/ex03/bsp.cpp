/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 03:40:25 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/15 00:59:52 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed  area( Point const &a, Point const &b, Point const &c )
{
    Fixed r1 = a.getX() * ( b.getY() - c.getY() );
    Fixed r2 = b.getX() * ( c.getY() - a.getY() );
    Fixed r3 = c.getX() * ( a.getY() - b.getY() );
    Fixed area = (r1 + r2 + r3) / 2;
    if (area < 0)
        area = area * (-1);
    return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed abcArea = area( a, b, c );
    Fixed pabArea = area( point, a, b );
    Fixed pbcArea = area( point, b, c );
    Fixed pcaArea = area( point, c, a );

    Fixed sum = pabArea + pbcArea + pcaArea;

    return  (abcArea == sum && !(pabArea == 0 || pbcArea == 0 || pcaArea == 0) );
}
