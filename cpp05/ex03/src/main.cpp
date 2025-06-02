/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:08:35 by educastro         #+#    #+#             */
/*   Updated: 2025/06/02 14:40:49 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm *tmp;

    std::cout << std::endl
              << "============ ROBOTOMY REQUEST ============" << std::endl;
    try {
        tmp = someRandomIntern.makeForm("robotomy request", "Bender");
        if (tmp) {
            std::cout << "Form created successfully!" << std::endl;
            delete tmp;
        }
    } catch (Intern::FormNotFoundException &e) {
        std::cout << "Form not found!" << std::endl;
    }

    std::cout << std::endl
              << "============ SHRUBBERY CREATION ============" << std::endl;
    try {
        tmp = someRandomIntern.makeForm("shrubbery creation", "Downtown");
        if (tmp) {
            std::cout << "Form created successfully!" << std::endl;
            delete tmp;
        }
    } catch (Intern::FormNotFoundException &e) {
        std::cout << "Form not found!" << std::endl;
    }

    std::cout << std::endl
              << "============ PRESIDENTIAL PARDON ============" << std::endl;
    try {
        tmp = someRandomIntern.makeForm("presidential pardon", "corrupt politician");
        if (tmp) {
            std::cout << "Form created successfully!" << std::endl;
            delete tmp;
        }
    } catch (Intern::FormNotFoundException &e) {
        std::cout << "Form not found!" << std::endl;
    }

    std::cout << std::endl
              << "============ TAX EXEMPTION ============" << std::endl;
    try {
        tmp = someRandomIntern.makeForm("tax exemption", "Bruno Moretti");
        if (tmp) {
            std::cout << "Form created successfully!" << std::endl;
            delete tmp;
        }
    } catch (Intern::FormNotFoundException &e) {
        std::cout << "Form not found!" << std::endl;
    }
}