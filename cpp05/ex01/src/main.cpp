/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:08:35 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 18:58:08 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << std::endl
              << "============ Form and Bureaucrat Tests ============" << std::endl;

    try {
        Form form("Application Form", 50, 25);
        Bureaucrat bureaucrat("John", 55);

        std::cout << std::endl
                  << "Form details:" << std::endl;
        std::cout << form << std::endl;

        std::cout << std::endl
                  << "Attempting to sign the form:" << std::endl;
        bureaucrat.signForm(form);

        std::cout << std::endl
                  << "Form details after signing:" << std::endl;
        std::cout << form << std::endl;

    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "======================================================" << std::endl;
        Form form2("Application Form", 50, 25);
        Bureaucrat bureaucrat("Michel", 45);

        std::cout << std::endl
                  << "Form details:" << std::endl;
        std::cout << form2 << std::endl;

        std::cout << std::endl
                  << "Sign the form:" << std::endl;
        bureaucrat.signForm(form2);

        std::cout << std::endl
                  << "Sign twice the form:" << std::endl;
        bureaucrat.signForm(form2);

    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "======================================================" << std::endl;
        Form form3("Approval Form", 5, 10);
        Bureaucrat bureaucrat2("Alice", 2);

        std::cout << std::endl
                  << "Form details:" << std::endl;
        std::cout << form3 << std::endl;

        std::cout << std::endl
                  << "Attempting to sign the form:" << std::endl;
        bureaucrat2.signForm(form3);

        std::cout << std::endl
                  << "Form details after signing:" << std::endl;
        std::cout << form3 << std::endl;

    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl
              << std::endl
              << "============ Testing validation and GradeTooHighException ============" << std::endl;
    try {
        std::cout << std::endl
                  << "Attempting to create a form with invalid grade:" << std::endl;
        Form invalidForm("Invalid Form", 0, -2);

    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}