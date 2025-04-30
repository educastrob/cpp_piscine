/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:19:13 by educastro         #+#    #+#             */
/*   Updated: 2025/04/29 22:19:15 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
   protected:
    std::string type;

   public:
    // Constructors
    Animal();
    Animal(const Animal &copy);

    // Destructor
    virtual ~Animal();

    // Operators
    Animal &operator=(const Animal &assign);

    // Getters
    std::string getType() const;

    // Menber functions
    virtual void makeSound() const;
};

#endif  // ANIMAL_HPP