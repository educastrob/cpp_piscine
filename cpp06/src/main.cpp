/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:17:29 by educastro         #+#    #+#             */
/*   Updated: 2025/06/04 20:17:30 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
}