NAME			= run_test.out
SIZE			= 42

CC 				= cc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=$(SIZE) -g
RM				= rm -fr
INC_FLAG	= -I ../ -I ./

SRC				= ../get_next_line.c ../get_next_line_utils.c
OBJ				= $(SRC:.c=.o)

SRC_B			= ../get_next_line_bonus.c ../get_next_line_utils_bonus.c
OBJ_B			= $(SRC_B:.c=.o)

T_MAN	= utils.o mandatory.o
T_BON	= utils.o bonus.o

COLOR_WHITE	= \e[00m
COLOR_GREEN	= \e[32m
COLOR_RED		= \e[91m

all: m

../%.o: ../%.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
	@$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

%.o: %.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
	@$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

m: $(T_MAN) $(OBJ)
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)test mandatory > $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(T_MAN) $(OBJ)

b: $(T_BON) $(OBJ_B)
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)test bonus > $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(T_BON) $(OBJ_B)

clean:
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)all objects"
	@$(RM) $(OBJ) $(OBJ_B) $(T_MAN) $(T_BON)

fclean: clean
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)$(NAME)"
	@$(RM) $(NAME)

.PHONY: all clean fclean m b