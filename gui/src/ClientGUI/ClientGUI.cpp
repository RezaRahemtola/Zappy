/*
** EPITECH PROJECT, 2023
** Zappy Project
** File description:
** ClientGUI.cpp
*/

#include "ClientGUI.hpp"

void ClientGUI::sendRequest(std::string message) {
    std::cout << " - Sending request: " << message;
    _socket.send(message.c_str(), message.length());
}

void ClientGUI::collectMessage() {
    std::string buffer;
    size_t size;

    if (_socket.receiveNonBlocking(buffer, size) == sf::Socket::Done) {
        std::cout << " - Recieved: " << buffer;
        _receiveBuffer += buffer;
    }
}

bool ClientGUI::receiveNonBlocking(std::vector<char>& buffer) {
    sf::Socket::Status status = m_socket->receive(m_receiveBuffer, m_bufferSize, m_received);

    if (status == sf::Socket::Done) {
        buffer.assign(m_receiveBuffer, m_receiveBuffer + m_received);
        return true;
    } else {
        return false;
    }
}