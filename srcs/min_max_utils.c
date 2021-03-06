/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:37:34 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/06 11:21:09 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_min_or_max(t_stack *a, int min_or_max)
{
	int min_max;

	min_max = (a)->nb;
	a = (a)->next;
	if (min_or_max == '+')
	{
		while (a)
		{
			if (min_max < (a)->nb)
				min_max = (a)->nb;
			a = (a)->next;
		}
	}
	else
	{
		while (a)
		{
			if (min_max > (a)->nb)
				min_max = (a)->nb;
			a = (a)->next;
		}
	}
	return (min_max);
}

int get_min_max_index(t_stack *a, char min_or_max)
{
	int index;
	int min_max;

	index = 0;
	if (min_or_max == '+')
		min_max = get_min_or_max(a, '+');
	else
		min_max = get_min_or_max(a, '-');
	while (a->nb != min_max)
	{
		index++;
		(a) = (a)->next;
	}
	return index;
}

void exclude_min_max(t_stack **a, t_stack **b, char min_or_max, int lenght)
{
	int index;
	int i;

	i = 0;
	if (min_or_max == '+')
		index = get_min_max_index(*a, '+');
	else
		index = get_min_max_index(*a, '-');
	if (index > lenght / 2)
	{
		index = lenght - index;
		i = 2;
	}
	if (i != 2)
	{
		while (index-- > 0)
			rotate(a, 1);
		push(a, b, 2);
	}
	else
	{
		while (index-- > 0)
			reverse(a, 1);
		push(a, b, 2);
	}
}

int get_middle(t_stack *a, int len, int devide_to)
{
	int mid;
	int *arr;
	int *sorted_arr;

	if (len == 1)
		return (a->nb);
	if (len == 2)
	{
		if (a->nb < a->next->nb)
			return (a->nb);
		return (a->next->nb);
	}
	arr = get_array(a);
	sorted_arr = quick_sort(arr, 0, len - 1);
	mid = sorted_arr[(len / devide_to)];
	free(arr);
	return (mid);
}

int get_closest_min_index(t_stack *a, int middle, int lenght) 
{
	int index1;
	int index2;
	
	index1 = getmin_index_top(a, middle);
	index2 =  getmin_index_bottum(a, middle);
	if (index1 < lenght - index2)
		return (index1);
	return (index2);
}