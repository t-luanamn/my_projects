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
#include "inc/Dog.hpp"
#include "inc/Cat.hpp"
#include "inc/WrongAnimal.hpp"
#include "inc/WrongCat.hpp"
#include "inc/Brain.hpp"

void test_normal()
{
  std::cout << "\nTEST NORMAL" << std::endl;
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  delete j;
  delete i;

  const WrongAnimal* w = new WrongCat();
  delete w;
  std::cout << "---------------------" << std::endl;
}

void test_animal_array()
{
  std::cout << "\nTEST ANIMAL ARRAY" << std::endl;
  const Animal* animal[6];
  for (int i = 0; i < 6; i++)
  {
      if (i < 3)
        animal[i] = new Dog();
      else
        animal[i] = new Cat();
  }
  for (int i = 0; i < 6; i++)
  {
    animal[i]->makeSound();
    delete animal[i];
  }
  std::cout << "---------------------" << std::endl;
}

void test_shallow_copy()
{
  std::cout << "\nTEST SHALLOW COPY" << std::endl;
  const Animal* a = new Dog();
  const Animal* b;
  b = a;
  b->makeSound();
  delete a;
  // delete b; // Do not delete b, as it points to the same memory as a
  std::cout << "---------------------" << std::endl;
  
  const Animal* c = new Cat();
  const Animal* d;
  d = c;
  d->makeSound();
  delete c;
  // delete d; // Do not delete d, as it points to the same memory as c
  std::cout << "---------------------" << std::endl;
}

void test_deep_copy()
{
  std::cout << "\nTEST DEEP COPY" << std::endl;
  Dog originalDog;
  std::cout << "---" << std::endl;
  Dog copiedDog = originalDog; // Using copy constructor
  copiedDog.makeSound();

  Cat originalCat;
  std::cout << "---" << std::endl;
  Cat copiedCat = originalCat; // Using copy constructor
  copiedCat.makeSound();
  std::cout << "---------------------" << std::endl;
}

int main()
{
  test_normal();
  test_animal_array();
  test_shallow_copy();
  test_deep_copy();
  return 0;
}
