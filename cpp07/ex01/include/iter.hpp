/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:17:58 by educastro         #+#    #+#             */
/*   Updated: 2025/06/18 19:36:46 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T* array, size_t size, void (*func)(T&)) {
    for (size_t i = 0; i < size; i++) {
        func(array[i]);
    }
}

#endif  // ITER_HPP