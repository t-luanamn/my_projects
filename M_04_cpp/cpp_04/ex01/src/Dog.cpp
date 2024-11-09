/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:06:33 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:06:34 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(): Animal::Animal("Dog")
{
  std::cout << "Dog : Default Constructor" << std::endl;
  this->_brain = new Brain();
}

Dog::~Dog()
{
  delete this->_brain;
  std::cout << "Dog : Destructor" << std::endl;
}

Dog::Dog(Dog const &cpy): Animal(cpy)
{
  std::cout << "Dog : Copy Constructor" << std::endl;
  this->_brain = new Brain(*cpy._brain); // Deep copy of Brain
}

void Dog::makeSound() const
{
  std::cout << "Dog Sound:\n\t>>>Woof Woof<<<\n" << std::endl;
}
