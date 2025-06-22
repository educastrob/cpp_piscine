/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:44:00 by educastro         #+#    #+#             */
/*   Updated: 2025/06/22 18:44:36 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <utility>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
    *this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &assign) {
    if (this == &assign) return *this;
    return *this;
}

bool PmergeMe::validateSequence(char **argv) {
    while (*argv != NULL) {
        std::string sequence = *argv++;

        if (sequence.find_first_not_of("0123456789 ") != std::string::npos) {
            std::cout << "Error: Only positive integers are allowed." << std::endl;
            return (false);
        }
    }

    return (true);
}

// Vector ======================================================================
void PmergeMe::sort(std::vector<int> &vector) {
    if (vector.size() < 2) {
        return;
    }

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;

    // If the vector has an odd number of elements, save the last element
    if (vector.size() % 2 != 0) {
        straggler = vector.back();
        vector.pop_back();
    }

    // Create pairs of elements and sort them
    pairs.reserve(vector.size() / 2);
    for (size_t i = 0; i < vector.size(); i += 2) {
        if (vector[i] < vector[i + 1]) {
            pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
        } else {
            pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
        }
    }

    // Sort the pairs by the second element
    PmergeMe::insertionSort<std::vector<std::pair<int, int> > >(pairs);

    // Rebuild the vector with the second element of each pair
    vector.clear();
    vector.reserve((pairs.size() * 2) + (straggler != -1 ? 1 : 0));
    for (size_t i = 0; i < pairs.size(); i++) {
        vector.push_back(pairs[i].second);
    }

    // Insert the first element in front of the vector
    vector.insert(vector.begin(), pairs.front().first);

    // Create insertion sequence and insert the first element of each pair
    std::vector<size_t> indexs;
    PmergeMe::generateInsertionSequence(pairs.size() - 1, indexs);
    for (size_t i = 0; i < indexs.size(); i++) {
        size_t pos = PmergeMe::binarySearchPosition(vector, indexs[i], pairs[i + 1].first);
        vector.insert(vector.begin() + pos, pairs[i + 1].first);
    }

    // Insert the straggler if it exists
    if (straggler != -1) {
        size_t pos = PmergeMe::binarySearchPosition(vector, vector.size() / 2, straggler);
        vector.insert(vector.begin() + pos, straggler);
    }
}

size_t PmergeMe::binarySearchPosition(const std::vector<int> &vector, size_t initialIndex, int x) {
    size_t low = 0;
    size_t high = vector.size() - 1;
    size_t mid = initialIndex;

    while (low <= high) {
        if (vector[mid] == x) {
            return mid;
        } else if (vector[mid] < x) {
            low = mid + 1;
        } else if (mid != 0) {
            high = mid - 1;
        } else {
            return mid;
        }
        mid = (low + high) / 2;
    }

    return low;
}

void PmergeMe::generateInsertionSequence(size_t maxIndex, std::vector<size_t> &sequence) {
    if (maxIndex == 0)
        return;

    std::vector<size_t> jacobsthalSequence;
    PmergeMe::jacobsthalSequence(maxIndex, jacobsthalSequence);

    sequence.reserve(maxIndex);
    sequence.push_back(jacobsthalSequence[0]);
    for (size_t i = 1; i < jacobsthalSequence.size(); i++) {
        size_t next = jacobsthalSequence[i];

        while ((sequence.size() < maxIndex) && (next > jacobsthalSequence[i - 1])) {
            sequence.push_back(next);
            next--;
        }
    }

    if (sequence.size() < maxIndex) {
        size_t next = maxIndex;

        while (sequence.size() < maxIndex) {
            sequence.push_back(next);
            next--;
        }
    }
}

// Deque =======================================================================
void PmergeMe::sort(std::deque<int> &deque) {
    if (deque.size() < 2) {
        return;
    }

    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;

    if (deque.size() % 2 != 0) {
        straggler = deque.back();
        deque.pop_back();
    }

    pairs.resize(deque.size() / 2);
    for (size_t i = 0; i < deque.size(); i += 2) {
        if (deque[i] < deque[i + 1]) {
            pairs[i / 2] = std::make_pair(deque[i], deque[i + 1]);
        } else {
            pairs[i / 2] = std::make_pair(deque[i + 1], deque[i]);
        }
    }

    PmergeMe::insertionSort<std::deque<std::pair<int, int> > >(pairs);

    deque.clear();
    deque.resize(pairs.size());
    for (size_t i = 0; i < pairs.size(); i++) {
        deque[i] = pairs[i].second;
    }

    deque.push_front(pairs.front().first);

    std::vector<size_t> indexs;
    PmergeMe::generateInsertionSequence(pairs.size() - 1, indexs);
    for (size_t i = 0; i < indexs.size(); i++) {
        size_t pos = PmergeMe::binarySearchPosition(deque, indexs[i], pairs[i + 1].first);
        deque.insert(deque.begin() + pos, pairs[i + 1].first);
    }

    if (straggler != -1) {
        size_t pos = PmergeMe::binarySearchPosition(deque, deque.size() / 2, straggler);
        deque.insert(deque.begin() + pos, straggler);
    }
}

size_t PmergeMe::binarySearchPosition(const std::deque<int> &deque, size_t initialIndex, int x) {
    size_t low = 0;
    size_t high = deque.size() - 1;
    size_t mid = initialIndex;

    while (low <= high) {
        if (deque[mid] == x) {
            return mid;
        } else if (deque[mid] < x) {
            low = mid + 1;
        } else if (mid != 0) {
            high = mid - 1;
        } else {
            return mid;
        }
        mid = (low + high) / 2;
    }

    return low;
}

void PmergeMe::generateInsertionSequence(size_t maxIndex, std::deque<size_t> &sequence) {
    if (maxIndex == 0)
        return;

    std::deque<size_t> jacobsthalSequence;
    PmergeMe::jacobsthalSequence(maxIndex, jacobsthalSequence);

    sequence.resize(maxIndex);
    sequence[0] = jacobsthalSequence[0];
    size_t index = 1;

    for (size_t i = 1; i < jacobsthalSequence.size(); i++) {
        size_t next = jacobsthalSequence[i];

        while ((sequence.size() < maxIndex) && (next > jacobsthalSequence[i - 1])) {
            sequence[index++] = next;
            next--;
        }
    }

    if (sequence.size() < maxIndex) {
        size_t next = maxIndex;

        while (sequence.size() < maxIndex) {
            sequence[index++] = next;
            next--;
        }
    }
}
