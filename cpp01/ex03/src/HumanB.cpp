/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:25:22 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 18:54:07 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : name(name) {
    this->weapon = NULL;
    return;
}

HumanB::~HumanB() {
    std::cout << "HumanB " << this->name << " destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon; 
}

void HumanB::attack() {
    if (this->weapon == NULL) {
        std::cout << this->name << " has no weapon to attack with" << std::endl;
        return;
    }

    std::cout << this->name << " attacks with their " << this->weapon->getType()
              << std::endl;
}