/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** ClientGUI.cpp
*/

#include <SFML/System.hpp>
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

// Handle the reception of the server's message

void ClientGUI::createHandleDic() {
    _handlers[std::string("msz")] = handleMsz;
    _handlers[std::string("bct")] = handleBct;
    _handlers[std::string("tna")] = handleTna;
    _handlers[std::string("pnw")] = handlePnw;
    _handlers[std::string("ppo")] = handlePpo;
    _handlers[std::string("plv")] = handlePlv;
    _handlers[std::string("pin")] = handlePin;
    _handlers[std::string("pex")] = handlePex;
    _handlers[std::string("pbc")] = handlePbc;
    _handlers[std::string("pic")] = handlePic;
    _handlers[std::string("pie")] = handlePie;
    _handlers[std::string("pfk")] = handlePfk;
    _handlers[std::string("pdr")] = handlePdr;
    _handlers[std::string("pgt")] = handlePgt;
    _handlers[std::string("pdi")] = handlePdi;
    _handlers[std::string("enw")] = handleEnw;
    _handlers[std::string("ebo")] = handleEbo;
    _handlers[std::string("edi")] = handleEdi;
    _handlers[std::string("sgt")] = handleSgt;
    _handlers[std::string("seg")] = handleSeg;
    _handlers[std::string("smg")] = handleSmg;
    _handlers[std::string("suc")] = handleSuc;
    _handlers[std::string("sbp")] = handleSbp;
}

void ClientGUI::handleMsz(std::vector<std::string> &data) {

}

void ClientGUI::handleBct(std::vector<std::string> &data) {

}

void ClientGUI::handleTna(std::vector<std::string> &data) {

}

void ClientGUI::handlePnw(std::vector<std::string> &data) {

}

void ClientGUI::handlePpo(std::vector<std::string> &data) {

}

void ClientGUI::handlePlv(std::vector<std::string> &data) {

}

void ClientGUI::handlePin(std::vector<std::string> &data) {

}

void ClientGUI::handlePex(std::vector<std::string> &data) {

}

void ClientGUI::handlePbc(std::vector<std::string> &data) {

}

void ClientGUI::handlePic(std::vector<std::string> &data) {

}

void ClientGUI::handlePie(std::vector<std::string> &data) {

}

void ClientGUI::handlePfk(std::vector<std::string> &data) {

}

void ClientGUI::handlePdr(std::vector<std::string> &data) {

}

void ClientGUI::handlePgt(std::vector<std::string> &data) {

}

void ClientGUI::handlePdi(std::vector<std::string> &data) {

}

void ClientGUI::handleEnw(std::vector<std::string> &data) {

}

void ClientGUI::handleEbo(std::vector<std::string> &data) {

}

void ClientGUI::handleEdi(std::vector<std::string> &data) {

}

void ClientGUI::handleSgt(std::vector<std::string> &data) {

}

void ClientGUI::handleSst(std::vector<std::string> &data) {

}

void ClientGUI::handleSeg(std::vector<std::string> &data) {

}

void ClientGUI::handleSmg(std::vector<std::string> &data) {

}

void ClientGUI::handleSuc(std::vector<std::string> &data){

}

void ClientGUI::handleSbp(std::vector<std::string> &data) {

}
