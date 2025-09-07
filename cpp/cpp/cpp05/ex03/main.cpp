/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:19:02 by akaddour          #+#    #+#             */
/*   Updated: 2024/10/02 15:00:15 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat john("John", 4);
        AForm* form;

        // Intern creates a robotomy request form
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        john.signForm(*form);
        john.executeForm(*form);
        if (form) {
            std::cout << *form << std::endl;
            delete form; // Don't forget to delete dynamically allocated memory
        }

        // // // Intern creates a shrubbery creation form
        // form = someRandomIntern.makeForm("shrubbery creation", "Garden");
        // if (form) {
        //     std::cout << *form << std::endl;
        //     delete form;
        // }

        // // // Intern creates a presidential pardon form
        // form = someRandomIntern.makeForm("presidential pardon", "Alice");
        // // form->beSigned(john);
        // // form->execute(john);
        // if (form) {
        //     std::cout << *form << std::endl;
        //     delete form;
        // }

        // // // // Trying to create an unknown form
        // form = someRandomIntern.makeForm("unknown form", "Test");
        // if (form) {
        //     delete form;
        // }
        
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}