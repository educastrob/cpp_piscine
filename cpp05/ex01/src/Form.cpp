/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:31:53 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 18:51:41 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Exceptions
const char *Form::GradeTooHighException::what() const throw() {
    return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "grade is too low";
}

const char *Form::FormAlreadySignException::what() const throw() {
    return "form already sign";
}

// Constructors
Form::Form() : name("default"), isSigned(false), gradeToSign(Form::minGrade), gradeToExecute(Form::minGrade) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, unsigned char gradeToSign, unsigned char gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    std::cout << "Form constructor called" << std::endl;
    if (gradeToSign > Form::minGrade || gradeToExecute > Form::minGrade) {
        throw Form::GradeTooLowException();
    }
    if (gradeToSign < Form::maxGrade || gradeToExecute < Form::maxGrade) {
        throw Form::GradeTooHighException();
    }
}

Form::Form(const Form &copy) : name(copy.getName()), gradeToSign(copy.getGradeToSign()), gradeToExecute(copy.getGradeToExecute()) {
    std::cout << "Form copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
Form::~Form() { std::cout << "Form destructor called" << std::endl; }

// Operators
Form &Form::operator=(const Form &assign) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &assign) {
        (std::string &)this->name = assign.getName();
        this->isSigned = assign.getIsSigned();
        (int &)this->gradeToSign = assign.getGradeToSign();
        (int &)this->gradeToExecute = assign.getGradeToExecute();
    }
    return *this;
}

// Getters
std::string Form::getName() const { return name; }

bool Form::getIsSigned() const { return isSigned; }

unsigned char Form::getGradeToSign() const { return gradeToSign; }

unsigned char Form::getGradeToExecute() const { return gradeToExecute; }

// Menber functions
void Form::beSigned(Bureaucrat &bureaucrat) {
    if (isSigned) {
        throw Form::FormAlreadySignException();
    }
    if (bureaucrat.getGrade() > gradeToSign) {
        throw Form::GradeTooLowException();
    }
    isSigned = true;
}

// Non-member functions
std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName()
        << ", is " << (form.getIsSigned() ? "signed" : "unsigned")
        << " require this grade to sign " << static_cast<int>(form.getGradeToSign())
        << " and this grade to execute: " << static_cast<int>(form.getGradeToExecute());
    return out;
}