/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:29:53 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/30 19:13:56 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*numbers;
	int		numbers_size;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	if (argc >= 2)
	{
		numbers = treat_entry(argv, argc - 1, &numbers_size);
		if (numbers_size == 0 || numbers_size == 1)
		{
			free(numbers);
			return (0);
		}
		a = NULL;
		b = NULL;
		sort_list(numbers, numbers_size, &a, &b);
		ft_lstclear(&a);
		ft_lstclear(&b);
	}
	return (0);
}
