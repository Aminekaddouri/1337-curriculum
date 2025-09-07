/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:51:59 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/04 04:25:52 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_numContacts;

	static std::string	readInput(std::string tag);

public:
	PhoneBook();
	~PhoneBook();

	int			getNumContacts(void);
		
	void	addContact(void);
	void	printContacts(void);
	void	search(void);
	void	showUsageInstructions(void) const;
};

#endif
