/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:18:19 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 19:18:26 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

# define SHRUBBERRY_TREE "\
        *\n\
       /|\\\n\
      /*|*\\\n\
     /*/|\\*\\\n\
    /*/*|*\\*\\\n\
   /*/*/|\\*\\*\\\n\
  /*/*/*|*\\*\\*\\\n\
 /*/*/*/|\\*\\*\\*\\\n\
/*/*/*/*|*\\*\\*\\*\\\n\
      |X|X|\n\
      |X|X|\n"

class ShrubberyCreationForm : public AForm {
   private:
    static const unsigned char gradeToSign = 145;
    static const unsigned char gradeToExecute = 137;

   public:
    // Exceptions
    class FileAlreadyExistException : public std::exception {
       public:
        const char *what() const throw();
    };
    class FailedToOpenException : public std::exception {
       public:
        const char *what() const throw();
    };

    // Constructors
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);

    // Destructor
    ~ShrubberyCreationForm();

    // Operators
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assign);

    // Member functions
    void execute(Bureaucrat const &executor) const;
};

#endif  // SHRUBBERYCREATIONFORM_HPP