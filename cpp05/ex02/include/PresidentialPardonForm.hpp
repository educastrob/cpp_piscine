/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:17:32 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 19:17:37 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
    static const unsigned char gradeToSign = 25;
    static const unsigned char gradeToExecute = 5;

   public:
    // Constructors
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &copy);

    // Destructor
    ~PresidentialPardonForm();

    // Operators
    PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);

    // Member functions
    void execute(Bureaucrat const &executor) const;
};

#endif  // PRESIDENTIALPARDONFORM_HPP