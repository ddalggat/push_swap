CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT = libft/libft.a

SRCS 	=	parser.c lists.c \
			push.c reverse.c \
			rotate.c swap.c \
			indexing.c three_nums.c \
			marking.c source.c \
			push_back.c main.c \

DEPS	=	push_swap.h \
			libft/libft.h \

OBJS = ${SRCS:.c=.o}

all:		${NAME}

.c.o: ${SRCS}
			@$(CC) $(CFLAGS) -o $@ -c $<
			
$(LIBFT):
			@make -C "libft"

$(NAME):	$(OBJS) $(LIBFT) $(DEPS) libft/*.c
			@$(CC) $(OBJS) $(LIBFT) -o $(NAME)
		
clean:		
			@$(RM) $(OBJS) $(BONUS_OBJS)
			@make clean -C "libft"
	
fclean:		clean
			@$(RM) $(NAME) $(BONUS_NAME)
			@make fclean -C "libft"
		
re:			fclean all

.PHONY:		all clean fclean re