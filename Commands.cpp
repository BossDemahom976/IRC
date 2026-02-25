#include "Commands.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homohame <homohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:57:19 by homohame          #+#    #+#             */
/*   Updated: 2026/02/06 07:57:20 by homohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


std::string clean_string(std::string s) {
	std::string chars = "\t\n\v\f\r ";
	s.erase(s.find_last_not_of(chars) + 1);
	return s;
}

Commands::Commands(char *buffer)
{
	std::string s(buffer);
	if (s.empty()) return;

    // 1. On isole le "trailing" (le message après " :")
	size_t trailing_pos = s.find(" :");
	std::string trailing;
	bool has_trailing = false;

	if (trailing_pos != std::string::npos) {
		trailing = s.substr(trailing_pos + 2);
		s.erase(trailing_pos); // On travaille maintenant sur une chaîne sans le message final
		has_trailing = true;
	}

    // 2. On extrait la commande et les paramètres simples
	size_t start = s.find_first_not_of(" ");
	size_t end;

	while (start != std::string::npos) {
		end = s.find(' ', start);
		std::string word = s.substr(start, (end == std::string::npos) ? std::string::npos : end - start);

		if (!word.empty()) {
			if (this->cmd.empty())
				this->cmd = clean_string(word);
			else
				this->params.push_back(word);
		}
		start = s.find_first_not_of(" ", end);
	}

    // 3. On rajoute le trailing à la fin de la liste des paramètres
    if (has_trailing) {
        this->params.push_back(clean_string(trailing));
    }
}