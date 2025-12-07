/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:59:42 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/02 00:11:36 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
public:

	Point(void);
	Point(float const x, float const y);
	Point(Point const &cpy);
	~Point(void);

	Point&	operator=(Point const &other);
	bool	operator!=(Point const &other) const;
	Fixed	getX(void) const;
	Fixed	getY(void) const;

private:

	Fixed const	p_x;
	Fixed const	p_y;

};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
