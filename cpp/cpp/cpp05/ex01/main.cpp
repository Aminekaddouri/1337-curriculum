/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:19:02 by akaddour          #+#    #+#             */
/*   Updated: 2024/10/02 14:41:42 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 50);

        Form taxForm("Tax Form", 45, 30);
        std::cout << taxForm << std::endl;

        // john will not sign the form here
        john.signForm(taxForm);
        std::cout << taxForm << std::endl;

        std::cout << "----------------------------" << std::endl;

        // boss will sign the form here
        Bureaucrat boss("Boss", 40);
        boss.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}