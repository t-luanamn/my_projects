NAME	= zombie

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= Zombie.cpp newZombie.cpp randomChump.cpp main.cpp

OBJ		= $(SRC:.cpp=.o)

HEADER	= Zombie.hpp

.SILENT:

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			echo "\033[36mMaking Zombie...\033[0m"
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			echo "\033[36mZombie compiled\033[0m"
			echo "\033[32mExecution: ./zombie\033[0m"

%.o: %.cpp
			$(CC) $(FLAGS) -c $< -o $@

clean:		
			rm -f $(OBJ)
			echo "\033[31mCleaned\033[0m"

fclean:		
			rm -f $(OBJ)
			rm -f $(NAME)
			echo "\033[31mCleaned everything\033[0m"

re:			fclean all

.PHONY: all clean fclean re
