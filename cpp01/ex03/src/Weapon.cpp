/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:16:36 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 18:55:13 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	this->type = "default type";
}

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon() {
	std::cout << "Weapon destroyed" << std::endl;
}

const std::string& Weapon::getType(void) const {
	return type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}