/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** SocketCommunication.hpp
*/


#ifndef SOCKETCOMMUNICATION_HPP_
	#define SOCKETCOMMUNICATION_HPP_

    #include <iostream>
    #include <SFML/Network.hpp>

class SocketCommunication {
	public:
		SocketCommunication() {

        };
		~SocketCommunication() {};

	private:
    sf::TcpSocket _socket;
};

#endif /*SOCKETCOMMUNICATION_HPP_*/