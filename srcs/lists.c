/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:54:31 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/21 18:19:32 by fsarbout         ###   ########.fr       */
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

void clear_list(t_stack **lst)
{
	if (*lst)
	{
		if ((*lst)->next)
			clear_list(&(*lst)->next);
		free(*lst);
		*lst = NULL;
	}
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

t_stack *lstnew(int nb)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->nb = nb;
	stack->next = NULL;
	return (stack);
}