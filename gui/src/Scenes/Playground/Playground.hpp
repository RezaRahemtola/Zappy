/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Playground.hpp
*/
#ifndef PLAYGROUND_HPP_
	#define PLAYGROUND_HPP_

    #include <SFML/Graphics.hpp>
    #include "ClientGUI.hpp"
    #include "IDisplay.hpp"
    #include "Button.hpp"
    #include "GameData.hpp"

class Playground : public IDisplay {
public:
    Playground(std::string machine, std::size_t port) : _pause(false), _machine(machine),
        _port(port), _client(ClientGUI(_machine, _port)), _gameData(GameData(10, 10)) {
        std::string data;

        _client.sending("GRAPHIC\n");
        sleep(1);

        // Setup la couleur
        sf::Color color = sf::Color(253, 217, 163);

        // Setup les Components UI
        _background = sf::RectangleShape(sf::Vector2f(1920, 1080));
        _background.setFillColor(sf::Color(48, 43, 52));
        _ButtonContainer = sf::RectangleShape(sf::Vector2f(1920, 200));
        _ButtonContainer.setPosition(sf::Vector2f(0, 920));
        _ButtonContainer.setFillColor(sf::Color(63, 57, 68));

        // Setup les boutons
        _playButton = Button("Play", sf::Vector2f(50, 950), sf::Vector2f(100, 50), color);
        _pauseButton = Button("Pause", sf::Vector2f(160, 950), sf::Vector2f(100, 50), color);
        _quitButton = Button("Quit", sf::Vector2f(1650, 950), sf::Vector2f(200, 50), color);
    };
    ~Playground() override {};

    std::string run(sf::RenderWindow &window) override;
    void display(sf::RenderWindow &window) override;

    void comunicateWithServer();

private:
    // Network
    int _port;
    std::string _machine;
    ClientGUI _client;
    std::string _buffer;

    // Content
    GameData _gameData;

    // Components UI
    sf::RectangleShape _background;
    sf::RectangleShape _ButtonContainer;

    // Boutons
    Button _pauseButton;
    Button _playButton;
    Button _quitButton;

    // Utils
    bool _pause;
    void handlePause();

    // handle receiving data
    void handleData();

    void handleMsz(std::string data);
    void handleBct(std::string data);
    void handleTna(std::string data);
    void handlePnw(std::string data);
    void handlePpo(std::string data);
    void handlePlv(std::string data);
    void handlePin(std::string data);
    void handlePex(std::string data);
    void handlePbc(std::string data);
    void handlePic(std::string data);
    void handlePie(std::string data);
    void handlePfk(std::string data);
    void handlePdr(std::string data);
    void handlePgt(std::string data);
    void handlePdi(std::string data);
    void handleEnw(std::string data);
    void handleEbo(std::string data);
    void handleEdi(std::string data);
    void handleSgt(std::string data);
    void handleSst(std::string data);
    void handleSeg(std::string data);
    void handleSmg(std::string data);
    void handleSuc(std::string data);
    void handleSbp(std::string data);
};

#endif /*PLAYGROUND_HPP_*/
