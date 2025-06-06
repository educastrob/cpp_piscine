/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:46:52 by educastro         #+#    #+#             */
/*   Updated: 2025/06/06 16:46:53 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
   private:
    T *elements;
    unsigned int length;

   public:
    // Constructors
    Array() : elements(new T[0]()), length(0) {}

    Array(unsigned int n) : elements(new T[n]()), length(n) {}

    Array(const Array &copy) : elements(new T[copy.size()]()), length(copy.size()) {
        for (unsigned int i = 0; i < copy.size(); i++) {
            elements[i] = copy[i];
        }
    }

    // Operators
    Array &operator=(const Array &assign) {
        if (this == &assign)
            return *this;

        delete[] elements;

        elements = new T[assign.size()]();
        length = assign.size();
        for (unsigned int i = 0; i < assign.size(); i++) {
            elements[i] = assign[i];
        }

        return *this;
    }

    // Destructor
    ~Array() {
        delete[] elements;
    }

    // Member functions
    unsigned int size() const {
        return length;
    }

    // Operators
    T const &operator[](const unsigned int &index) const {
        if (index >= this->length)
            throw std::out_of_range("Index out of range");
        return elements[index];
    }

    T &operator[](const unsigned int &index) {
        if (index >= this->length)
            throw std::out_of_range("Index out of range");
        return elements[index];
    }
};

#endif  // ARRAY_HPP