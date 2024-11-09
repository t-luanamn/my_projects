/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:34:47 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/14 14:34:48 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Point_HPP
# define Point_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Point &other);
		Point(const float xValue, const float yValue);
		~Point();

		Point &operator=(const Point &other);

		float	getX(void) const;
		float	getY(void) const;
	
	private:
		const Fixed	_x;
		const Fixed	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
