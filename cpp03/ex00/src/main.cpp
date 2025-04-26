/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:44:49 by educastro         #+#    #+#             */
/*   Updated: 2025/04/26 15:44:56 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    std::cout << "--------------- Constructor calls ---------------" << std::endl;
    ClapTrap goodTrap("good");
    ClapTrap badTrap("bad");
    std::cout << std::endl;

    std::cout << "--------------- Start battle ---------------" << std::endl;
    goodTrap.beRepaired(10);
    badTrap.attack(goodTrap.getName());
    goodTrap.takeDamage(badTrap.getAttackDamage());
    goodTrap.attack(badTrap.getName());
    badTrap.takeDamage(goodTrap.getAttackDamage());

    std::cout << std::endl
              << "--------------- Combo attack ---------------" << std::endl;
    for (int i = 0; i < 10; i++)
        badTrap.attack(goodTrap.getName());
    std::cout << "The good ClapTrap won because the bad ClapTrap is hasty!" << std::endl;

    std::cout << std::endl
              << "--------------- Destructor calls ---------------" << std::endl;
}