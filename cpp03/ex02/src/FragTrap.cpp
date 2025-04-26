/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:26:46 by educastro         #+#    #+#             */
/*   Updated: 2025/04/26 18:26:59 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap() {
    name = "FragTrap";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

// Destructor
FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

// Operators
FragTrap &FragTrap::operator=(const FragTrap &assign) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    ClapTrap::operator=(assign);
    return (*this);
}

// Member functions
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " says: \"High five, guys!\"" << std::endl;
}