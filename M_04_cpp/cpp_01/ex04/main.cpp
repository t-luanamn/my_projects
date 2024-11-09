/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:26:01 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/02 12:26:02 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char **av)
{
	if (ac == 4)
	{
		Sed	sed(av[1]);
		sed.replace(av[2], av[3]);
	}
	else
	{
		std::cerr << "Usage: ./sed <filename> <s1:find> <s2:replace>." << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
