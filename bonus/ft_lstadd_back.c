/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:12:56 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/31 17:25:05 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*last_node;

	if (!new_node || !lst)
		return ;
	last_node = ft_lstlast(*lst);
	if (!last_node)
		*lst = new_node;
	else
	{
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
