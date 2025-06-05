/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:53:13 by educastro         #+#    #+#             */
/*   Updated: 2025/06/04 20:56:35 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

// Constructors
Serializer::Serializer() {
}

Serializer::Serializer(const Serializer &copy) {
    *this = copy;
}

// Destructor
Serializer::~Serializer() {
}

// Operators
Serializer &Serializer::operator=(const Serializer &assign) {
    (void)assign;
    return *this;
}

// Member functions
uintptr_t Serializer::serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}