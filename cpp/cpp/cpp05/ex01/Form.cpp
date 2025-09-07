/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:44:31 by akaddour          #+#    #+#             */
/*   Updated: 2024/10/02 14:43:03 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : gradeToSign(1), gradeToExecute(1)
{
    this->isSigned = false;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooHighException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned),
    gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const
{
    return (name);
}

bool Form::getIsSigned() const
{
    return (isSigned);
}

int Form::getGradeToSign() const
{
    return (gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (!this->isSigned)
    {
        if (bureaucrat.getGrade() <= this->gradeToSign)
        {
            this->isSigned = true;
            std::cout << this->name << " signed by: " << bureaucrat.getName() << " with grade: " << bureaucrat.getGrade() << "." << std::endl;
        }
        else
            throw GradeTooLowException();
    }
    else
        std::cout << this->name << " Form already signed." << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!"; 
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form '" << form.getName() << "' [signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute() << "]";
    return (os);
}