/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:22:10 by educastro         #+#    #+#             */
/*   Updated: 2025/06/22 16:36:23 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

#define DATA_FILE "data.csv"

class BitcoinExchange {
   private:
    std::map<std::string, double> exchangeRates;

    double findClosestDate(const std::string &date) const;
    static bool isDateValid(const std::string &date);

   public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &assign);

    void queryExchangeRate(const std::string &queyFile) const;
};

#endif  // BITCOINEXCHANGE_HPP