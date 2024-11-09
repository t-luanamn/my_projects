NAME	= megaphone

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= megaphone.cpp

OBJ		= $(SRC:.cpp=.o)

.SILENT:

all:	$(NAME)

$(NAME): $(OBJ)
		echo "\033[36mMaking megaphone...\033[0m"
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)
		echo "\033[36mmegaphone compiled\033[0m"

clean:		
			rm -f $(OBJ)
			echo "\033[31mCleaned\033[0m"

fclean:		
			rm -f $(OBJ)
			rm -f $(NAME)
			echo "\033[31mCleaned everything\033[0m"

re:			fclean all

.PHONY: all clean fclean re
