/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:39:43 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/29 13:11:53 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void 	push_swap(t_stack **a, t_stack **b, int  ac)
{
	(void)b;
	if (ac == 2)
		swap(a, 1);
	else if (ac == 3)
		sort_three(a);
	else if (ac == 5)
		sort_five(a, b);
	else if (ac <= 100)
		sort_hundred(a, b);
	// else if (ac == 500)
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

void	sort_five(t_stack **a, t_stack **b)
{
	exclude_max(a, b);
	exclude_min(a, b);
	if (!is_sorted(*a))
		sort_three(a);
	push(b,a, 2);
	push(b,a, 2);
	rotate(a, 1);
}

void	sort_hundred(t_stack **a, t_stack **b)
{
	int lenght;
	int middle;

	(void)b;
	lenght = list_lenght(*a);
	middle = get_middle(*a , lenght);
	move_mins_to_b(a, b, lenght / 2 , middle);
	lenght = list_lenght(*b);
		visualize(*a, *b);

	sort_min_half(a, b, lenght , lenght / 2);
	
}

void	sort_min_half(t_stack **a, t_stack **b, int lenght, int half_lenght)
{
	int min_index;
	int max_index;
	

		
	while (*b)
	{
		min_index = get_min_index(*b);
 		max_index = get_max_index(*b);
		// max_index = get_max_index(*b);

		 printf (" min index %d\n", min_index);
		 printf (" max index %d\n", max_index);
		
		if (min_index > half_lenght)
		{
			min_index = lenght - min_index - 1;
			while (min_index >= 0 && min_index--)
				reverse(b,2);			
			push(b, a, 1);
			rotate(a, 1);
		}
		else
		{
			while (min_index >= 1 && min_index--)
				rotate(b,1);
			push(b, a, 1);
			rotate(a, 1);
		}
		/**/
		visualize(*a, *b);
		
		printf (" min index %d\n", min_index);
		printf (" max index %d\n", max_index);
		
		if (max_index > half_lenght)
		{
			max_index = lenght - max_index - 1;
			while (max_index >= 0 && max_index--)
				reverse(b,2);
			push(b, a, 2);
			visualize(*a, *b);
		}
		else
		{
			while (max_index >= 1 && max_index--)
				rotate(b,2);
			push(b, a, 2);
			visualize(*a, *b);
		}
		lenght--;
	}
	// visualize(*a, *b);
}

void	do_something(char *str)
{
	printf("%s\n", str);
}

void	move_mins_to_b(t_stack **a, t_stack **b, int half_stack ,int middle)
{
	int index;
	int lenght = list_lenght(*a);
	int i = 0;
	int j = 0;

	while (i < half_stack)
	{
		lenght = list_lenght(*a);
		int mid = lenght / 2;
		index = get_closest_min_index(*a, middle, lenght);
		j = 0;
		if (index < mid)
			while (j < index && ++j)
				rotate(a, 1);
		else
			while (index < lenght && ++index)			
				reverse(a, 1);
		push(a,b, 1);
		i++;
	}
}