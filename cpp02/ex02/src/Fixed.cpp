/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:42:51 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/24 23:42:51 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed() { rawBits = 0; }

Fixed::Fixed(const Fixed &copy) { *this = copy; }

Fixed::Fixed(const int value) { rawBits = value << fractionalBits; }

Fixed::Fixed(const float value) {
    rawBits = roundf(value * (1 << fractionalBits));
}

// Destructor
Fixed::~Fixed() {}

// Operators
Fixed &Fixed::operator=(const Fixed &assign) {
    rawBits = assign.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &other) const {
    return (rawBits > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const {
    return (rawBits < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const {
    return (rawBits >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const {
    return (rawBits <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const {
    return (rawBits == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const {
    return (rawBits != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const {
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const {
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const {
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const {
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++(void) {
    rawBits++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed &Fixed::operator--(void) {
    rawBits--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b) return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b) return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b) return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b) return a;
    return b;
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
