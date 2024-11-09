/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:14:28 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/17 10:44:45 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string str)
{
	this->first_name = str;
}

void Contact::setLastName(std::string str)
{
	this->last_name = str;
}

void Contact::setNickName(std::string str)
{
	this->nick_name = str;
}

void Contact::setPhoneNumber(std::string str)
{
	this->phone_number = str;
}

void Contact::setDarkestSecret(std::string str)
{
	this->darkest_secret = str;
}

const std::string &Contact::getFirstName(void) const
{
	return (this->first_name);
}

const std::string &Contact::getLastName(void) const
{
	return (this->last_name);
}

const std::string &Contact::getNickName(void) const
{
	return (this->nick_name);
}

const std::string &Contact::getPhoneNumber(void) const
{
	return (this->phone_number);
}

const std::string &Contact::getDarkestSecret(void) const
{
	return (this->darkest_secret);
}

