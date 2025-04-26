/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:43:13 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/24 23:43:13 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
   private:
    static const int fractionalBits = 8;
    int rawBits;

   public:
    // Constructors
    Fixed();
    Fixed(const Fixed &copy);
    Fixed(const int value);
    Fixed(const float value);

    // Destructor
    ~Fixed();

    // Operators
    Fixed &operator=(const Fixed &assign);

    // Getters / Setters
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversion functions
    float toFloat(void) const;
    int toInt(void) const;
};

// Non-member function
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif  // FIXED_HPP
