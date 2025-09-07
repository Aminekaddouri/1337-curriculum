/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 01:14:43 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/08 06:41:02 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log level>" << std::endl;
        return (1);
    }

    Harl harl;
    std::string level = argv[1];
    harl.complain(level);
    return 0;
}