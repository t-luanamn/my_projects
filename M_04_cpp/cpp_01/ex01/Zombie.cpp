/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:59:23 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/18 12:12:58 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::~Zombie()
{
	std::cout << R << this->_name << " is dead" << RST << std::endl;
}

void	Zombie::announce()
{
	std::cout << G << this->_name << ": BraiiiiiiinnnzzzZ..." << RST << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
