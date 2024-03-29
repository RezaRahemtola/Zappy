##
## EPITECH PROJECT, 2023
## Zappy Server
## File description:
## Makefile
##

BASE_DIR	= 	src
BASE_SRC	=	server.c \
				client/client.c \
				client/write.c \
				client/disconnect.c \
				params/params.c \
				params/setters.c \
				params/checks.c \
				params/eggs.c \
				network/socket.c \
				network/fd_set.c \
				network/select.c \
				network/messages/read.c \
				network/messages/parsing.c \
				commands/handling.c \
				commands/execute.c \
				commands/gui/msz.c \
				commands/gui/tna.c \
				commands/gui/sgt.c \
				commands/gui/sst.c \
				commands/gui/player.c \
				commands/gui/tiles.c \
				commands/gui/events/pnw.c \
				commands/gui/events/pbc.c \
				commands/gui/events/resource.c \
				commands/gui/events/egg.c \
				commands/gui/events/pdi.c \
				commands/gui/events/pex.c \
				commands/gui/events/incantation.c \
				commands/gui/events/events.c \
				commands/gui/events/end_game.c \
				commands/ai/connect_nbr.c \
				commands/ai/inventory.c \
				commands/ai/direction.c \
				commands/ai/broadcast.c \
				commands/ai/objects.c \
				commands/ai/fork.c \
				commands/ai/look.c \
				commands/ai/eject.c \
				commands/ai/incantation.c \
				utils/teams.c \
				utils/player.c \
				utils/tile.c \
				utils/strings.c \
				utils/random.c \
				utils/direction.c \
				utils/incantation.c \
				utils/time.c \
				game/player/player.c \
				game/map/map.c \
				game/map/refill_map.c \
				game/map/refill_tile.c \
				game/map/future_resource.c \
				game/game.c \
				game/end.c

TESTS_DIR	=	tests
TESTS_SRC	=

MAIN		=	main.c

SRC			=	$(addprefix $(BASE_DIR)/, $(BASE_SRC)) \
				$(addprefix $(BASE_DIR)/, $(MAIN))

TEST		=	$(addprefix $(BASE_DIR)/, $(BASE_SRC)) \
				$(addprefix $(TESTS_DIR)/, $(TESTS_SRC))

OBJ			=	$(SRC:.c=.o)
TEST_OBJ	=	$(TEST:.c=.o)

LIBS			=	my
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
			$(MAKE) $(LIBS)
			$(CC) -o $(BINARY) $(OBJ) $(LDFLAGS) $(LDLIBS)
			cd .. && ln -s server/$(BINARY) $(BINARY)

$(TEST_BINARY):	LDLIBS	+=	-lcriterion -lgcov
$(TEST_BINARY):	CFLAGS	+=	-ftest-coverage -fprofile-arcs
$(TEST_BINARY):	$(TEST_OBJ)
				$(MAKE) $(LIBS)
				$(CC) -o $(TEST_BINARY) $(TEST_OBJ) $(LDFLAGS) $(LDLIBS)

$(DEBUG_BINARY):	CFLAGS	+=	-g3
$(DEBUG_BINARY):	$(OBJ)
					$(MAKE) $(LIBS)
					$(CC) -o $(DEBUG_BINARY) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIBS):
		$(MAKE) -C $(@:%=lib/%)

clean:
		$(foreach lib, $(LIB_DIRS), make clean -C $(lib);)
		$(RM) $(OBJ) $(TEST_OBJ)

fclean:	clean
		$(foreach lib, $(LIB_DIRS), make fclean -C $(lib);)
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
