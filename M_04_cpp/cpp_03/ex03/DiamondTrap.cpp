/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:54:40 by tluanamn          #+#    #+#             */
/*   Updated: 2024/08/27 13:54:42 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"),
  ScavTrap(), FragTrap()
{
  this->_name = name;
  this->_hitPoints = FragTrap::_hitPoints;
  this->_energyPoints = ScavTrap::_energyPoints;
  this->_attackDamage = FragTrap::_attackDamage;

  std::cout << "DiamondTrap "
            << G << this->_name << RST
            << " : Created" << std::endl;

  std::cout << "STAT\nHit Points: " << this->_hitPoints << std::endl;
  std::cout << "Energy Points: " << this->_energyPoints << std::endl;
  std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
  std::cout << "DiamondTrap "
            << R << this->_name << RST
            << " : Destructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj): ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
  std::cout << "Copy Constructor" << std::endl;
  if (this != &obj)
    *this = obj;
}

void DiamondTrap::whoAmI(void)
{
  std::cout << "My DiamondTrap named " << this->_name
            << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
