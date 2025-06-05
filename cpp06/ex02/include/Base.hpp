/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:34:11 by educastro         #+#    #+#             */
/*   Updated: 2025/06/05 15:34:12 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
   public:
    virtual ~Base();
};

Base *generate(void);

void identify(Base *p);

void identify(Base &p);

#endif  // BASE_HPP