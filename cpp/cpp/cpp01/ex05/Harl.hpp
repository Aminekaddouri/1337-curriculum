/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:56:51 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/09 00:43:32 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{

private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    Harl();
    ~Harl();
    void complain( std::string level );
  
};

#endif