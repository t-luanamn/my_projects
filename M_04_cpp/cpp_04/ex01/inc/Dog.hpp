/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:06:39 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:06:40 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _Dog_HPP_
# define _Dog_HPP_

# include "Animal.hpp"

class	Dog: public Animal
{
  public:
    Dog(void);
    Dog(const Dog &cpy);
    ~Dog(void);

    using Animal::operator=;

    void makeSound() const;

  private:
    Brain *_brain;
};

#endif
