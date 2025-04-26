/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:27:09 by educastro         #+#    #+#             */
/*   Updated: 2025/04/26 18:27:11 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "--------------- Constructor calls ---------------" << std::endl;
    FragTrap frag("Fragility");
    std::cout << std::endl;

    std::cout << "--------------- Unmodified functions calls ---------------" << std::endl;
    frag.takeDamage(10);
    frag.beRepaired(10);
    frag.attack("enemy");
    std::cout << std::endl;

    std::cout << "--------------- Modified functions calls ---------------" << std::endl;
    frag.highFivesGuys();
    std::cout << std::endl;

    std::cout << "--------------- Operator overloads ---------------" << std::endl;
    FragTrap frag2;
    frag2 = frag;
    frag2.attack("another enemy");
    std::cout << std::endl;

    std::cout << "--------------- Copy constructor ---------------" << std::endl;
    FragTrap frag3(frag2);
    frag3.attack("another another enemy");
    std::cout << std::endl;

    std::cout << "--------------- Destructor calls ---------------" << std::endl;
}