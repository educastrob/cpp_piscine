/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:11:26 by educastro         #+#    #+#             */
/*   Updated: 2025/06/19 22:11:27 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
    // Constructors
    MutantStack() : std::stack<T>(){};
    MutantStack(const MutantStack &copy) : std::stack<T>(copy){};

    // Destructor
    ~MutantStack(){};

    // Operators
    MutantStack &operator=(const MutantStack &assign) {
        if (this == &assign) {
            return *this;
        }

        std::stack<T>::operator=(assign);
        return *this;
    }

    // Iterator
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() {
        return std::stack<T>::c.begin();
    }

    iterator end() {
        return std::stack<T>::c.end();
    }

    const_iterator begin() const {
        return std::stack<T>::c.begin();
    }

    const_iterator end() const {
        return std::stack<T>::c.end();
    }
};

#endif  // MUTANTSTACK_HPP