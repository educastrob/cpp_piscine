/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:21:21 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:21:21 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>
#include <sstream>

// Constructors
Brain::Brain(void) {
    std::cout << "Brain default constructor called" << std::endl;
    std::stringstream ss;
    for (int i = 0; i < 100; i++) {
        ss << i;
        ideas[i] = "Idea #" + ss.str();
    }
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
Brain::~Brain(void) { std::cout << "Brain destructor called" << std::endl; }

// Operators
Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) ideas[i] = other.ideas[i];
    }
    return (*this);
}
