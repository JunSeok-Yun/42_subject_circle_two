NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rc
RM = rm -rf
FILES = child_process.c ft_split_single_quote.c pipex_free.c pipex.c pipex_split.c pipex_utils.c print_error.c

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
