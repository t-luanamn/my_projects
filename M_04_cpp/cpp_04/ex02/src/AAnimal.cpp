/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:05:22 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/14 14:40:43 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal(void): _type("Unknown Animal")
{
  std::cout << "Animal : Default Constructor" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
  std::cout << "Animal : Parameter Constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &cpy): _type(cpy._type)
{
  std::cout << "Animal : Copy Constructor" << std::endl;
}

AAnimal::~AAnimal()
{
  std::cout << "Animal : Destructor" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &cpy)
{
  std::cout << "Animal : Assignation Operator" << std::endl;
  if (this != &cpy)
    this->_type = cpy._type;
  return (*this);
}

std::string AAnimal::getType() const
{
  return (this->_type);
}
