/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:14:06 by jgim              #+#    #+#             */
/*   Updated: 2022/01/25 23:14:07 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(){return (_nbAccounts);}
int	Account::getTotalAmount(){return (_totalAmount);}
int	Account::getNbDeposits(){return (_totalNbDeposits);}
int	Account::getNbWithdrawals(){return (_totalNbWithdrawals);}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	if (_accountIndex == 0)
	std::cout << "---------------------------------------------------------------------" << std::endl;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex  << ';';
	std::cout << "amount:" <<_amount << ';';
	std::cout << "created" << std::endl;
}

void	Account::displayAccountsInfos()
{
	std::cout << "---------------------------------------------------------------------" << std::endl;
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << getTotalAmount() << ';';
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
}

void	Account::displayStatus() const
{
	if (_accountIndex == 0)
	{
		std::cout << std::endl;
		std::cout << "---------------------------------------------------------------------" << std::endl;
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposit:" << _nbDeposits << ';';
	std::cout << "withdrwals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp()
{
	time_t now = time(0);
	tm *tm = localtime(&now);

	std::cout << '[';
	std::cout << tm->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_mday;
	std::cout << '_';
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_sec;
	std::cout << "] ";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_accountIndex == 0)
		std::cout << "---------------------------------------------------------------------" << std::endl;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	_amount -= withdrawal;
	if (!checkAmount())
	{
		_amount += withdrawal;
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ';';
	std::cout << "amount" << _amount << ';';
	std::cout << "nb_withdrawals" << _nbWithdrawals << std::endl;
	return (true);
}


void	Account::makeDeposit(int deposit)
{
	if (_accountIndex == 0)
		std::cout << "---------------------------------------------------------------------" << std::endl;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	std::cout << "deposit:" << deposit << ';';
	_amount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ';';
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

int	Account::checkAmount() const
{
	if (_amount < 0)
		return (0);
	return (1);
}

Account::~Account (void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
	if (_accountIndex == 0)
		std::cout << "---------------------------------------------------------------------" << std::endl;
}
