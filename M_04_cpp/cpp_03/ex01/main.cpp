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

/*
when a derived class object is created, the base class constructor is called first,
followed by the derived class constructor. This ensures that the base part of
the object is properly initialized before the derived part. When the object
is destroyed, the derived class destructor is called first,
followed by the base class destructor. This ensures that the derived part
of the object is cleaned up before the base part.
*/
int main(void)
{
  ScavTrap st1("Sv-David");
  ScavTrap st2("Sv-Sam");
  ClapTrap ct1("Cl-Bob");

  showStats(st1);
  showStats(st2);
  showStats(ct1);
	std::cout << "---------------------------------------------------" << std::endl;

  ct1.attack(st1.getName());
  st1.takeDamage(ct1.getAttackDamage());
  showStats(st1);
  showStats(ct1);
  st1.guardGate();
	std::cout << "---------------------------------------------------" << std::endl;

  st2.attack(ct1.getName());
  ct1.takeDamage(st2.getAttackDamage());
  ct1.beRepaired(5);
  showStats(st2);
  showStats(ct1);
	std::cout << "---------------------------------------------------" << std::endl;

  ScavTrap st3("Sv-AAA");
  ScavTrap st4("Sv-BBB");
  st3.attack(st4.getName());
  st4.takeDamage(st3.getAttackDamage());
  st4.beRepaired(5);
  st4.attack(st3.getName());
  st3.takeDamage(st4.getAttackDamage());
  st3.beRepaired(10);
  showStats(st3);
  showStats(st4);
  std::cout << "---------------------------------------------------" << std::endl;
  
  st4.takeDamage(1000);
  st4.beRepaired(500);
  showStats(st4);

  st3.beRepaired(1000);
  st3.takeDamage(888);
  showStats(st3);
  
  return (0);
}
