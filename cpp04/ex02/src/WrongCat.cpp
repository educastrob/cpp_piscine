/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:23:47 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:23:47 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

// Constructors
WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat default constructor called" << std::endl;
    type = "Cat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

// Destructor
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

// Operators
WrongCat &WrongCat::operator=(const WrongCat &assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    WrongAnimal::operator=(assign);
    return *this;
}

// Getters
std::string WrongCat::getType() const { return type; }

// Menber functions
void WrongCat::makeSound() const {
    std::cout << type << " say \"Meow Meow\"" << std::endl;
}
