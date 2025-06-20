/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:09:50 by educastro         #+#    #+#             */
/*   Updated: 2025/06/19 22:10:31 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream>

#include "Span.hpp"

int generateRandomNumber(int min, int max);

int main() {
    std::cout << std::endl
              << "==== Simple test with small span ====" << std::endl;
    try {
        Span span(10);
        int nbs[] = {3, 7, 2, 9, 1, 4, 8, 6, 5, 10};
        for (int i = 0; i < 10; ++i) {
            span.addNumber(nbs[i]);
        }

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;

        std::cout << "Trying to add number 11 to span." << std::endl;
        span.addNumber(11);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "==== Random test with larger span ====" << std::endl;
    try {
        srand(static_cast<unsigned>(time(NULL)));
        Span largeSpan(100000);
        for (int i = 0; i < 100000; ++i) {
            largeSpan.addNumber(generateRandomNumber(1, 1000000));
        }
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;

        std::cout << "Trying to add number 100001 to span." << std::endl;
        largeSpan.addNumber(generateRandomNumber(1, 1000000));
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}