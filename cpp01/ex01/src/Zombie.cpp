/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:24:00 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 17:47:38 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::Zombie() {
	this->_name = "";
}

Zombie::~Zombie() {
	std::cout << this->_name << " is dead." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}