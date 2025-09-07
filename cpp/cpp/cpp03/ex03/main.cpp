/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:38:22 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/17 23:08:30 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("Shiny");

    diamond.attack("target"); 
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    diamond.whoAmI(); 

    return 0;
}