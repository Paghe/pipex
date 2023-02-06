FLAGS = -fsanitize=address -g -Wall -Wextra -Werror

NAME = pipex
SRC = main.c \
		 pipex_input.c	\
		 error.c			\
		 child.c			\
		 path.c 			\
		 init_args.c		\
		 free.c 			\
		 init_pipe.c		\

OBJ = $(SRC:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ) pipex.h
	make -C libft
	cc $(LINKFLAGS) $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft
fclean:
	make clean
	rm -f $(NAME)

re: fclean all
