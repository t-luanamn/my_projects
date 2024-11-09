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
}

Dog::~Dog()
{
  std::cout << "Dog : Destructor" << std::endl;
}

Dog::Dog(Dog const &obj)
{
  std::cout << "Dog : Copy Constructor" << std::endl;
  if (this != &obj)
    *this = obj;
}

void Dog::makeSound() const
{
  std::cout << "Dog Sound:\n\t>>>Woof Woof<<<\n" << std::endl;
}
