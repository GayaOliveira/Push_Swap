/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarinho <gmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:19:18 by gmarinho          #+#    #+#             */
/*   Updated: 2026/02/02 18:43:25 by gmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	get_line_from_storage(char **line, char **storage)
{
	char	*detect_new_line;
	char	*temp;
	int		size;

	if (ft_strlen(*storage))
	{
		detect_new_line = ft_strchr(*storage, '\n');
		size = detect_new_line - *storage;
		if (detect_new_line)
		{
			*line = ft_strnjoin(*line, *storage, size);
			temp = *storage;
			*storage = ft_strdup(detect_new_line + 1);
			free(temp);
			return (1);
		}
		*line = ft_strnjoin(*line, *storage, ft_strlen(*storage));
		free(*storage);
		*storage = ft_strdup("");
	}
	return (0);
}

static int	get_line_from_buffer(char **line, char **storage, char *buffer)
{
	char	*detect_nl;
	int		size;

	detect_nl = ft_strchr(buffer, '\n');
	size = detect_nl - buffer;
	if (detect_nl)
	{
		*line = ft_strnjoin(*line, buffer, size);
		*storage = ft_strnjoin(*storage, detect_nl + 1, BUFFER_SIZE - size);
		return (1);
	}
	*line = ft_strnjoin(*line, buffer, BUFFER_SIZE);
	return (0);
}

static int	read_from_buffer(char **line, char **storage, int fd)
{
	char	*buffer;
	int		n_bytes;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (free(buffer), 0);
	n_bytes = read(fd, buffer, BUFFER_SIZE);
	while (n_bytes > 0)
	{
		buffer[n_bytes] = '\0';
		if (get_line_from_buffer(line, storage, buffer))
			break ;
		n_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (n_bytes == -1)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	int			read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (!storage)
		storage = ft_strdup("");
	if (get_line_from_storage(&line, &storage))
		return (line);
	read = read_from_buffer(&line, &storage, fd);
	if (line[0] == '\0')
	{
		free(storage);
		free(line);
		storage = NULL;
		return (NULL);
	}
	if (!read)
		return (free(storage), free(line), NULL);
	return (line);
}
