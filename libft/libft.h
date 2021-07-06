/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 09:00:09 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/06 10:05:23 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stddef.h>
#include "../includes/push_swap.h"

int			ft_isdigit(int c);
char		*ft_itoa(int n);
void		ft_putchar(char c);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr(char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_atoi(const char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

#  define BUFFER_SIZE 37

int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s1);
int			lenline(char *s1);
int			abc(int fd, char **s2, int rd);
int			search(char *str);
int			fr(char **s);

# endif
#endif
