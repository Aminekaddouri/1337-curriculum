/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 02:27:42 by akaddour          #+#    #+#             */
/*   Updated: 2024/10/01 02:33:01 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base* base = generate();

    std::cout << "Identifying by pointer: ";
    identify(base);

    std::cout << "Identifying by reference: ";
    identify(*base);

    delete base;
    return (0);
}