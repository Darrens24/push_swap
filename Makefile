NAME = push_swap

NAMEBONUS = bonus/checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = utils.c \
		utils2.c \
		errors.c \
		errors_utils.c \
		lists.c \
		instructions1.c \
		instructions2.c \
		sorting.c \
		sorting_utils.c \
		sorting_utils2.c \
		bools.c \
		back_in_a.c \
		main.c \

SRCBONUS = bonus/my_checker.c \
		bonus/instructions_bonus.c \
		bonus/instructions_bonus2.c \
		utils.c \
		utils2.c \
		errors.c \
		errors_utils.c \
		lists.c \
		instructions1.c \
		instructions2.c \
		sorting.c \
		sorting_utils.c \
		sorting_utils2.c \
		bools.c \
		back_in_a.c \
		bonus/bonus_utils.c \

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./Libft
	$(CC) $(CFLAGS) -I ./ -LLibft -lft $(SRC) -o $@ ./Libft/libft.a

bonus: $(OBJBONUS)
	@make -C ./Libft
	$(CC) $(CFLAGS) -I ./ -LLibft -lft $(SRCBONUS) -o $(NAMEBONUS) ./Libft/libft.a
	 
clean:
	rm -f $(OBJ)
	rm -f $(OBJBONUS)
	@make clean -C ./Libft

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAMEBONUS)
	@make fclean -C ./Libft

re:	fclean all

