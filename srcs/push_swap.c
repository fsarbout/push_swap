/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:39:43 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/06 11:58:46 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_swap(t_stack **a, t_stack **b, int ac)
{
	if (ac == 2)
		swap(a, 1);
	else if (ac == 3)
		sort_three(a);
	else if (ac == 4)
	{
		exclude_min_max(a, b, '-', list_lenght(*a));
		if (!is_sorted(*a))
			sort_three(a);
		push(b,a,1);
	}
	else if (ac == 5)
		sort_five(a, b);
	// else if (ac == 20)
	// 	sort_hundred(a, b);
	else if (ac > 5)
		sort_plus_5(a, b, list_lenght(*a), 0);
}

void sort_three(t_stack **a)
{
	int min;

	min = get_min_or_max(*a, '-');
	if ((*a)->nb == get_min_or_max(*a, '+'))
	{
		if ((*a)->next->nb == min)
			rotate(a, 1);
		else
		{
			rotate(a, 1);
			swap(a, 1);
		}
	}
	else if ((*a)->nb == min)
	{
		reverse(a, 1);
		swap(a, 1);
	}
	else
	{
		if ((*a)->next->nb == min)
			swap(a, 1);
		else
			reverse(a, 1);
	}
}

void sort_five(t_stack **a, t_stack **b)
{
	exclude_min_max(a, b, '+', list_lenght(*a));
	exclude_min_max(a, b, '-', list_lenght(*a));
	if (!is_sorted(*a))
		sort_three(a);
	push(b, a, 1);
	push(b, a, 1);
	rotate(a, 1);
}

/*
** for norminette cnt used as middle_index in first loop 
** and max_index in second one
*/

void	sort_plus_5(t_stack **a, t_stack **b, int lenght_stack, int cnt)
{
	while (lenght_stack)
	{
		lenght_stack = list_lenght(*a);
		cnt = get_middle(*a, lenght_stack ,7);
		if (lenght_stack <= 7)
			push(a,b ,2);
		else
			move_mins_to_b(a, b, cnt);
	}
	while (*b)
	{
		lenght_stack = list_lenght(*b);
		cnt = get_min_max_index(*b, '+');
		if (cnt > lenght_stack / 2)
		{
			cnt = lenght_stack - cnt;
			while (cnt-- > 0)
				reverse(b, 2);
		}
		else
			while (cnt-- > 0)
				rotate(b, 2);
		push(b, a, 1);	
	}
}