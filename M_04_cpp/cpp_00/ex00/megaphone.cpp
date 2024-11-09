/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:30:04 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/04 16:30:14 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 1;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				std::cout << (char)toupper(av[i][j]);
				j++;
			}
			if (i < ac -1)
				std::cout << ' ';
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}

/*
cout stands for “character output”

std::cout << "Hello world!"; // print Hello world! to console

std::cout << "Hi!" << std::endl; 
std::endl = new line
*/
