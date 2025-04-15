/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:58:17 by educastro         #+#    #+#             */
/*   Updated: 2025/04/15 18:09:56 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phoneBook;
	std::string input;
	
	std::cout << "---------- Welcome to the PhoneBook ----------" << std::endl;

	while (true) {
		std::cout << "Valid commands: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> input;

		if (input == "ADD") {
			phoneBook.addContact(); // needs
			std::cout << "Adding contact..." << std::endl;
		} else if (input == "SEARCH") {
			phoneBook.searchContact(); // needs
			std::cout << "Searching contact..." << std::endl;
		} else if (input == "EXIT") {
			std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
			break;
		} else {
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}

	return EXIT_SUCCESS;
}