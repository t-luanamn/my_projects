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

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << "ScavTrap "
            << G << this->_name << RST
            << " : Created" << std::endl;
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

void ScavTrap::guardGate(void)
{
  std::cout << "ScavTrap "
            << G << this->_name << RST
            << " is now in Gate keeper mode!" << std::endl;
}
