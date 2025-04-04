/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:43:31 by educastro         #+#    #+#             */
/*   Updated: 2025/03/25 11:43:32 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1 ; av[i] ; i++)
        {
            for (int j = 0 ; av[i][j] ; j++)
            {
                std::cout << static_cast<char>(std::toupper(av[i][j]));
            }
        }
        std::cout << std::endl;
    }
}