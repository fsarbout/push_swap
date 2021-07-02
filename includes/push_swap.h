/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:40:09 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/02 16:41:34 by fsarbout         ###   ########.fr       */
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
# define WHT "\e[0;37m"
# define YEL "\e[1;33m"
# define BLU "\e[1;34m"

typedef	struct	s_stack
{	
	int				nb;
	struct s_stack	*next;
}				t_stack;

/* lists */
void		clear_list(t_stack **lst);
t_stack		*new_stack(int argc, char **argv);
void		print_list(t_stack **head);
void		list_add_front(t_stack **head , int nb);
void		list_add_back(t_stack **head, int nb);
int			del_first_node(t_stack **list);
int			del_last_node(t_stack **list);
int			list_lenght(t_stack *a);

/* check args */
void		exit_(t_stack **a,t_stack **b, char *string, int error);
int 		duplicate_int(t_stack **stack, int i);
int			not_number(char *str);
int 		is_valid_arg(t_stack **stack, char *str);
int			is_sorted(t_stack *stack);
int			ft_atoi_(t_stack **stack, const char *s);

/* instructions */
void		swap(t_stack **stack, int key);
void		push(t_stack **stack_1 , t_stack **stack_2, int key);
void		rotate(t_stack **stack_1, int key);
void		reverse(t_stack **stack_1, int key);

/* instructions utils */
void		complex_instructions(char *instruction, t_stack **a, t_stack **b);
int			apply_instruction(char *line , t_stack **a , t_stack **b);
int 		*get_array(t_stack *a);
void 		push_swap(t_stack **a, t_stack **b, int  ac);
void		sort_three(t_stack **a);
void		sort_five(t_stack **a, t_stack **b);
void		sort_hundred(t_stack **a, t_stack **b);

/* quick_sort algo functions */
void 		ft_swap(int* a, int* b);
int 		partition (int arr[], int low, int high);
int 		*quick_sort(int arr[], int low, int high);
void 		print_array(int arr[], int size);

/* min max utils */
int			get_middle(t_stack	*a, int	len);
int			get_closest_min_index(t_stack *a, int middle, int lenght);
void		move_mins_to_b(t_stack **a, t_stack **b, int half_stack ,int middle);
void		sort_min_half(t_stack **a, t_stack **b, int lenght);
int 		min_or_max(t_stack *a, t_stack *b);
void 		move_mins(t_stack **a, t_stack **b, int back_min, int min_index);
void 		move_maxs(t_stack **a, t_stack **b, int back_max, int max_index);
void 		exclude_min_max(t_stack **a, t_stack **b, char min_or_max, int lenght);
int 		get_min_max_index(t_stack *a, char min_or_max);
int 		get_min_or_max(t_stack *a, int min_or_max);

/*to remove later */
void 		visualize(t_stack *a, t_stack *b);
void		do_something(char *str);
 
 #endif