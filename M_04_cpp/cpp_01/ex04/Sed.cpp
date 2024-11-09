/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:26:07 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/02 12:26:08 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string fileName) : _inFile(fileName)
{
	this->_outFile = this->_inFile + ".replace";
}

Sed::~Sed()
{
}

void	Sed::replace(std::string toFind, std::string replace)
{
	std::ifstream ifs(this->_inFile);

	if (ifs.is_open())
	{
		std::string content;
		if (std::getline(ifs, content, '\0'))
		{
			std::ofstream	ofs(this->_outFile);
			size_t			pos = content.find(toFind); //Store the position of a substring
			if (pos == std::string::npos)
			{
				std::cerr << "\033[31mCannot find the content to replace.\033[0m" << std::endl;
				ifs.close();
				return;
			}
			//If the substring is not found, find returns std::string::npos
			while (pos != std::string::npos)
			{
				content.erase(pos, toFind.length());
				content.insert(pos, replace);
				pos = content.find(toFind);
			}
			ofs << content;
			ofs.close();
		}
		else
		{
			std::cerr << "\033[31mEmpty file found.\033[0m" << std::endl;
		}
		ifs.close();
	}
	else
	{
		std::cerr << "\033[31mUnable to open the file or file doesn't exist.\033[0m" << std::endl;
		exit(EXIT_FAILURE);
	}
}

/*
cerr means "character error (stream)"
Output to stderr via std::cerr flushes out the pending output on std::cout
*/
