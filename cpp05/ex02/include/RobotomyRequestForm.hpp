/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:17:51 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 19:18:04 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   private:
    static const unsigned char gradeToSign = 72;
    static const unsigned char gradeToExecute = 45;

   public:
    // Constructors
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);

    // Destructor
    ~RobotomyRequestForm();

    // Operators
    RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);

    // Member functions
    void execute(Bureaucrat const &executor) const;
};

#endif  // ROBOTOMYREQUESTFORM_HPP