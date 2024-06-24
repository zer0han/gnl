/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:31:11 by rdalal            #+#    #+#             */
/*   Updated: 2024/06/24 21:12:07 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char	*get_next_line(int fd);

char	*ft_read(char *str, int fd);

char	*ft_strchr(char *str, int c);

char    *ft_strjoin(char *s1, char *s2);

char	*ft_extract_line(char *buffer);

size_t	ft_strlen(char *str);

char	*ft_get_remaining(char *buffer);

void	*ft_calloc(size_t nmemb, size_t size);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
