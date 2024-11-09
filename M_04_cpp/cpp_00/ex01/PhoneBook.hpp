/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:32:28 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/17 10:45:22 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

# include "Contact.hpp"

# define MAX_CONTACTS 8
# define MAX_CONTACT_INDEX 7

class PhoneBook
{
	public:
		PhoneBook();
		void	addContact(void);
		void	searchContact(void);

	private:
		size_t	count;
		Contact	contacts[MAX_CONTACTS];
		int		index;
};

#endif
