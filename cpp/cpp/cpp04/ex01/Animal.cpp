/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:08:52 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/16 01:09:44 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal: Assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a generic sound!" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
