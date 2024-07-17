NAME		=	philo
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# Includes
INC			=	-I.

SRC			=	main.c \
				clean.c \
				error.c \
				initialise.c \
				input_handler.c \
				print.c \
				set_status.c \
				simulation.c \
				thread.c \
				time.c \
				watcher.c

OBJ			=	$(SRC:.c=.o)

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:		$(NAME)

$(NAME):	$(OBJ)
				@echo "\033[36mMaking philo...\033[0m"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) 
				@echo "\033[36mphilo compiled\033[0m"

clean:		
			@rm -f $(OBJ)
			@echo "\033[31mCleaned\033[0m"

fclean:		
			@rm -f $(OBJ)
			@rm -f $(NAME)
			@echo "\033[31mCleaned everything\033[0m"

re:			fclean all

.PHONY: all clean fclean re
