/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:21:58 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:21:59 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal {
   protected:
    std::string type;

   public:
    // Constructors
    AAnimal();
    AAnimal(const AAnimal &copy);

    // Destructor
    virtual ~AAnimal();

    // Operators
    AAnimal &operator=(const AAnimal &assign);

    // Getters
    std::string getType() const;

    // Menber functions
    virtual void makeSound() const = 0;
};

#endif  // AANIMAL_HPP
