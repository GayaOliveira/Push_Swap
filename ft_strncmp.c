/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:53:58 by gabrieol          #+#    #+#             */
/*   Updated: 2026/01/30 18:57:39 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (ps1[i] && ps2[i] && i < n - 1 && ps1[i] == ps2[i])
	{
		i++;
	}
	return (ps1[i] - ps2[i]);
}
/*#include <stdio.h>
int main(void)
{
	char s1[] = "sus";
	char s2[] = "sos";
	
	printf("%i",ft_strncmp(s1,s2,3));
}*/
