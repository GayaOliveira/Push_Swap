/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:33:10 by gabrieol          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:32 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	*check_entry(int argc, char **argv, int *numbers_size)
{
	int	*numbers;

	if (argc < 2)
		return (NULL);
	numbers = treat_entry(argv, argc - 1, numbers_size);
	if (*numbers_size <= 1)
	{
		free(numbers);
		exit(0);
	}
	return (numbers);
}

static int	is_sorted(t_stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	exit_write(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		numbers_size;
	t_stack	*a;
	t_stack	*b;

	numbers = check_entry(argc, argv, &numbers_size);
	if (!numbers)
		return (0);
	a = NULL;
	b = NULL;
	create_stack_a(&a, numbers, numbers_size);
	get_command(&a, &b);
	free(numbers);
	exit_write(a, b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
