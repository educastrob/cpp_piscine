/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:40:59 by educastro         #+#    #+#             */
/*   Updated: 2025/06/02 14:43:57 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Exceptions
const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}

// Constructors
Intern::Intern() {
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &copy) {
    std::cout << "Intern copy constructor" << std::endl;
    *this = copy;
}

// Destructor
Intern::~Intern() {
    std::cout << "Intern destructor" << std::endl;
}

// Operators
Intern &Intern::operator=(const Intern &assign) {
    std::cout << "Intern assignation operator" << std::endl;
    if (this == &assign) return *this;
    return *this;
}

// Member functions
AForm *Intern::makeForm(std::string formName, std::string target) {
    int nameIndex = -1;
    AForm *form = NULL;
    std::string names[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            nameIndex = i;
            break;
        }
    }

    switch (nameIndex) {
        case 0:
            form = new RobotomyRequestForm(target);
            break;
        case 1:
            form = new ShrubberyCreationForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::FormNotFoundException();
    }

    std::cout << "Intern creates " << *form << std::endl;
    return form;
}