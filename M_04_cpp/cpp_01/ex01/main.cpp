/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:58:50 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/18 12:13:16 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int	main(void)
{
	std::string	N;
	std::string	name;
	Zombie		*zoms;

	std::cout << "Creating a hord of zombie." << std::endl;

	while (true)
	{
		std::cout << "Number of zombie: ";
		std::cin >> N;

		if (!N.empty() && std::all_of(N.begin(), N.end(), ::isdigit))
		{
			if (stoi(N) == 0)
			{
				std::cout << "No zombie being created." << std::endl;
				continue;
			}
			break;
		}
		std::cout << "Invalid input. Please enter a number." << std::endl;
	}

	std::cout << "Zombie name: ";
	std::cin >> name;

	zoms = zombieHorde(stoi(N), name);
	for (int i = 0; i < stoi(N); i++)
	{
		zoms[i].announce();
	}
	delete[] zoms;
	return (0);
}
