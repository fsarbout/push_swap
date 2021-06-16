/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:40:09 by fsarbout          #+#    #+#             */
/*   Updated: 2021/04/11 23:17:42 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

# define GREEN "\e[1;32m"
# define RED "\e[0;31m"

typedef	struct	s_stack{
	int				nb;
	struct s_stack	*next;
}				t_stack;

void	clear_list(t_stack **lst);
t_stack	*new_stack(int argc, char **argv);
void	print_list(t_stack **head);
void	list_add_front(t_stack **head , int nb);
void	list_add_back(t_stack **head, int nb);
void	exit_(t_stack **stack, char *string, int error);
int 	duplicate_int(t_stack **stack, int i);
int		not_number(char *str);
int 	is_valid_arg(t_stack **stack, char *str);
int		is_sorted(t_stack *stack);
int		ft_atoi_(t_stack **stack, const char *s);
// void	ft_putendl_fd(char *s, int fd, int newline);


 #endif