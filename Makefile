
CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

LIB = ar rcs

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap

SRCS = push_swap.c utils_stacks.c utils_split_stack.c utils_algorithm.c\
		utils_towers.c utils_nodes.c utils_cost.c utils_move_a.c utils_swap.c\
		utils_rotate.c utils_push.c utils_cost.c utils_reverse.c utils_move_b.c\
		utils_reverses_nodes.c utils_rotates_nodes.c utils_cost1.c utils_move.c\
		utils_split_move.c 
		

OBJS = $(SRCS:.c=.o)
.SECONDARY: $(OBJS)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(LIBFT_DIR)
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
