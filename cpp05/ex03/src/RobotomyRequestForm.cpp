/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:21:00 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 19:21:09 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy request", "unknown", gradeToSign, gradeToExecute) {
    std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request", target, gradeToSign, gradeToExecute) {
    std::cout << "RobotomyRequestForm target constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
    *this = copy;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor" << std::endl;
}

// Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign) {
    AForm::operator=(assign);
    std::cout << "RobotomyRequestForm assignation operator" << std::endl;
    if (this == &assign) return *this;
    return *this;
}

// Member functions
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    this->checkCanExecute(executor);

    std::cout << "Whirrr...zzzz...clink...zzzz...whirrr..." << std::endl;

    std::srand(std::time(0));
    if (std::rand() % 2 == 0) {
        std::cout << "Hey hey, look! " << this->getTarget()
                  << " was sucessfully robotomized"
                  << std::endl;
    } else {
        std::cout << "Oh no... " << this->getTarget() << " robotomization failed"
                  << std::endl;
    }
}