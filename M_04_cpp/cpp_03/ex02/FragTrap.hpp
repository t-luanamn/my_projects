/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:53:51 by tluanamn          #+#    #+#             */
/*   Updated: 2024/08/27 13:53:52 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
  public:
    FragTrap(std::string name);
    FragTrap(const FragTrap &obj);
    ~FragTrap(void);

    using	ClapTrap::operator=;

    void highFivesGuys(void);
};

#endif
