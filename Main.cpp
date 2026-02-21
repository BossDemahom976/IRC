/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homohame <homohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 05:43:32 by homohame          #+#    #+#             */
/*   Updated: 2026/02/04 06:44:57 by homohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

int main(int argc, char **argv)
{
	int port = std::atoi(argv[1]); //A CHECK
	std::string password = argv[2]; // A CHECK

	Server server(port, password);

	server.initServer();
	server.serverLooping();
}