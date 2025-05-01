/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:21:25 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:21:25 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

// Constructors
Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*copy.brain);
}

// Destructor
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

// Operators
Cat &Cat::operator=(const Cat &assign) {
    Animal::operator=(assign);
    if (this != &assign) {
        brain = new Brain(*assign.brain);
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

// Menber functions
void Cat::makeSound() const {
    std::cout << type << " say \"Meow Meow\"" << std::endl;
}
