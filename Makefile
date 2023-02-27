CC =	gcc -fsanitize=address -g
NAME =	so_long
RM =	rm -f
CD =	cd

CFLAGS = -Wall -Werror -Wextra

GREEN =		\033[0;32m
YELLOW =	\033[0;33m
RED =		\033[0;31m
RESET =		\033[0m

SRC_DIR =	src
LIB_DIR =	libft
PRINT_DIR =	printf
GET_DIR =	get_next_line
MLX_LIB =	mlx/libmlx.a -lmlx -framework OpenGL -framework AppKit

OBJS	= $(SRCS:.o=.c)

all: $(NAME)

$(NAME): $(SRCS)
		@echo "$(YELLOW)[ Compiling so_long... ] $(RESET)"
		@$(MAKE) all -C ./libft
		@$(MAKE) all -C ./libft/printf
		@$(CC) $(SRC_DIR)/*.c $(LIB_DIR)/$(LIB_DIR).a\
		$(LIB_DIR)/$(PRINT_DIR)/libftprintf.a $(LIB_DIR)/$(GET_DIR)/*.c\
		$(OBJS) $(MLX_LIB) -o $(NAME)
		@echo "$(GREEN)[ So_long is compiled! ] $(RESET)"

libft:
	@$(MAKE) all -C ./libft

printf:
	@$(MAKE) all -C ./libft/printf

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(CD) $(LIB_DIR) && make -i fclean
	@$(CD) $(LIB_DIR)/$(PRINT_DIR) && make -i fclean
	@$(RM) $(NAME)
	@echo "$(RED)[ Everything has been removed! ] $(RESET)"

init: all
	@echo "$(GREEN)[ Starting Game! ] $(RESET)"
	@./so_long maps/map4.ber
	@echo "$(RED)[ Game closed! ] $(RESET)"

re: fclean all

.PHONY: all libft printf clean fclean init re