/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:06:40 by educastro         #+#    #+#             */
/*   Updated: 2025/04/26 18:06:40 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap() {
    name = "ScavTrap";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

// Operators
ScavTrap &ScavTrap::operator=(const ScavTrap &assign) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(assign);
    return (*this);
}

// Member functions
void ScavTrap::attack(std::string const &target) {
    if (hitPoints == 0) {
        std::cout << "ScavTrap " << name << " already is dead!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ScavTrap " << name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}