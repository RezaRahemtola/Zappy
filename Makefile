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

clean:
	$(MAKE) -C server clean
	$(MAKE) -C gui clean

fclean:
	$(MAKE) -C server fclean
	$(MAKE) -C gui fclean
	rm -f zappy_server
	rm -f zappy_gui
	rm -f zappy_ai

re: fclean all
