/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:33:10 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/30 19:06:15 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_entry(int argc, char **argv, int *numbers_size)
{
	int	*numbers;

	numbers = NULL;
	if (argc < 2)
		exit(1);
	if (argc >= 2)
	{
		numbers = treat_entry(argv, argc - 1, numbers_size);
		if (*numbers_size == 0 || *numbers_size == 1)
			{
				free(numbers);
				exit(0);
			}
	}
	return (numbers);
}

static int	is_sorted(t_stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
static int	exec_command(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap_x(a, b, 'a');
	else if (!ft_strncmp(line, "sb\n", 3))
		swap_x(a, b, 'b');
	else if (!ft_strncmp(line, "ss\n", 3))
		swap_x(a, b, 's');
	else if (!ft_strncmp(line, "pa\n", 3))
		push_x(a, b, 'a');
	else if (!ft_strncmp(line, "pb\n", 3))
		push_x(a, b, 'b');
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate_x(a, b, 'a'); 
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate_x(a, b, 'b');
	else if (!ft_strncmp(line, "rr\n", 3))
		rotate_x(a, b, 'r');
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate_x(a, b, 'a');
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate_x(a, b, 'b');
	else if (!ft_strncmp(line, "rrr\n", 4))
		reverse_rotate_x(a, b, 'r');
	else
		return (0);
	return (1);
}
void	exit_write(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		numbers_size;
	char	*line;
	t_stack	*a;
	t_stack	*b;

	numbers = check_entry(argc, argv, &numbers_size);
	a = NULL;
	b = NULL;
	create_stack_a(&a, numbers, numbers_size);
	line = get_next_line(0);
	while (line)
	{
		exec_command(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	free(numbers);
	ft_lstclear(&a);
	ft_lstclear(&b);
	exit_write(a,b);
	return (0);
}
