/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:08:35 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 19:20:21 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void shruberryTests();
void robotomyTests();
void presidentialTests();

int main(void) {
    shruberryTests();
    robotomyTests();
    presidentialTests();
}

void shruberryTests() {
    std::cout << "============ SHRUBBERY CREATION FORM TESTS ============" << std::endl;
    std::cout << std::endl
              << "=== LOW GRADE TO SIGN FORM ===" << std::endl;
    {
        AForm *form = new ShrubberyCreationForm("home");
        Bureaucrat bureaucrat("Tauros", 150);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);

        delete form;
    }

    std::cout << std::endl
              << "=== LOW GRADE TO EXECUTE FORM ===" << std::endl;
    {
        AForm *form = new ShrubberyCreationForm("home");
        Bureaucrat bureaucrat("Daron", 140);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);

        delete form;
    }

    std::cout << std::endl
              << "=== CREATING A SHRUBBERY CREATION FORM ==="
              << std::endl;
    {
        AForm *form = new ShrubberyCreationForm("home");
        Bureaucrat bureaucrat("Shavo", 130);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);

        delete form;
    }
}

void robotomyTests() {
    std::cout << std::endl
              << std::endl
              << "============ ROBOTOMY REQUEST FORM TESTS ============" << std::endl;
    std::cout << std::endl
              << "== LOW GRADE TO SIGN FORM ===" << std::endl;
    {
        AForm *form = new RobotomyRequestForm("home");
        Bureaucrat bureaucrat("Freddie", 73);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);

        delete form;
    }
    std::cout << std::endl
              << "=== LOW GRADE TO EXECUTE FORM ===" << std::endl;
    {
        AForm *form = new RobotomyRequestForm("home");
        Bureaucrat bureaucrat("Brian", 48);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);

        delete form;
    }
    std::cout << std::endl
              << "=== CREATING A ROBOTOMY REQUEST FORM ===" << std::endl;
    {
        AForm *form = new RobotomyRequestForm("Arthur");
        Bureaucrat bureaucrat("Roger", 42);
        Bureaucrat boss("Mike", 5);

        bureaucrat.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
}

void presidentialTests() {
    std::cout << std::endl
              << std::endl
              << "============ PRESIDENTIAL REQUEST FORM TESTS ============"
              << std::endl;
    std::cout << std::endl
              << "== LOW GRADE TO SIGN FORM ===" << std::endl;
    {
        AForm *form = new PresidentialPardonForm("Renato");
        Bureaucrat bureaucrat("Hermes", 73);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);

        delete form;
    }
    std::cout << std::endl
              << "=== LOW GRADE TO EXECUTE FORM ===" << std::endl;
    {
        AForm *form = new PresidentialPardonForm("pardon");
        Bureaucrat bureaucrat("Linus", 48);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);

        delete form;
    }
    std::cout << std::endl
              << "=== CREATING A PRESIDENTIAL REQUEST FORM ==="
              << std::endl;
    {
        AForm *form = new PresidentialPardonForm("James");
        Bureaucrat bureaucrat("Bjarne", 42);
        Bureaucrat boss("Stroustrup", 5);

        bureaucrat.signForm(*form);
        boss.executeForm(*form);

        delete form;
    }
}