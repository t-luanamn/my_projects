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

#include "inc/AMateria.hpp"
#include "inc/Character.hpp"
#include "inc/MateriaSource.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"

void std_test()
{
  std::cout << "\n------Standard Test------\n" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  std::cout << "=====================" << std::endl;

  ICharacter* me = new Character("me");
  std::cout << "=====================" << std::endl;

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  std::cout << "=====================" << std::endl;

  ICharacter* bob = new Character("bob");
  std::cout << "=====================" << std::endl;

  me->use(0, *bob);
  me->use(1, *bob);
  std::cout << "=====================" << std::endl;

  delete bob;
  delete me;
  delete src;
}

void materia_test_1()
{
  std::cout << "\n------Materia Test 1------\n" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  std::cout << "=====================" << std::endl;
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  std::cout << "=====================" << std::endl;
  delete src;
}

void materia_test_2()
{
  std::cout << "\n------Materia Test 2------\n" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  std::cout << "=====================" << std::endl;

  ICharacter* me = new Character("me");
  std::cout << "=====================" << std::endl;

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  std::cout << "=====================" << std::endl;
  tmp = src->createMateria("aaaaaa");
  me->unequip(3);
  me->equip(tmp);
  std::cout << "=====================" << std::endl;

  delete src;
  delete me;
}

void inventory_test()
{
  std::cout << "\n------Inventory Test------\n" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  std::cout << "=====================" << std::endl;

  ICharacter* me = new Character("me");
  std::cout << "=====================" << std::endl;

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  std::cout << "=====================" << std::endl;

  ICharacter* bob = new Character("bob");
  std::cout << "=====================" << std::endl;

  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *bob);
  me->use(3, *bob);
  std::cout << "=====================" << std::endl;

  me->unequip(0);
  me->unequip(1);
  me->unequip(2);
  me->unequip(3);
  std::cout << "=====================" << std::endl;

  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *bob);
  me->use(3, *bob);
  std::cout << "=====================" << std::endl;

  delete bob;
  delete me;
  delete src;
}

void stress_test()
{
  ICharacter* me = new Character("me");
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Cure());

  for (int i = 0; i < 1000; ++i)
  {
    AMateria* tmp = src->createMateria("cure");
    me->equip(tmp);
    me->unequip(i % 4);
  }

  delete me;
  delete src;
}

int main()
{
  std_test();
  materia_test_1();
  materia_test_2();
  inventory_test();
  //stress_test();
  return 0;
}
