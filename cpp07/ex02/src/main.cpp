/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:47:27 by educastro         #+#    #+#             */
/*   Updated: 2025/06/06 16:47:28 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <Array.hpp>
#include <iostream>

#define MAX_VAL 750

int main(int, char**) {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try {
        numbers[-2] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        numbers[MAX_VAL] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }

    std::cout << std::endl
              << "mirror[0] = " << mirror[0] << std::endl;
    std::cout << "mirror[" << MAX_VAL - 1 << "] = " << mirror[MAX_VAL - 1] << std::endl
              << std::endl;

    std::cout << std::endl
              << "numbers[0] = " << numbers[0] << std::endl;
    std::cout << "numbers[" << MAX_VAL - 1 << "] = " << numbers[MAX_VAL - 1] << std::endl
              << std::endl;

    delete[] mirror;

    std::cout << "Everything is ok." << std::endl;
}