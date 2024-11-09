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

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &oth);
		~Fixed(void);
		Fixed &operator = (const Fixed &oth);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_value;
		static const int	_bits = 8;
};

#endif
