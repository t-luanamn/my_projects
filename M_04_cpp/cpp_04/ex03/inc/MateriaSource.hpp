/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:52:16 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/14 15:52:17 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
  public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

class MateriaSource: public IMateriaSource
{
  public:
    MateriaSource(void);
    MateriaSource(const MateriaSource &cpy);
    ~MateriaSource(void);
    MateriaSource &operator=(const MateriaSource &cpy);

    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);

  private:
    AMateria *_inventory[4];
    int _idx;
};

#endif
