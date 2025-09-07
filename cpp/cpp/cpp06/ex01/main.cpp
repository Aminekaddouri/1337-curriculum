/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:19:53 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/30 23:59:07 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Serializer instence;
    
    Data *data = new Data;
    data->id = 1337;
    data->name = "school";

    std::cout << "original Data: " << std::endl;
    std::cout << "ID: " << data->id << std::endl;
    std::cout << "Name: " << data->name << std::endl;

    uintptr_t serialized = instence.serialize(data);


    Data* deserializedData = instence.deserialize(serialized);

    std::cout << "\nDeserialized Data: " << std::endl;
    std::cout << "ID: " << deserializedData->id << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;

    if (deserializedData == data) {
        std::cout << "\nSuccess: The deserialized pointer matches the original pointer!" << std::endl;
    } else {
        std::cout << "\nError: The deserialized pointer does not match the original pointer!" << std::endl;
    }


    return (0);
}