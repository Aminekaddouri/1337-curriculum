/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 03:35:59 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/08 23:17:06 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout << "Error: Only the output executable file name should be provided." << std::endl;
		return (1);
	}
	
	std::string brainMessage = "HI THIS IS BRAIN";

	std::string* stringPTR = &brainMessage;

	std::string& stringREF = brainMessage;

	std::cout << "Memory address of the string variable: " << &brainMessage << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of the string variable: " << brainMessage << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}