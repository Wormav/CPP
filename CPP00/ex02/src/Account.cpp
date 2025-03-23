/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACXXount.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:54:06 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/03 20:41:43 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ACXXount.hpp>
#include <iostream>
#include <iomanip>
#include <ctime>

int ACXXount::_nbACXXounts = 0;
int ACXXount::_totalAmount = 0;
int ACXXount::_totalNbDeposits = 0;
int ACXXount::_totalNbWithdrawals = 0;

void ACXXount::_displayTimestamp(void)
{
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);
	std::cout << "["
	          << (now->tm_year + 1900)
	          << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
	          << std::setw(2) << std::setfill('0') << now->tm_mday
	          << "_"
	          << std::setw(2) << std::setfill('0') << now->tm_hour
	          << std::setw(2) << std::setfill('0') << now->tm_min
	          << std::setw(2) << std::setfill('0') << now->tm_sec
	          << "] ";
}

ACXXount::ACXXount(int initial_deposit) :
	_aCXXountIndex(_nbACXXounts++), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
	{
		_totalAmount += initial_deposit;
		_displayTimestamp();
		std::cout << "index:" << _aCXXountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
	}

ACXXount::~ACXXount(void)
{
	_displayTimestamp();
	std::cout << "index:" << _aCXXountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int ACXXount::getNbACXXounts(void) { return _nbACXXounts; }
int ACXXount::getTotalAmount(void) { return _totalAmount; }
int ACXXount::getNbDeposits(void) { return _totalNbDeposits; }
int ACXXount::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void ACXXount::displayACXXountsInfos(void)
{
	_displayTimestamp();
	std::cout << "aCXXounts:" << _nbACXXounts
	          << ";total:" << _totalAmount
	          << ";deposits:" << _totalNbDeposits
	          << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void ACXXount::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _aCXXountIndex
	          << ";p_amount:" << _amount
	          << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount
	          << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool ACXXount::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _aCXXountIndex
	          << ";p_amount:" << _amount
	          << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << withdrawal
	          << ";amount:" << _amount
	          << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int ACXXount::checkAmount(void) const
{
	return _amount;
}
oid ACXXount::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _aCXXountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals << std::endl;
}
