/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:41:25 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/24 23:41:26 by edcastro         ###   ########.fr       */
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
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);

    // Static member functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    // Getters / Setters
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversion functions
    float toFloat(void) const;
    int toInt(void) const;
};

// Non-member function
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif