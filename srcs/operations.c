/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:07:10 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/20 13:03:09 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	int tmp;
	
	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack)->next->nb;
		(*stack)->next->nb = (*stack)->nb;
		(*stack)->nb = tmp;
	}
}

void	push(t_stack **stack_1 , t_stack **stack_2)
{
	int		nbr;

	if (*stack_2)
	{
		nbr = del_first_node(stack_1);
		list_add_front(stack_2, nbr);
	}
}

void	rotate(t_stack **stack_1)
{
	int		nbr;
	
	if (*stack_1 && (*stack_1)->next)
	{
		nbr = del_first_node(stack_1);
		list_add_back(stack_1, nbr);
	}
}

void	reverse(t_stack **stack_1)
{
	int		nbr;
	
	if (*stack_1 && (*stack_1)->next)
	{
		nbr = del_last_node(stack_1);
		list_add_front(stack_1, nbr);
	}
}

int	apply_instruction(char *line , t_stack **a , t_stack **b)
{
	if (!strncmp(line, "sa" , 3))
		swap(a);
	else if (!strncmp(line, "sb" , 3))
		swap(b);
	else if (!strncmp(line, "ss" , 3))
		complex_instructions("ss",a,b);
	else if (!strncmp(line, "pa" , 3))
		push(a,b);
	else if (!strncmp(line, "pb" , 3))
		push(b,a);
	else if (!strncmp(line, "ra" , 3))
		rotate(a);
	else if (!strncmp(line, "rb" , 3))
		rotate(b);
	else if (!strncmp(line, "rr" , 3))
		complex_instructions("rr",a,b);
	else if (!strncmp(line, "rra" , 4))
		reverse(a);
	else if (!strncmp(line, "rrb" , 4))
		reverse(b);
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
		swap(a);
		swap(b);
	}
	else if (!strncmp(instruction, "rr" , 3))
	{
		rotate(a);
		rotate(b);
	}
	else if (!strncmp(instruction, "rrr" , 4))
	{
		reverse(a);
		reverse(b);
	}
}