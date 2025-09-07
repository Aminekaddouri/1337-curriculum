/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:19:02 by akaddour          #+#    #+#             */
/*   Updated: 2024/10/02 14:52:14 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat john("John", 40);
        Bureaucrat sarah("Sarah", 3); // Higher grade bureaucrat for executing high-level forms

        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("Bender");
        PresidentialPardonForm pardonForm("Alice");

        // std::cout << shrubberyForm << std::endl;
        // john.signForm(shrubberyForm);
        // john.executeForm(shrubberyForm);

        std::cout << robotomyForm << std::endl;
        john.signForm(robotomyForm);
        john.executeForm(robotomyForm);

        // std::cout << pardonForm << std::endl;
        // sarah.signForm(pardonForm);
        // sarah.executeForm(pardonForm); // Sarah has a high enough grade to execute this form
        
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}