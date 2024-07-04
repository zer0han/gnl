/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:31:19 by rdalal            #+#    #+#             */
/*   Updated: 2024/07/04 18:17:08 by rdalal           ###   ########.fr       */
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
	if (!pntr)
		return (NULL);
	i = 0;
	while (i < size_total)
	{
		pntr[i] = '\0';
		i++;
	}
	return (pntr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (free(s1), NULL);
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
	result[i + j] = '\0';
	free (s1);
	return (result);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
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

char	*ft_read(char *str, int fd)
{
	char	*buffer;
	int		bytes_read;

	if (!str)
		str = ft_calloc(1, 1);
	if (!str)
		return (NULL);
	bytes_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(str), NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(str), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		str = ft_strjoin (str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), str);
}
