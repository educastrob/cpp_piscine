/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:55:54 by educastro         #+#    #+#             */
/*   Updated: 2025/05/08 18:50:03 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class Bureaucrat {
	private:
		const std::string name;
		unsigned char grade;

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

		// Constructors
		Bureaucrat();
		Bureaucrat(std::string name, unsigned char grade);
		Bureaucrat(const Bureaucrat &copy);

		// Destructor
		~Bureaucrat();

		// Operators
		Bureaucrat &operator=(const Bureaucrat &assign);

		// Getters
		std::string getName() const;
		unsigned char getGrade() const;

		// Menber functions
		void incrementGrade();
		void decrementGrade();
		void signForm(class Form &form);

};

// Non-member functions
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif  // BUREAUCRAT_HPP