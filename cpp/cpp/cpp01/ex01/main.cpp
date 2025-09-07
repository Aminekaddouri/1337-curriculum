/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 03:18:40 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/09 00:06:13 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout << "Error: Only the output executable file name should be provided." << std::endl;
		return (1);
	}
    int N = 5;
    std::string name = "HordeZombie";

    Zombie* horde = zombieHorde(N, name);

    for (int i = 0; i < N; i++)
        horde[i].announce();

    delete[] horde;
    return (0);
}