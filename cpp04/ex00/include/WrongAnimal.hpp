/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:19:35 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:19:36 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
   protected:
    std::string type;

   public:
    // Constructors
    WrongAnimal();
    WrongAnimal(const WrongAnimal &copy);

    // Destructor
    ~WrongAnimal();

    // Operators
    WrongAnimal &operator=(const WrongAnimal &assign);

    // Getters
    std::string getType() const;

    // Menber functions
    void makeSound() const;
};

#endif  // WRONGANIMAL_HPP
