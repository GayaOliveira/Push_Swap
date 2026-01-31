/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/31 17:25:05 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*second_node_src;

	second_node_src = (*src)->next;
	if (!(*dest))
	{
		*dest = *src;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->prev = *src;
		(*src)->next = *dest;
		*dest = (*dest)->prev;
	}
	if (second_node_src)
	{
		second_node_src->prev = NULL;
		*src = second_node_src;
	}
	else
		*src = NULL;
}

void	push_x(t_stack **src, t_stack **dest, char stack)
{
	if (stack == 'a')
	{
		push(dest, src);
		write(1, "pa\n", 3);
	}
	else
	{
		push(src, dest);
		write(1, "pb\n", 3);
	}
}
