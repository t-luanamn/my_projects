/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:52:50 by tluanamn          #+#    #+#             */
/*   Updated: 2024/08/27 13:52:53 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
  public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &obj);
    ~ScavTrap(void);
    
    using	ClapTrap::operator=;

    void guardGate(void);
    void attack(const std::string &target); // For DiamondTrap
};

#endif
