/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:06:04 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/23 08:51:02 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    brain = new Brain();
    type = "Dog";
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog: Assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

