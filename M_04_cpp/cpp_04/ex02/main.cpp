/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:07:28 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:07:31 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/AAnimal.hpp"
#include "inc/WrongAnimal.hpp"
#include "inc/Cat.hpp"
#include "inc/Dog.hpp"
#include "inc/WrongCat.hpp"

int main()
{
  const AAnimal* j = new Dog();
  const AAnimal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  delete j;
  delete i;

  // object of abstract class type "AAnimal" is not allowed
  // function "AAnimal::makeSound" is a pure virtual function
  //const AAnimal* meta = new AAnimal();

  return 0;
}