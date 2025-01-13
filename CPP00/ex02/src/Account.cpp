/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:54:06 by jlorette          #+#    #+#             */
/*   Updated: 2025/01/13 14:02:19 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>
#include <iostream>
#include <iomanip>
#include <ctime>

// Initialisation des variables statiques
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Affiche l'horodatage au format spécifié
void Account::_displayTimestamp(void) {
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

// Constructeur
Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts++), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0) {
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructeur
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Accesseurs statiques
int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

// Affiche les informations sur tous les comptes
void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	          << ";total:" << _totalAmount
	          << ";deposits:" << _totalNbDeposits
	          << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Fait un dépôt et met à jour les statistiques
void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << _amount
	          << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount
	          << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Effectue un retrait si possible
bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
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

// Vérifie le montant
int Account::checkAmount(void) const {
	return _amount;
}

// Affiche l'état du compte
void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals << std::endl;
}
