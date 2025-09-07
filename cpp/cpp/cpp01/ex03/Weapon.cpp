/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 03:50:48 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/08 06:14:41 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

const std::string& Weapon::getType(void) {
    return (this->_type);
}


void Weapon::setType(std::string newType) {
    this->_type = newType;
}
