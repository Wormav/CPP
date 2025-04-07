/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:57:44 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/14 08:28:33 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Point.hpp>

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return (*this);
}

Point::~Point() {}

Fixed Point::getX() const
{
	return (_x);
}
Fixed Point::getY() const
{
	return (_y);
}

Point Point::operator-(const Point& other) const
{
    return Point(
        (this->_x - other._x).toFloat(),
        (this->_y - other._y).toFloat()
    );
}
