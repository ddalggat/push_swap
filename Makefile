CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

LIBFT = libft/libft.a

SRCS 	=	parser.c lists.c \
			push.c reverse.c \
			rotate.c swap.c \
			indexing.c three_nums.c \
			marking.c source.c \
			push_back.c sorting.c \
			source_second.c main.c \

SRCS_BONUS	=	bonus/checker.c parser.c \
				bonus/swap_bonus.c lists.c \
				bonus/push_bonus.c source.c \
				bonus/rotate_bonus.c \
				bonus/reverse_bonus.c \
				gnl/get_next_line.c gnl/get_next_line_utils.c

DEPS	=	push_swap.h \
			libft/libft.h \
			gnl/get_next_line.h \

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${SRCS_BONUS:.c=.o}

all:		${NAME}

bonus:		$(BONUS_NAME)

.c.o: ${SRCS}
			@$(CC) $(CFLAGS) -o $@ -c $<
			
$(LIBFT):
			@make -C "libft"

$(NAME):	$(OBJS) $(LIBFT) $(DEPS) libft/*.c
			@$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(DEPS) libft/*.c
			@$(CC) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
		
clean:		
			@$(RM) $(OBJS) $(BONUS_OBJS)
			@make clean -C "libft"
	
fclean:		clean
			@$(RM) $(NAME) $(BONUS_NAME)
			@make fclean -C "libft"

re:			fclean all

.PHONY:		all clean fclean re