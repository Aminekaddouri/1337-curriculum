/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GarbageCollector.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:30:01 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/25 09:55:11 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GarbageCollector.hpp"
GarbageCollector::GarbageCollector()
{
    this->head = NULL;
}

t_Node* GarbageCollector::list_new(void *tmp)
{
    t_Node *node;
    
    node = new(t_Node);
    node->data = tmp;
    node->next = NULL;
    return (node);
}

void GarbageCollector::list_add(t_Node *node)
{
    if (node)
    {
        node->next = this->head;
        this->head = node;
    }
}

void    GarbageCollector::list_remove(void *tmp)
{
    t_Node *tmpNode;

    if (this->head->data == tmp)
    {
        tmpNode = this->head;
        this->head = this->head->next;
        delete tmpNode;
    }
    else
    {
        t_Node *newTmp = this->head;
        while (newTmp)
        {
            if (newTmp->data == tmp)
            {
                tmpNode = newTmp;
                newTmp = newTmp->next;
                delete tmpNode;
                break ;
            }
            newTmp = newTmp->next;
        }
    }
}

bool GarbageCollector::list_check(void *tmp)
{
    t_Node *tmplist = this->head;
    while (tmplist)
    {
        if (tmplist->data == tmp)
            return (1);
        tmplist = tmplist->next;
    }
    return (0);
}

GarbageCollector::~GarbageCollector()
{
    if (this->head)
    {
        t_Node *tmp;
        while (this->head)
        {
            tmp = this->head;
            this->head = this->head->next;
            ::operator delete(tmp->data);
            delete tmp;
        }
    }
}

GarbageCollector GB;
