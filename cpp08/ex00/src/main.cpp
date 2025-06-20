#include <iostream>
#include <list>
#include <vector>
#include <deque>

#include "easyfind.hpp"

int main() {
    std::cout << "Vector tests ======================" << std::endl;
    try {
        std::vector<int> vec;

        for (int i = 1; i <= 10; ++i) {
            vec.push_back(i);
        }

        std::cout << "Trying to find number 5 in vector" << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found in vector number: " << *it << std::endl;

        std::cout << "Trying to find number 42 in vector" << std::endl;
        it = easyfind(vec, 42);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl
              << "List tests ========================" << std::endl;
    try {
        std::list<int> lst;

        for (int i = 1; i < 10; ++i) {
            lst.push_back(i * 10);
        }

        std::cout << "Trying to find number 10 in list" << std::endl;
        std::list<int>::iterator it = easyfind(lst, 10);
        std::cout << "Found in list number: " << *it << std::endl;

        std::cout << "Trying to find number 1000 in list" << std::endl;
        it = easyfind(lst, 1000);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    std::cout << std::endl
              << "List tests ========================" << std::endl;
    try {
        std::deque<int> dec;

        for (int i = 1; i < 10; ++i) {
            dec.push_back(i * 10);
        }

        std::cout << "Trying to find number 30 in list" << std::endl;
        std::deque<int>::iterator it = easyfind(dec, 30);
        std::cout << "Found in list number: " << *it << std::endl;

        std::cout << "Trying to find number 1000 in list" << std::endl;
        it = easyfind(dec, 1000);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}