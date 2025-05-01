/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:22:44 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:22:45 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
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
