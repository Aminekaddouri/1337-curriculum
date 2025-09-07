/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 06:28:20 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/23 08:53:09 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* j = new Dog();
    j->makeSound();
    const Animal* i = new Cat();
    i->makeSound();

    delete j;
    delete i;

    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    animals[0]->makeSound();

    for (int k = 0; k < 4; ++k) {
        delete animals[k];  
    }

    return 0;
}


