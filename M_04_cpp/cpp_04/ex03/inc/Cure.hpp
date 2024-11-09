/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:15:00 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:15:03 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Cure: public AMateria
{
  public:
    Cure(void);
    Cure(const Cure &cpy);
    ~Cure(void);
    Cure &operator=(const Cure &cpy);

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif
