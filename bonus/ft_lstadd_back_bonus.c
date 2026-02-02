/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:12:56 by gmarinho          #+#    #+#             */
/*   Updated: 2026/02/02 18:43:25 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
