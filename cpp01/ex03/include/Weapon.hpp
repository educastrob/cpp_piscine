/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:09:09 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 18:52:56 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon {
   private:
    std::string type;

   public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType(void) const;
    void setType(std::string type);
};

#endif  // WEAPON_H