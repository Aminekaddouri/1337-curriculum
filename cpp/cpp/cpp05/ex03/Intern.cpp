/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:03:59 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/28 16:33:34 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[3] =
    {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i])
        {
            std::cout << "Intern creates " << formName << "." << std::endl;
            for (int j = i + 1; j < 3; j++)
                delete forms[j];
            return (forms[i]);
        }
        delete forms[i];
    }
    std::cout << "Intern: Form type \"" << formName << "\" is unknown." << std::endl;
    return NULL;
}