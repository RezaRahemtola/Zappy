# Zappy

Epitech Project - 2nd Year PGE


## Description

The goal of this project is to create a network game where several teams confront on a tiles map containing resources. Each team has players controlled by artificial intelligences.\
The objective is to collect resources to survive, reproduce and perform rituals to level up.\
The first team with 6 players at the maximum level wins the game 🎮

The project is divided in 3 parts:
- [Server](./server): created in C, it that generates the inhabitants' world and contains the game logic. 
- [GUI](./gui/): created in C++, it connects to the server to follow the progress of the game.
- [AI](./ai/): created in Python, it controls an inhabitant through orders sent to the server.


## Getting started 🔧

### Installation
```
git clone git@github.com:RezaRahemtola/Zappy.git
cd Zappy
make
```
> 💡 You should have the Raylib installed to run the GUI, follow [this official guide](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux) to install it.

### Quickstart 🚀

Launch the server:
```sh
./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
```

Launch the GUI:
```sh
./zappy_gui -p port -h machine
```

Launch the AI:
```sh
./zappy_ai -p port -n name -h machine
```


## Developers 💻
| [<img src="https://github.com/Tomi-Tom.png?size=85" width=85><br><sub>Tom Bariteau-Peter</sub>](https://github.com/Tomi-Tom) | [<img src="https://github.com/Steci.png?size=85" width=85><br><sub>Léa Guillemard</sub>](https://github.com/Steci) | [<img src="https://github.com/Croos3r.png?size=85" width=85><br><sub>Dorian Moy</sub>](https://github.com/Croos3r) | [<img src="https://github.com/pablo0675.png?size=85" width=85><br><sub>Pablo Levy</sub>](https://github.com/pablo0675) | [<img src="https://github.com/RezaRahemtola.png?size=85" width=85><br><sub>Reza Rahemtola</sub>](https://github.com/RezaRahemtola)
| :---: | :---: | :---: | :---: | :---: