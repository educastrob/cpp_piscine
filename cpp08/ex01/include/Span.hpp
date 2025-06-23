/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:09:40 by educastro         #+#    #+#             */
/*   Updated: 2025/06/22 21:27:06 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
   private:
    std::vector<int> numbers;
    unsigned int size;

   public:
    // Constructors
    Span();
    Span(unsigned int N);
    Span(const Span &copy);

    // Destructor
    ~Span();

    // Operators
    Span &operator=(const Span &assign);

    // Member functions
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

	void addRange(int values[], unsigned int size);
};

#endif  // SPAN_HPP