/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:33:10 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/02 11:33:11 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::removeWeapon()
{
	this->_weapon = NULL;
}

void	HumanB::attack()
{
	if (this->_weapon != NULL && this->_weapon->getType() != "")
	{
		std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
	}
	else
	{
		std::cout << _name << " doesn't have a weapon to attack." << std::endl;
	}
}
