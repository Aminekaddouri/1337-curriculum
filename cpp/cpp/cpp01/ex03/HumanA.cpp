/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 03:59:53 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/09 00:27:05 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>


HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), weapon(weapon) {
}


void    HumanA::attack( void ) const {
    if (this->weapon.getType() != "") {
        std::cout << _name << " attacks with their " << this->weapon.getType() << std::endl;
    } else {
        std::cout << _name << " doesn't have a weapon to attack." << std::endl;
    }
}