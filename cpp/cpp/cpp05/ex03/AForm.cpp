/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:44:31 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/28 16:29:13 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : gradeToSign(1), gradeToExecute(1)
{
    this->isSigned = false;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
    return (name);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (!this->isSigned)
    {
        if (bureaucrat.getGrade() <= this->gradeToSign)
            this->isSigned = true;
        else
        {
            std::cout << "here\n";
            throw GradeTooLowException();
        }
    }
    else
        std::cout << this->name << " Form already signed." << std::endl;
}

void AForm::executeCheck(const Bureaucrat& executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!"; 
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form '" << form.getName() << "' [signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute() << "]";
    return (os);
}