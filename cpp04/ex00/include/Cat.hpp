/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:19:24 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:19:25 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
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
