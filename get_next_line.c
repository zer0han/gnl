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

/*char	*get_next_line(int fd)
{
	static int	counter;
	long		buffer_size;
	long		i;
	char		*line;

	counter = 0;
	buffer_size = 0;
	i = 0;
	while (line[i])
	{
		read (fd, &line, buffer_size);
		counter++;
		i++;
	}
	if (line[i])
		return (NULL);
	if (!line[i])
	{
		free (line);
		return (NULL);
	}
	return (line);
}*/
	// should read the text file pointed by the fd one line at a time 
	// can use static counter to read the lines
	// return value: the line that was read end with \n
	// should return NULL if nothing to read or error (free)
	// add flag when compiling -D BUFFER_SIZE=n to define the buffer size
	// try to read as little as possible.
	// don't read the file first and then  process it line by line (TO)

char	ft_extract_line(char *buffer)
{
	int	i;
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || read(fd, NULL, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = (char *)malloc(1 * sizeof(char));
	if (!ft_strchr(buffer, '\n'))
		buffer = ft_read(buffer, fd);
	if (!buffer[fd])
	{
		free (buffer);
		return (NULL);
	}
	line = ft_extract_line(buffer);
	buffer = ft_get_remaining(buffer);
	return (line);
}
