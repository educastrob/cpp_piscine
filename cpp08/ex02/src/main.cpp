/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 22:12:00 by educastro         #+#    #+#             */
/*   Updated: 2025/06/19 22:12:05 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>

#include "MutantStack.hpp"

int main() {
    std::cout << std::endl
              << "Subject tests ================" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "Top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "[";
        while (it != ite) {
            std::cout << *it << ", ";
            ++it;
        }
        std::cout << "\b\b]" << std::endl;
        std::stack<int> s(mstack);
    }

    std::cout << std::endl
              << "Subject tests with list ======" << std::endl;
    {
        std::list<int> lstack;
        lstack.push_back(5);
        lstack.push_back(17);
        std::cout << "Back: " << lstack.back() << std::endl;
        lstack.pop_back();
        std::cout << "Size: " << lstack.size() << std::endl;
        lstack.push_back(3);
        lstack.push_back(5);
        lstack.push_back(737);
        lstack.push_back(0);
        std::list<int>::iterator it = lstack.begin();
        std::list<int>::iterator ite = lstack.end();
        ++it;
        --it;
        std::cout << "[";
        while (it != ite) {
            std::cout << *it << ", ";
            ++it;
        }
        std::cout << "\b\b]" << std::endl;
        std::list<int> list(lstack);
    }

    std::cout << std::endl
              << "Test for iterate =============" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        std::cout << "[";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++) {
            std::cout << *it << ", ";
        }
        std::cout << "\b\b]" << std::endl;
    }

    std::cout << std::endl
              << "Tests empty stack ============" << std::endl;
    {
        MutantStack<int> mstack;

        std::cout << "Stack is empty: " << (mstack.empty() ? "true" : "false") << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it < mstack.end(); it++) {
            std::cout << *it << std::endl;
        }
    }

    std::cout << std::endl
              << "Tests for with pop ===========" << std::endl;
    {
        std::stack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        std::cout << "[";
        for (std::stack<int> dump = mstack; !dump.empty(); dump.pop()) {
            std::cout << dump.top() << ", ";
        }
        std::cout << "\b\b]" << std::endl;
        std::cout << "Original stack is empty: " << (mstack.empty() ? "true" : "false") << std::endl;
    }
}