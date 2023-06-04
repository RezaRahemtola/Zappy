##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

SRC_DIR =	src/

SRC		=	list/my_list_add.c \
			list/my_list_operations.c \
			list/my_list_remove.c

OBJ		=	$(addprefix $(SRC_DIR), $(SRC:.c=.o))

NAME	=	libmy.a

INC		=	include/

AR		=	ar rc
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Wpedantic
CPPFLAGS =	-iquote $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
