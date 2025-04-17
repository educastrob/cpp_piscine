/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:43:48 by educastro         #+#    #+#             */
/*   Updated: 2025/04/17 18:27:30 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
   private:
    static const size_t MAX_CONTACTS = 8;
    Contact contacts[MAX_CONTACTS];
    size_t contactCount;

   public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContact();
};

#endif