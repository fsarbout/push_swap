/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:46:06 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/22 23:54:55 by fsarbout         ###   ########.fr       */
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
	clear_list(&a);
	clear_list(&b);
	// print_list(&a);
	// printf("**********\n");
	// print_list(&b);
}

void 	push_swap(t_stack **a, t_stack **b, int  ac)
{
	(void)b;
	if (ac == 2)
		swap(a);
	if (ac == 3)
		sort_three(a);
	if (ac == 5)
		sort_five(a, b);
	// if (ac == 100)
	// 	do_something();
	// else
	// 	do_something();
	else 
		printf("hello1\n");
	printf("l9laawi\n");
	print_list(a);
	printf("*******\n");
	print_list(b);
	
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
	
	lenght = list_lenght(*a);
	min_index = get_min_index(*a);
	if (min_index <= lenght / 2)
	{
		printf(" min in th/e first half\n");
		while (lenght > min_index && lenght--)
			rotate(a);
		push(a,b);
	}
	else
	{
		printf("min in the second half\n");
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