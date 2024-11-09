NAME	= PhoneBook

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= PhoneBook.cpp Contact.cpp main.cpp

OBJ		= $(SRC:.cpp=.o)

HEADER	= PhoneBook.hpp Contact.hpp

.SILENT:

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			echo "\033[36mMaking PhoneBook...\033[0m"
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			echo "\033[36mPhoneBook compiled\033[0m"

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
