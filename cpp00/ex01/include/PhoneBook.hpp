/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:43:48 by educastro         #+#    #+#             */
/*   Updated: 2025/04/15 20:01:46 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"


class	PhoneBook {
	private:
		Contact	contacts[8];
		size_t	contactCount;
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact();
};

#endif