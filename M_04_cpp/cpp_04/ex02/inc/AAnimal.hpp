/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:05:59 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/14 14:40:25 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
  public:
    AAnimal(void);
    AAnimal(std::string type);
    AAnimal(const AAnimal &cpy);
    virtual ~AAnimal();
    AAnimal &operator=(const AAnimal &cpy);

    std::string getType() const;

    // Pure virtual function
    // Derived classes must provide an implementation for makeSound()
    virtual void makeSound() const = 0;

  protected:
    std::string _type;
};

#endif
