/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:16:18 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:16:19 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _idx(0)
{
  std::cout << "MateriaSource default constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &cpy)
{
  std::cout << "MateriaSource copy constructor" << std::endl;
  *this = cpy;
}

MateriaSource::~MateriaSource(void)
{
  for (int i = 0; i < this->_idx; i++)
    delete this->_inventory[i];
  std::cout << "MateriaSource destructor" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &cpy)
{
  std::cout << "MateriaSource assignation operator" << std::endl;
  if (this != &cpy)
  {
    for (int i = 0; i < cpy._idx; i++)
      this->_inventory[i] = cpy._inventory[i];
    this->_idx = cpy._idx;
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
  if (this->_idx == 4)
  {
    std::cout << "Inventory is full" << std::endl;
    delete m;
  }
  else
  {
    this->_inventory[this->_idx] = m;
    std::cout << "Materia learned: " << _inventory[this->_idx]->getType()
              << "\nsaved at index: " << this->_idx
              << std::endl;
    this->_idx++;
  }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
  for (int i = 0; i < this->_idx; i++)
  {
    if (this->_inventory[i]->getType() == type)
    {
      std::cout << "Materia created: " << type << std::endl;
      return (this->_inventory[i]->clone());
    }
  }
  std::cout << "Materia not found: Type is unknown" << std::endl;
  return (0);
}
