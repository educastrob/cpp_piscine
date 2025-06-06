/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:17:58 by educastro         #+#    #+#             */
/*   Updated: 2025/06/06 16:41:48 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &p1, T &p2) {
    T aux = p1;
    p1 = p2;
    p2 = aux;
}

template <typename T>
T min(const T &value1, const T &value2) {
    if (value2 <= value1)
        return (value2);
    return (value1);
}

template <typename T>
T max(const T &value1, const T &value2) {
    if (value2 >= value1)
        return (value2);
    return (value1);
}

#endif  // WHATEVER_HPP