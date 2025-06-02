/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:31:46 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 19:16:57 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>

class AForm {
   private:
    const std::string name;
    const std::string target;
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
    class FormNotSignedException : public std::exception {
       public:
        const char *what() const throw();
    };

    // Constructors
    AForm();
    AForm(std::string name, std::string target, unsigned char gradeToSign, unsigned char gradeToExecute);
    AForm(const AForm &copy);

    // Destructor
    virtual ~AForm();

    // Operators
    AForm &operator=(const AForm &assign);

    // Getters
    std::string getName() const;
    std::string getTarget() const;
    bool getIsSigned() const;
    unsigned char getGradeToSign() const;
    unsigned char getGradeToExecute() const;

    // Menber functions
    void beSigned(class Bureaucrat &bureaucrat);
    void checkCanExecute(Bureaucrat const &executor) const;
    virtual void execute(Bureaucrat const &executor) const = 0;
};

// Non-member functions
std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif  // AFORM_HPP