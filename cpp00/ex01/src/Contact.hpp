/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:43:44 by educastro         #+#    #+#             */
/*   Updated: 2025/04/15 19:44:53 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>

class	Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
		
	public:
		Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickname, \
			std::string phoneNumber, std::string darkestSecret);
		
		~Contact();
		void displayContactRow(size_t index);
		void displayContact(void);
};

#endif