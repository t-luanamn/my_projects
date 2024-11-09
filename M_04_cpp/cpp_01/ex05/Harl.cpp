/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:26:07 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/02 13:26:09 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <map>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "Debug..." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Info..." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Warning..." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Error..." << std::endl;
}

// std::map<key_type, value_type> map_name;
void Harl::complain(std::string level)
{
	typedef void (Harl::*FuncPtr)();
	std::map<std::string, FuncPtr> levelFunctionMap;

	levelFunctionMap["DEBUG"] = &Harl::debug;
	levelFunctionMap["INFO"] = &Harl::info;
	levelFunctionMap["WARNING"] = &Harl::warning;
	levelFunctionMap["ERROR"] = &Harl::error;

	std::map<std::string, FuncPtr>::iterator lvl = levelFunctionMap.find(level);
	if (lvl != levelFunctionMap.end())
	{
		(this->*(lvl->second))();
	}
}

/*
void	Harl::complain(std::string level)
{
	void	(Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			(this->*f[i])();
	}
}
*/