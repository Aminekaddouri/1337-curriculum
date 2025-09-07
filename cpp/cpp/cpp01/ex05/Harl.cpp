/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:58:20 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/09 00:43:33 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::debug(void) {
	std::cout << "DEBUG: I love having extra bacon for my burger!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money!" << std::endl; 
}

void	Harl::warning(void) {
	std::cout << "WARNING: I think I deserve some extra bacon for free!" << std::endl;
}

void	Harl::error(void) {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now!" << std::endl;
}

void Harl::complain(std::string level) 
{
	void (Harl::*functions[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "Error: '" << level << "' is not a valid level." << std::endl;
	std::cout << "Please enter one of the following levels: DEBUG, INFO, WARNING, ERROR." << std::endl;
}
