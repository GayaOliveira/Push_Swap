/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieol <gabrieol@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:47:48 by gabrieol          #+#    #+#             */
/*   Updated: 2025/11/25 15:14:55 by gabrieol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	get_line(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size && buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*get_next(char *temps)
{
	int	sizet;

	if (!temps || temps[0] == '\0')
		return (NULL);
	sizet = get_line(temps, ft_strlen(temps));
	if (sizet >= 0)
		return (ft_substr(temps, 0, sizet + 1));
	return (ft_strdup(temps));
}

static char	*get_new_temps(char *temps)
{
	int		i;
	char	*new;

	i = get_line(temps, ft_strlen(temps));
	if (i < 0)
	{
		free(temps);
		return (NULL);
	}
	new = ft_substr(temps, i + 1, ft_strlen(temps) - (i + 1));
	free(temps);
	return (new);
}

static char	*read_until_line(char *temps, int fd)
{
	int		size;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (get_line(temps, ft_strlen(temps)) < 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buffer[size] = '\0';
		temps = ft_strjoin_get(temps, buffer);
	}
	free(buffer);
	return (temps);
}

char	*get_next_line(int fd)
{
	static char	*temps;
	char		*line;

	if (!temps)
		temps = ft_strdup("");
	temps = read_until_line(temps, fd);
	if (!temps)
		temps = (NULL);
	line = get_next(temps);
	if (!line)
	{
		free(temps);
		temps = NULL;
		return (NULL);
	}
	temps = get_new_temps(temps);
	return (line);
}
