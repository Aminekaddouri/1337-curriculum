/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 04:00:46 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/05 01:54:32 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

std::string Contact::getFirstName(void) const {
	return (this->_firstName);
}

std::string Contact::getLastName(void) const {
	return (this->_lastName);
}

std::string Contact::getNickName(void) const {
	return (this->_nickName);
}

std::string Contact::getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const {
	return (this->_darkestSecret);
}

void	Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void	Contact::setNickName(std::string nickName) {
	this->_nickName = nickName;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

std::string Contact::_printLen(std::string str) const {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::showContactSummary(int index) const {
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName);
	std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName);
	std::cout << "|" << std::setw(10) << this->_printLen(this->_nickName);
	std::cout << "|" << std::endl;
}

void	Contact::display(int index) const {
	std::cout << std::endl;
	std::cout << "---->> CONTACT #" << index << "<<----" << std::endl << std::endl;
	std::cout << "First Name:\t" << this->_firstName << std::endl;
	std::cout << "Last Name:\t" << this->_lastName << std::endl;
	std::cout << "Nick Name:\t" << this->_nickName << std::endl;
	std::cout << "Phone Number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << this->_darkestSecret << std::endl;
	std::cout << std::endl;
}
