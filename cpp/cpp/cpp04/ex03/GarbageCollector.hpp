/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GarbageCollector.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:24:24 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/25 09:45:41 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGECOLLECTOR_HPP
#define GARBAGECOLLECTOR_HPP

#include <iostream>

typedef struct s_Node
{
    void *data;
    struct s_Node *next;    
}   t_Node;

class GarbageCollector 
{
private:
    t_Node *head;
public:
    GarbageCollector();
    ~GarbageCollector();
    void list_add(t_Node *node);
    void list_remove(void *data);
    bool list_check(void *data);
    t_Node* list_new(void *data);
};

extern GarbageCollector GB;

#endif