/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:21:22 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 19:21:28 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

// Exceptions
const char *ShrubberyCreationForm::FileAlreadyExistException::what() const throw() { return "File already exist"; }

const char *ShrubberyCreationForm::FailedToOpenException::what() const throw() { return "Failed to open file"; }

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery creation", "unknown", gradeToSign, gradeToExecute) {
    std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery creation", target, gradeToSign, gradeToExecute) {
    std::cout << "ShrubberyCreationForm target constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
    *this = copy;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

// Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign) {
    AForm::operator=(assign);
    std::cout << "ShrubberyCreationForm assignation operator" << std::endl;
    if (this == &assign) return *this;
    return *this;
}

// Member functions
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    this->checkCanExecute(executor);

    const std::string file_name = this->getTarget() + "_shrubberry";

    if (std::ifstream(file_name.c_str()))
        throw ShrubberyCreationForm::FileAlreadyExistException();

    std::ofstream out(file_name.c_str());
    if (!out)
        throw ShrubberyCreationForm::FailedToOpenException();

    out << SHRUBBERRY_TREE << std::endl;

    out.close();
}