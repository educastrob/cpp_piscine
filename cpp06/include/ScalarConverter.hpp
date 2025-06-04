/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:17:58 by educastro         #+#    #+#             */
/*   Updated: 2025/06/04 20:18:00 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
   private:
    // Constructors
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);

    // Operators
    ScalarConverter &operator=(const ScalarConverter &assign);

   public:
    // Destructor
    ~ScalarConverter();

    // Member functions
    static void convert(const std::string &str);
};

#endif  // SCALARCONVERTER_HPP