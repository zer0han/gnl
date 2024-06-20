/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:31:19 by rdalal            #+#    #+#             */
/*   Updated: 2024/06/17 16:31:20 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			size_total;
	unsigned char	*pntr;

	if (nmemb != 0 && size != 0 && ((size_t) - 1 / nmemb < size))
		return (NULL);
	size_total = nmemb * size;
	pntr = malloc(size_total);
	if (pntr == NULL)
		return (NULL);
	i = 0;
	while (i < size_total)
	{
		pntr[i] = 0;
		i++;
	}
	return (pntr);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
	{
		free (result);
		return (NULL);
	}	
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	free (result);
	return (result);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char) c)
		return (&str[i]);
	return (NULL);
}

char	*ft_read(char *buffer, int fd)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		buffer = ft_strjoin (buffer, buf);
		if (ft_strchr(buffer, '\n'))
			return (buf);
	}
	free (buffer);
	return (buffer);
}
