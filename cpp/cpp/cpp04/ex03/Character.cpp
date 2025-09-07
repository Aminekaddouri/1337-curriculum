/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:03:52 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/25 10:16:30 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Default") {
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
    // std::cout << "Character " << name << " created (Default constructor)." << std::endl;
}

Character::Character(std::string const & name) : name(name) {
    for(int i = 0; i < 4; i++)
        inventory[i] = NULL;
    // std::cout << "Character " << name << " created (Param constructor)." << std::endl;
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
            {
                delete inventory[i];
                inventory[i] = NULL;
            }
            if (other.inventory[i])
            {
                inventory[i] = other.inventory[i]->clone();
                GB.list_remove(inventory[i]);   
            }
            else
                inventory[i] = NULL;    
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
    // std::cout << "Character " << name << " destroyed." << std::endl;
}

std::string const &Character::getName() const {
    return (name);
}

void Character::equip(AMateria* m) {
    if (GB.list_check(m))
    {
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i] == NULL)
            {
                inventory[i] = m;
                GB.list_remove(m);
                // std::cout << "Character " << this->name << " equipped with " << m->getType() << std::endl;
                return ;
            }
        }
        // std::cout << "Character " << this->name << " can't equip " << m->getType() << std::endl;
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        GB.list_add(GB.list_new(this->inventory[idx]));
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}