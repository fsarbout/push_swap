/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:07:10 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/16 21:12:23 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	int tmp;
	if ((*stack) && (*stack)->next )
	{
		tmp = (*stack)->next->nb;
		(*stack)->next->nb = (*stack)->nb;
		(*stack)->nb = tmp;
	}
}

void	push(t_stack **stack_1 , t_stack **stack_2)
{
	int		nbr;

	nbr = del_first_node(stack_1);
	list_add_front(stack_2, nbr);
}


void	rotate(t_stack **stack_1 , t_stack **stack_2)
{
	int		nbr;

	nbr = del_first_node(stack_1);
	list_add_back(stack_2, nbr);
}

void	reverse(t_stack **stack_1 , t_stack **stack_2)
{
	int		nbr;

	nbr = del_last_node(stack_1);
	list_add_back(stack_2, nbr);
}