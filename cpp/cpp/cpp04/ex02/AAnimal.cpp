/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:08:52 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/23 08:54:44 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal: Destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    std::cout << "AAnimal: Copy constructor called" << std::endl;
    *this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "Animal: Assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

std::string AAnimal::getType() const {
    return (type);
}
