/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:23:43 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:23:43 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

// Constructors
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

// Operators
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign) {
        this->type = assign.type;
    }
    return *this;
}

// Getters
std::string WrongAnimal::getType() const { return type; }

// Menber functions
void WrongAnimal::makeSound() const {
    std::cout << type << " don't know how sound make" << std::endl;
}
