/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 06:58:44 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/24 11:43:53 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "GarbageCollector.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];

public:
    Character();
    Character(std::string const &name);
    Character(const Character &other);
    Character& operator=(const Character &other);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& targer);
};

#endif