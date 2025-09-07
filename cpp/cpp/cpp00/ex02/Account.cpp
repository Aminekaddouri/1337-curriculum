/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 02:24:51 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/05 02:28:49 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Initialize Static Variables
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Implement the Constructor
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

// Implement the Destructor
Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= this->_amount;
}

// Implement geter Functions
int Account::getNbAccounts() {
	return (_nbAccounts);
}

int Account::getTotalAmount() {
	return (_totalAmount);
}

int Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

//Implement the Member Functions
void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << (this->_amount - deposit)
		  << ";deposit:" << deposit << ";amount:" << this->_amount
		  << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (withdrawal > this->_amount) {
		std::cout << "index:" << this->_accountIndex << ";p_amont:" << this->_amount
			  << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << (this->_amount + withdrawal)
		  << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
		  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount() const {
	return (this->_amount);
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		  << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		  << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp() {
	char MY_TIME[20];
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);
	strftime(MY_TIME, sizeof(MY_TIME), "[%Y%m%d_%H%M%S] ", ltm);
	std::cout << MY_TIME;
}
