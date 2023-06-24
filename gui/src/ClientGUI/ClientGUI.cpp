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
    timeout.tv_sec = 0.1;  // Temps d'attente en secondes
    timeout.tv_usec = 0;

    int selectResult = select(_sockfd + 1, &readSet, NULL, NULL, &timeout);
    if (selectResult == -1) {
        perror("Erreur lors de l'appel à select");
        return false;
    } else if (selectResult == 0) {
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

void ClientGUI::handleDataServer() {
    std::string data;
    std::vector<Player> players = _gameData->getPlayers();

    sending("mct\n");

    for (auto &player : players) {
        sending("ppo #" + std::to_string(player.getId()) + "\n");
        sending("pin #" + std::to_string(player.getId()) + "\n");
        sending("plv #" + std::to_string(player.getId()) + "\n");
    }

    receive(data);
    if (data.empty())
        return;
    dispatchData(data);
}

void ClientGUI::createHandleDic() {
    _handlers[std::string("msz")] = &ClientGUI::handleMsz;
    _handlers[std::string("bct")] = &ClientGUI::handleBct;
    _handlers[std::string("tna")] = &ClientGUI::handleTna;
    _handlers[std::string("pnw")] = &ClientGUI::handlePnw;
    _handlers[std::string("ppo")] = &ClientGUI::handlePpo;
    _handlers[std::string("plv")] = &ClientGUI::handlePlv;
    _handlers[std::string("pin")] = &ClientGUI::handlePin;
    _handlers[std::string("pex")] = &ClientGUI::handlePex;
    _handlers[std::string("pbc")] = &ClientGUI::handlePbc;
    _handlers[std::string("pic")] = &ClientGUI::handlePic;
    _handlers[std::string("pie")] = &ClientGUI::handlePie;
    _handlers[std::string("pfk")] = &ClientGUI::handlePfk;
    _handlers[std::string("pdr")] = &ClientGUI::handlePdr;
    _handlers[std::string("pgt")] = &ClientGUI::handlePgt;
    _handlers[std::string("pdi")] = &ClientGUI::handlePdi;
    _handlers[std::string("enw")] = &ClientGUI::handleEnw;
    _handlers[std::string("ebo")] = &ClientGUI::handleEbo;
    _handlers[std::string("edi")] = &ClientGUI::handleEdi;
    _handlers[std::string("sgt")] = &ClientGUI::handleSgt;
    _handlers[std::string("seg")] = &ClientGUI::handleSeg;
    _handlers[std::string("smg")] = &ClientGUI::handleSmg;
    _handlers[std::string("suc")] = &ClientGUI::handleSuc;
    _handlers[std::string("sbp")] = &ClientGUI::handleSbp;
}

void ClientGUI::dispatchData(std::string data) {
    std::vector<std::string> commands;

    tokenize(data, '\n', commands);
    for (auto &command : commands) {
        std::vector<std::string> tokens;

        tokenize(command, ' ', tokens);
        if (tokens.size() > 0) {
            auto it = _handlers.find(tokens[0]);
            if (it != _handlers.end()) {
                (this->*(it->second))(tokens);
            }
        }
    }
}

void ClientGUI::handleMsz(std::vector<std::string> &data) {
    if (data.size() != 3)
        return;
    _gameData->updateMapSize(std::stoi(data[1]), std::stoi(data[2]));
}

void ClientGUI::handleBct(std::vector<std::string> &data) {
    if (data.size() != 10)
        return;
    _gameData->updateRessources(data);
}

void ClientGUI::handleTna(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    std::cout << "tna" << std::endl;
}

void ClientGUI::handlePnw(std::vector<std::string> &data) {
    if (data.size() != 7)
        return;
    std::cout << "pnw : " << data[1] << " pos : " << data[2] << " " << data[3] << " level : " << data[4] << " team : " << data[5] << std::endl;
    data[1].erase(0, 1);
    _gameData->createPlayer(std::stoi(data[1]), Vector2(std::stoi(data[2]), std::stoi(data[3])), std::stoi(data[4]), std::stoi(data[5]), data[6]);
}

void ClientGUI::handlePpo(std::vector<std::string> &data) {
    if (data.size() != 5)
        return;
    _gameData->updatePlayerPosition(std::stoi(data[1]), Vector2(std::stoi(data[2]), std::stoi(data[3])), std::stoi(data[4]));
}

void ClientGUI::handlePlv(std::vector<std::string> &data) {
    if (data.size() != 3)
        return;
    _gameData->updatePlayerLevel(std::stoi(data[1]), std::stoi(data[2]));
}

void ClientGUI::handlePin(std::vector<std::string> &data) {
    if (data.size() != 11)
        return;
    _gameData->updatePlayerInventory(std::stoi(data[1]), data);
}

void ClientGUI::handlePex(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    std::cout << "pex" << std::endl;
}

void ClientGUI::handlePbc(std::vector<std::string> &data) {
    std::size_t id;
    std::string message;

    if (data.size() < 3)
        return;
    id = _gameData->getPlayerId(std::stoi(data[1]));
    if (id == -1)
        return;
    for (int i = 2; i < data.size(); i++)
        message += data[i] + " ";
    _gameData->addMessageToPlayer(id, message);
}

void ClientGUI::handlePic(std::vector<std::string> &data) {
    std::vector <std::string> players;

    if (data.size() < 4)
        return;
    for (int i = 4; i < data.size(); i++)
        players.push_back(data[i]);
    _gameData->startIncantation(players);
}

void ClientGUI::handlePie(std::vector<std::string> &data) {
    if (data.size() != 4)
        return;
    std::cout << "pie" << std::endl;
    _gameData->endIncantation(Vector2(std::stoi(data[1]), std::stoi(data[2])));
}

void ClientGUI::handlePfk(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    std::cout << "pfk" << std::endl;
}

void ClientGUI::handlePdr(std::vector<std::string> &data) {
    if (data.size() != 3)
        return;
    std::cout << "pdr" << std::endl;
}

void ClientGUI::handlePgt(std::vector<std::string> &data) {
    if (data.size() != 3)
        return;
    std::cout << "pgt" << std::endl;
}

void ClientGUI::handlePdi(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    _gameData->deletePlayer(std::stoi(data[1]));
}

void ClientGUI::handleEnw(std::vector<std::string> &data) {
    if (data.size() != 5)
        return;
    _gameData->createEgg(Vector2(std::stoi(data[3]), std::stoi(data[4])), std::stoi(data[1]), std::stoi(data[2]));
}

void ClientGUI::handleEbo(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    std::cout << "ebo" << std::endl;
}

void ClientGUI::handleEdi(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    _gameData->deleteEgg(std::stoi(data[1]));
}

void ClientGUI::handleSgt(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    std::cout << "sgt" << std::endl;
}

void ClientGUI::handleSst(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    std::cout << "sst" << std::endl;
}

void ClientGUI::handleSeg(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    std::cout << "seg" << std::endl;
}

void ClientGUI::handleSmg(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    std::cout << "smg" << std::endl;
}

void ClientGUI::handleSuc(std::vector<std::string> &data){
    if (data.size() != 2)
        return;
    std::cout << "suc" << std::endl;
}

void ClientGUI::handleSbp(std::vector<std::string> &data) {
    if (data.size() != 2)
        return;
    std::cout << "sbp" << std::endl;
}
