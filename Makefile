CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
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
		calculate_position.c

# SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
# 			ft_lstsize_bonus.c ft_lstlast_bonus.c \
# 			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
# 			ft_lstclear_bonus.c ft_lstiter_bonus.c \
# 			ft_lstmap_bonus.c 

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -g

# bonus: $(OBJS) $(OBJS_BONUS)
# 	ar rcs $(OBJS) $^

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:
	rm -f $(NAME) $(OBJS) $(OBJS_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
