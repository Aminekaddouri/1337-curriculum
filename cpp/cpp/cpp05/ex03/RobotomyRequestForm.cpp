/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:17:54 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/28 13:02:59 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target(target)
{
    std::srand(std::time(0)); // Seed random number generator
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Execute function: Simulate robotomization with 50% success rate
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    executeCheck(executor);

    std::cout << "BZZZZZZZZZZ... *drilling noises*" << std::endl;

    if (std::rand() % 2 == 0)
        std::cout << target << " has been successfully robotomized!" << std::endl;
    else
        std::cout << "The robotomy on " << target << " failed." << std::endl;
}