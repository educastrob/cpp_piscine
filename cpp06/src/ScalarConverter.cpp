/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:17:47 by educastro         #+#    #+#             */
/*   Updated: 2025/06/04 20:17:49 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <math.h>

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

// Constructors
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    *this = copy;
}

// Destructor
ScalarConverter::~ScalarConverter() {}

// Operators
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &assign) {
    (void)assign;
    return *this;
}

void ScalarConverter::convert(const std::string &str) {
    char *endptr = NULL;
    bool isFloat = false;
    double value;

    if (str.size() == 1 && !std::isdigit(str[0])) {
        if (!std::isprint(str[0])) {
            std::cout << "invalid input" << std::endl;
            return;
        }
        value = static_cast<double>(str[0]);
    } else {
        std::string str_copy = str;
        if (str[str.size() - 1] == 'f' && (str.rfind("inf") != str.size() - 3)) {
            isFloat = true;
            str_copy.erase(str.size() - 1);
        }
        value = std::strtod(str_copy.c_str(), &endptr);
    }

    if ((endptr != NULL && *endptr != '\0') || (isFloat && !std::isinf(value) && !std::isnan(value) && str.find(".") == std::string::npos)) {
        std::cout << "invalid input" << std::endl;
        return;
    }

    if (std::isnan(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }

    if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);

    if (!std::isinf(value) && (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }

    std::cout << "double: " << value << std::endl;
}