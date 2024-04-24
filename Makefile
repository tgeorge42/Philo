NAME = philo

SRC = src/main.c src/philo_utils.c src/init.c src/philos_actions.c src/check_death.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror -g3

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