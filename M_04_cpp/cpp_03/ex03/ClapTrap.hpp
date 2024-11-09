/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:51:38 by tluanamn          #+#    #+#             */
/*   Updated: 2024/08/27 17:05:31 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>

// Colored text
# define R "\033[1;31m"
# define G "\033[1;32m"
# define RST "\033[0m"

class	ClapTrap
{
  public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &obj);
    ~ClapTrap(void);
    ClapTrap &operator=(const ClapTrap &obj);

    // Polymorphism with virtual keyword
    virtual void attack(const std::string &target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);

    // Test function
    std::string   getName() const;
    unsigned int  getHitPoints() const;
    unsigned int  getEnergyPoints() const;
    unsigned int  getAttackDamage() const;
    std::string   getClassName() const;

  protected:
    std::string   _name;
    unsigned int  _hitPoints;
    unsigned int  _energyPoints;
    unsigned int  _attackDamage;
};

#endif
