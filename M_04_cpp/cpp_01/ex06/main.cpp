/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:25:59 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/09 14:02:58 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cout << "Invalid input. Please try again." << std::endl;
	}
	else
	{
		std::string	input = av[1];
		harl.complain(input);
	}
	return (0);
}
