/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:08:33 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 18:12:37 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// Constructors
Bureaucrat::Bureaucrat() : name("default"), grade(Bureaucrat::minGrade) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned char grade) : name(name) {
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade > Bureaucrat::minGrade) {
        throw GradeTooLowException();
    } else if (grade < Bureaucrat::maxGrade) {
        throw GradeTooHighException();
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor called" << std::endl; }

// Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign) {
        (std::string) this->name = assign.getName();
        this->grade = assign.getGrade();
    }
    return *this;
}

// Getters
std::string Bureaucrat::getName() const { return name; }

unsigned char Bureaucrat::getGrade() const { return grade; }

// Menber functions
void Bureaucrat::incrementGrade() {
    if (grade == Bureaucrat::maxGrade) {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade == Bureaucrat::minGrade) {
        throw GradeTooLowException();
    }
    grade++;
}

// Non-member functions
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << "Bureaucrat " << bureaucrat.getName() << ", grade " << static_cast<int>(bureaucrat.getGrade()) << ".";
    return out;
}