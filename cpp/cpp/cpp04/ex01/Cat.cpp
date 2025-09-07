/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:15:18 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/23 08:50:58 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    brain = new Brain();
    type = "Cat";
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat: Assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat: Destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
