/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:05:18 by fsarbout          #+#    #+#             */
/*   Updated: 2021/04/11 23:25:03 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_valid_arg(t_stack **stack, char *str)
{
	int i;

	if (not_number(str))
		exit_(stack, "argument isn't number or integer\n" , 1);
	i = ft_atoi_(stack, str);
	if (*stack)
		if (duplicate_int(stack, i))
			exit_(stack, "duplicate argument\n" , 1);
	return (1);
}

int		not_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (1);
		str++;
	}
	return (0);
}

int 	duplicate_int(t_stack **stack, int i)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->nb == i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		is_sorted(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			exit_(&stack, "KO" , 2);
		tmp = tmp->next;
	}
	exit_(&stack, "OK" , 0);
	return (0);
}

int	ft_atoi_(t_stack **stack, const char *s)
{
	int		sign;
	long	a;

	sign = 1;
	a = 0;
	while (*s == ' ' || (*s <= 13 && *s >= 9))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while ((*s <= '9') && (*s >= '0'))
	{
		a = a * 10 + *s - '0';
		if (a > 4294967296 && sign == 1)
			exit_(stack, "argument is not in int limts", 1);
		if (a > 4294967296 && sign == -1)
			exit_(stack, "argument is not in int limts", 1);
		s++;
	}
	return ((int)a * sign);
}