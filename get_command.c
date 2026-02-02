/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:50:50 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/31 16:50:50 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_command(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate_x(a, b, 'a');
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate_x(a, b, 'b');
	else if (!ft_strncmp(line, "rrr\n", 4))
		reverse_rotate_x(a, b, 'r');
	else if (!ft_strncmp(line, "sa\n", 3))
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
	else
		return (0);
	return (1);
}

static void	error_exit(t_stack **a, t_stack **b, char *line)
{
	if (line)
		free(line);
	ft_lstclear(a);
	ft_lstclear(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	get_command(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_command(line, a, b))
			error_exit(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}
