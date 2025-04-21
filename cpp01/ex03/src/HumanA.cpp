/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:19:36 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 18:54:25 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon& weapon) : name(name), weapon(weapon) {
    return;
}

HumanA::~HumanA() {
    std::cout << "HumanA " << this->name << " destroyed" << std::endl;
}

void HumanA::attack() {
    std::cout << this->name << " attacks with their " << this->weapon.getType()
              << std::endl;
}