/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:35:27 by gabrieol          #+#    #+#             */
/*   Updated: 2026/02/02 15:03:32 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	*treat_entry(char **entry, int args, int *numbers_size)
{
	char	**treated_entry;
	int		*numbers;

	if (ft_strlen(entry[1]) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
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
