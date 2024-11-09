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

#include "inc/Animal.hpp"
#include "inc/WrongAnimal.hpp"
#include "inc/Cat.hpp"
#include "inc/Dog.hpp"
#include "inc/WrongCat.hpp"

int main()
{
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  std::cout << "======================" << std::endl;
  const WrongAnimal* meta2 = new WrongAnimal();
  const WrongAnimal* i2 = new WrongCat();
  std::cout << i2->getType() << " " << std::endl;
  i2->makeSound();
  meta2->makeSound();

  delete meta2;
  delete i2;

  return 0;
}
