/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:09:52 by educastro         #+#    #+#             */
/*   Updated: 2025/06/22 21:49:56 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <iostream>


// Constructors
Span::Span() : size(0) {}

Span::Span(unsigned int N) : size(N) {
    numbers.reserve(N);
}

Span::Span(const Span &copy) {
    *this = copy;
}

// Destructor
Span::~Span() {}

// Operators
Span &Span::operator=(const Span &assign) {
    if (this == &assign) return *this;

    this->numbers = assign.numbers;
    this->size = assign.size;

    return *this;
}

// Member functions
void Span::addNumber(int number) {
    if (this->numbers.size() >= this->size) {
        throw std::overflow_error("Not enough space in Span");
    }
    this->numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (this->numbers.size() <= 1) {
        throw std::runtime_error("Not enough numbers in Span");
    }

    std::vector<int> sorted = this->numbers;
    std::sort(sorted.begin(), sorted.end());

    int shortest = sorted[1] - sorted[0];
    int current;

    for (size_t i = 1; i < sorted.size() - 1; i++) {
        current = sorted[i + 1] - sorted[i];

        if (current == 0) {
            return 0;
        }
        if (current < shortest) {
            shortest = current;
        }
    }

    return shortest;
}

int Span::longestSpan() const {
    if (this->numbers.size() <= 1) {
        throw std::runtime_error("Not enough numbers in Span");
    }

    std::vector<int>::const_iterator minIt = std::min_element(this->numbers.begin(), this->numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(this->numbers.begin(), this->numbers.end());

    return *maxIt - *minIt;
}

void Span::addRange(int values[], unsigned int size) {
    try {
        for (size_t i = 0; i < size; i++)
            addNumber(values[i]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}