/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:22:59 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:23:00 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#include <iostream>

// Constructors
AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

// Operators
AAnimal &AAnimal::operator=(const AAnimal &assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign) {
        this->type = assign.type;
    }
    return *this;
}

// Getters
std::string AAnimal::getType() const { return type; }
