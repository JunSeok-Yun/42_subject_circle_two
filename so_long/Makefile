NAME = so_long
MAKELFAG += --silent
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILES = error.c so_long.c get_next_line.c get_next_line_utils.c check_exception.c check_exception2.c \
		free.c dfs.c draw_map.c move_player.c ft_itoa.c ft_print_hex.c ft_print_unsigned.c ft_print_ptr.c \
		ft_printf.c ft_put_func.c

OBJS = $(FILES:.c=.o)

all: $(NAME)
				echo "Make!"

$(NAME): $(OBJS)
		make -C ./minilibx-linux/
		$(CC)	$(CFLAGS)	$(OBJS)	-o	${NAME} -L./minilibx-linux -lmlx -lXext -lX11

clean:
		$(RM)	$(OBJS)

fclean: clean
		$(RM)	$(NAME)

re:	fclean	$(NAME)

.PHONY:	all	clean	fclean	re