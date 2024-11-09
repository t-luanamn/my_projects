/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:09:39 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:09:41 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain(void)
{
  std::cout << "Brain : Default Constructor" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
  std::cout << "Brain : Copy Constructor" << std::endl;
  *this = cpy; // Calls the assignment operator
  //std::cout << "Brain : After operator called" << std::endl;
}

Brain::~Brain(void)
{
  std::cout << "Brain : Destructor" << std::endl;
}

Brain &Brain::operator=(const Brain &cpy)
{
  std::cout << "Brain : Assignation Operator" << std::endl;
  if (this != &cpy)
  {
    for (int i = 0; i < 100; i++)
      this->_ideas[i] = cpy._ideas[i];
  }
  return (*this);
}
