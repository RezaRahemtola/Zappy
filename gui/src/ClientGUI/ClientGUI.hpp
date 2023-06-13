/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** ClientGUI.hpp
*/


#ifndef CLIENTGUI_HPP_
	#define CLIENTGUI_HPP_

    #include <iostream>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <sys/time.h>
    #include <fcntl.h>

class ClientGUI {
	public:
        ClientGUI(std::string &machine, int port) : _sockfd(-1), _buffer("") {
            std::string data;
            std::cout << "On va se connecter à [" << machine << ":" << port << "]" << std::endl;
            // Création du socket
            _sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (_sockfd == -1) {
                std::cerr << "Erreur lors de la création du socket." << std::endl;
                exit(84);
            }

            // Configuration de l'adresse et du port du serveur
            struct sockaddr_in serverAddr;
            serverAddr.sin_family = AF_INET;
            serverAddr.sin_addr.s_addr = inet_addr(machine.c_str());
            serverAddr.sin_port = htons(port);

            // Connexion au serveur
            int connectResult = connect(_sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
            if (connectResult == -1) {
                std::cerr << "Erreur lors de la connexion au serveur." << std::endl;
                if (_sockfd != -1) {
                    close(_sockfd);
                    _sockfd = -1;
                }
                exit(84);
            }

            // Passage en mode non bloquant
            int flags = fcntl(_sockfd, F_GETFL, 0);
            fcntl(_sockfd, F_SETFL, flags | O_NONBLOCK);
            sending("GRAPHIC\n");
            receive(data);
            std::cout << "Server said: " << data << std::endl;
        }
		~ClientGUI() {
            if (_sockfd != -1) {
                close(_sockfd);
                _sockfd = -1;
            }
        };

    bool sending(const std::string& message);
    bool receive(std::string& receivedData);

    std::pair<std::size_t, std::size_t> msz();
    std::vector<std::size_t> bct(std::size_t x, std::size_t y);

	private:
        int _sockfd;

        std::string _buffer;
};

#endif /*CLIENTGUI_HPP_*/