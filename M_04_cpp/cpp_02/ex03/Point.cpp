/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:35:04 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/14 14:35:06 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0)
{
	//std::cout << "Point created" << std::endl;
}

// Constructor with parameters
Point::Point(const float xValue, const float yValue) : _x(xValue), _y(yValue)
{
	//std::cout << "Point with parameters created" << std::endl;
}

// Copy constructor
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	//std::cout << "Point copied" << std::endl;
}

// Destructor
Point::~Point()
{
	//std::cout << "Point destroyed" << std::endl;
}

// Copy assignment operator
Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		// _x and _y are const, they cannot be assigned to.
		const_cast<Fixed&>(_x) = other._x;
		const_cast<Fixed&>(_y) = other._y;
	}
	return *this;
}

// Getters
float Point::getX(void) const
{
	return _x.toFloat();
}

float Point::getY(void) const
{
	return _y.toFloat();
}
