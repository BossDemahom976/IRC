/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homohame <homohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:19:13 by homohame          #+#    #+#             */
/*   Updated: 2026/02/25 10:48:20 by homohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "Server.hpp"

#define RPL_WELCOME(client) ":localhost 001 " + std::string(client) + " :Bievenue sur le serv'bg !\r\n"

class Commands
{
private:
	std::string					cmd;
	std::vector<std::string>	params;

	void	cmdPASS(User user);
	void	cmdNick(User user);
	void	cmdUser(User user);
	void	cmdPong(User user);
public:
	Commands(char *command);
	~Commands();
};

#endif