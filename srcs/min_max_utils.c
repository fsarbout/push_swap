/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:37:34 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/01 12:00:21 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_min(t_stack *a)
{
	int min;

	min = (a)->nb;
	a = (a)->next;
	while (a)
	{
		if (min > (a)->nb)
			min = (a)->nb;
		a = (a)->next;
	}
	return (min);
}

int get_max(t_stack *a)
{
	int max;

	max = (a)->nb;
	a = (a)->next;
	while (a)
	{
		if (max < (a)->nb)
			max = (a)->nb;
		a = (a)->next;
	}
	return (max);
}

void exclude_max(t_stack **a, t_stack **b)
{
	int max_index;
	int lenght;
	int i;

	lenght = list_lenght(*a);
	i = 0;
	max_index = get_max_index(*a);
	// printf ("maaaaaaaax index %d \n", max_index);

	if (max_index > lenght / 2)
	{
		max_index = lenght - max_index;
		i = 2;
	}

	if (i != 2)
	{
		while (max_index-- > 0)
			rotate(a, 1);
		push(a, b, 2);
	}
	else
	{
		// i = lenght;
		while (max_index-- > 0)
			reverse(a, 1);
		push(a, b, 2);
	}
}

void exclude_min(t_stack **a, t_stack **b)
{
	int min_index;
	int lenght;
	int i;

	i = 0;
	lenght = list_lenght(*a);
	min_index = get_min_index(*a);
	// printf ("miiiiiiiiiiin index %d \n", min_index);
	// printf ("min index %d lenght / 2 %d i %d \n", min_index , lenght / 2, i );
	
	if (min_index > lenght / 2)
	{
		min_index = lenght - min_index;
		i = 2;
	}

	if (i != 2)
	{
		while (min_index-- > 0)
			rotate(a, 1);
		push(a, b, 2);
	}
	else
	{
		// i = lenght;
		while (min_index-- > 0)
			reverse(a, 1);
		push(a, b, 2);
	}
}

int get_max_index(t_stack *a)
{
	int max_index;
	int max;

	max = get_max(a);
	max_index = 0;
	while (a->nb != max)
	{
		max_index++;
		(a) = (a)->next;
	}
	return max_index;
}

int get_min_index(t_stack *a)
{
	int min_index;
	int min;

	min = get_min(a);
	min_index = 0;
	while (a->nb != min)
	{
		min_index++;
		(a) = (a)->next;
	}
	return min_index;
}

int get_closest_min_index(t_stack *a, int middle, int lenght)
{
	int *arr;
	int i;

	arr = get_array(a);
	int index1 = 0;
	int index2 = 0;
	i = 0;
	while (arr[i] >= middle && ++i)
		index1++;
	i = 0;
	while (arr[lenght - i - 1] >= middle && ++i)
		index2++;
	if (index1 <= index2)
	{
		free(arr);
		return (index1);
	}
	free(arr);
	return (lenght - i - 1);
}

int get_closest_max_index(t_stack *a, int middle, int lenght)
{
	int *arr;
	int i;

	arr = get_array(a);
	int index1 = 0;
	int index2 = 0;
	i = 0;
	while (arr[i] <= middle && ++i)
		index1++;
	i = 0;
	while (arr[lenght - i - 1] <= middle && ++i)
		index2++;
	if (index1 <= index2)
		return (index1);
	return (lenght - i - 1);
}

int get_middle(t_stack *a, int len)
{
	int mid;
	int *arr;
	// int	i;
	int *sorted_arr;

	if (len == 1)
		return (a->nb);
	if (len == 2)
	{
		if (a->nb < a->next->nb)
			return (a->nb);
		return (a->next->nb);
	}
	// i = 0; ::::::;1
	arr = get_array(a);
	sorted_arr = quick_sort(arr, 0, len - 1);
	mid = sorted_arr[len / 2];
	free(arr);
	return (mid);
}