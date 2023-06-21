##
## EPITECH PROJECT, 2021
## Zappy
## File description:
## Makefile of the project
##

all:
	$(MAKE) -C server
	$(MAKE) -C gui
	$(MAKE) -C ai
	cp server/zappy_server .
	cp gui/zappy_gui .
	cp ai/zappy_ai .

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
