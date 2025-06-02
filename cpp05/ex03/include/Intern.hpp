/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:39:19 by educastro         #+#    #+#             */
/*   Updated: 2025/06/02 14:39:26 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
   public:
    // Exceptions
    class FormNotFoundException : public std::exception {
       public:
        const char *what() const throw();
    };

    // Constructors
    Intern();
    Intern(const Intern &copy);

    // Destructor
    ~Intern();

    // Operators
    Intern &operator=(const Intern &assign);

    // Member functions
    AForm *makeForm(std::string formName, std::string target);
};

#endif  // INTERN_HPP