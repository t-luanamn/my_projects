/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:25:59 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/02 13:26:01 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string	input;
	Harl		harl;

	std::string	levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "EXIT"};

	std::cout << "Levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
	std::cout << "or enter: EXIT to exit" << std::endl;

	while (true)
	{
		std::cout << "Enter level: ";
		std::cin >> input;

		bool isValidLevel = std::find(std::begin(levels), std::end(levels), input) != std::end(levels);
		if (isValidLevel)
		{
			if (input == "EXIT")
			{
				break;
			}
			else
			{
				harl.complain(input);
			}
		}
		else
		{
			std::cout << "Invalid level. Please try again." << std::endl;
		}
	}
	return (0);
}