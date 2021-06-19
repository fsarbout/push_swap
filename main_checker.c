/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:46:03 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/19 21:28:20 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b = NULL;
	char *line;
	int gnl_ret;
	
	if (ac >= 2)
	{
		a = new_stack(ac, av);
		while (get_next_line(0, &line))
		{
			gnl_ret = apply_instruction(line, &a, &b);
			if (gnl_ret == -1)
				return (-1);
		}
		// swap(&a);
		// push(&a , &b);
		// rotate(&a , &b);
		// rotate(&a);
		// printf("heeyyyy\n");
		// print_list(&a);
		// printf("heeyyyy\n");
		// print_list(&b);
		// print_list(&a);
		is_sorted(a);
	}
	return (0);
}

void	exit_(t_stack **a,t_stack **b ,char *string, int error)
{
	if (error == 1)
		ft_putstr("Error\n");
	if (error == 0)
		ft_putendl_fd(GREEN, STDOUT_FILENO);
	if (error == 2)
		ft_putendl_fd(RED, STDOUT_FILENO);
	ft_putstr(string);
	if (error == 1)
	{
		clear_list(a);
		clear_list(b);
	}
	exit(0);
}

int	apply_instruction(char *line , t_stack **a , t_stack **b)
{
	if (!strncmp(line, "sa" , 3))
		swap(a);
	if (!strncmp(line, "sb" , 3))
		swap(b);
	if (!strncmp(line, "ss" , 3))
		complex_instructions("ss",a,b);
	if (!strncmp(line, "pa" , 3))
		push(a,b);
	if (!strncmp(line, "pb" , 3))
		push(a,b);
	if (!strncmp(line, "ra" , 3))
		rotate(a);
	if (!strncmp(line, "rb" , 3))
		rotate(b);
	if (!strncmp(line, "rr" , 3))
		complex_instructions("rr",a,b);
	if (!strncmp(line, "rra" , 4))
		reverse(a);
	if (!strncmp(line, "rrb" , 4))
		reverse(b);
	if (!strncmp(line, "rrr" , 4))
		complex_instructions("rr",a,b);
	else
		exit_(a,b,0,1);
	return (0);
}

void	complex_instructions(char *instruction, t_stack **a, t_stack **b)
{
	if ((!strncmp(instruction, "ss" , 3)))
	{
		swap(a);
		swap(b);
	}
	if (!strncmp(instruction, "rr" , 3))
	{
		reverse(a);
		rotate(b);
	}
	if (!strncmp(instruction, "rrr" , 4))
	{
		reverse(a);
		reverse(b);
	}
}
