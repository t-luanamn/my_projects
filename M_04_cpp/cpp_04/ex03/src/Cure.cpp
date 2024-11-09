/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:14:54 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:14:56 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
  std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(const Cure &cpy) : AMateria(cpy)
{
  std::cout << "Cure copy constructor" << std::endl;
}

Cure::~Cure(void)
{
  std::cout << "Cure destructor" << std::endl;
}

Cure &Cure::operator=(const Cure &cpy)
{
  std::cout << "Cure assignation operator" << std::endl;
  if (this != &cpy)
    AMateria::operator=(cpy);
  return (*this);
}

AMateria *Cure::clone() const
{
  return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
