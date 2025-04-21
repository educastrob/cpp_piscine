/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:43:32 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 19:52:59 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./" << argv[0] << " <level>" << std::endl;
        return (1);
    }

    Harl harl;
    std::string level = argv[1];
    harl.complain(level);
    return (0);
}