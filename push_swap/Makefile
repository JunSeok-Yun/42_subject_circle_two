NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -rf

FILES = push_swap.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c sort.c sort2.c \
		stack_a_operate.c stack_b_operate.c stack_ab_operate.c ft_split.c ft_split_utils.c\
		ft_atoi.c check_exception.c ft_itoa.c ft_print_hex.c ft_print_ptr.c \
		ft_print_unsigned.c ft_printf.c ft_put_func.c free.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(AR)	$@	$^
		@${CC}	${CFLAGS}	${OBJS}	-o	${NAME}

clean:
		$(RM)	$(OBJS)

fclean:		clean
		$(RM)	$(NAME)

re:			fclean	$(NAME)

.PHONY:	all	clean	fclean	re
