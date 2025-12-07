/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:57:48 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/01 21:57:49 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : p_fixedNbr(0)
{
}

Fixed::Fixed(Fixed const &cpy) : p_fixedNbr(cpy.p_fixedNbr)
{
}

Fixed::Fixed(int const intNbr)
{
	p_fixedNbr = intNbr << p_fractBits; // Multiplie par 256
}

Fixed::Fixed(float const floatNbr)
{
	p_fixedNbr = roundf(floatNbr * (1 << p_fractBits)); // Multiplie par 256 et arrondit
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return p_fixedNbr;
}

void	Fixed::setRawBits(int const raw)
{
	p_fixedNbr = raw; // Affecte la valeur brute
}

float	Fixed::toFloat(void) const
{
	return (float)p_fixedNbr / (float)(1 << p_fractBits); // Divise par 256
}

int		Fixed::toInt(void) const
{
	return p_fixedNbr >> p_fractBits; // Divise par 256
}

Fixed&	Fixed::min(Fixed &nbr1, Fixed &nbr2)
{
	if (nbr1 < nbr2)
		return nbr1;
	return nbr2;
}

Fixed const&	Fixed::min(Fixed const &nbr1, Fixed const &nbr2)
{
	if (nbr1 < nbr2)
		return nbr1;
	return nbr2;
}

Fixed&	Fixed::max(Fixed &nbr1, Fixed &nbr2)
{
	if (nbr1 > nbr2)
		return nbr1;
	return nbr2;
}

Fixed const&	Fixed::max(Fixed const &nbr1, Fixed const &nbr2)
{
	if (nbr1 > nbr2)
		return nbr1;
	return nbr2;
}
