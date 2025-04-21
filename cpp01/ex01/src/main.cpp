/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:45:30 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 17:57:22 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie*	horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}
	
	delete[] horde;
	return 0;
}