NAME	=	pipex
NAME_B	=	pipex_bonus
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c\
			process.c\
			utils.c

SRCS_B	=	pipex_bonus.c\
			process.c\
			utils.c		

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

%.o: %.c
			@${CC} ${FLAGS} -I. -I./libft -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS}
			@make re -C ./libft
			@${CC} ${FLAGS} -o ${NAME} ${OBJS} -L./libft -lft
			@echo "\033[32mPipex Compiled!\033"

bonus:		${NAME_B}

${NAME_B}:	${OBJS_B}
			@make re -C ./libft
			@${CC} ${FLAGS} -o ${NAME_B} ${OBJS_B} -L./libft -lft
			@echo "\033[32mPipex_bonus Compiled!\033"
clean:
			@make clean -C ./libft
			@rm -f ${OBJS} ${OBJS_B}
			@echo "\033[32mPipex Cleaned!\033"

fclean:		clean
			@rm -f ${NAME} ${NAME_B}
			@make fclean -C ./libft

re:			fclean all

re_bonus:	fclean bonus

.PHONY:		all clean fclean re re_bonus bonus