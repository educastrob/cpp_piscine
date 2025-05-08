/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:31:53 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 19:19:50 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

// Exceptions
const char *AForm::GradeTooHighException::what() const throw() {
    return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "grade is too low";
}

const char *AForm::FormAlreadySignException::what() const throw() {
    return "form already sign";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

// Constructors
AForm::AForm() : name("default"), isSigned(false), gradeToSign(AForm::minGrade), gradeToExecute(AForm::minGrade) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, std::string target, unsigned char gradeToSign, unsigned char gradeToExecute) : name(name), target(target), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "AForm constructor called" << std::endl;
    if (gradeToSign > AForm::minGrade || gradeToExecute > AForm::minGrade) {
        throw AForm::GradeTooLowException();
    }
    if (gradeToSign < AForm::maxGrade || gradeToExecute < AForm::maxGrade) {
        throw AForm::GradeTooHighException();
    }
}

AForm::AForm(const AForm &copy) : name(copy.getName()), gradeToSign(copy.getGradeToSign()), gradeToExecute(copy.getGradeToExecute()) {
    std::cout << "AForm copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
AForm::~AForm() { std::cout << "AForm destructor called" << std::endl; }

// Operators
AForm &AForm::operator=(const AForm &assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign) {
        (std::string &)this->name = assign.getName();
        (std::string &)this->target = assign.getTarget();
        this->isSigned = assign.getIsSigned();
        (int &)this->gradeToSign = assign.getGradeToSign();
        (int &)this->gradeToExecute = assign.getGradeToExecute();
    }
    return *this;
}

// Getters
std::string AForm::getName() const { return name; }

std::string AForm::getTarget() const { return target; }

bool AForm::getIsSigned() const { return isSigned; }

unsigned char AForm::getGradeToSign() const { return gradeToSign; }

unsigned char AForm::getGradeToExecute() const { return gradeToExecute; }

// Menber functions
void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (isSigned) {
        throw AForm::FormAlreadySignException();
    }
    if (bureaucrat.getGrade() > gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    isSigned = true;
}

void AForm::checkCanExecute(Bureaucrat const &executor) const {
    if (executor.getGrade() > gradeToExecute) {
        throw AForm::GradeTooLowException();
    }
    if (!isSigned) {
        throw AForm::FormNotSignedException();
    }
}

// Non-member functions
std::ostream &operator<<(std::ostream &out, const AForm &Aform) {
    out << "Form " << Aform.getName()
        << ", is " << (Aform.getIsSigned() ? "signed" : "unsigned")
        << " require this grade to sign " << static_cast<int>(Aform.getGradeToSign())
        << " and this grade to execute: " << static_cast<int>(Aform.getGradeToExecute());
    return out;
}