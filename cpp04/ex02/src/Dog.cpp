/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:23:34 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:23:35 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

// Constructors
Dog::Dog() : AAnimal() {
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal(copy) {
    *this = copy;
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*copy.brain);
}

// Destructor
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

// Operators
Dog &Dog::operator=(const Dog &assign) {
    AAnimal::operator=(assign);
    if (this != &assign) {
        brain = new Brain(*assign.brain);
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

// Menber functions
void Dog::makeSound() const {
    std::cout << type << " say \"Woof Woof\"" << std::endl;
}
