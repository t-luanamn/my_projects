/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:13:38 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:13:40 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
  public:
    AMateria(void);
    AMateria(std::string const &type);
    AMateria(const AMateria &cpy);
    virtual ~AMateria(void);
    AMateria &operator=(const AMateria &cpy);

    std::string const &getType() const; //Returns the materia type

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target) = 0;

  protected:
    std::string _type;
};

#endif
