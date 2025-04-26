/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:03:04 by educastro         #+#    #+#             */
/*   Updated: 2025/04/26 18:05:24 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
   public:
    // Constructors
    ScavTrap();
    ScavTrap(const ScavTrap &copy);
    ScavTrap(const std::string name);

    // Destructor
    ~ScavTrap();

    // Operators
    ScavTrap &operator=(const ScavTrap &assign);

    // Menber functions
    void attack(std::string const &target);
    void guardGate();
};

#endif  // SCAVTRAP_HPP