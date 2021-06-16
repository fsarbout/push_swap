/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:54:31 by fsarbout          #+#    #+#             */
/*   Updated: 2021/04/11 18:22:11 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	list_add_back(t_stack **head, int nb)
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

void	list_add_front(t_stack **head , int nb)
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

void	print_list(t_stack **head)
{
	t_stack *temp;
	temp = *head;
	while (temp)
	{
		printf("%d\n" , temp->nb);
		temp = temp->next;
	}	
}


t_stack	*new_stack(int argc, char **argv)
{
	t_stack *stack;
	
	stack = NULL;
	while (argc > 1)
	{
		if (is_valid_arg(&stack, argv[argc - 1]))
			list_add_front(&stack , ft_atoi(argv[argc - 1]));
		else
			exit_(&stack, "not valid argument\n", 1);
		argc--;
	}
	return (stack);
}

void	clear_list(t_stack **lst)
{
	if (*lst)
	{
		if ((*lst)->next)
			clear_list(&(*lst)->next);
		free(*lst);
		*lst = NULL;
	}
}
