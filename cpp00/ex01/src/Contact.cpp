/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:11:48 by educastro         #+#    #+#             */
/*   Updated: 2025/04/15 20:08:33 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, \
		std::string phoneNumber, std::string darkestSecret) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
	return;
}

Contact::Contact(void) { return; }
Contact::~Contact(void) { return; }

static std::string	truncateText(const std::string &text) {
	if (text.length() > 10) {
		return text.substr(0, 9) + ".";
	}
	return text;
}

void Contact::displayContactRow(size_t index) {
	std::cout << std::endl << "|" << std::setw(10) << index << "|" << std::setw(10) 
		<< truncateText(firstName) << "|" << std::setw(10)
		<< truncateText(lastName) << "|" << std::setw(10)
		<< truncateText(nickname) << "|" << std::endl;
}

void Contact::displayContact(void) {
    std::cout << std::endl << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl << std::endl;
}
