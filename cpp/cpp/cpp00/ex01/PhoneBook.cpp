/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 03:38:27 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/05 02:06:48 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _numContacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::showUsageInstructions(void) const {
	std::cout << std::endl;
	std::cout << "Welcome to Your Awesome PhoneBook" << std::endl;
	std::cout << std::endl;
	std::cout << "------------- USAGE --------------" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: To quit the PhoneBook." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}

int	PhoneBook::getNumContacts(void)
{
	if (this->_numContacts >= 0 && this->_numContacts <= 8)
		return (this->_numContacts);
	return (8);
}


std::string PhoneBook::readInput(std::string input)
{
	std::string line;

	std::cout << std::setw(4) << "[" << input << "]: ";
	getline(std::cin, line);
	if (std::cin.eof())
	{
		std::cout << std::endl << "You exited the PhoneBook." << std::endl;
		exit(0);
	}
	return (line);
}

void	PhoneBook::addContact(void) {
	this->_contacts[this->_numContacts % 8].setFirstName(readInput("First Name"));
	if (this->_contacts[this->_numContacts % 8].getFirstName().empty()) {
		std::cout << "Error: Input cannot be empty." << std::endl;
		return ;
	}

	this->_contacts[this->_numContacts % 8].setLastName(readInput("Last Name"));
	if (this->_contacts[this->_numContacts % 8].getLastName().empty()) {
		std::cout << "Error: Input cannot be empty." << std::endl;
		return ;
	}

	this->_contacts[this->_numContacts % 8].setNickName(readInput("NickName"));
	if (this->_contacts[this->_numContacts % 8].getNickName().empty()) {
		std::cout << "Error: Input cannot be empty." << std::endl;
		return ;
	}

	this->_contacts[this->_numContacts % 8].setPhoneNumber(readInput("Phone Number"));
	if (this->_contacts[this->_numContacts % 8].getPhoneNumber().empty()) {
		std::cout << "Error: Input cannot be empty." << std::endl;
		return ;
	}

	this->_contacts[this->_numContacts % 8].setDarkestSecret(readInput("Darkest Secret"));
	if (this->_contacts[this->_numContacts % 8].getDarkestSecret().empty()) {
		std::cout << "Error: Input cannot be empty." << std::endl;
		return ;
	}
	this->_numContacts++;
}

void	PhoneBook::printContacts(void)
{
	std::cout << std::endl;
	std::cout << "------------- PHONEBOOK CONTACTS -------------" << std::endl << std::endl;
	
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nick Name" << "|" << std::endl;
	for (int i = 0; i < this->getNumContacts(); i++)
		this->_contacts[i].showContactSummary(i);
	std::cout << std::endl;
}

void PhoneBook::search(void)
{
	if (this->getNumContacts() == 0) {
		std::cout << "Error: no contacts available." << std::endl;
		return;
	}
	this->printContacts();
	while (true)
	{
		std::string str = this->readInput("Enter the contact index");
		int index = -1;
		bool isValid = true;
		for (int i = 0; str[i] != '\0'; i++) {
			if (!std::isdigit(str[i])) {
				isValid = false;
				break;
			}
		}
		if (isValid && !str.empty()) {
			index = std::stoi(str);
			if (index >= 0 && index < this->getNumContacts()) {
				this->_contacts[index].display(index);
				break;
			}
		}
		std::cout << "Error: Invalid index or contact does not exist." << std::endl;
		break;
	}
}
