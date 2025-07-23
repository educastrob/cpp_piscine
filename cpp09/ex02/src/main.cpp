/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:43:57 by educastro         #+#    #+#             */
/*   Updated: 2025/07/17 21:40:54 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "Usage: " << argv[0] << " <[...] sequance of positive numbers>" << std::endl;
        return (1);
    } else if (!PmergeMe::validateSequence(++argv)) {
        return (1);
    }

    // Print Jacobsthal insertion sequence
    // std::vector<size_t> sequence;
    // PmergeMe::generateInsertionSequence(12, sequence);
    // std::cout << "Sequence: ";
    // PmergeMe::print(sequence);

    std::vector<int> vector;
    PmergeMe::parseSequence(argv, vector);

    std::cout << "Before:\t";
    PmergeMe::print(vector);

    clock_t vectorStart = clock();
    PmergeMe::sort(vector);
    clock_t vectorEnd = clock();

    std::cout << "After:\t";
    PmergeMe::print(vector);

    double vectorDuration = static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << vectorDuration * 1e6 << " us" << std::endl;

    std::deque<int> deque;
    PmergeMe::parseSequence(argv, deque);

    // std::cout << "Before:\t";
    // PmergeMe::print(deque);

    clock_t dequeStart = clock();
    PmergeMe::sort(deque);
    clock_t dequeEnd = clock();

    // std::cout << "After:\t";
    // PmergeMe::print(deque);

    double dequeDuration = static_cast<double>(dequeEnd - dequeStart) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << dequeDuration * 1e6 << " us" << std::endl;
}

