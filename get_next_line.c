/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:31:04 by rdalal            #+#    #+#             */
/*   Updated: 2024/06/24 21:45:56 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + (buffer[i] == '\n') + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_get_remaining(char *buffer)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	dup = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!dup)
	{
		free (buffer);
		return (NULL);
	}
	i += 1;
	while (buffer[i])
		dup[j++] = buffer[i++];
	free (buffer);
	return (dup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
		{
			free (buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	if (!line)
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_get_remaining(buffer);
	return (line);
}
