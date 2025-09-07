/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:31:02 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/25 10:17:29 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++) {
        learned[i] = NULL;
    }
    // std::cout << "MateriaSource: Default Constructor called." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.learned[i])
            learned[i] = other.learned[i]->clone();
        else
            learned[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (learned[i])
            {
                delete learned[i];
                learned[i] = NULL;
            }
            if (other.learned[i])
            {
                learned[i] = other.learned[i]->clone();
                GB.list_remove(learned[i]);
            }
            else
                learned[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (learned[i])
        {
            delete learned[i];
            learned[i] = NULL;    
        }
    }
    // std::cout << "MateriaSource: Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (learned[i] == NULL)
            {
                learned[i] = m->clone();
                GB.list_remove(learned[i]);
                // std::cout << "MateriaSource: Learned Materia of type " << m->getType() << std::endl;
                return;
            }
        }
    }
    // std::cout << "MateriaSource: No more space to learn new Materia" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (type == "cure" || type == "ice")
    {
        for (int i = 0; i < 4; i++)
        {
            if (learned[i] && learned[i]->getType() == type)
                return (learned[i]->clone());
        }
    }
    return (NULL);
}