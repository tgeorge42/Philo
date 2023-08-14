NAME = philo

SRC = main.c philo_utils.c init.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror

CC = cc

RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY : all clean fclean re philo