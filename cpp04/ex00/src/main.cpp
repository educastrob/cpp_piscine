/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:20:11 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:20:12 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    std::cout << "------------- Subject tests -------------" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound();  // will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }

    std::cout << std::endl
              << "------------- My tests -------------" << std::endl;
    {
        const WrongCat* wrongCat = new WrongCat();
        const WrongAnimal* wrongAnimal = new WrongCat();

        std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
        std::cout << "wrongAnimal type: " << wrongAnimal->getType()
                  << std::endl;

        wrongCat->makeSound();
        wrongAnimal->makeSound();

        delete wrongCat;
        delete wrongAnimal;
    }
}
