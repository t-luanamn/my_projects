/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:35:39 by tluanamn          #+#    #+#             */
/*   Updated: 2024/06/17 13:35:22 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

using std::cin;
using std::cout;
using std::endl;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << endl;
	return ;
}

Account::~Account()
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		 << "amount:" << this->_amount << ";"
		 << "closed" << endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";

	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;

	cout << "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits << endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";

	this->_amount -= withdrawal;
	if (checkAmount())
	{
		this->_amount += withdrawal;
		cout << "withdrawal:refused" << endl;
		return (false);
	}
	_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	this->_totalNbWithdrawals += 1;
	cout << "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << endl;
	return (true);
}

int Account::checkAmount(void) const
{
	if (this->_amount < 0)
		return (1);
	return (0);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << endl;
}

void Account::_displayTimestamp(void)
{
	time_t      t_stmp_ptr;
	struct tm   *t_stmp;

	std::time(&t_stmp_ptr);
	t_stmp = localtime(&t_stmp_ptr);
	cout << "[";
	cout << t_stmp->tm_year + 1900;
	cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mon + 1;
	cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mday << "_";
	cout << std::setw(2) << std::setfill('0') << t_stmp->tm_hour;
	cout << std::setw(2) << std::setfill('0') << t_stmp->tm_min;
	cout << std::setw(2) << std::setfill('0') << t_stmp->tm_sec;
	cout << "] ";
}

// diff <(sed 's/\[[^]]*\]//g' file1.log) <(sed 's/\[[^]]*\]//g' file2.log)
