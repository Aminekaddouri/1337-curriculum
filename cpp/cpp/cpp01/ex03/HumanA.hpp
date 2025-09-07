/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 03:58:56 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/08 05:41:48 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
    std::string _name;
    Weapon& weapon;  // Reference to the weapon

public:
    HumanA(std::string name, Weapon &weapon);
    void attack(void) const;
};

#endif