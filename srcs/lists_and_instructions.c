/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_and_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:09:00 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/06 12:04:01 by fsarbout         ###   ########.fr       */
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

void print_list(t_stack **head)
{
	t_stack *temp;
	temp = *head;
	while (temp)
	{
		printf("%d\n", temp->nb);
		temp = temp->next;
	}
}

void	complex_instructions(char *instruction, t_stack **a, t_stack **b)
{
	if ((!strncmp(instruction, "ss" , 3)))
	{
		swap(a, 0);
		swap(b, 0);
	}
	else if (!strncmp(instruction, "rr" , 3))
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (!strncmp(instruction, "rrr" , 4))
	{
		reverse(a, 0);
		reverse(b, 0);
	}
}