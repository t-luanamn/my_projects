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

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
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
  std::cout << "\nTesting Basic:" << std::endl;

  FragTrap ft1("Ft-David");
  FragTrap ft2("Ft-Sam");
  ClapTrap ct1("Cl-Bob");

  showStats(ft1);
  showStats(ft2);
  showStats(ct1);

  ct1.attack(ft1.getName());
  ft1.takeDamage(ct1.getAttackDamage());
  ft1.highFivesGuys();
  std::cout << "---------------------------------------------------" << std::endl;

}

void test2()
{
  std::cout << "\n\nTesting Battle: ClapTrap vs FragTrap" << std::endl;

  ClapTrap clap("Clap");
  FragTrap frag("Frag");

  showStats(clap);
  showStats(frag);

  while (clap.getHitPoints() > 0 && clap.getEnergyPoints() > 0
    && frag.getHitPoints() > 0 && frag.getEnergyPoints() > 0)
  {
    clap.attack(frag.getName());
    frag.takeDamage(clap.getAttackDamage());

    frag.attack(clap.getName());
    clap.takeDamage(frag.getAttackDamage());

    clap.beRepaired(2);
    frag.beRepaired(10);

    if (frag.getHitPoints() == 0 || frag.getEnergyPoints() == 0)
      break;
    if (clap.getHitPoints() == 0 || clap.getEnergyPoints() == 0)
      break;

    showStats(clap);
    showStats(frag);
  }

  std::cout << "Battle ended." << std::endl;
  showStats(clap);
  showStats(frag);
  std::cout << "---------------------------------------------------" << std::endl;
}

void test3()
{
  std::cout << "\n\nTesting Battle: ScavTrap vs FragTrap" << std::endl;

  ScavTrap scav("Scav");
  FragTrap frag("Frag");

  showStats(scav);
  showStats(frag);

  while (scav.getHitPoints() > 0 && scav.getEnergyPoints() > 0
    && frag.getHitPoints() > 0 && frag.getEnergyPoints() > 0)
  {
    scav.attack(frag.getName());
    frag.takeDamage(scav.getAttackDamage());

    frag.attack(scav.getName());
    scav.takeDamage(frag.getAttackDamage());

    scav.beRepaired(5);
    frag.beRepaired(10);

    if (frag.getHitPoints() == 0 || frag.getEnergyPoints() == 0)
      break;
    if (scav.getHitPoints() == 0 || scav.getEnergyPoints() == 0)
      break;

    showStats(scav);
    showStats(frag);
  }

  std::cout << "Battle ended." << std::endl;
  showStats(scav);
  showStats(frag);
  std::cout << "---------------------------------------------------" << std::endl;
}

int main(void)
{
  test1();
  test2();
  test3();
  return (0);
}
