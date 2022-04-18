NAME	= tests.out
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -fr
SRC		= get_next_line*
MAIN	= tests.c

all: norm
	$(CC) $(CFLAGS) $(MAIN) -o $(NAME)

norm:
	$(NORM) $(SRC)

clean:
	$(RM) $(NAME)

re: clean all