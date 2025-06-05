/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:34:29 by educastro         #+#    #+#             */
/*   Updated: 2025/06/05 15:34:30 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Base.hpp"

int main() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Test " << i + 1 << " ========================" << std::endl;
        std::cout << "Generating base: ";
        Base *ptr = generate();

        std::cout << "Pointer test: ";
        identify(ptr);

        std::cout << "Reference test: ";
        identify(*ptr);

        std::cout << std::endl;
        delete ptr;
    }
}