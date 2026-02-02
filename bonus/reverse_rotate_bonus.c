/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gmarinho          #+#    #+#             */
/*   Updated: 2026/02/02 18:43:25 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack	*last_node;
	t_stack	*penultimate_node;

	if (ft_lstsize(*head) <= 1)
		return ;
	last_node = ft_lstlast(*head);
	penultimate_node = last_node->prev;
	penultimate_node->next = NULL;
	last_node->prev = NULL;
	last_node->next = *head;
	(*head)->prev = last_node;
	*head = last_node;
}

void	reverse_rotate_x(t_stack **head_a, t_stack **head_b, char stack)
{
	if (stack == 'a')
	{
		reverse_rotate(head_a);
		write(1, "rra\n", 4);
	}
	else if (stack == 'b')
	{
		reverse_rotate(head_b);
		write(1, "rrb\n", 4);
	}
	else
	{
		reverse_rotate(head_a);
		reverse_rotate(head_b);
		write(1, "rrr\n", 4);
	}
}
