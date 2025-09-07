/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 06:42:09 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/25 10:17:01 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    // std::cout << "Ice: Default Constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria("ice")
{
    *this = other;     
    // std::cout << "Ice: Copy Constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    (void)other;
    // std::cout << "Ice: Copy Assignment Operator called" << std::endl;
    return *this;
}

void *Ice::operator new(size_t size)
{
    void *p = ::operator new(size);
    GB.list_add(GB.list_new(p));
    return p;
}

Ice::~Ice() {
    // std::cout << "Ice: Destructor called" << std::endl;
}

AMateria* Ice::clone() const {
    return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}