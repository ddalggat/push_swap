CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

PUSH_SWAP = ${NAME}.a

LIBFT= 	libft/libft.a

SRCS 	=	parser.c 

DEPS	=	push_swap.h \
			libft/libft.h \

OBJS = ${SRCS:.c=.o}

all:		${PUSH_SWAP}

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