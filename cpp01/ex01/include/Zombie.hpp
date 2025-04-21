/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:09:44 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 17:42:28 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void setName(std::string name);
		void announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif