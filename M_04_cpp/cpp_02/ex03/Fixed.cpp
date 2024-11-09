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

// Constructors and Destructor
Fixed::Fixed() : _value(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const int intValue)
{
	this->_value = intValue << _bits;
}

Fixed::Fixed(const float floatValue)
{
	this->_value = roundf(floatValue * (1 << _bits));
}

// Assignment Operator
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return *this;
}

// Getter and Setter
int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

// Conversion Functions
float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _bits);
}

int Fixed::toInt(void) const
{
	return _value >> _bits;
}

// Comparison Operators
bool Fixed::operator>(const Fixed &other) const
{
	return this->_value > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_value != other.getRawBits();
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(_value + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(_value - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((_value * other.getRawBits()) >> _bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((_value << _bits) / other.getRawBits());
	return result;
}

// Increment/Decrement Operators
Fixed &Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed &Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return temp;
}

// Static Member Functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

// Output Stream Operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

