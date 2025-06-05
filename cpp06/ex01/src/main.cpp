/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:53:11 by educastro         #+#    #+#             */
/*   Updated: 2025/06/04 20:56:45 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

static void printData(const Data *p) {
    std::cout << "Name: " << p->name << std::endl;
    std::cout << "Quantity: " << p->quantity << std::endl;
    std::cout << "Price: " << p->price << std::endl << std::endl;
}

int main() {
    Data *data = new Data();

    data->name = "cap";
    data->quantity = 23;
    data->price = 70.4f;

    uintptr_t ptr;

    std::cout << "Data before serialize" << std::endl;
    std::cout << "Data address: " << data << std::endl;
    printData(data);

    ptr = Serializer::serialize(data);
    std::cout << "Data after serialize" << std::endl;
    std::cout << "Data address: " << data << std::endl;
    std::cout << "Serialized data address: " << ptr << std::endl;
    printData(data);

    Data *testData;

    testData = Serializer::deserialize(ptr);
    std::cout << "Data after deserialize" << std::endl;
    std::cout << "Data address: " << testData << std::endl;
    printData(testData);

    delete data;
}