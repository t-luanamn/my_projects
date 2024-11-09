/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:54:54 by tluanamn          #+#    #+#             */
/*   Updated: 2024/08/27 13:54:55 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

// virtual inheritance, you ensure that only one instance of ClapTrap is created and
// shared among FragTrap, ScavTrap, and DiamondTrap.
class	DiamondTrap: public ScavTrap, public FragTrap
{
  public:
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap const &obj);
    ~DiamondTrap(void);

    using	ClapTrap::operator=;
    using ScavTrap::attack;
    void whoAmI(void);

  private:
    std::string _name;
};

#endif
