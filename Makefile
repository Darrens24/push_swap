NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
		errors.c \
		push_swap.c \
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./Libft
	$(CC) $(FLAGS) -I ./ -LLibft -lft $(SRC) -o $@ ./Libft/libft.a

clean:
	rm -f $(OBJ)
	@make clean -C ./Libft

fclean: clean
	rm -f $(NAME) 
	@make fclean -C ./Libft

re: fclean all
