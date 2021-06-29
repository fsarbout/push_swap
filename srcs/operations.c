/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:07:10 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/29 11:33:20 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack, int key)
{
	int tmp;
	
	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack)->next->nb;
		(*stack)->next->nb = (*stack)->nb;
		(*stack)->nb = tmp;
	}
	if (key == 1)
		write(1 ,"sa\n", 3);
	else if (key == 2)
		write(1 ,"sb\n", 3);
}

void	push(t_stack **stack_1 , t_stack **stack_2, int key)
{
	int		nbr;

	if (*stack_1)
	{	
		nbr = del_first_node(stack_1);
		list_add_front(stack_2, nbr);
	}
	if (key == 1)
		write(1 ,"pa\n", 3);
	else if (key == 2)
		write(1 ,"pb\n", 3);
}

void	rotate(t_stack **stack_1, int key)
{
	int		nbr;
	
	if (*stack_1 && (*stack_1)->next)
	{
		nbr = del_first_node(stack_1);
		list_add_back(stack_1, nbr);
	}
	if (key == 1)
		write(1 ,"ra\n", 3);
	else if (key == 2)
		write(1 ,"rb\n", 3);
}

void	reverse(t_stack **stack_1, int key)
{
	int		nbr;
	
	if (*stack_1 && (*stack_1)->next)
	{
		nbr = del_last_node(stack_1);
		list_add_front(stack_1, nbr);
	}
	if (key == 1)
		write(1 ,"rra\n", 4);
	else if (key == 2)
		write(1 ,"rrb\n", 4);
}

int	apply_instruction(char *line , t_stack **a , t_stack **b)
{
	if (!strncmp(line, "sa" , 3))
		swap(a, 0);
	else if (!strncmp(line, "sb" , 3))
		swap(b, 0);
	else if (!strncmp(line, "ss" , 3))
		complex_instructions("ss",a,b);
	else if (!strncmp(line, "pa" , 3))
		push(a,b, 0);
	else if (!strncmp(line, "pb" , 3))
		push(b,a, 0);
	else if (!strncmp(line, "ra" , 3))
		rotate(a, 0);
	else if (!strncmp(line, "rb" , 3))
		rotate(b, 0);
	else if (!strncmp(line, "rr" , 3))
		complex_instructions("rr",a,b);
	else if (!strncmp(line, "rra" , 4))
		reverse(a, 0);
	else if (!strncmp(line, "rrb" , 4))
		reverse(b, 0);
	else if (!strncmp(line, "rrr" , 4))
		complex_instructions("rr",a,b);
	else
		exit_(a,b,0,1);
	return (0);
}

void	complex_instructions(char *instruction, t_stack **a, t_stack **b)
{
	if ((!strncmp(instruction, "ss" , 3)))
	{
		swap(a, 0);
		swap(b, 0);
	}
	else if (!strncmp(instruction, "rr" , 3))
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (!strncmp(instruction, "rrr" , 4))
	{
		reverse(a, 0);
		reverse(b, 0);
	}
}