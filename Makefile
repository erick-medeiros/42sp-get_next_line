NAME	= tests.out
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=3
RM		= rm -fr
INC		= .
SRC		= get_next_line.c get_next_line_utils.c tests.c
SRC_B	= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ		= $(SRC:.c=.o)
OBJ_B	= $(SRC_B:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re