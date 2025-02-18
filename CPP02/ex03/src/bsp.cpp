/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:01:22 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/02 12:02:26 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

static Fixed	area(Point const &p1, Point const &p2, Point const &p3)
{
    return Fixed(0.5f) * ( (p1.getX() * (p2.getY() - p3.getY())) +
                           (p2.getX() * (p3.getY() - p1.getY())) +
                           (p3.getX() * (p1.getY() - p2.getY())) ).toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = area(a, b, c);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPAC = area(a, point, c);
    Fixed areaPAB = area(a, b, point);

    return (areaPBC > 0 && areaPAC > 0 && areaPAB > 0 &&
            (areaABC == (areaPBC + areaPAC + areaPAB)));
}
