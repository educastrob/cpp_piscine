/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:03:02 by educastro         #+#    #+#             */
/*   Updated: 2025/04/26 18:04:57 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
   protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

   public:
    // Constructors
    ClapTrap();
    ClapTrap(const ClapTrap &copy);
    ClapTrap(const std::string name);

    // Destructor
    ~ClapTrap();

    // Operators
    ClapTrap &operator=(const ClapTrap &assign);

    // Getters / Setters
    std::string getName() const;
    unsigned int getAttackDamage() const;

    // Menber functions
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif  // CLAPTRAP_HPP