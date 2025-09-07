/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:00:39 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/15 06:24:21 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string	type;

public:
	Animal();
	Animal(const Animal &other);
	Animal& operator=(const Animal &other);
	virtual ~Animal();

	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif