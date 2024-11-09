/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:32:12 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/17 10:45:09 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::cout;
using std::cin;
using std::endl;

PhoneBook::PhoneBook() : count(0), index(0) {};

std::string getFormattedField(const std::string &field)
{
	if (field.length() > 10)
		return (field.substr(0,9) + ".");
	return (field);
}

void display_contact_info(Contact contact)
{
	cout << endl;
	cout << "First name: " << contact.getFirstName() << endl;
	cout << "Last name: " << contact.getLastName() << endl;
	cout << "Nickname: " << contact.getNickName() << endl;
	cout << "Phone number: " << contact.getPhoneNumber() << endl;
	cout << "Darkest secret: " << contact.getDarkestSecret() << endl;
	cout << endl;
}

void PhoneBook::addContact(void)
{
	Contact	new_contact;
	std::string	input;

	while (1)
	{
		cout << "First name: ";
		getline(cin, input);
		if (input.empty() || input[0] == ' ' || !all_of(input.begin(), input.end(), ::isalpha))
		{
			cin.clear();
			cout << "\033[31mFirst name can only contain alphabetic characters"
				<< " and cannot start with a space.\033[0m" << endl;
			continue;
		}
		else
		{
			new_contact.setFirstName(input);
			break;
		}
	}

	while (1)
	{
		cout << "Last name: ";
		getline(cin, input);
		if (input.empty() || input[0] == ' ' || !all_of(input.begin(), input.end(), ::isalpha))
		{
			cin.clear();
			cout << "\033[31mLast name can only contain alphabetic characters"
				<< " and cannot start with a space.\033[0m" << endl;
			continue;
		}
		else
		{
			new_contact.setLastName(input);
			break;
		}
	}

	while (1)
	{
		cout << "Nick name: ";
		getline(cin, input);
		if (input.empty() || input[0] == ' ' || !all_of(input.begin(), input.end(), ::isalpha))
		{
			cin.clear();
			cout << "\033[31mNick name can only contain alphabetic characters"
				<< " and cannot start with a space.\033[0m" << endl;
			continue;
		}
		else
		{
			new_contact.setNickName(input);
			break;
		}
	}

	while (1)
	{
		cout << "Phone number: ";
		getline(cin, input);
		if (input.empty() || 
			input.find_first_not_of("0123456789") != std::string::npos || 
			input.length() != 10 || 
			input[0] != '0')
		{
			cin.clear();
			cout << "\033[31mPhone number must not be empty.\033[0m" << endl;
			cout << "\033[31mPhone number must be numbers.\033[0m" << endl;
			cout << "\033[31mPhone number must be 10 digits long.\033[0m" << endl;
			cout << "\033[31mPhone number must start with 0.\033[0m" << endl;
			continue;
		}
		new_contact.setPhoneNumber(input);
		break;
	}

	while (1)
	{
		cout << "Darkest secret: ";
		getline(cin, input);
		if (input.empty() || input[0] == ' ')
		{
			cin.clear();
			cout << "\033[31mDarkest secret cannot be empty or start with a space.\033[0m" << endl;
			continue;
		}
		else
		{
			new_contact.setDarkestSecret(input);
			break;
		}
	}

	if (count < MAX_CONTACTS)
	{
		contacts[index] = new_contact;
		count++;
	}
	else
	{
		contacts[index] = new_contact;
	}
	index = (index + 1) % MAX_CONTACTS;
	cout << "Contact successfully added." << endl;
}

void PhoneBook::searchContact(void)
{
	if (count == 0)
	{
		cout << "\033[31mThere are no contacts\033[0m" << endl;
		return;
	}
	cout << "\n|     Index|First Name| Last Name| Nick Name|" << endl;
	for (size_t i = 0; i < this->count; i += 1)
	{
		cout << "|" << std::right << std::setw(10) << i << "|";
		cout << std::right << std::setw(10) << getFormattedField(contacts[i].getFirstName()) << "|";
		cout << std::right << std::setw(10) << getFormattedField(contacts[i].getLastName()) << "|";
		cout << std::right << std::setw(10) << getFormattedField(contacts[i].getNickName()) << "|";
		cout << endl;
	}
	std::string index;
	int conv_index;

	while (1)
	{
		cout << "Please insert the index of the contact: ";
		getline(cin, index);
		if (!index.empty() && index.find_first_not_of("0123456789") == std::string::npos)
		{
			conv_index = atoi(index.c_str());
			if (conv_index <= MAX_CONTACT_INDEX)
				break;
		}
		cin.clear();
		cout << "\033[31mInvalid input\033[0m" << endl;
	}
	if ((size_t)conv_index > (count - 1))
		cout << "\033[31mThere's no contact with that index\033[0m" << endl;
	else
		display_contact_info(this->contacts[conv_index]);
}

