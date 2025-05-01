/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:19:29 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:19:30 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
   public:
    // Constructors
    Dog();
    Dog(const Dog &copy);

    // Destructor
    ~Dog();

    // Operators
    Dog &operator=(const Dog &assign);

    // Menber functions
    void makeSound(void) const;
};

#endif  // DOG_HPP
