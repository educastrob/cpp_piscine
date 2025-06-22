/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:36:44 by educastro         #+#    #+#             */
/*   Updated: 2025/06/22 16:36:45 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {
    std::ifstream inputFile(DATA_FILE);

    if (!inputFile.is_open()) {
        throw std::runtime_error("data file not found.");
    }

    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        inputFile.close();
        throw std::runtime_error("data file is empty.");
    }

    std::string line;
    std::size_t lineNumber = 2;
    std::getline(inputFile, line);  // Skip header

    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        inputFile.close();
        throw std::runtime_error("data file does not contain any data.");
    }

    while (std::getline(inputFile, line)) {
        std::stringstream ss;
        char date[12];
        double rate;

        if (sscanf(line.c_str(), "%11[^,],%lf", date, &rate) != 2) {
            inputFile.close();
            ss << "invalid line format at data file [" << DATA_FILE << "]:\n"
               << lineNumber << "| " << line;
            throw std::runtime_error(ss.str());
        }

        if (!isDateValid(date)) {
            inputFile.close();
            ss << "invalid date at data file [" << DATA_FILE << "]:\n"
               << lineNumber << "| " << line;
            throw std::runtime_error(ss.str());
        }

        if (rate < 0) {
            inputFile.close();
            ss << "invalid rate at data file [" << DATA_FILE << "]:\n"
               << lineNumber << "| " << line;
            throw std::runtime_error(ss.str());
        }

        exchangeRates[date] = rate;
        lineNumber++;
    }

    inputFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign) {
    if (this == &assign) return *this;
    exchangeRates = assign.exchangeRates;
    return *this;
}

void BitcoinExchange::queryExchangeRate(const std::string &queyFile) const {
    std::ifstream inputFile(queyFile.c_str());

    if (!inputFile.is_open()) {
        throw std::runtime_error("query file not found.");
    }

    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        inputFile.close();
        throw std::runtime_error("query file is empty.");
    }

    std::string line;
    std::getline(inputFile, line);  // Skip header

    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        inputFile.close();
        throw std::runtime_error("query file does not contain any data.");
    }

    while (std::getline(inputFile, line)) {
        char date[12];
        double value;

        if (sscanf(line.c_str(), "%11[^ ] | %lf", date, &value) != 2) {
            std::cout << "Error: invalid line => \"" << line << "\"" << std::endl;
            continue;
        }

        if (!isDateValid(date)) {
            std::cout << "Error: invalid date => \"" << date << "\"" << std::endl;
            continue;
        }

        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        try {
            double rate = findClosestDate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    inputFile.close();
}

bool BitcoinExchange::isDateValid(const std::string &date) {
    if (date.size() != 10) {
        return false;
    }

    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        return false;
    }

    std::tm timeStruct = {};
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;

    std::time_t res = std::mktime(&timeStruct);
    if (res < 0) {
        return false;
    }

    return (timeStruct.tm_year == (year - 1900) &&
            timeStruct.tm_mon == (month - 1) &&
            timeStruct.tm_mday == day);
}

double BitcoinExchange::findClosestDate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);

    if (it == exchangeRates.begin() && it->first != date) {
        throw std::runtime_error("no data available for date \"" + date + "\" later than \"" + exchangeRates.begin()->first + "\"");
    }

    if (it != exchangeRates.end() && it->first == date) {
        return it->second;
    }

    return (--it)->second;
}