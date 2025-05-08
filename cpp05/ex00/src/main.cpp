/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:08:35 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 18:24:28 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main(void) {
    {
        std::cout << "============ Valid Bureaucrat Test ============" << std::endl;
        Bureaucrat bureaucrat = Bureaucrat("Eduardo", 1);

        std::cout << "Initial state: " << bureaucrat << std::endl
                  << std::endl;

        try {
            bureaucrat.incrementGrade();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << bureaucrat << std::endl
                  << std::endl;

        try {
            bureaucrat.decrementGrade();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << bureaucrat << std::endl
                  << std::endl;

        for (int i = 1; i < 150; i++) {
            try {
                bureaucrat.decrementGrade();
            } catch (std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }

        std::cout << bureaucrat << std::endl
                  << std::endl;
    }

    {
        std::cout << std::endl
                  << "============ Fail Bureaucrat Test ============" << std::endl;

        try {
            Bureaucrat("João", 150);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }

        try {
            Bureaucrat("João", 0);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }

        try {
            Bureaucrat("Ferrete", 151);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}