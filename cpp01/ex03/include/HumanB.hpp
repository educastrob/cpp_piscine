/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:08:47 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 18:52:46 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
   private:
    std::string name;
    Weapon* weapon;

   public:
    HumanB(const std::string name);
    ~HumanB();
    void setWeapon(Weapon& weapon);
    void attack();
};

#endif  // HUMANB_H