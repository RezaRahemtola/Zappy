##
## EPITECH PROJECT, 2023
## Zappy Server
## File description:
## Makefile
##

BASE_DIR	= 	src
BASE_SRC	=	server.c \
				params/params.c \
				params/setters.c \
				params/checks.c \
				network/socket.c

TESTS_DIR	=	tests
TESTS_SRC	=

MAIN		=	main.c

SRC			=	$(addprefix $(BASE_DIR)/, $(BASE_SRC)) \
				$(addprefix $(BASE_DIR)/, $(MAIN))

TEST		=	$(addprefix $(BASE_DIR)/, $(BASE_SRC)) \
				$(addprefix $(TESTS_DIR)/, $(TESTS_SRC))

OBJ			=	$(SRC:.c=.o)
TEST_OBJ	=	$(TEST:.c=.o)

LIBS			=
LIB_DIRS		=	$(addprefix lib/, $(LIBS))

BINARY			=	zappy_server
TEST_BINARY		=	$(BINARY).test
DEBUG_BINARY	=	$(BINARY).debug

HEADERS_DIRS 	=	include/ \
					$(LIB_DIRS:%=%/include/)

CFLAGS		=	-Wall -Wextra -Wpedantic
CPPFLAGS	=	$(HEADERS_DIRS:%=-iquote %)
LDLIBS		=	$(addprefix -l, $(LIBS))
LDFLAGS		=	$(addprefix -L, $(LIB_DIRS))

VG_FLAGS	=	--leak-check=full --track-origins=yes --show-leak-kinds=all \
				--error-limit=no

CC			=	gcc
VG			=	valgrind $(VG_FLAGS)

all:	$(BINARY)

$(BINARY):	$(OBJ)
			$(CC) -o $(BINARY) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(TEST_BINARY):	LDLIBS	+=	-lcriterion -lgcov
$(TEST_BINARY):	CFLAGS	+=	-ftest-coverage -fprofile-arcs
$(TEST_BINARY):	$(TEST_OBJ)
				$(CC) -o $(TEST_BINARY) $(TEST_OBJ) $(LDFLAGS) $(LDLIBS)

$(DEBUG_BINARY):	CFLAGS	+=	-g3
$(DEBUG_BINARY):	$(OBJ)
					$(CC) -o $(DEBUG_BINARY) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIBS):
		$(MAKE) -C $(@:%=lib/%)

clean:
		$(RM) $(OBJ) $(TEST_OBJ)

fclean:	clean
		$(RM) $(BINARY) $(TEST_BINARY) $(DEBUG_BINARY)

clean_coverage:	fclean
				find \( -name '*.gcno' -o -name '*.gcda' \) -delete

re:	fclean all

debug:	fclean $(DEBUG_BINARY)
		$(VG) ./$(DEBUG_BINARY) $(ARGS)

tests_run:
			@$(MAKE) clean_coverage > /dev/null
			@$(MAKE) $(TEST_BINARY) > /dev/null
			./$(TEST_BINARY)

check_coding_style:	fclean
			./scripts/coding-style.sh . .

.PHONY:	all	clean fclean clean_coverage re debug tests_run check_coding_style
