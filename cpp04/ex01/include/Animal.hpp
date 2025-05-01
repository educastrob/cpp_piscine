/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:20:38 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:20:39 by edcastro         ###   ########.fr       */
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
