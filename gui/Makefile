##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

NAME	=	zappy_gui

all:
	cargo build --release
	cp target/release/$(NAME) .

run:
	cargo run --release

clean:
	cargo clean

fclean: clean
	rm -f $(NAME)
	rm -rf target

re: fclean all

.PHONY: all clean fclean re