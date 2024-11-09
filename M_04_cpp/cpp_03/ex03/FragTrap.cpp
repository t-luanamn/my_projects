/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:53:39 by tluanamn          #+#    #+#             */
/*   Updated: 2024/08/27 13:53:41 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
  this->_hitPoints = 100;
  //this->_energyPoints = 100;
  this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "FragTrap "
            << G << this->_name << RST
            << " : Created" << std::endl;
  std::cout << "STAT\nHit Points: " << this->_hitPoints << std::endl;
  std::cout << "Energy Points: " << this->_energyPoints << std::endl;
  std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "
				<< R << this->_name << RST
				<< " : Destructor" << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj): ClapTrap(obj)
{
	std::cout << "Copy Constructor" << std::endl;
	if (this != &obj)
		*this = obj;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap "
						<< G << this->_name << RST
						<< " is asking for a high five!" << std::endl;
}
