/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:39:43 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/05 16:40:24 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_swap(t_stack **a, t_stack **b, int ac)
{
	(void)b;
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
	else if (ac <= 100 && ac != 20)
		sort_hundred(a,b);
	else if (ac == 500)
		sort_500(a,b);
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

void sort_hundred(t_stack **a, t_stack **b)
{
	int lenght_a;
	int lenght_b;
	int middle;
	int min= get_min_or_max(*a, '-');

	(void)b;
	lenght_a = list_lenght(*a);
	middle = get_middle(*a, lenght_a , 2);
	move_mins_to_b(a, b,  middle);
	lenght_b = list_lenght(*b);
	sort_min_half(a, b, lenght_b);
	while (*a)
	{
		if ((*a)->nb == min)
			break;
		push(a,b,2);
	}
	lenght_b = list_lenght(*b);
	sort_min_half(a, b, lenght_b);
}

void sort_min_half(t_stack **a, t_stack **b, int lenght)
{
	int min_index;
	int max_index;
	int back_min;
	int back_max;
	int ra_number;
	
	ra_number = 0;
	while (*b)
	{
		back_min = 0;
		back_max = 0;
		min_index = get_min_max_index(*b, '-');
		max_index = get_min_max_index(*b ,'+');
		if (min_index > lenght / 2)
		{
			back_min = 1;
			min_index = lenght - min_index - 1;
		}
		if (max_index > lenght / 2)
		{
			back_max = 1;
			max_index = lenght - max_index - 1;
		}
		if (min_index <= max_index)
			move_mins(a,b,back_min,min_index);
		else
		{
			move_maxs(a,b,back_max,max_index);
			ra_number++;
		}
		lenght--;
	}
	while (ra_number)
	{
		rotate(a, 1);
		ra_number--;
	}
}

void move_mins(t_stack **a, t_stack **b, int back_min, int min_index)
{
	if (back_min == 1)
	{
		while (min_index >= 0)
		{
			reverse(b, 2);
			min_index--;
		}
		push(b, a, 1);
		rotate(a, 1);
	}
	else
	{
		while (min_index >= 1)
		{
			rotate(b, 2);
			min_index--;
		}
		push(b, a, 1);
		rotate(a, 1);
	}
}

void move_maxs(t_stack **a, t_stack **b, int back_max, int max_index)
{
	if (back_max == 1)
	{
		while (max_index >= 0)
		{
			reverse(b, 2);
			max_index--;
		}
		push(b, a, 1);
	}
	else
	{
		while (max_index >= 1)
		{
			rotate(b, 2);
			max_index--;
		}
		push(b, a, 1);
	}
}

void move_mins_to_b(t_stack **a, t_stack **b, int middle)
{
	int index;
	int lenght = list_lenght(*a);
	int i = 0;
	int j = 0;

	while (isthere(*a, middle))
	{
	
		lenght = list_lenght(*a);
		// print_list(a);
		int mid = lenght / 2;
		// printf("middle %d\n", middle);
		// printf("mid %d\n", mid);
		index = get_closest_min_index(*a, middle, lenght);
		// printf("closest min index %d \n", index);
		j = 0;
		if (index < mid)
			while (j < index && ++j)
				rotate(a, 1);
		else
			while (index < lenght && ++index)
				reverse(a, 1);
		push(a, b, 2);
		i++;
		
		// printf ("a******\n");
		// print_list(a);
		// printf ("a******\n");
		
		// printf ("b******\n");
		// print_list(b);
		// printf ("b******\n");
	}
}

int		isthere(t_stack *a, int middle)
{
	
	t_stack *tmp;
	tmp = a;
	while (tmp)
	{
		if (tmp->nb < middle)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}