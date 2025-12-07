/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:57:58 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/01 21:58:00 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:

	Fixed(void);
	Fixed(Fixed const &cpy);
	Fixed(int const intNbr);
	Fixed(float const floatNbr);
	~Fixed(void);

	Fixed&				operator=(Fixed const &other);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;

	bool				operator>(Fixed const &other) const;
	bool				operator<(Fixed const &other) const;
	bool				operator>=(Fixed const &other) const;
	bool				operator<=(Fixed const &other) const;
	bool				operator==(Fixed const &other) const;
	bool				operator!=(Fixed const &other) const;

	Fixed				operator+(Fixed const &other) const;
	Fixed				operator-(Fixed const &other) const;
	Fixed				operator*(Fixed const &other) const;
	Fixed				operator/(Fixed const &other) const;
	
	Fixed&				operator++(void);
	Fixed				operator++(int);
	Fixed&				operator--(void);
	Fixed				operator--(int);

	static Fixed&		min(Fixed &nbr1, Fixed &nbr2);
	static Fixed const&	min(Fixed const &nbr1, Fixed const &nbr2);
	static Fixed&		max(Fixed &nbr1, Fixed &nbr2);
	static Fixed const&	max(Fixed const &nbr1, Fixed const &nbr2);

private:

	int					p_fixedNbr;
	static int const	p_fractBits = 8;

};

std::ostream&	operator<<(std::ostream &flux, Fixed const &fixedNbr);

#endif
