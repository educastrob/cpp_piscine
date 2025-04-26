/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:03:08 by educastro         #+#    #+#             */
/*   Updated: 2025/04/26 18:06:26 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "--------------- Constructor calls ---------------" << std::endl;
    ScavTrap scav("Scaven");
    std::cout << std::endl;

    std::cout << "--------------- Unmodified functions calls ---------------" << std::endl;
    scav.takeDamage(10);
    scav.beRepaired(10);
    std::cout << std::endl;

    std::cout << "--------------- Modified functions calls ---------------" << std::endl;
    scav.attack("enemy");
    scav.guardGate();
    std::cout << std::endl;

    std::cout << "--------------- Operator overloads ---------------" << std::endl;
    ScavTrap scav2;
    scav2 = scav;
    scav2.attack("another enemy");
    std::cout << std::endl;

    std::cout << "--------------- Copy constructor ---------------" << std::endl;
    ScavTrap scav3(scav2);
    scav3.attack("another another enemy");
    std::cout << std::endl;

    std::cout << "--------------- Destructor calls ---------------" << std::endl;
}