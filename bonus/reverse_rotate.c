/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:00:08 by gabrieol          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:32 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack	*last_node;
	t_stack	*penultimate_node;

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
	}
	else if (stack == 'b')
	{
		reverse_rotate(head_b);
	}
	else
	{
		reverse_rotate(head_a);
		reverse_rotate(head_b);
	}
}
