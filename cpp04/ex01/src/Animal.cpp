/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:21:13 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:21:14 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

// Constructors
Animal::Animal() : type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

// Operators
Animal &Animal::operator=(const Animal &assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign) {
        this->type = assign.type;
    }
    return *this;
}

// Getters
std::string Animal::getType() const { return type; }

// Menber functions
void Animal::makeSound() const {
    std::cout << type << " don't know how sound make" << std::endl;
}
