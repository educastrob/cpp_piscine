/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:26:00 by educastro         #+#    #+#             */
/*   Updated: 2025/04/26 18:26:07 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
   public:
    // Constructors
    FragTrap();
    FragTrap(const FragTrap &copy);
    FragTrap(const std::string name);

    // Destructor
    ~FragTrap();

    // Operators
    FragTrap &operator=(const FragTrap &assign);

    // Menber functions
    void highFivesGuys(void);
};

#endif  // FRAGTRAP_HPP