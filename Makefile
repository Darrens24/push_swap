NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = utils.c \
		utils2.c \
		errors.c \
		lists.c \
		instructions1.c \
		instructions2.c \
		sorting.c \
		main.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./Libft
	$(CC) $(FLAGS) -I ./ -LLibft -lft $(SRC) -o $@ ./Libft/libft.a

clean:
	rm -f $(OBJ)
	@make clean -C ./Libft

fclean:	clean
	rm -f $(NAME)
	@make fclean -C ./Libft

re:	fclean all

