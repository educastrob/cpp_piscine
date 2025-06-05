/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:34:41 by educastro         #+#    #+#             */
/*   Updated: 2025/06/05 15:34:42 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate() {
    static bool first_try = true;

    if (first_try) {
        srand(time(NULL));
        first_try = false;
    }

    int choice = rand() % 3;
    switch (choice) {
        case 0:
            std::cout << "A is generated" << std::endl;
            return new A();
        case 1:
            std::cout << "B is generated" << std::endl;
            return new B();
        case 2:
            std::cout << "C is generated" << std::endl;
            return new C();
    }

    return NULL;
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else {
        std::cerr << "error: bad casting!" << std::endl;
    }
}

void identify(Base &p) {
    try {
        A a = dynamic_cast<A &>(p);

        std::cout << "A" << std::endl;
        return;
    } catch (std::exception &e) {
        try {
            B b = dynamic_cast<B &>(p);

            std::cout << "B" << std::endl;
            return;
        } catch (std::exception &e) {
            try {
                C c = dynamic_cast<C &>(p);

                std::cout << "C" << std::endl;
                return;
            } catch (std::exception &e) {
                std::cerr << "error: bad casting!" << std::endl;
                return;
            }
        }
    }
}