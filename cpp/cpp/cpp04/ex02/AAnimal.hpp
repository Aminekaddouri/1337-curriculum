/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:00:39 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/16 23:36:17 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    virtual ~AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif
