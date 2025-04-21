/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:59:59 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 19:04:16 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SED_H
#define	SED_H

#include <fstream>
#include <iostream>
#include <string>

class Sed {
	private:
		std::string	filename;
		std::string	source_text;
		std::string	destiny_text;
		std::string	replace_text(std::string line);

	public:
		Sed(std::string& filename, const std::string& source_text, const std::string& destiny_text);
		~Sed();
};

#endif // SED_H