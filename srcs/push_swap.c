/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:39:43 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/25 17:46:24 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void 	push_swap(t_stack **a, t_stack **b, int  ac)
{
	(void)b;
	if (ac == 2)
		swap(a);
	else if (ac == 3)
		sort_three(a);
	else if (ac == 5)
		sort_five(a, b);
	else if (ac <= 100)
		sort_hundred(a, b);
	// else
	// 	do_something();
	else 
		printf("hello1\n");
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

void	sort_five(t_stack **a, t_stack **b)
{
	exclude_max(a, b);
	exclude_min(a, b);
	if (!is_sorted(*a))
		sort_three(a);
	push(b,a);
	push(b,a);
	rotate(a);
}

void	sort_hundred(t_stack **a, t_stack **b)
{
	int lenght;
	int middle;

	(void)b;
	lenght = list_lenght(*a);
	middle = get_middle(*a , lenght);
	move_mins_to_b(a, b, lenght / 2 , middle);
	// sort_part();
	printf("the middle %d\n", middle);
}

void	move_mins_to_b(t_stack **a, t_stack **b, int half_stack ,int middle)
{
	int index;
	int lenght = list_lenght(*a);
	int i = 0;
	int j = 0;
	(void)b;
	index = get_closest_min_index(*a, middle);
	printf("the fucking closest min index is : %d\n" , index);
	printf("stack half is :%d \n", half_stack);
	
	while (i < half_stack)
	{
		lenght = list_lenght(*a);
		index = get_closest_min_index(*a, middle);
		middle = lenght / 2;
		j = 0;
		if (index < middle)
			while (j < index && j++)
				rotate(a);
		else
			while (index < lenght && index++)			
				reverse(a);
		push(a,b);
		i++;
	}
	printf("adiiik zzmer\n");
	print_list(a);
	printf("adiiik zzmerqwejkgheoqug eqgheqrgh\n");
	print_list(b);
}