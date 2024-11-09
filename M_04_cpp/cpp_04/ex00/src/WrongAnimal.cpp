/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:09:17 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/04 21:09:19 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Unknown WrongAnimal")
{
  std::cout << "WrongAnimal : Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
  std::cout << "WrongAnimal : Parameter Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &cpy)
{
  std::cout << "WrongAnimal : Copy Constructor" << std::endl;
  if (this != &cpy)
    *this = cpy;
}

WrongAnimal::~WrongAnimal()
{
  std::cout << "WrongAnimal : Destructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &cpy)
{
  std::cout << "WrongAnimal : Copy Assignment Operator" << std::endl;
  if (this != &cpy)
    this->_type = cpy._type;
  return (*this);
}

std::string WrongAnimal::getType() const
{
  return (this->_type);
}

void WrongAnimal::makeSound() const
{
  std::cout << "WrongAnimal Sound:\n\t>>>...!!!...<<<\n" << std::endl;
}
