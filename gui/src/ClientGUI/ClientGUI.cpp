/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** ClientGUI.cpp
*/

#include <vector>
#include "ClientGUI.hpp"
#include "Tokenize.hpp"

bool ClientGUI::sending(const std::string& message) {
    ssize_t bytesSent = send(_sockfd, message.c_str(), message.size(), 0);
    if (bytesSent == -1) {
        std::cerr << "Erreur lors de l'envoi des données." << std::endl;
        return false;
    }
    return true;
}

bool ClientGUI::receive(std::string& receivedData) {
    char buffer[4096];
    int bytesRead = 0;

    fd_set readSet;
    FD_ZERO(&readSet);
    FD_SET(_sockfd, &readSet);

    struct timeval timeout;
    timeout.tv_sec = 5;  // Temps d'attente en secondes
    timeout.tv_usec = 0;

    int selectResult = select(_sockfd + 1, &readSet, NULL, NULL, &timeout);
    if (selectResult == -1) {
        perror("Erreur lors de l'appel à select");
        return false;
    } else if (selectResult == 0) {
        std::cout << "Timeout atteint lors de la réception des données." << std::endl;
        return false;
    }

    if (FD_ISSET(_sockfd, &readSet)) {
        bytesRead = recv(_sockfd, buffer, sizeof(buffer), 0);
        if (bytesRead == -1) {
            perror("Erreur lors de la réception des données");
            return false;
        } else if (bytesRead == 0) {
            std::cout << "La connexion a été fermée par le serveur." << std::endl;
            return false;
        }
    }

    receivedData = std::string(buffer, bytesRead);
    return true;
}

// Commands to send to the server

std::pair<std::size_t, std::size_t> ClientGUI::msz() {
    std::string data;
    std::vector<std::string> tokens;
    std::vector<std::string> line_tokens;

    sending("msz\n");
    receive(data);
    tokenize(data, '\n', tokens);
    for (auto &token : tokens) {
        tokenize(token, ' ', line_tokens);
        if (line_tokens.size() == 3 && line_tokens[0] == "msz") {
            return std::make_pair(std::stoi(line_tokens[1]), std::stoi(line_tokens[2]));
        }
    }
    return std::make_pair(0, 0);
}