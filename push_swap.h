/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:29:42 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/24 20:04:51 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

#include <stdio.h> // APAGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int	    ft_isdigit(int c);
long    ft_atol(const char *nptr);
int     ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char *s, char c);
int     arraylen(char **arr);
void	free_array(char **arr);
int     show_error(char **arr);
char    **prepare_to_convert(char **entry, int args);
int     is_convertible(char **entry, int args);
int     *parse_to_int(char **str_arr, int size);
int     is_duplicate(int *nums, int size);
int     *get_index(int *numbers, int numbers_size);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void    create_stack_a(t_stack **a, int *numbers, int *indexes, int size);
void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *lst);
void    swap_x(t_stack **head_a, t_stack **head_b, char stack);
void    push_x(t_stack **head_1, t_stack **head_2, char stack);
void    rotate_x(t_stack **head_a, t_stack **head_b, char stack);
void    reverse_rotate_x(t_stack **head_a, t_stack **head_b, char stack);
void    sort_3(t_stack **src, t_stack **dest);
void    send_to_b(t_stack **stack_a, t_stack **stack_b);
void 	calculate_position(t_stack **head);
void 	calculate_target_position(t_stack **head_a, t_stack **head_b);
void 	calculate_cost_b(t_stack **head);
void 	calculate_cost_a(t_stack **head_a, t_stack **head_b);
t_stack *get_biggest(t_stack *head);
t_stack *get_smallest(t_stack *head);
t_stack *choose_node_to_move(t_stack *head_b);

#endif