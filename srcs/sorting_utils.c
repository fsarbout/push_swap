/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:12:05 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/06 11:59:44 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void move_mins_to_b(t_stack **a, t_stack **b, int middle)
{
	int index;
	int lenght;
	int j;

	lenght = list_lenght(*a);
	while (isthere(*a, middle))
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
		push(a, b, 2);
	}
}

int		getmin_index_top(t_stack *a, int min)
{
	t_stack *tmp;
	int cnt;

	tmp = a;
	cnt = 0;
	while (tmp)
	{
		if (tmp->nb < min)
			return (cnt);
		cnt++;
		tmp = tmp->next;
	}
	return (0);
}

int		getmin_index_bottum(t_stack *a, int min)
{
	t_stack *tmp;
	int cnt;
	int minnn;
	
	tmp = a;
	cnt = 0;
	while (tmp)
	{
		if (tmp->nb < min)
			minnn = tmp->nb;
		tmp = tmp->next;
	}
	tmp = a;
	while (tmp)
	{
		if (tmp->nb == minnn)
			return (cnt);
		cnt++;
		tmp = tmp->next;
	}
	return (0);
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