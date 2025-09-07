/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 05:27:31 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/25 07:57:43 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "Character.hpp"
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
            std::string type;

    public:
            AMateria(void);
            AMateria(std::string const & type);
            AMateria(const AMateria &other);
            AMateria& operator=(const AMateria &other);
            virtual ~AMateria();
            
            std::string const & getType() const;
            
            virtual AMateria* clone() const = 0;
            virtual void use(ICharacter& target);
};

#endif