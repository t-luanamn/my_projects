/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:58:50 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/17 13:58:58 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	name;
	Zombie	*zom;

	std::cout << "Creating zombie." << std::endl;
	std::cout << "Zombie name: ";
	std::cin >> name;

	zom = newZombie(name); // heap
	zom->announce();
	delete zom;

	std::cout << "Calling randomChump." << std::endl; // stack
	randomChump("Chump");
	return (0);
}
