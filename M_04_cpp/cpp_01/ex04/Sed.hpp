/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:26:13 by tluanamn          #+#    #+#             */
/*   Updated: 2024/07/02 12:26:14 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

/*
	ofstream: Stream class to write on files
	ifstream: Stream class to read from files
	fstream: Stream class to both read and write from/to files.
*/

# include <iostream>
# include <fstream>

class Sed
{
	public:
		Sed(std::string fileName);
		~Sed();

		void	replace(std::string s1, std::string s2);

	private:
		std::string _inFile;
		std::string _outFile;
};

#endif
