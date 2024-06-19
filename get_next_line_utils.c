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

static int	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '/0')
	{
		len++;
	}
	return (len);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	if (result)
	{
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			result[i + j] = s2[j];
			j++;
		}
		result [i + j] = '\0';
		return (result);
	}
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
	else
		return (NULL);
}

char	ft_change_buffer(char *buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(buffer, read_buffer);
	free (buffer);
	return (temp);
}

char	*ft_read(char *buffer, int fd)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
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
		buffer = ft_change_buffer (buffer, buf);
		if (ft_strchr(buffer, '\n'))
			return (buf);
	}
	free (buf);
	return (buffer);
}
