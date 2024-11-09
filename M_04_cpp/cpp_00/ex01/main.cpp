/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:14:42 by tluanamn          #+#    #+#             */
/*   Updated: 2024/02/09 14:14:44 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

using std::cin;
using std::cout;
using std::endl;

void printWelcome(void)
{
	cout << "*-------------------------------------------*\n"
			"*           Phone Book by tluanamn          *\n"  
			"*                                           *\n"
			"*          ADD - Add a new contact          *\n"
			"*          SEARCH - Display a contact       *\n"
			"*          EXIT - Exit PhoneBook            *\n"
			"*-------------------------------------------*" << endl;
}

static inline bool isInputValid(const std::string &input)
{
	return (input == "ADD" || input == "SEARCH" || input == "EXIT");
}

std::string getInput(void)
{
	std::string input;

	while (1)
	{
		cout << "> ";
		getline(cin, input);
		if (cin.eof() == true)
		{
			cin.clear();
			clearerr(stdin);
		}
		if (!input.empty() && isInputValid(input))
			break;
		cin.clear();
		cout << "\033[31mPlease insert a valid input\033[0m" << endl;
	}
	return (input);
}

int main(void)
{
	PhoneBook phonebook;
	std::string input;

	printWelcome();
	while (1)
	{
		input = getInput();
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else
		{
			cout << "Good Bye!" << endl;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
