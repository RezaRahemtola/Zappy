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
#include <memory>
#include <functional>
#include "GameData.hpp"

class ClientGUI {
	public:
        ClientGUI() = default;
        ClientGUI(std::string &machine, int port, std::shared_ptr<GameData> gameData) : _sockfd(-1),
            _gameData(gameData), _buffer("") {

            createHandleDic();
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

    void handleDataServer();

	private:
        int _sockfd;
        std::shared_ptr<GameData> _gameData;

        std::string _buffer;

        // handle data from server
        void createHandleDic();
        void dispatchData(std::string data);
        std::unordered_map<std::string, void(ClientGUI::*)(std::vector<std::string>&)> _handlers;

        void handleMsz(std::vector<std::string> &data);
        void handleBct(std::vector<std::string> &data);
        void handleTna(std::vector<std::string> &data);
        void handlePnw(std::vector<std::string> &data);
        void handlePpo(std::vector<std::string> &data);
        void handlePlv(std::vector<std::string> &data);
        void handlePin(std::vector<std::string> &data);
        void handlePex(std::vector<std::string> &data);
        void handlePbc(std::vector<std::string> &data);
        void handlePic(std::vector<std::string> &data);
        void handlePie(std::vector<std::string> &data);
        void handlePfk(std::vector<std::string> &data);
        void handlePdr(std::vector<std::string> &data);
        void handlePgt(std::vector<std::string> &data);
        void handlePdi(std::vector<std::string> &data);
        void handleEnw(std::vector<std::string> &data);
        void handleEbo(std::vector<std::string> &data);
        void handleEdi(std::vector<std::string> &data);
        void handleSgt(std::vector<std::string> &data);
        void handleSst(std::vector<std::string> &data);
        void handleSeg(std::vector<std::string> &data);
        void handleSmg(std::vector<std::string> &data);
        void handleSuc(std::vector<std::string> &data);
        void handleSbp(std::vector<std::string> &data);
};

#endif /*CLIENTGUI_HPP_*/
