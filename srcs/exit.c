/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsarbout <fsarbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:10:54 by fsarbout          #+#    #+#             */
/*   Updated: 2021/06/30 11:28:31 by fsarbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_(t_stack **a,t_stack **b ,char *string, int error)
{
	// (void)b;
	// (void)a;
	if (error == 1)
		ft_putstr("Error\n");
	if (error == 0)
		ft_putendl_fd(GREEN, STDOUT_FILENO);
	if (error == 2)
		ft_putendl_fd(RED, STDOUT_FILENO);
	ft_putstr(string);
	if (error == 1)
	{
		clear_list(a);
		if (b)
			clear_list(b);
	}
	else 
	{
		clear_list(a);
		if (b)
			clear_list(b);
	}
	exit(0);
}