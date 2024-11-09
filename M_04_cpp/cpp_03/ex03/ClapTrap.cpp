/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:51:23 by tluanamn          #+#    #+#             */
/*   Updated: 2024/08/27 17:05:23 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <typeinfo>

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name):
  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
  std::cout << "ClapTrap "
            << G << this->_name << RST
            << " : Created" << std::endl;
}

ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap "
            << R << this->_name << RST
            << " : Destructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
  std::cout << "Copy Constructor" << std::endl;
  if (this != &obj)
    *this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
  std::cout << obj._name << "Copy Assignment Operator" << std::endl;
  if (this != &obj)
  {
    this->_name = obj._name;
    this->_hitPoints = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
  }
  return (*this);
}

std::string ClapTrap::getClassName() const
{
  std::string className = typeid(*this).name();
  if (className.find("ScavTrap") != std::string::npos)
  {
      return "ScavTrap";
  }
  if (className.find("FragTrap") != std::string::npos)
  {
      return "FragTrap";
  }
  if (className.find("DiamondTrap") != std::string::npos)
  {
      return "DiamondTrap";
  }
  return "ClapTrap";
}

void ClapTrap::attack(const std::string& target)
{
  std::string className = getClassName();
  if (this->_hitPoints == 0)
  {
    std::cout << className << " "
              << R << this->_name << RST
              << " is destroyed and cannot attack!" << std::endl;
    return;
  }
  if (this->_energyPoints == 0)
  {
    std::cout << className << " "
              << R << this->_name << RST
              << " has no energy left to attack!" << std::endl;
    return;
  }
  std::cout << className << " "
            << G << this->_name << RST
            << " attacks " << target
            << ", causing "
            << R << this->_attackDamage << RST
            << " points of damage!" << std::endl;
  this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
  std::string className = getClassName();
  if (this->_hitPoints == 0)
  {
    std::cout << className << " "
              << R << this->_name << RST
              << " is already destroyed!" << std::endl;
    return ;
  }
  if (this->_hitPoints <= amount)
  {
    this->_hitPoints = 0;
    std::cout << className << " "
              << R << this->_name << RST
              << " is destroyed!" << std::endl;
    return ;
  }
  std::cout << className << " "
            << G << this->_name << RST
            << " takes "
            << R << amount << RST
            << " points of damage!" << std::endl;
  this->_hitPoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
  std::string className = getClassName();
  if (this->_hitPoints == 0)
  {
    std::cout << className << " "
              << R << this->_name << RST
              << " is destroyed and cannot be repaired!" << std::endl;
    return ;
  }
  if (this->_energyPoints <= 0)
  {
    std::cout << className << " "
              << R << this->_name << RST
              << " is out of energy!" << std::endl;
    return ;
  }
  std::cout << className << " "
            << G << this->_name << RST
            << " is repaired for "
            << G << amount << RST
            << " points!" << std::endl;

  this->_hitPoints += amount;
  this->_energyPoints -= 1;
}

// Test function
std::string ClapTrap::getName() const
{
  return _name;
}

unsigned int ClapTrap::getHitPoints() const
{
  return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
  return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
  return _attackDamage;
}
