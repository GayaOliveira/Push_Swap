/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:17:52 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/31 17:25:05 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static t_stack	*ft_lstnew(int value, int index, int pos)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
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

void	create_stack_a(t_stack **a, int *numbers,
		int numbers_size)
{
	int		i;
	int		*indexes;
	t_stack	*node;

	indexes = get_index(numbers, numbers_size);
	i = 0;
	while (i < numbers_size)
	{
		node = ft_lstnew(numbers[i], indexes[i], i);
		ft_lstadd_back(a, node);
		i++;
	}
	free(indexes);
}
