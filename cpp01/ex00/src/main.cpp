/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:20:44 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 17:38:00 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie*	zombie = newZombie("Zombie");
	zombie->announce();
	delete zombie;

	randomChump("Random Zombie");
}