/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:38:22 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/17 23:38:56 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Amine");

    clap1.attack("Bandit");
    clap1.takeDamage(5);
    clap1.beRepaired(3);

    return 0;
}