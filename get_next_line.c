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

	// should read the text file pointed by the fd one line at a time 
	// can use static counter to read the lines
	// return value: the line that was read end with \n
	// should return NULL if nothing to read or error (free)
	// add flag when compiling -D BUFFER_SIZE=n to define the buffer size
	// try to read as little as possible.
	// don't read the file first and then  process it line by line (TO)

char	*ft_extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
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
	{
		free (buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
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

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(1 * sizeof(char));
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
