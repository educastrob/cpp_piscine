/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:00:13 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 19:07:54 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <source_text> <destiny_text>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string source_txt = argv[2];
	std::string destiny_txt = argv[3];

	try {
		Sed(filename, source_txt, destiny_txt);
	} catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}