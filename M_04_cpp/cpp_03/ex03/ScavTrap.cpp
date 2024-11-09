/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:52:36 by tluanamn          #+#    #+#             */
/*   Updated: 2024/08/27 13:52:37 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
  //this->_hitPoints = 100;
  this->_energyPoints = 50;
  //this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << "ScavTrap "
            << G << this->_name << RST
            << " : Created" << std::endl;
  std::cout << "STAT\nHit Points: " << this->_hitPoints << std::endl;
  std::cout << "Energy Points: " << this->_energyPoints << std::endl;
  std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
}

ScavTrap::~ScavTrap()
{
  std::cout << "ScavTrap "
          << R << this->_name << RST
          << " : Destructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj): ClapTrap(obj)
{
  std::cout << "Copy Constructor" << std::endl;
  if (this != &obj)
    *this = obj;
}

void ScavTrap::attack(const std::string& target)
{
  if (this->_hitPoints == 0)
  {
    std::cout << "ScavTrap "
              << R << this->_name << RST
              << " is destroyed and cannot attack!" << std::endl;
    return;
  }
  if (this->_energyPoints == 0)
  {
    std::cout << "ScavTrap "
              << R << this->_name << RST
              << " has no energy left to attack!" << std::endl;
    return;
  }
  std::cout << "ScavTrap "
            << G << this->_name << RST
            << " attacks " << target
            << ", causing "
            << R << this->_attackDamage << RST
            << " points of damage!" << std::endl;
  this->_energyPoints -= 1;
}

void ScavTrap::guardGate(void)
{
  std::cout << "ScavTrap "
            << G << this->_name << RST
            << " is now in Gate keeper mode!" << std::endl;
}
