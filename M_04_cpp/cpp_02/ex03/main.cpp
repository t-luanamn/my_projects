/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:26:42 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/14 14:26:43 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

int	main( void )
{
	Point a(0, 0);
	Point b(0, 4);
	Point c(4, 0);
	Point point(1, 1);

	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << RED << "The point is outside the triangle" << RESET << std::endl;
	return (0);
}
