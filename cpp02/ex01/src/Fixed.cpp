/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:43:07 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/24 23:43:08 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    rawBits = 0;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    rawBits = value << fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    rawBits = roundf(value * (1 << fractionalBits));
}

// Destructor
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

// Operators
Fixed &Fixed::operator=(const Fixed &assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign) {
        rawBits = assign.getRawBits();
    }
    return *this;
}

// Getters / Setters
int Fixed::getRawBits() const { return rawBits; }

void Fixed::setRawBits(int const raw) { rawBits = raw; }

// Conversion functions
float Fixed::toFloat(void) const {
    return ((float)rawBits / (float)(1 << fractionalBits));
}

int Fixed::toInt(void) const { return (rawBits >> fractionalBits); }

// Non-member function
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return (out);
}
