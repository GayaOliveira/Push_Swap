/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:12:56 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/20 18:32:36 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (!new || !lst)
		return ;
	last_node = ft_lstlast(*lst);
	if (!last_node)
		*lst = new;
	else
	{
		last_node->next = new;
		new->prev = last_node;
	}	
}
