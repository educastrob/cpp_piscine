/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:31:46 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 18:32:13 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>

class Form {
   private:
    const std::string name;
    bool isSigned;
    const unsigned char gradeToSign;
    const unsigned char gradeToExecute;

    static const unsigned char maxGrade = 1;
    static const unsigned char minGrade = 150;

   public:
    // Exceptions
    class GradeTooHighException : public std::exception {
       public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        const char *what() const throw();
    };
    class FormAlreadySignException : public std::exception {
       public:
        const char *what() const throw();
    };

    // Constructors
    Form();
    Form(std::string name, unsigned char gradeToSign, unsigned char gradeToExecute);
    Form(const Form &copy);

    // Destructor
    ~Form();

    // Operators
    Form &operator=(const Form &assign);

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    unsigned char getGradeToSign() const;
    unsigned char getGradeToExecute() const;

    // Menber functions
    void beSigned(class Bureaucrat &bureaucrat);
};

// Non-member functions
std::ostream &operator<<(std::ostream &out, const Form &Form);

#endif  // FORM_HPP