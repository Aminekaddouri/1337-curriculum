/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 06:47:20 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/25 07:17:56 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "GarbageCollector.hpp"

class Cure : public AMateria {
public:
    Cure();
    Cure(const Cure &other);
    Cure& operator=(const Cure &other);
    void* operator new(size_t size);
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif