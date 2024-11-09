/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:13:33 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:13:35 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(void) : _type("default")
{
  std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
  std::cout << "AMateria constructor for: " << this->_type << std::endl;
}

AMateria::AMateria(const AMateria &cpy)
{
  std::cout << "AMateria copy constructor" << std::endl;
  *this = cpy;
}

AMateria::~AMateria(void)
{
  std::cout << "AMateria destructor" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &cpy)
{
  std::cout << "AMateria assignation operator" << std::endl;
  if (this != &cpy)
    this->_type = cpy._type;
  return (*this);
}

std::string const &AMateria::getType() const
{
  return (this->_type);
}
