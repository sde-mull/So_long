NAME=		libft.a
RM=			rm -f

CC=			gcc
CFLAGS=		\
			-Wall\
			-Werror\
			-Wextra\

SRCS=		$(shell find . -maxdepth 1 -type f -name "*.c")
OBJS=		$(patsubst %.c,%.o,$(SRCS))

all: $(NAME) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re