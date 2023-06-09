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

enum class Request {

};

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
            // recieve a welcome message
            std::size_t size;
            char buffer[1024];
            _socket.receive(buffer, 1024, size);
            std::cout << "Server said : " << buffer << std::endl;
        };
		~ClientGUI() {};

        void sendRequest(std::string message);

        void collectMessage();
        std::vector<std::string> getMessageQueue() const { return _messageQueue; };

	private:
        std::string _machine;
        int _port;

        sf::TcpSocket _socket;
        sf::Socket::Status _status;

        std::string _receiveBuffer;
        std::vector<std::string> _messageQueue;
};

#endif /*CLIENTGUI_HPP_*/