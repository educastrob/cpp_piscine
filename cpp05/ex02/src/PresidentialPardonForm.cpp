/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:20:35 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 19:20:44 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential pardon", "unknown", gradeToSign, gradeToExecute) {
    std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential pardon", target, gradeToSign, gradeToExecute) {
    std::cout << "PresidentialPardonForm target constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {
    std::cout << "PresidentialPardonForm copy constructor" << std::endl;
    *this = copy;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor" << std::endl;
}

// Operators
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assign) {
    AForm::operator=(assign);
    std::cout << "PresidentialPardonForm assignation operator" << std::endl;
    if (this == &assign) return *this;
    return *this;
}

// Member functions
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    this->checkCanExecute(executor);
    std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}