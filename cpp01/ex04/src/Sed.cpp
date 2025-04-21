/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:00:01 by educastro         #+#    #+#             */
/*   Updated: 2025/04/21 19:26:43 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string& filename, const std::string& source_text, const std::string& destiny_text)
	: filename(filename), source_text(source_text), destiny_text(destiny_text) {
	std::ifstream input_file(filename.c_str());
	if (!input_file.is_open()) {
		throw std::runtime_error("Invalid input file.");
	}

	std::ofstream output_file(filename.append(".replace").c_str());
	if (!output_file.is_open()) {
		input_file.close();
		throw std::runtime_error("Error while open output file.");
	}

	std::string line;
	if (source_text != "") {
		while (std::getline(input_file, line)) {
			output_file << replace_text(line) << std::endl;
		}
	}

	input_file.close();
	output_file.close();
}

Sed::~Sed() {
	return;
}

std::string Sed::replace_text(std::string line) {
	size_t pos = 0;
	while ((pos = line.find(source_text, pos)) != std::string::npos) {
		line.erase(pos, source_text.length());
		line.insert(pos, destiny_text);
		pos += destiny_text.length();
	}

	return line;
}