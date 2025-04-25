/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:48:54 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/24 21:02:22 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
   private:
    static const int fractionalBits = 8;
    int rawBits;

   public:
    Fixed();
    Fixed(const Fixed &copy);
    ~Fixed();

    Fixed &operator=(const Fixed &assign);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif  // FIXED_HPP