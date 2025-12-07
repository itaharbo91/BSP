/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:00:32 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/02 00:27:57 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

static float	area(Point const a, Point const b, Point const c)
{
	float	area; // Aire du triangle

	area = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
			b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
			c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f;
	if (area >= 0) // Retourne la valeur absolue de l'aire
		return (area);
	return (-area); // Si l'aire est négative, on la rend positive
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	d0(0.0f), d1(0.0f), d2(0.0f), d3(0.0f);

	d0 = area(a, b, c);
	d1 = area(point, a, b);
	d2 = area(point, b, c);
	d3 = area(point, c, a);
	if (d0 == 0 || d1 == 0 || d2 == 0 || d3 == 0) // Si un des aires est nul, le point est sur un bord ou un sommet
		return false;
	if (d0 != d1 + d2 + d3) // Si la somme des aires des sous-triangles n'est pas égale à l'aire du triangle, le point est en dehors
		return false;
	return true; // Le point est à l'intérieur du triangle
}
