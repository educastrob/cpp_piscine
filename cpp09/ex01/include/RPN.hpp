/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:15:32 by educastro         #+#    #+#             */
/*   Updated: 2025/06/22 18:15:40 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
   private:
    std::stack<int> numbers;

    void varifyToken(const std::string &token) const;
    void operation(const char &op);

   public:
    RPN();
    RPN(const RPN &copy);
    ~RPN();
    RPN &operator=(const RPN &assign);

    int calculate(const std::string &expression);
};

#endif  // RPN_HPP
