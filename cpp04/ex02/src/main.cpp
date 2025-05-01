/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:23:39 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:23:40 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    std::cout << "------------- Subject tests -------------" << std::endl;
    {
        const AAnimal *j = new Dog();
        const AAnimal *i = new Cat();

        delete j;  // should not create a leak
        delete i;
    }

    std::cout << std::endl
              << "------------- My tests -------------" << std::endl;
    {
        const int arraySize = 4;
        AAnimal *animals[arraySize];

        for (int i = 0; i < arraySize / 2; ++i) {
            animals[i * 2] = new Dog();
            animals[i * 2 + 1] = new Cat();
        }

        /* Delete animals */
        for (int i = 0; i < arraySize; ++i) {
            delete animals[i];
        }
    }

    std::cout << std::endl
              << "------------- Extra test -------------" << std::endl;
    {
        Dog basic;
        std::cout << basic.getType() << std::endl;
        basic.makeSound();
    }

    // std::cout << "------------- Fail test -------------" << std::endl;
    // {
    //     AAnimal test;
    // }
}
