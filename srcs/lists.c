/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:54:31 by fsarbout          #+#    #+#             */
/*   Updated: 2021/07/06 11:55:34 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void list_add_back(t_stack **head, int nb)
{
	t_stack *lastnode;
	t_stack *node;

	node = malloc(sizeof(t_stack));
	node->nb = nb;
	node->next = NULL;
	if (!(*head))
		*head = node;
	else
	{
		lastnode = *head;
		while ((*head)->next && head)
			(*head) = (*head)->next;
		(*head)->next = node;
		*head = lastnode;
	}
}

void list_add_front(t_stack **head, int nb)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->nb = nb;
		new->next = *head;
		*head = new;
	}
}

t_stack *new_stack(int ac, char **av)
{
	t_stack *stack;

	stack = NULL;
	while (ac > 1)
	{
		if (is_valid_arg(&stack, av[ac - 1]))
			list_add_front(&stack, ft_atoi(av[ac - 1]));
		else
			exit_(&stack, 0, "not valid argument\n", 1);
		ac--;
	}
	return (stack);
}

int del_last_node(t_stack **list)
{
	t_stack *tmp;
	t_stack *new;
	int last_node;

	tmp = *list;
	new = NULL;
	if (!tmp)
		return (0);
	if (!tmp->next)
	{
		free(new);
		return (0);
	}
	new = tmp;
	while (new->next->next)
		new = new->next;
	last_node = new->next->nb;
	free(new->next);
	new->next = NULL;
	return (last_node);
}

int del_first_node(t_stack **list)
{
	int first_node;
	t_stack *tmp;

	tmp = NULL;
	if ((*list)->next)
		tmp = (*list)->next;
	first_node = (*list)->nb;
	free(*list);
	*list = tmp;
	return (first_node);
}