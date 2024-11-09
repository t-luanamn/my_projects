/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:14:43 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:14:45 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Ice: public AMateria
{
  public:
    Ice(void);
    Ice(const Ice &cpy);
    ~Ice(void);
    Ice &operator=(const Ice &cpy);

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif
