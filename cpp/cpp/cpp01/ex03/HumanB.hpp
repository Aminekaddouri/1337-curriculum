/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 04:00:38 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/08 22:59:30 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
    std::string _name;
    Weapon* weapon;

public:
    HumanB(std::string name);
    void setWeapon(Weapon &weapon);
    void attack(void) const;
};

#endif