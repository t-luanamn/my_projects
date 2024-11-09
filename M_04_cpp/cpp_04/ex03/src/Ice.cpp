/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:14:38 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:14:40 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
  std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(const Ice &cpy) : AMateria(cpy)
{
  std::cout << "Ice copy constructor" << std::endl;
}

Ice::~Ice(void)
{
  std::cout << "Ice destructor" << std::endl;
}

Ice &Ice::operator=(const Ice &cpy)
{
  std::cout << "Ice assignation operator" << std::endl;
  if (this != &cpy)
    AMateria::operator=(cpy);
  return (*this);
}

AMateria *Ice::clone() const
{
  return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}