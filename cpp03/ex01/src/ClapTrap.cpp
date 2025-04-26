/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:05:45 by educastro         #+#    #+#             */
/*   Updated: 2025/04/26 18:05:45 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() : name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor called" << std::endl; }

// Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &assign) {
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &assign) {
        this->name = assign.name;
        this->hitPoints = assign.hitPoints;
        this->energyPoints = assign.energyPoints;
        this->attackDamage = assign.attackDamage;
    }
    return *this;
}

// Getters / Setters
std::string ClapTrap::getName() const {
    return (name);
}

unsigned int ClapTrap::getAttackDamage() const {
    return (attackDamage);
}

// Menber functions
void ClapTrap::attack(const std::string &target) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " already is dead!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= amount) {
        std::cout << "ClapTrap " << name << " is dead!" << std::endl;
        hitPoints = 0;
        return;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " already is dead!" << std::endl;
        return;
    }
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points!" << std::endl;
    hitPoints += amount;
    energyPoints--;
}