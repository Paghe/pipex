FLAGS = -g -Wall -Wextra -Werror

NAME = pipex
SRC = main.c \
		parse.c \
		data.c  \
		free.c	\
		args.c 	\
		utils.c \
		child.c \
		error.c \

SRCB = bonus/main_bonus.c \
		bonus/parse_bonus.c \
		bonus/data_bonus.c  \
		bonus/free_bonus.c	\
		bonus/args_bonus.c 	\
		bonus/utils_bonus.c \
		bonus/child_bonus.c \
		bonus/error_bonus.c \

OBJ = $(SRC:.c=.o)

OBJSB =  $(SRCB:.c=.o)

LIBFT = ./libft/libft.a
all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ) pipex.h
	make -C libft
	cc $(LINKFLAGS) $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJSB)
	make clean -C libft

fclean:
	make clean
	rm -f $(NAME)

bonus: $(OBJSB)
	make -C libft
	cc $(OBJSB) $(LIBFT) $(FLAGS) -o $(NAME)

re: fclean all
