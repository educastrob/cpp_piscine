/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:15:27 by educastro         #+#    #+#             */
/*   Updated: 2025/06/22 18:25:20 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN &copy) {
    *this = copy;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &assign) {
    if (this == &assign) return *this;

    numbers = assign.numbers;

    return *this;
}

int RPN::calculate(const std::string &expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        varifyToken(token);

        if (isdigit(token[0])) {
            numbers.push(token[0] - '0');
        } else {
            operation(token[0]);
        }
    }

    if (numbers.size() != 1) {
        throw std::invalid_argument("invalid expression");
    }

    int result = numbers.top();
    numbers.pop();

    return result;
}

void RPN::varifyToken(const std::string &token) const {
    if (token.size() != 1 || (!isdigit(token[0]) && token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/')) {
        throw std::invalid_argument("invalid expression");
    }
}

void RPN::operation(const char &op) {
    if (numbers.size() < 2) {
        throw std::invalid_argument("invalid expression");
    }

    int right = numbers.top();
    numbers.pop();
    int left = numbers.top();
    numbers.pop();

    switch (op) {
        case '+':
            numbers.push(left + right);
            break;
        case '-':
            numbers.push(left - right);
            break;
        case '*':
            numbers.push(left * right);
            break;
        case '/':
            if (right == 0) {
                throw std::invalid_argument("division by zero");
            }
            numbers.push(left / right);
            break;
    }
}
