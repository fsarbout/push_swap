/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:09:00 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/23 12:52:16 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int 	*get_array(t_stack *a)
{
	int lenght;
	int *tab;
	int i;
	
	i = 0;
	lenght = list_lenght(a);
	tab = malloc(sizeof(int*) * (lenght + 1));
	while (i < lenght)
	{
		tab[i] = a->nb;	
		i++;
		a = a->next;
	}
	return (tab);
}