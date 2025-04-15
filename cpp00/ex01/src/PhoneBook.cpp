/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:43:40 by educastro         #+#    #+#             */
/*   Updated: 2025/04/15 20:46:46 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) { contactCount = 0; return; }
PhoneBook::~PhoneBook(void) { return; }

static Contact createNewContact(void) {
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << std::endl << "Add a contact: " << std::endl;
	std::cout << "First name: " << std::endl;
	std::cin >> firstName;
	std::cout << "Last name: " << std::endl;
	std::cin >> lastName;
	std::cout << "Nickname: " << std::endl;
	std::cin >> nickname;
	std::cout << "Phone number: " << std::endl;
	std::cin >> phoneNumber;
	std::cout << "Darkest secret: " << std::endl;
	std::cin >> darkestSecret;
	std::cout << std::endl;

	return (Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
}

static void	printTableHead(void) {
	std::cout << std::endl << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First name" << "|"
			<< std::setw(10) << "Last name" << "|"
			<< std::setw(10) << "Nickname" << "|";
	std::cout << std::endl << "---------------------------------------------" << std::endl;
}

void PhoneBook::addContact(void) {
	Contact newContact = createNewContact();
	if (contactCount < 8) {
		contacts[contactCount++] = newContact;
	} else {
		for (size_t i = 0; i < 8 - 1; i++)
			contacts[i] = contacts[i + 1];
		contacts[8 - 1] = newContact;
	}
}

void PhoneBook::searchContact(void) {
	size_t	index;

	if (contactCount == 0) {
		std::cout << "No contacts to display." << std::endl << std::endl;
		return;
	}

	printTableHead();

	for (size_t i = 0; i < contactCount; i++)
		contacts[i].displayContactRow(i);
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Enter the index of the contact you want to display: ";
	std::cin >> index;
	if (index < contactCount) {
		contacts[index].displayContact();
	} else {
		std::cout << "Invalid index." << std::endl << std::endl;
	}
}