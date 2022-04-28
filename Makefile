NAME	= run_test.out
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=3 -g
RM		= rm -fr
INC		= .
SRC		= get_next_line.c get_next_line_utils.c
SRC_B	= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ		= $(SRC:.c=.o)
OBJ_B	= $(SRC_B:.c=.o)

#TESTS

T_SRC	= tests/utils.c tests/mandatory.c tests/bonus.c
T_OBJ	= $(T_SRC:.c=.o)
T_MAN	= tests/utils.o tests/mandatory.o
T_BON	= tests/utils.o tests/bonus.o

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

tests/%.o: tests/*.o
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

bonus: $(NAME) $(OBJ_B)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_B)

clean:
	@$(RM) $(OBJ) $(OBJ_B) $(T_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

m: $(T_OBJ) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(T_MAN) $(OBJ)
	make clean

b: $(T_OBJ) $(OBJ_B)
	$(CC) $(CFLAGS) -o $(NAME) $(T_BON) $(OBJ_B)
	make clean

.PHONY: all clean fclean re bonus rebonus m b