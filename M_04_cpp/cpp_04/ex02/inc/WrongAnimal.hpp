/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:08:20 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/04 21:08:21 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WrongAnimal_HPP_
# define _WrongAnimal_HPP_

# include <iostream>

class	WrongAnimal
{

  public:
    WrongAnimal(void);
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &cpy);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &cpy);

    std::string getType() const;
    virtual void makeSound() const;

  protected:
    std::string _type;
};

#endif
