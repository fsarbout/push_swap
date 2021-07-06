# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 16:40:08 by fsarbout          #+#    #+#              #
#    Updated: 2021/07/06 10:01:26 by fsarbout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c\
	   ft_isdigit.c\
	   ft_itoa.c\
	   ft_putstr.c\
	   ft_strdup.c\
	   ft_strjoin.c\
	   ft_strlcat.c\
	   ft_strlcpy.c\
	   ft_strlen.c\
	   ft_strncmp.c\
	   ft_substr.c\
	   ft_putstr_fd.c\
	   get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME):
	@$(CC) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf *.o

fclean:clean
	@rm -rf $(NAME) 

re: fclean all