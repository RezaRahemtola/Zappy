##
## EPITECH PROJECT, 2021
## Zappy
## File description:
## Makefile of the project
##

all: zappy_server zappy_gui zappy_ai

zappy_server:
	$(MAKE) -C server

zappy_gui:
	$(MAKE) -C gui

zappy_ai:
	$(MAKE) -C ai
