/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:26:15 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/14 14:26:17 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << this->_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = std::roundf(f * (1 << this->_bits));
}

Fixed::Fixed(Fixed const &oth)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = oth;
}

Fixed	&Fixed::operator = (const Fixed &oth)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &oth)
	{
		this->_value = oth.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return ((int)(this->_value >> this->_bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return (out);
}
