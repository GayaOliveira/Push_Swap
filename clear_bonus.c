/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:40:32 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/31 16:46:34 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear(char *line, int *numbers, t_stack **a, t_stack **b)
{
	free(line);
	if (numbers)
		free(numbers);
	ft_lstclear(a);
	ft_lstclear(b);
	exit(1);
}
