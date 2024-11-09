/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:59:23 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/17 13:59:24 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << R << this->_name << " is dead" << RST << std::endl;
}

void	Zombie::announce()
{
	std::cout << G << this->_name << ": BraiiiiiiinnnzzzZ..." << RST << std::endl;
}
