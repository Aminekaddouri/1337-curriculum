/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:08:52 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/15 06:32:09 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a generic sound!" << std::endl;
}

std::string Animal::getType(void) const {
    return (this->type);
}