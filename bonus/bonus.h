/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:29:42 by gabrieol          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:32 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
}					t_stack;

int					ft_strncmp(const char *s1, const char *s2, int n);
int					ft_isdigit(int c);
long				ft_atol(const char *nptr);
int					ft_strlen(const char *str);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char *s1, char const *s2);
char				*ft_strjoin_get(char *s1, char *s2);
char				*ft_strjoin_gnl(char const *s1, char const *s2);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				**ft_split(char *s, char c);
int					arraylen(char **arr);
void				free_array(char **arr);
int					show_error(char **arr);
char				**prepare_to_convert(char **entry, int args);
int					is_convertible(char **entry, int args);
int					*parse_to_int(char **str_arr, int size);
int					is_duplicate(int *nums, int size);
int					*get_index(int *numbers, int numbers_size);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new_node);
void				create_stack_a(t_stack **a, int *numbers, int size);
void				ft_lstclear(t_stack **lst);
int					ft_lstsize(t_stack *lst);
void				swap_x(t_stack **head_a, t_stack **head_b, char stack);
void				push_x(t_stack **head_1, t_stack **head_2, char stack);
void				rotate_x(t_stack **head_a, t_stack **head_b, char stack);
void				reverse_rotate_x(t_stack **head_a, t_stack **head_b,
						char stack);
int					*treat_entry(char **entry, int args, int *numbers_size);
char				*get_next_line(int fd);
char				*ft_substr(char const *s, int start, int len);
void				clear(char *line, int *numbers, t_stack **a, t_stack **b);
void				get_command(t_stack **a, t_stack **b);

#endif