/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 12:01:22 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/14 08:32:22 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

static Fixed crossProduct(Point const& a, Point const& b)
{
    return (a.getX() * b.getY() - a.getY() * b.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed crossPA_AB = crossProduct(point - a, b - a);
    Fixed crossPB_BC = crossProduct(point - b, c - b);
    Fixed crossPC_CA = crossProduct(point - c, a - c);

    return ((crossPA_AB >= 0 && crossPB_BC >= 0 && crossPC_CA >= 0) ||
            (crossPA_AB <= 0 && crossPB_BC <= 0 && crossPC_CA <= 0)) &&
            (crossPA_AB != 0 || crossPB_BC != 0 || crossPC_CA != 0);
}
