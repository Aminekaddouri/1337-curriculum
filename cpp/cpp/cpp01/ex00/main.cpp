/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 01:53:46 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/08 23:59:25 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout << "Error: Only the output executable file name should be provided." << std::endl;
		return (1);
	}
	std::cout << std::endl;
	std::cout << "Creating zombie on the heap." << std::endl << std::endl;
	Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
	std::cout << std::endl;
	std::cout << "-------------------------------------" << std::endl << std::endl;
	std::cout << "Creating zombie on the stack." << std::endl << std::endl;
   	randomChump("StackZombie");
	std::cout << std::endl;
	return (0);
}
