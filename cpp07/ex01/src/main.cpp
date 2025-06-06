/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:17:29 by educastro         #+#    #+#             */
/*   Updated: 2025/06/06 16:43:56 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "iter.hpp"

void printIntTimeTwo(int &x);
void printDoubleMinusFour(double &x);
void printStringUpper(std::string &x);

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string stringArray[] = {"oi", "xau"};

    std::cout << "Array de inteiros: [";
    ::iter(intArray, 5, printIntTimeTwo);
    std::cout << "\b\b" << "]" << std::endl;

    std::cout << "Array de doubles: [";
    ::iter(doubleArray, 5, printDoubleMinusFour);
    std::cout << "\b\b" << "]" << std::endl;

    std::cout << "Array de strings: [";
    ::iter(stringArray, 2, printStringUpper);
    std::cout << "\b\b" << "]" << std::endl;
}

void printIntTimeTwo(int &x) {
    std::cout << x * 2 << ", ";
}

void printDoubleMinusFour(double &x) {
    std::cout << x - 4 << ", ";
}

void printStringUpper(std::string &x) {
    for (size_t i = 0; i < x.size(); i++) {
        std::cout << static_cast<char>(toupper(x[i]));
    }
    std::cout << ", ";
}