/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 03:18:42 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/08 05:32:03 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
    Zombie();
    ~Zombie();

    void setName(std::string name);
    void announce(void);
    
private:
    std::string _name;
    
};

Zombie* zombieHorde( int N, std::string name );

#endif
