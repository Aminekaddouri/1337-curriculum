/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 05:27:33 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/25 10:16:05 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("unkown")
{
    // std::cout << "AMateria: default constuctor" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
    // std::cout << "AMateria " << this->type << " created (param constructor)." << std::endl;
}

AMateria::AMateria( AMateria const &other )
{
    (void)other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    (void)other;
    return *this;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria " << this->type << " Destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses " << type << " on " << target.getName() << " *" << std::endl;
}