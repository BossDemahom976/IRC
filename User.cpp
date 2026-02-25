/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: homohame <homohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 05:35:35 by homohame          #+#    #+#             */
/*   Updated: 2026/02/21 13:07:26 by homohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"
#define RPL_WELCOME(client) ":localhost 001 " + std::string(client) + " :Bievenue sur le serv'bg !\r\n"

User::User(int fd)
{
	this->fd = fd;
	this->nick = "nick";
	this->username = "username";
	this->registered = false;
}

User::~User()
{
}

void User::setNick(std::string nick)
{
	this->nick = nick;
}

void User::setUsername(std::string username)
{
	this->username = username;
}

void User::welcome()
{
	//message de co pour le serveur
	std::string msg = RPL_WELCOME(nick);
	send(fd, msg.c_str(), msg.length(), 0);
	this->registered = true;
}
