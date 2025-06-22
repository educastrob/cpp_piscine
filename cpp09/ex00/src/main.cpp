/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:22:12 by educastro         #+#    #+#             */
/*   Updated: 2025/06/22 16:36:56 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " <query_file>" << std::endl;
        return (1);
    }

    try {
        BitcoinExchange exchange;

        exchange.queryExchangeRate(argv[1]);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return (1);
    }
}