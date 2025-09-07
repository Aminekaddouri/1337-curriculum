/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:38:22 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/17 23:35:53 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Test ClapTrap
    ClapTrap clap1("CL4P-TP");
    clap1.attack("Bandit");
    clap1.takeDamage(5);
    clap1.beRepaired(3);

    // Test ScavTrap
    ScavTrap scav1("SC4V-TP");
    scav1.attack("Psycho");
    scav1.takeDamage(20);
    scav1.beRepaired(10);
    scav1.guardGate();


    return 0;
}
