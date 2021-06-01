NAME = hash_table
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
