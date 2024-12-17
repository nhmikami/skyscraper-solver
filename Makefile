NAME		=	skyscraper-solver
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRCS		=	src/main.c src/solve.c src/count.c
OBJS		=	$(SRCS:.c=.o)
INCLUDES	=	include/header.h

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $(OBJS)


%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re