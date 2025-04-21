/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:43:09 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 19:43:18 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() { return; }

Harl::~Harl() { return; }

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*methods[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (size_t i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*methods[i])();
            return;
        }
    }

    std::cout << WHITE << "Harl has complained too much, he doesn't know how to complain in level " << level << "." << RESET << std::endl;
}

void Harl::debug(void) {
    std::cout << BLUE << "[ DEBUG ]" << RESET << std::endl;
    std::cout << BLUE << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << RESET << std::endl;
    std::cout << std::endl;
}

void Harl::info(void) {
    std::cout << GREEN << "[ INFO ]" << RESET << std::endl;
    std::cout << GREEN << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << RESET << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void) {
    std::cout << YELLOW << "[ WARNING ]" << RESET << std::endl;
    std::cout << YELLOW << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << RESET << std::endl;
    std::cout << std::endl;
}

void Harl::error(void) {
    std::cout << RED << "[ ERROR ]" << RESET << std::endl;
    std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
    std::cout << std::endl;
}