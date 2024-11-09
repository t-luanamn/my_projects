/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:51:05 by tluanamn          #+#    #+#             */
/*   Updated: 2024/08/27 13:51:10 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iomanip>

void showStats(const ClapTrap& clapTrap)
{
  const int labelWidth = 15;
  const int valueWidth = 10;
  const std::string border = "===========================";
  
  std::cout << " " << border << std::endl;
  std::cout << "***         Stats        ***" << std::endl;
  std::cout << " " << border << std::endl;
  std::cout << "| " << std::left << std::setw(labelWidth) << "Name:" 
            << R << std::right << std::setw(valueWidth)
            << clapTrap.getName() << RST << " |" << std::endl;
  std::cout << "| " << std::left << std::setw(labelWidth) << "Hit Points:" 
            << std::right << std::setw(valueWidth)
            << clapTrap.getHitPoints() << " |" << std::endl;
  std::cout << "| " << std::left << std::setw(labelWidth) << "Energy Points:" 
            << std::right << std::setw(valueWidth)
            << clapTrap.getEnergyPoints() << " |" << std::endl;
  std::cout << "| " << std::left << std::setw(labelWidth) << "Attack Damage:" 
            << std::right << std::setw(valueWidth)
            << clapTrap.getAttackDamage() << " |" << std::endl;
  std::cout << " " << border << std::endl;
}

void test1()
{
  std::cout << "----------TEST 1---------" << std::endl;
  DiamondTrap diamond("D1");

  diamond.attack("enemy");
  diamond.takeDamage(10);
  diamond.beRepaired(10);
  diamond.whoAmI();
  diamond.guardGate();
  diamond.highFivesGuys();
  showStats(diamond);
  std::cout << "---------------------------------------------------" << std::endl;
}

void test2()
{
  std::cout << "----------TEST 2---------" << std::endl;
  DiamondTrap diamond("D1");
  DiamondTrap diamond2("D2");

  showStats(diamond);
  showStats(diamond2);

  while (diamond.getHitPoints() > 0 && diamond.getEnergyPoints() > 0
    && diamond2.getHitPoints() > 0 && diamond2.getEnergyPoints() > 0)
  {
    diamond.attack(diamond2.getName());
    diamond2.takeDamage(diamond.getAttackDamage());

    diamond2.attack(diamond.getName());
    diamond.takeDamage(diamond2.getAttackDamage());

    diamond.beRepaired(2);
    diamond2.beRepaired(10);

    if (diamond2.getHitPoints() == 0 || diamond2.getEnergyPoints() == 0)
      break;
    if (diamond.getHitPoints() == 0 || diamond.getEnergyPoints() == 0)
      break;

    showStats(diamond);
    showStats(diamond2);
  }

  std::cout << "Battle ended." << std::endl;
  showStats(diamond);
  showStats(diamond2);
  std::cout << "---------------------------------------------------" << std::endl;
}

void test3()
{
  std::cout << "----------TEST 3---------" << std::endl;
  ClapTrap clapTrap("C1");
  ScavTrap scavTrap("S1");
  FragTrap fragTrap("F1");
  DiamondTrap diamondTrap("D1");

  showStats(clapTrap);
  showStats(scavTrap);
  showStats(fragTrap);
  showStats(diamondTrap);
  std::cout << "---------------------------------------------------" << std::endl;
}

int main(void)
{
  test1();
  test2();
  test3();
  return (0);
}
