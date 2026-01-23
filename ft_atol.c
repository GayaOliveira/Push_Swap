/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:36:22 by gmarinho          #+#    #+#             */
/*   Updated: 2026/01/12 20:34:17 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long	ft_atol(const char *nptr)
{
	char	*str;
	long		num;
	int		i;
	long		sign;

	str = (char *) nptr;
	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{		
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
/*
#include <stdio.h>
#include <stdlib.h> // For INT_MAX and INT_MIN (optional for overflow handling)
#include <limits.h>

int main() {
    printf("'%s' -> %d\n", "42", atoi("42"));
    printf("'%s' -> %d\n", "42", ft_atoi("42"));
    printf("'%s' -> %d\n", "   -42", atoi("   -42"));
    printf("'%s' -> %d\n", "   -42", ft_atoi("   -42"));
    printf("'%s' -> %d\n", "4193 with words", atoi("4193 with words"));
    printf("'%s' -> %d\n", "4193 with words", ft_atoi("4193 with words"));
    printf("'%s' -> %d\n", "words and 987", atoi("words and 987"));
    printf("'%s' -> %d\n", "words and 987", ft_atoi("words and 987"));
    printf("'%s' -> %d\n", "2147483647", atoi("2147483647")); // Max int
    printf("'%s' -> %d\n", "2147483647", ft_atoi("2147483647")); // Max int
    printf("'%s' -> %d\n", "-2147483648", atoi("-2147483648")); // Min int
    printf("'%s' -> %d\n", "-2147483648", ft_atoi("-2147483648")); // Min int
    return 0;
}
*/
