/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:36:34 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/16 01:10:01 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain: Default constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "Default idea";
    }
}

Brain::~Brain() {
    std::cout << "Brain: Destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain: Copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain: Assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

std::string Brain::getIdea(int index) const {
    return ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
    ideas[index] = idea;
}
