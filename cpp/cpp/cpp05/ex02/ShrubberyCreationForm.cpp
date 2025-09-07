/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:06:57 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/28 12:55:03 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    executeCheck(executor);

    std::ofstream file((target + "_shrubbery").c_str());
    if (file.is_open())
    {
         file << "      _-_      \n"
             << "   /~~   ~~\\   \n"
             << " /~~       ~~\\ \n"
             << "{             }\n"
             << " \\  _-     -_/ \n"
             << "   ~  \\\\ //  ~ \n"
             << "      | |      \n"
             << "      | |      \n"
             << "      []       \n";
        file.close();
    }
    else
    {
        std::cout << "Failed to open the file." << std::endl;
    }
}