/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_entry_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:35:27 by gmarinho          #+#    #+#             */
/*   Updated: 2026/02/02 19:10:06 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	is_empty_string(char **entry, int args)
{
	int	i;

	i = 1;
	while (i < args)
	{
		if (ft_strlen(entry[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	*treat_entry(char **entry, int args, int *numbers_size)
{
	char	**treated_entry;
	int		*numbers;

	is_empty_string(entry, args);
	treated_entry = prepare_to_convert(entry, args);
	*numbers_size = arraylen(treated_entry);
	if (!is_convertible(treated_entry, *numbers_size))
		show_error(treated_entry);
	numbers = parse_to_int(treated_entry, *numbers_size);
	if (!numbers)
		show_error(treated_entry);
	if (is_duplicate(numbers, *numbers_size))
	{
		write(2, "Error\n", 6);
		free(numbers);
		exit(1);
	}
	return (numbers);
}
