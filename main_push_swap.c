/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:46:06 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/22 14:31:33 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	
	if (ac > 2)
	{
		b = NULL;
		a = new_stack(ac, av);
		if (!is_sorted(a))
			push_swap(&a, &b, ac - 1);
	}
}

void 	push_swap(t_stack **a, t_stack **b, int  ac)
{
	(void)b;
	if (ac == 2)
		swap(a);
	if (ac == 3)
		sort_three(a);
	// if (ac == 5)
	// 	do_something();
	// if (ac == 100)
	// 	do_something();
	// else
	// 	do_something();
	print_list(a);
}

void	sort_three(t_stack **a)
{
	int min;
	
	min = get_min(*a);
	if ((*a)->nb == get_max(*a))
	{
		if ((*a)->next->nb == min)
			rotate(a);
		else
		{
			rotate(a);
			swap(a);
		}
	}
	else if ((*a)->nb == min)
	{
		reverse(a);
		swap(a);
	}
	else
	{
		if ((*a)->next->nb == min)
			swap(a);
		else
			reverse(a);
	}
}

void	sort_five(t_stack **a)
{
	int min;
	int max;

	

	
	
}