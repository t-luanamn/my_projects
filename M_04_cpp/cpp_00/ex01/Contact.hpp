/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:14:35 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/17 10:44:54 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNickName(std::string str);
		void	setPhoneNumber(std::string str);
		void	setDarkestSecret(std::string str);

		const	std::string &getFirstName(void) const;
		const	std::string &getLastName(void) const;
		const	std::string &getNickName(void) const;
		const	std::string &getPhoneNumber(void) const;
		const	std::string &getDarkestSecret(void) const;

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
