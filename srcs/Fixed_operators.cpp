/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_operators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:57:52 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/01 21:57:54 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed&	Fixed::operator=(Fixed const &other)
{
	if (this != &other)
		this->p_fixedNbr = other.p_fixedNbr;
	return *this;
}

bool	Fixed::operator>(Fixed const &other) const
{
	return this->p_fixedNbr > other.p_fixedNbr;
}

bool	Fixed::operator<(Fixed const &other) const
{
	return this->p_fixedNbr < other.p_fixedNbr;
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return this->p_fixedNbr >= other.p_fixedNbr;
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return this->p_fixedNbr <= other.p_fixedNbr;
}

bool	Fixed::operator==(Fixed const &other) const
{
	return this->p_fixedNbr == other.p_fixedNbr;
}

bool	Fixed::operator!=(Fixed const &other) const
{
	return this->p_fixedNbr != other.p_fixedNbr;
}

Fixed	Fixed::operator+(Fixed const &other) const
{
	Fixed	result;

	result.setRawBits(this->p_fixedNbr + other.p_fixedNbr); // Additionne les parties entières
	return result;
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	result;

	result.setRawBits(this->p_fixedNbr - other.p_fixedNbr);
	return result;
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	return Fixed(this->toFloat() * other.toFloat()); // Multiplie les valeurs flottantes et crée un nouveau Fixed
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	this->p_fixedNbr += 1; // Ajoute epsilon (1/256)
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	cpy(*this);

	++(*this); //incremente l'objet courant
	return cpy; // Retourne la valeur avant incrémentation
}

Fixed&	Fixed::operator--(void)
{
	this->p_fixedNbr -= 1; // Soustrait epsilon (1/256)
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	cpy(*this);

	--(*this);
	return cpy;
}
std::ostream&	operator<<(std::ostream &flux, Fixed const &fixedNbr)
{
	flux << fixedNbr.toFloat();
	return	flux;
}
