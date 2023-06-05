##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

NAME	=	zappy_gui

all:
	cmake -B build;make -C build;mv build/${NAME} .

re: fclean all

clean:
	rm -rf build
	rm -rf cmake-build-debug

fclean: clean
	rm -rf ${NAME}

.PHONY: all re clean fclean
