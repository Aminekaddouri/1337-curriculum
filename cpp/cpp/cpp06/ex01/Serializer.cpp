/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:16:36 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/30 23:56:40 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other)
{
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
	if (!ptr)
		return (0);
	uintptr_t numPtr = reinterpret_cast<uintptr_t>(ptr);
	return (numPtr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	if (!raw)
		return (NULL);
	Data *data = reinterpret_cast<Data *>(raw);
	return (data);
}