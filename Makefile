CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = push_swap
NAME_BONUS = checker
SRCS = push_swap.c ft_atol.c \
		ft_strdup.c ft_strlen.c \
		ft_isdigit.c ft_memcpy.c \
		ft_strjoin.c ft_split.c \
		arraylen.c show_error.c \
		validate_entry.c free_array.c \
		get_index.c ft_lstadd_back.c \
		ft_lstlast.c create_stack_a.c \
		ft_lstclear.c ft_lstsize.c \
		push.c swap.c rotate.c reverse_rotate.c \
		sort_3.c send_to_b.c \
		calculate_position.c calculate_target_pos.c \
		calculate_cost.c \
		get_extremes.c \
		choose_node_to_move.c \
		move_current_node.c \
		final_rotate.c \
		position_sort.c \
		sort_2.c is_sorted.c \
		treat_entry.c sort_list.c \

SRCS_BONUS = bonus/checker_bonus.c \
				bonus/clear_bonus.c \
				bonus/get_command.c \
				bonus/get_next_line.c \
				bonus/get_next_line_utils.c \
				bonus/ft_strncmp.c \
				bonus/ft_atol.c \
				bonus/ft_strdup.c bonus/ft_strlen.c \
				bonus/ft_isdigit.c bonus/ft_memcpy.c \
				bonus/ft_strjoin.c bonus/ft_split.c \
				bonus/arraylen.c bonus/show_error.c \
				bonus/validate_entry.c bonus/free_array.c \
				bonus/get_index.c bonus/ft_lstadd_back.c \
				bonus/ft_lstlast.c bonus/create_stack_a.c \
				bonus/ft_lstclear.c bonus/ft_lstsize.c \
				bonus/push.c bonus/swap.c bonus/rotate.c \
				bonus/reverse_rotate.c \
				bonus/treat_entry.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:
	rm -f $(NAME) $(OBJS) $(OBJS_BONUS) checker

re: fclean all

.PHONY: all clean fclean re bonus
