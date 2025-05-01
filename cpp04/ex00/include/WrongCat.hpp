/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:19:47 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:19:48 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   public:
    // Constructors
    WrongCat();
    WrongCat(WrongCat const &copy);

    // Destructor
    ~WrongCat();

    // Operators
    WrongCat &operator=(const WrongCat &assign);
    // Getters
    std::string getType() const;

    // Menber functions
    void makeSound() const;
};

#endif  // WRONGCAT_HPP
