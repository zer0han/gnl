# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 15:29:22 by rdalal            #+#    #+#              #
#    Updated: 2024/09/05 15:33:12 by rdalal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = get_next_line.a

INCLUDES    = get_next_line.h

CC          = gcc
 
CFLAGS      = -Wall -Werror -Wextra

AR          = ar rcs

SRCS        = get_next_line.c get_next_line_utils.c main.c
 
OBJS        = $(SRCS:.c=.o)
 
all: $(NAME)
 
$(NAME): $(OBJS) $(INCLUDES)
		$(AR) $(NAME) $(OBJS)
 
clean:
		rm -f $(OBJS)
 
fclean: clean
		rm -f $(NAME)
 
re: fclean all
 
.PHONY: all clean fclean re
