NAME		= libftprintf.a
SRCS		= ft_printf.c \
	   		ft_print_c.c \
			ft_print_id.c \
			ft_print_p.c \
			ft_print_percent.c \
			ft_print_s.c \
			ft_print_u.c \
			ft_print_x.c \
			ft_fn.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re Libft