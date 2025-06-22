/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:43:55 by educastro         #+#    #+#             */
/*   Updated: 2025/06/22 18:44:57 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

class PmergeMe {
   private:
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &assign);

    static size_t binarySearchPosition(const std::vector<int> &vector, size_t initialIndex, int x);
    static size_t binarySearchPosition(const std::deque<int> &deque, size_t initialIndex, int x);

    static void generateInsertionSequence(size_t maxIndex, std::deque<size_t> &sequence);

   public:
    static void sort(std::vector<int> &vector);
    static void sort(std::deque<int> &deque);

    static bool validateSequence(char **argv);

    static void generateInsertionSequence(size_t maxIndex, std::vector<size_t> &sequence);

    template <typename T>
    static void jacobsthalSequence(size_t maxIndex, T &container) {
        if (maxIndex == 1) {
            container.push_back(1);
            return;
        }
        container.push_back(0);
        container.push_back(1);
        size_t i = 2;
        while (true) {
            size_t current = container[i - 1] + 2 * container[i - 2];
            if (current > maxIndex)
                break;
            container.push_back(current);
            i++;
        }
        container.erase(container.begin(), container.begin() + 2);
    }

    template <typename T>
    static void insertionSort(T &container) {
        for (size_t index = 1; index < container.size(); index++) {
            size_t previus = index - 1;
            std::pair<int, int> currentValue = container[index];
            while (container[previus].second > currentValue.second) {
                container[previus + 1] = container[previus];
                if (previus-- == 0)
                    break;
            }
            container[previus + 1] = currentValue;
        }
    }

    template <typename T>
    static void parseSequence(char **argv, T &container) {
        while (*argv != NULL) {
            std::string sequence = *argv++;
            std::stringstream iss(sequence);
            int num;

            while (iss >> num)
                container.push_back(num);
        }
    }

    template <typename T>
    static void print(T &container) {
        typename T::const_iterator it;
        for (it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\b" << std::endl;
    }
};

#endif  // PMERGEME_HPP
