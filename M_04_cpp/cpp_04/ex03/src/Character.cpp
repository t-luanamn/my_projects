/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:15:30 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:15:32 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character(void) : _name("default"), _inventory()
{
  std::cout << "Character default constructor" << std::endl;
}

Character::Character(std::string const name) : _name(name), _inventory()
{
  std::cout << "Character constructor for: " << this->_name << std::endl;
  // for (int i = 0; i < 4; i++)
  //   this->_inventory[i] = NULL;
}

Character::Character(const Character &cpy)
{
  std::cout << "Character copy constructor" << std::endl;
  *this = cpy;
}

Character::~Character(void)
{
  std::cout << "Character destructor" << std::endl;
  for (int i = 0; i < 4; i++)
  {
    if (this->_inventory[i])
      delete this->_inventory[i];
  }
}

Character &Character::operator=(const Character &cpy)
{
  std::cout << "Character assignation operator" << std::endl;
  if (this != &cpy)
  {
    this->_name = cpy._name;
    for (int i = 0; i < 4; i++)
    {
      if (this->_inventory[i])
        this->_inventory[i] = cpy._inventory[i];
    }
  }
  return (*this);
}

std::string const &Character::getName() const
{
  return (this->_name);
}

void Character::equip(AMateria *m)
{
  if (!m)
  {
    std::cout << "Invalid materia" << std::endl;
    delete m;
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    if (!this->_inventory[i])
    {
      this->_inventory[i] = m;
      std::cout << "Materia equipped: " << m->getType()
                << "\nsaved at index: " << i
                << std::endl;
      break;
    }
    if (i == 3)
      std::cout << "Inventory is full" << std::endl;
  }
}

void Character::unequip(int idx)
{
  if (!this->_inventory[idx])
  {
    std::cout << "No materia at index: " << idx << std::endl;
    return;
  }
  if (idx >= 0 && idx < 4)
  {
    if (this->_inventory[idx])
    {
      std::cout << "Materia unequipped: " << this->_inventory[idx]->getType()
                << "\nremoved from index: " << idx
                << std::endl;
      delete this->_inventory[idx];
      this->_inventory[idx] = nullptr;
    }
  }
  else
    std::cout << "Invalid index" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
  if (idx >= 0 && idx < 4)
  {
    if (this->_inventory[idx])
    {
      std::cout << "Using materia: " << this->_inventory[idx]->getType()
                << std::endl;
      this->_inventory[idx]->use(target);
    }
    else
      std::cout << "No materia at index: " << idx << std::endl;
  }
  else
    std::cout << "Invalid index" << std::endl;
}
