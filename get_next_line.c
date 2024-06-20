/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:31:04 by rdalal            #+#    #+#             */
/*   Updated: 2024/06/17 16:31:07 by rdalal           ###   ########.fr       */
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
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_remaining(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\0')
		i++;
	if (!buffer[i])
		return (NULL);
	new_buffer = (char *)ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!new_buffer)
		return (NULL);
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free (buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)ft_calloc(1, sizeof(char));
		buffer[0] = '\0';
	}
	if (!ft_strchr(buffer, '\n'))
		buffer = ft_read(buffer, fd);
	if (!buffer || buffer[0] == '\0')
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_extract_line(buffer);
	buffer = ft_get_remaining(buffer);
	return (line);
}
