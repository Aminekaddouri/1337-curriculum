/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:06:04 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/15 06:27:13 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
    Animal::operator=(other);
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}