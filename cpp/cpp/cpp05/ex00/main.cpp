/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:19:02 by akaddour          #+#    #+#             */
/*   Updated: 2024/10/02 14:36:08 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;

        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;

        john.incrementGrade();
        std::cout << "After another increment: " << john << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    
    try
    {
        Bureaucrat alice("Alice", 149);
        std::cout << alice << std::endl;

        alice.decrementGrade();
        std::cout << "After decrement: " << alice << std::endl;

        alice.decrementGrade();
        std::cout << "After another decrement: " << alice << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}