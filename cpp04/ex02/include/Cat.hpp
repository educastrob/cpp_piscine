/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:22:36 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:22:36 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
   private:
    Brain *brain;

   public:
    // Constructors
    Cat();
    Cat(const Cat &copy);

    // Destructor
    ~Cat();

    // Operators
    Cat &operator=(const Cat &assign);

    // Menber functions
    void makeSound(void) const;
};

#endif  // CAT_HPP
