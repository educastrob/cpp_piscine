/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:08:47 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 18:52:37 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA {
   private:
    std::string name;
    Weapon& weapon;

   public:
    HumanA(const std::string name, Weapon& weapon);
    ~HumanA();
    void attack();
};

#endif  // HUMANA_H