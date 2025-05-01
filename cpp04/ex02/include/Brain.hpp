/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:22:30 by edcastro          #+#    #+#             */
/*   Updated: 2025/04/30 23:22:31 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_HPP
#define Brain_HPP

#include <string>

class Brain {
   private:
    std::string ideas[100];

   public:
    // Constructors
    Brain();
    Brain(const Brain &copy);

    // Destructor
    virtual ~Brain();

    // Operators
    Brain &operator=(const Brain &assign);
};

#endif  // Brain_HPP
