/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:51:05 by tluanamn          #+#    #+#             */
/*   Updated: 2024/08/27 17:05:40 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iomanip>

void showStats(const ClapTrap& clapTrap)
{
	const int labelWidth = 15;
	const int valueWidth = 10;
	const std::string border = "===========================";
	
	std::cout << " " << border << std::endl;
	std::cout << "***    ClapTrap Stats    ***" << std::endl;
	std::cout << " " << border << std::endl;
	std::cout << "| " << std::left << std::setw(labelWidth) << "Name:" 
			  << std::right << std::setw(valueWidth) << clapTrap.getName() << " |" << std::endl;
	std::cout << "| " << std::left << std::setw(labelWidth) << "Hit Points:" 
			  << std::right << std::setw(valueWidth) << clapTrap.getHitPoints() << " |" << std::endl;
	std::cout << "| " << std::left << std::setw(labelWidth) << "Energy Points:" 
			  << std::right << std::setw(valueWidth) << clapTrap.getEnergyPoints() << " |" << std::endl;
	std::cout << "| " << std::left << std::setw(labelWidth) << "Attack Damage:" 
			  << std::right << std::setw(valueWidth) << clapTrap.getAttackDamage() << " |" << std::endl;
	std::cout << " " << border << std::endl;
}

void	testCopyAssignmentOperator()
{
	std::cout << "Testing Copy Assignment Operator:" << std::endl;
	ClapTrap a("ClapTrap A");
	ClapTrap b("ClapTrap B");

	std::cout << "Before assignment:" << std::endl;
	std::cout << "a: " << a.getName() << std::endl;
	std::cout << "b: " << b.getName() << std::endl;

	b = a;

	std::cout << "After assignment: b = a" << std::endl;
	std::cout << "a: " << a.getName() << std::endl;
	std::cout << "b: " << b.getName() << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
}

void	testClapTrapFunctions()
{
	std::cout << "Testing ClapTrap Functions:" << std::endl;
	ClapTrap clapTrap("TestClapTrap");

	std::cout << "Initial state:" << std::endl;
	showStats(clapTrap);

	std::cout << "Calling attack():" << std::endl;
	clapTrap.attack("Target");
	showStats(clapTrap);

	std::cout << "Calling takeDamage():" << std::endl;
	clapTrap.takeDamage(5);
	showStats(clapTrap);

	std::cout << "Calling beRepaired():" << std::endl;
	clapTrap.beRepaired(3);
	showStats(clapTrap);

	std::cout << "Calling takeDamage():" << std::endl;
	clapTrap.takeDamage(20);
	showStats(clapTrap);

	std::cout << "Calling beRepaired():" << std::endl;
	clapTrap.beRepaired(3);
	showStats(clapTrap);
	std::cout << "---------------------------------------------------" << std::endl;
}

int	main(void)
{
	//testCopyAssignmentOperator();
	//testClapTrapFunctions();

	ClapTrap clapTrap1("Alice");
	ClapTrap clapTrap2("Bob");

	while (clapTrap1.getHitPoints() > 0 && clapTrap2.getHitPoints() > 0 &&
		   clapTrap1.getEnergyPoints() > 0 && clapTrap2.getEnergyPoints() > 0)
	{
		std::cout << "Alice attacks Bob:" << std::endl;
		clapTrap1.attack(clapTrap2.getName());
		clapTrap2.takeDamage(clapTrap1.getAttackDamage());
		clapTrap2.beRepaired(1);
		showStats(clapTrap1);
		showStats(clapTrap2);

		if (clapTrap2.getHitPoints() <= 0 || clapTrap2.getEnergyPoints() <= 0)
			break;

		std::cout << "Bob attacks Alice:" << std::endl;
		clapTrap2.attack(clapTrap1.getName());
		clapTrap1.takeDamage(clapTrap2.getAttackDamage());
		clapTrap1.beRepaired(2);
		showStats(clapTrap1);
		showStats(clapTrap2);
	}

	std::cout << "\nFinal state:" << std::endl;
	showStats(clapTrap1);
	showStats(clapTrap2);

	return (0);
}
