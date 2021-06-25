/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:37:34 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/25 17:15:56 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_middle(t_stack	*a, int	len)
{
	int	mid;
	int	*arr;
	int	i;
	int	*sorted_arr;

	if (len == 1)
		return (a->nb);
	if (len == 2)
	{
		if (a->nb < a->next->nb)
			return (a->nb);
		return (a->next->nb);
	}
	i = 0;
	arr = get_array(a);
		
	sorted_arr = quick_sort(arr, 0, len - 1);
	mid = sorted_arr[len / 2];
	// free(arr);
	printf("      Sorted array\n");
	print_array(arr, len); 
	return (mid);
}

int	get_min(t_stack *a)
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

int		get_max(t_stack *a)
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

void	exclude_max(t_stack **a, t_stack **b)
{
	int max_index;
	int lenght;
	int i;
	
	lenght = list_lenght(*a);
	i = 1;
	max_index = get_max_index(*a);
	if (max_index <= lenght / 2)
	{
		while (i < max_index && i++)
			rotate(a);
		push(a,b);
	}
	else
	{
		i = lenght;
		while (i >= max_index && i--)
			reverse(a);
		push(a,b);
	}
}

void exclude_min(t_stack **a, t_stack **b)
{
	int min_index;
	int lenght;
	int i;
	
	i = 1;
	lenght = list_lenght(*a);
	min_index = get_min_index(*a);
	if (min_index <= lenght / 2)
	{
		while (i < min_index && i++)
			rotate(a);
		push(a,b);
	}
	else
	{
		i = lenght;
		while (i >= min_index && i--)
			reverse(a);
		push(a,b);
	}
}

int	get_max_index(t_stack *a)
{
	int max_index;
	int max;
	
	max = get_max(a);
	max_index = 1;
	while ((a) && ((a)->next))
	{
		if ((a)->nb == max)
			return (max_index);
		max_index++;
		(a) = (a)->next;
	}
	return max_index;
}

int	get_min_index(t_stack *a)
{
	int min_index;
	int min;
	
	min = get_min(a);
	min_index = 1;
	while ((a) && ((a)->next))
	{
		if ((a)->nb == min)
			return (min_index);
		min_index++;
		(a) = (a)->next;
	}
	return min_index;
}

int	get_closest_min_index(t_stack *a, int middle)
{
	int	*arr;
	int lenght;
	int i;

	lenght = list_lenght(a);
	printf("lenght dzmer %d \n", lenght);
	arr = get_array(a);
	int index1 = 0;
	int index2 = 0;
	i = 0;
	while (arr[i] >= middle && i++)
		index1++;
	i = 0;
	while (arr[lenght - i - 1] >= middle && i++)
		index2++;
	if (index1 <= index2)
		return (index1);
	return (lenght - i - 1);
}