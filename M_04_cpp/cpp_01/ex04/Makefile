NAME	= sed

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= main.cpp Sed.cpp

OBJ		= $(SRC:.cpp=.o)

HEADER	= Sed.hpp

.SILENT:

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			echo "\033[36mMaking sed...\033[0m"
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			echo "\033[36msed compiled\033[0m"
			echo "\033[32mExecution: ./sed <filename> <s1:find> <s2:replace>\033[0m"

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
