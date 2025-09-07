/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 06:49:07 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/25 10:16:45 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    // std::cout << "Cure: Default Constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
    *this = other;
    // std::cout << "Cure: Copy Constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    (void)other;
    // std::cout << "Cure: Copy Assignment Operator called" << std::endl;
    return *this;
}

Cure::~Cure() {
    // std::cout << "Cure: Destructor called" << std::endl;
}

void *Cure::operator new(size_t size)
{
    void *p = ::operator new(size);
    GB.list_add(GB.list_new(p));
    return p;
}

AMateria* Cure::clone() const {
    return (new Cure());
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}