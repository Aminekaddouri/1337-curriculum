/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 02:54:00 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/05 02:06:10 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int ac, char **av)
{
	PhoneBook phonebook;
	std::string input;

	(void)av;
	if (ac != 1)
	{
		std::cout << "Error: Only the output executable file name should be provided." << std::endl;
		return (0);
	}
	phonebook.showUsageInstructions();
	while (1)
	{
		std::cout << "Awaiting command >> ";
		getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "You have exited the PhoneBook." << std::endl;
			break ;
		}
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
		{
			phonebook.search();
		}
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Error: you entered an invalid command." << std::endl;
	}
	return (0);
}
