/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** ClientGUI.hpp
*/


#ifndef CLIENTGUI_HPP_
	#define CLIENTGUI_HPP_

    #include <iostream>
    #include <SFML/Network.hpp>

class ClientGUI {
	public:
        ClientGUI(std::string machine, int port) : _socket(sf::TcpSocket()), _machine(machine), _port(port) {
            _status = _socket.connect(sf::IpAddress::LocalHost, _port);
            if (_status != sf::Socket::Done) {
                std::cerr << "Error: Connection Failed" << std::endl;
                exit(84);
            } else {
                std::cout << "Connected to server" << std::endl;
            }
        };
		~ClientGUI() {};

	private:
        std::string _machine;
        int _port;

        sf::TcpSocket _socket;
        sf::Socket::Status _status;
};

#endif /*CLIENTGUI_HPP_*/