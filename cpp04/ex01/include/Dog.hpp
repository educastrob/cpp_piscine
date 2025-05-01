/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:20:51 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:20:51 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
   private:
    Brain *brain;

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
