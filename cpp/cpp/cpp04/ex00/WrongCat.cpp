/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:58:09 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/16 00:00:43 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    WrongAnimal::operator=(other);
    std::cout << "WrongCat: Copy assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat: Destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "WrongCat makes a wrong sound!" << std::endl;
}