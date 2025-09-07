/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:56:03 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/08 06:39:21 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	std::string input;
	Harl harl;

	(void)av;
	if (ac != 1)
	{
		std::cout << "Error: Only the output executable file name should be provided." << std::endl;
		return (1);
	}
	while (true)
	{
		std::cout << "Enter a level: ";
		getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << "You have exited the programme." << std::endl;
			break ;
		}
		if (input == "EXIT")
			break ;
		else
			harl.complain(input);
	}
	return (0);
}