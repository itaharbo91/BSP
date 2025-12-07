/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:57:43 by itaharbo          #+#    #+#             */
/*   Updated: 2025/10/02 00:29:13 by itaharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int	main(void)
{
	// Définir le triangle
    Point const	a(0.0f, 0.0f);
    Point const	b(10.0f, 0.0f);
    Point const	c(5.0f, 10.0f);

    Point const inside(5.0f, 5.0f); // Point à l'intérieur du triangle
    Point const outside(15.0f, 5.0f); // Point à l'extérieur du triangle
    Point const onEdge(5.0f, 0.0f); // Point sur un côté du triangle
    Point const onVertex(0.0f, 0.0f); // Point sur un sommet du triangle

    std::cout << "Point inside: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Point outside: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "Point on edge: " << (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;
    std::cout << "Point on vertex: " << (bsp(a, b, c, onVertex) ? "true" : "false") << std::endl;

	return 0;
}
