/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:17:52 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/21 19:08:10 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_lstnew(int value, int index, int pos)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->pos = pos;
	new->target_pos = 0;
    new->cost_a = 0;
	new->cost_b = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void    create_stack_a(t_stack **a, int *numbers, int *indexes, int size)
{
    int i;
    t_stack *node;

    i = 0;
    while (i < size)
    {
        node = ft_lstnew(numbers[i], indexes[i], i);
        ft_lstadd_back(a, node);
        i++;
    }
}