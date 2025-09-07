/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:38:22 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/13 06:29:10 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap frag("Fraggy");

    frag.attack("target");
    frag.highFivesGuys();
    frag.takeDamage(20);
    frag.beRepaired(10);

    return 0;
}