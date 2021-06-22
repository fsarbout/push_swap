/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:09:00 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/22 11:49:42 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_min(t_stack *a)
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

int		list_lenght(t_stack *a)
{
	int lenght;

	lenght = 0;
	while (a)
	{
		a = a->next;
		lenght++;
	}	
	return (lenght);
}

int *get_array(t_stack *a)
{
	int lenght;
	int *tab;
	int i;
	 
	i = 0;
	lenght = list_lenght(a);
	tab = malloc(sizeof(int*) * (lenght + 1));
	while (i < lenght)
	{
		tab[i] = get_min(a);
		i++;
		a = a->next;
	}
	return (tab);
}

