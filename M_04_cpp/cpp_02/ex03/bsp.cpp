/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:34:39 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/14 14:34:41 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Function to calculate the sign of the area formed by three points
float	sign(Point const p1, Point const p2, Point const p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
			- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

// Function to check if a point is inside a triangle
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	d1, d2, d3;
	bool	has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	// Check if the point is on the edge of the triangle
	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}

// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
