/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:53:09 by educastro         #+#    #+#             */
/*   Updated: 2025/06/04 20:56:24 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

class Serializer {
   private:
    // Constructors
    Serializer();
    Serializer(const Serializer &copy);

    // Operators
    Serializer &operator=(const Serializer &assign);

   public:
    // Destructor
    ~Serializer();

    // Member functions
    static uintptr_t serialize(struct Data *ptr);
    static struct Data *deserialize(uintptr_t raw);
};

#endif  // SERIALIZER_HPP