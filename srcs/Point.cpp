/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:59:37 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/02 00:05:58 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point(void) : p_x(0), p_y(0)
{
}

Point::Point(Point const &cpy) : p_x(cpy.p_x), p_y(cpy.p_y)
{
}

Point::Point(float const x, float const y) : p_x(x), p_y(y)
{
}

Point::~Point(void)
{
}

// Dans la plupart des implémentations géométriques,
// les points sont considérés comme immuables une fois créés.
Point&	Point::operator=(Point const &other)
{
	(void)other;
	return *this;
}

bool	Point::operator!=(Point const &other) const
{
	if (this->p_x != other.p_x && this->p_y != other.p_y)
		return true;
	return false;
}

Fixed	Point::getX(void) const
{
	return this->p_x;
}

Fixed	Point::getY(void) const
{
	return this->p_y;
}
