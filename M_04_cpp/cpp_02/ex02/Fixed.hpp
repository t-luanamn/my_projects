/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:26:25 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/14 14:26:27 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		~Fixed();

		Fixed &operator=(const Fixed &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// Comparison operators
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		// Arithmetic operators
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		// Increment/Decrement operators
		Fixed	&operator++();		// Pre-increment
		Fixed	operator++(int);	// Post-increment
		Fixed	&operator--();		// Pre-decrement
		Fixed	operator--(int);	// Post-decrement

		// Static member functions
		static			Fixed &min(Fixed &a, Fixed &b);
		static const	Fixed &min(const Fixed &a, const Fixed &b);
		static			Fixed &max(Fixed &a, Fixed &b);
		static const	Fixed &max(const Fixed &a, const Fixed &b);

		private:
			int					_value;
			static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
