NAME		=	fractol
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# Includes
INC			=	-I ./Libft/\
				-I ./minilibx_opengl/\
				-I.

SRC			=	./srcs/main.c\
				./srcs/initialise.c\
				./srcs/control.c\
				./srcs/utils.c\
				./srcs/render.c\
				./srcs/math.c

OBJ			=	$(SRC:.c=.o)

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:		$(NAME)

$(NAME):	$(OBJ)
				@echo "\033[36mMaking Libft...\033[0m"
				@make -C ./Libft
				@echo "\033[36mMaking mlx...\033[0m"
				@make -C ./minilibx_opengl
				@echo "\033[36mMaking fractol...\033[0m"
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L./Libft -lft\
				-L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit
				@echo "\033[36mfractol compiled\033[0m"
				@echo "\033[36mSupport set:mandelbrot, julia, mandelbar\033[0m"
				@echo "\033[36m	Example: ./fractol mandelbrot\033[0m"
				@echo "\033[36m	Example: ./fractol julia -0.80 0.156\033[0m"
				@echo "\033[36m	Example: ./fractol mandelbar\033[0m"


clean:		
			@make clean -C ./Libft
			@make clean -C ./minilibx_opengl
			@rm -f $(OBJ)
			@echo "\033[31mCleaned\033[0m"

fclean:		
			@make fclean -C ./Libft
			@make fclean -C ./minilibx_opengl
			@rm -f $(OBJ)
			@rm -f $(NAME)
			@echo "\033[31mCleaned everything\033[0m"

re:			fclean all

.PHONY: all clean fclean re
